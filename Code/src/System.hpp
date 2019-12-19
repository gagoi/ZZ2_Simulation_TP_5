#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <iostream>
#include "Entities/Entity.hpp"
#include "Entities/Agent/Agent.hpp"

class System
{
public:
    System(int w, int h);
    ~System();

    void addEntity(Entity* entity);

    friend std::ostream& operator<<(std::ostream& out, System const & sys);
    char& operator[](Point const & p);

private:
    std::vector<std::vector<char>> _display;
    std::vector<Entity*> _entities;
    int _width;
    int _height;
};

#endif