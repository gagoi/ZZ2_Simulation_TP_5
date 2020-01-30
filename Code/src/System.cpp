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
    _addingBuffer.push_back(a);
    World::getInstance().add(a);
}

void System::update()
{
    std::vector<std::vector<Agent*>::iterator> toSuppr;
    // Updates
    for (auto it = _agents.begin(); it != _agents.end(); it++)
    {
        auto ptr = *it;
        if (!ptr->isDead())
            ptr->update();
        else
            toSuppr.push_back(it);
    }

    // Suppression des agents morts pendant cette update
    for (auto itit = toSuppr.begin(); itit != toSuppr.end(); itit++)
    {
        _agents.erase(*itit);
    }

    // Ajout des agents nés dans cette update
    if (_addingBuffer.size() > 0)
    {
        for (auto it = _addingBuffer.begin(); it != _addingBuffer.end(); it++)
            _agents.push_back(*it);
        _addingBuffer.clear();
    }
}

std::ostream& operator<<(std::ostream& out, System const & sys)
{
    out << World::getInstance();
    return out;
}