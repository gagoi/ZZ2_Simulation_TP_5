#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include "Utils/Map.hpp"
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

private:
    std::vector<Agent*> _agents;
    int _width;
    int _height;
    Map _map;
};

#endif