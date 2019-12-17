#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../Utils/Point.hpp"

class Entity
{
public:
    Entity(Point const & p, char c = 'E');
    virtual ~Entity();

public:
    Point _position;
    char _shellChar;
};

#endif