/**
 * @file System.cpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
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

void System::deleteInstance()
{
    delete instance;
}

System::System()
{
}

System::~System()
{
}

void System::addAgent(Agent* a)
{
    _addingBuffer.push_back(a);
    World::getInstance().add(a);
}

void System::update()
{
    // Updates
    std::shuffle(_agents.begin(), _agents.end(), World::gen);
    for (auto it = _agents.begin(); it != _agents.end(); it++)
    {
        auto ptr = *it;
        if (!ptr->isDead())
            ptr->update();
    }

    // Suppression des agents morts pendant cette update
    _agents.erase(std::remove_if(_agents.begin(), _agents.end(), [](Agent * a)
    {
        bool suppr = false;
        if (a->isDead())
        {
            suppr = true;
            delete a;
        }
        return suppr;
    }), _agents.end());

    // Ajout des agents nés dans cette update
    if (_addingBuffer.size() > 0)
    {
        for (auto it = _addingBuffer.begin(); it != _addingBuffer.end(); it++)
            _agents.push_back(*it);
        _addingBuffer.clear();
    }
}