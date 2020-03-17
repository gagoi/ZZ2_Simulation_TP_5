/**
 * @file Harvester.cpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
 * @brief Fichier d'implémentation de la classe Harvester
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Harvester.hpp"

Harvester::Harvester(Point const & p, Base* base, char c) :
    Agent(p, c),
    _base(base),
    _state(STATE::SEARCH)
{
}

Harvester::~Harvester()
{
}

void Harvester::moveHarvester()
{
    std::vector<Entity*> env;
    Point nPos;
    switch (_state)
    {
    case STATE::SEARCH:
        env = World::getInstance().getEnvironment(_position, 1);
        if (World::getInstance().findRandomPositionInEnvironment(env, 1, ENTITY_TYPE::NONE, nPos))
            move(nPos);
        break;
    case STATE::BRING:
        nPos = World::getInstance().getDirection(_position, _base->getPosition());
        if (World::getInstance()[_position + nPos] == nullptr)
            move(nPos);
        break;
    }
}

void Harvester::update()
{
    std::vector<Entity*> environment;
    switch (_state)
    {
    case STATE::SEARCH:
        environment = World::getInstance().getEnvironment(_position, 1); // On récupère l'environnement du Harvester (voisinage de Moore d'ordre 1 autour de la position de l'agent)
        for (auto &&e : environment)
        {
            if (e != nullptr && e->getType() == ENTITY_TYPE::RESOURCE)
            {
                _state = STATE::BRING;
                notifyKill(e);
                break;
            }
        }
        break;
    case STATE::BRING:
        Point p = World::getInstance().getDistances(getPosition(), _base->getPosition());
        if (p.x <= 1 && p.y <= 1)
        {
            _state = STATE::SEARCH;
            if (_base->addResources(1))
            {
                _base->birth();
            }
        }
        break;
    }
    moveHarvester();
}