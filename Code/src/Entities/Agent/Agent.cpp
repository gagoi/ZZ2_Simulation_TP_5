/**
 * @file Agent.cpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
 * @brief Fichier d'implémentation de la classe Agent
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Agent.hpp"

Agent::Agent(Point const & p, char c) :
    Entity(p, c),
    _dead(false)
{
    addObserver(&World::getInstance());
}

Agent::~Agent()
{
}

void Agent::setPosition(Point const & p)
{
    notifyMove(this, p);
    _position = p;
}

void Agent::move(Point const & p)
{
    notifyMove(this, _position + p);
    _position += p;
}