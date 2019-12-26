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
    for (auto &&h : _harvesters)
        delete h;

    for (auto &&h : _hunters)
        delete h;

    for (auto &&r : _resources)
        delete r;

    for (auto &&b : _bases)
        delete b;
}

void System::addHarvester(Harvester* h)
{
    _harvesters.push_back(h);
    if (std::find(_bases.begin(), _bases.end(), h->getBase()) == _bases.end())
        _bases.push_back(h->getBase());
}

void System::addHunter(Hunter* h)
{
    _hunters.push_back(h);
}

void System::update()
{
    // Updates
    for (auto &&h : _hunters)
        h->update(_harvesters, _map);

    for (auto &&h : _harvesters)
        h->update(_resources, _map);

    for (auto &&b : _bases)
        b->update(_harvesters);
    
    // Clear
    _map.clear();

    // Render
    for (auto &&h : _harvesters)
        h->draw(_map);

    for (auto &&h : _hunters)
        h->draw(_map);

    for (auto &&b : _bases)
        b->draw(_map);

    std::cout << "------------------------------------------------------" << std::endl;
}

std::ostream& operator<<(std::ostream& out, System const & sys)
{
    out << sys._map;
    return out;
}