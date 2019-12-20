#include "Harvester.hpp"

std::mt19937 Harvester::gen(253);
std::uniform_int_distribution<> Harvester::move_distribution(-1, 1);

Harvester::Harvester(Point const & p, Point const & basePos, char c) :
    Agent(p, c),
    _basePosition(basePos),
    _state(STATE::SEARCHING)
{
}

Harvester::~Harvester()
{
}

void Harvester::move()
{
    switch (_state)
    {
    case STATE::SEARCHING:
        _position += Point(move_distribution(gen), move_distribution(gen));
        break;
    case STATE::BRINGING:
        break;
    }
}

void Harvester::update()
{
    move();
    switch (_state)
    {
    case STATE::SEARCHING:
        
        break;
    case STATE::BRINGING:
        break;
    }
}