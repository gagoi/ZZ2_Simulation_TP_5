#ifndef HARVESTER_HPP
#define HARVESTER_HPP

#include "Agent.hpp"

class Harvester : public Agent
{
public:
    Harvester(Point const & p, Point const & basePos, char c = 'H');
    ~Harvester();

    void move() override;
    void update() override;

private:
    enum class STATE
    {
        SEARCHING,
        BRINGING
    };

    Point _basePosition;
    STATE _state;
};

#endif