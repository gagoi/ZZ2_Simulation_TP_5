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
    Entity(p, c),
    _base(base),
    _state(STATE::SEARCH)
{
}

Harvester::~Harvester()
{
}

void Harvester::move(Map const & map)
{
    switch (_state)
    {
    case STATE::SEARCH:
        _position += Point(move_distribution(gen), move_distribution(gen));
        break;
    case STATE::BRING:
        _position += map.getDirection(_position, _base->getPosition());
        break;
    }
}

void Harvester::update(std::vector<Resource*> & resources, Map const & map)
{
    switch (_state)
    {
    case STATE::SEARCH:
        for (std::vector<Resource*>::iterator it = resources.begin(); it != resources.end(); it++)
        {
            Point d = map.getDistances(getPosition(), (*it)->getPosition());
            if (d.x <= 1 && d.y <= 1)
            {
                _state = STATE::BRING;
                delete *it;
                resources.erase(it);
                break;
            }
        }
        break;
    case STATE::BRING:
        if (_base->getPosition() == _position)
        {
            _state = STATE::SEARCH;
            _base->addResources(1);
        }
        break;
    }
    move(map);
}

Base* const Harvester::getBase() const
{
    return _base;
}