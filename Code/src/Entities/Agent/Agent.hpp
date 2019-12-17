#ifndef AGENT_HPP
#define AGENT_HPP

#include "Entity.hpp"

class Agent : public Entity
{
public:
    Agent(Point const & p, char c = 'A');
    ~Agent();

    virtual void move() = 0;
    virtual void update() = 0;
};

#endif