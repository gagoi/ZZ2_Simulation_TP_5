#include "Entity.hpp"

Entity::Entity(Point const & p, char c) :
    _position(p),
    _shellChar(c)
{
}

Entity::~Entity()
{
}

void Entity::draw(Map & map)
{
    map[_position] = _shellChar;
}