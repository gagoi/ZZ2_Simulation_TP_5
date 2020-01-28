/**
 * @file Agent.cpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier d'implémentation de la classe Agent
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Agent.hpp"

Agent::Agent(Point const & p, char c) :
    Entity(p, c)
{
    addObserver(&World::getInstance());
    addObserver(&System::getInstance());
}

Agent::~Agent()
{
}

void Agent::setPosition(Entity* e, Point const & p)
{
    notifyMove(e, p);
    _position = p;
}

void Agent::move(Entity* e, Point const & p)
{
    notifyMove(e, _position + p);
    _position += p;
}