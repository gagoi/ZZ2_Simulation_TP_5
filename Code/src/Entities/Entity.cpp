/**
 * @file Entity.cpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier d'implémentation de la classe Entity
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Entity.hpp"

Entity::Entity(Point const & p, char c) :
    _world(World::getInstance()),
    _position(p),
    _shellChar(c)
{
}

Entity::~Entity()
{
}

std::ostream& operator<<(std::ostream& out, Entity const & e)
{
    out << e.getChar();
    return out;
}