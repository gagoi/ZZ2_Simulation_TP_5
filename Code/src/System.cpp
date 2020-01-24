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

System* System::instance = nullptr;

System& System::getInstance()
{
    if (instance == nullptr)
        instance = new System();
    return *instance;
}

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
    World::getInstance().add(a);
}

void System::update()
{
    // Updates
    for (auto it = _agents.begin(); it != _agents.end(); it++)
    {
        if (*it == nullptr)
        {
            std::cout << "ERASE: " << *it << std::endl;
            _agents.erase(it);
        }
        else
        {
            std::cout << "UPDATE: " << *it << std::endl;
            (*it)->update();
        }
    }

    std::cout << "------------------------------------------------------" << std::endl;
}

void System::updateDelete(Entity * e)
{
    auto f = std::find(_agents.begin(), _agents.end(), e);
    if (f != _agents.end())
        _agents.erase(f);
}

std::ostream& operator<<(std::ostream& out, System const & sys)
{
    out << World::getInstance();
    return out;
}