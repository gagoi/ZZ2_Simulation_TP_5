/**
 * @file Hunter.cpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier d'implémentation de la classe Hunter
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Hunter.hpp"

std::mt19937 Hunter::gen(253);
std::uniform_int_distribution<> Hunter::move_distribution(-2, 2);

Hunter::Hunter(Point const & p, char c) :
    Agent(p, c),
    _lifeState(LIFE_STATE::ORANGE),
    _stepsBeforeChange(ORANGE_STATE_DURATION)
{
}

Hunter::~Hunter()
{
}

void Hunter::update()
{
    // Environnement du Hunter (voisinage de Moore d'ordre 3)
    std::vector<Entity*> environment = World::getInstance().getEnvironment(_position, 3);
    bool moved = false;

    for (auto &&e : environment)
    {
        if (e != nullptr && e->getType() == ENTITY_TYPE::HARVESTER)
        {
            Harvester* harvester = dynamic_cast<Harvester*>(e);
            if (!harvester->isDead())
            {
                Point d = World::getInstance().getDistances(getPosition(), e->getPosition());
                if (d.x <= 2 && d.y <= 2) // Si il y a un Harvester dans un voisinage de Moore d'ordre 2
                {
                    // On se déplace et on mange le récolteur
                    Point pos(harvester->getPosition());
                    harvester->kill();
                    notifyKill(harvester);
                    setPosition(pos);
                    // TODO: Système de barre de vie
                    moved = true;
                }
                else
                {
                    // On se déplace vers lui
                    // TODO: regarder si il y a quelque chose entre les deux sur lequel le Hunter ne peux pas marcher (Base, ressource)
                    move(World::getInstance().getDirection(_position, e->getPosition()) * 2);
                    moved = true;
                }
                break;
            }
        }
    }
    if (!moved) //TODO: gerer les deplacement sur une entité
    {
        // Si il y a pls position disponible, on bouge sur une aléatoirement, sinon on reste sur sa position
        environment = World::getInstance().getEnvironment(_position, 2);
        Point nPos;
        if (World::getInstance().findRandomPositionInEnvironment(environment, 2, ENTITY_TYPE::NONE, nPos))
            move(nPos);
    }
}

bool Hunter::isDead() const
{
    return _lifeState == LIFE_STATE::RED && _stepsBeforeChange <= 0;
}