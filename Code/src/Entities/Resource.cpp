/**
 * @file Resource.cpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
 * @brief Fichier d'implémentation de la classe Resource
 * @version 0.1
 * @date 2020-02-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "Resource.hpp"

Resource::Resource(Point const & p, char c) :
    Entity(p, c)
{
}

Resource::~Resource()
{
}
