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
    _life(100)
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
            Point d = World::getInstance().getDistances(getPosition(), e->getPosition());
            if (d.x <= 2 && d.y <= 2) // Si il y a un Harvester dans un voisinage de Moore d'ordre 2
            {
                // On se déplace et on mange le récolteur
                Point pos(e->getPosition());
                notifyDelete(e);
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
        }
        if (!moved) //TODO: gerer les deplacement sur une entité
        {
            // Si il y a pls position disponible, on bouge sur une aléatoirement, sinon on reste sur sa position
            Point nPos;
            if (World::getInstance().findRandomPositionInEnvironment(environment, 2, ENTITY_TYPE::NONE, nPos))
                move(nPos);
        }
    }
}