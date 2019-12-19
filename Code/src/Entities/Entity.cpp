#include "Entity.hpp"

Entity::Entity(Point const & p, char c) :
    _position(p),
    _shellChar(c)
{
}

Entity::~Entity()
{
}

void Entity::draw(std::vector<std::vector<char>>& frame)
{
    frame[_position.x][_position.y] = _shellChar;
}