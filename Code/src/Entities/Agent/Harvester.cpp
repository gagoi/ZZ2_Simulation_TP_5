#include "Harvester.hpp"


Harvester::Harvester(Point const & p, Point const & basePos, char c) :
    Agent(p, c),
    _basePosition(basePos)
{
}

Harvester::~Harvester()
{
}

void Harvester::move()
{
    
}

void Harvester::update()
{
    switch (_state)
    {
    case STATE::SEARCHING:
        
        break;
    case STATE::BRINGING:
        break;
    }
}