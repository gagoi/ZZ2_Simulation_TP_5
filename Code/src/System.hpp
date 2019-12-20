#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include "Entities/Entity.hpp"
#include "Entities/Agent/Agent.hpp"

class System
{
public:
    System(int w, int h);
    ~System();

    void addAgent(Agent* agent);
    void update();

    friend std::ostream& operator<<(std::ostream& out, System const & sys);
    char& operator[](Point const & p);

private:
    std::vector<std::vector<char>> _display;
    std::vector<Agent*> _agents;
    int _width;
    int _height;
};

#endif