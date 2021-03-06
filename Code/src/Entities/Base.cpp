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
    _nextBirths(0)
{
}

Base::~Base()
{
}

void Base::addResources(int r)
{
    _resources += r;
    if (_resources > _limit)
    {
        _resources -= _limit;
        _nextBirths++;
    }
}

void Base::update(std::vector<Harvester*> & harvesters)
{
    for (; _nextBirths > 0; _nextBirths--)
    {
        harvesters.push_back(new Harvester(getPosition(), this));
    }
}