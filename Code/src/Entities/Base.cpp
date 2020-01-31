/**
 * @file Base.cpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier d'implémentation de la classe Base
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Base.hpp"

Base::Base(Point const & p, int limit, char c) :
    Entity(p, c),
    _resources(0),
    _limit(limit),
    _hasToBirth(false)
{
}

Base::~Base()
{
}

bool Base::addResources(int r)
{
    _resources += r;
    if (_resources > _limit)
    {
        _resources -= _limit;
        _hasToBirth = true;
        return true;
    }
    return false;
}

void Base::birth()
{
    if (_hasToBirth)
    {
        std::vector<Entity*> env = World::getInstance().getEnvironment(_position, 1);
        Point pos;
        if (World::getInstance().findRandomPositionInEnvironment(env, 1, ENTITY_TYPE::NONE, pos))
        {
            System::getInstance().addAgent(new Harvester(_position + pos, this));
            _hasToBirth = false;
        }
    }
}