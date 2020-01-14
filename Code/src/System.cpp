/**
 * @file System.cpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier d'implémentation de la classe System
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "System.hpp"

System::System()
{
}

System::~System()
{
    for (auto &&a : _agents)
        delete a;
}

void System::addAgent(Agent* a)
{
    _agents.push_back(a);
}

void System::update()
{
    // Updates
    for (auto it = _agents.begin(); it != _agents.end(); it++)
    {
        if (World::getInstance()[(*it)->getPosition()] == nullptr)
            _agents.erase(it);
        else
            (*it)->update();
    }

    std::cout << "------------------------------------------------------" << std::endl;
}

std::ostream& operator<<(std::ostream& out, System const & sys)
{
    out << World::getInstance();
    return out;
}