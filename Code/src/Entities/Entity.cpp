#include "Entity.hpp"

Entity::Entity(Point const & p, char c) :
    _position(p),
    _shellChar(c)
{
}

Entity::~Entity()
{
}
