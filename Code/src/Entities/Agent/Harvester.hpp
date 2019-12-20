#ifndef HARVESTER_HPP
#define HARVESTER_HPP

#include <random>
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

    static std::mt19937 gen;
    static std::uniform_int_distribution<> move_distribution;
};

#endif