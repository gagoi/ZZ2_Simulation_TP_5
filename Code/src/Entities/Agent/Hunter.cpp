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
    std::vector<Entity*&> environment = World::getInstance().getEnvironment(_position, 3);
    bool moved = false;

    for (auto &&e : environment)
    {
        if (e != nullptr && e->getType() == ENTITY_TYPE::HARVESTER)
        {
            Point d = World::getInstance().getDistances(getPosition(), e->getPosition());
            if (d.x <= 2 && d.y <= 2) // Si il y a un Harvester dans un voisinage de Moore d'ordre 2
            {
                // On se déplace et on mange le récolteur
                _position = e->getPosition();
                delete e;
                e = nullptr;
                // TODO: Système de barre de vie
                moved = true;
            }
        }
        else
        {
            // On se déplace vers lui
            _position += World::getInstance().getDirection(_position, e->getPosition()) * 2;
            moved = true;
        }
        if (!moved)
            _position += Point(move_distribution(gen), move_distribution(gen));
    }
}