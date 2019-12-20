#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include "../Utils/Point.hpp"

class Entity
{
public:
    Entity(Point const & p, char c = 'E');
    virtual ~Entity();

    Point const & getPosition() const { return _position; }
    Point& getPosition() { return _position; }
    char getChar() const { return _shellChar; }

    void draw(std::vector<std::vector<char>>& frame);

protected:
    Point _position;
    char _shellChar;
};

#endif