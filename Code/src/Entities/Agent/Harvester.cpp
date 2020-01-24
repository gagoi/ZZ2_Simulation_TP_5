/**
 * @file Harvester.cpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier d'implémentation de la classe Harvester
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Harvester.hpp"

std::mt19937 Harvester::gen(253);
std::uniform_int_distribution<> Harvester::move_distribution(-1, 1);

Harvester::Harvester(Point const & p, Base* base, char c) :
    Agent(p, c),
    _base(base),
    _state(STATE::SEARCH)
{
}

Harvester::~Harvester()
{
}

void Harvester::randomMove()
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
        if (World::getInstance()[_position + nPos] != nullptr)
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
                World::getInstance()[e->getPosition()] = nullptr;
                delete e;
                break;
            }
        }
        break;
    case STATE::BRING:
        if (_base->getPosition() == _position)
        {
            _state = STATE::SEARCH;
            if (_base->addResources(1))
            {
                _base->birth();
            }
        }
        break;
    }
    randomMove();
}

Base* const Harvester::getBase() const
{
    return _base;
}