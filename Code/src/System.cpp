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

System::System(int w, int h) :
    _map(w, h)
{
}

System::~System()
{
    for (auto &&agent : _agents)
    {
        delete agent;
    }    
}

void System::addAgent(Agent* agent)
{
    _agents.push_back(agent);
}

void System::update()
{
    // Updates
    for (auto &&agent : _agents)
    {
        agent->update();
    }
    
    // Clear
    _map.clear();

    // Render
    for (auto &&agent : _agents)
    {
        agent->draw(_map);
    }

    std::cout << "------------------------------------------------------" << std::endl;
}

std::ostream& operator<<(std::ostream& out, System const & sys)
{
    out << sys._map;
    return out;
}