#include "Hunter.hpp"

std::mt19937 Hunter::gen(253);
std::uniform_int_distribution<> Hunter::move_distribution(-2, 2);

Hunter::Hunter(Point const & p, char c) :
    Entity(p, c),
    _state(STATE::SEARCH)
{
}

Hunter::~Hunter()
{
}

void Hunter::move()
{
    switch (_state)
    {
    case STATE::SEARCH:
        _position = Point(move_distribution(gen), move_distribution(gen));
        break;
    case STATE::AIM:
        // TODO: déplacement le plus rapide vers _food
        break;
    }
}

void Hunter::update(std::vector<Harvester*> & harvesters, Map const & map)
{
    switch (_state)
    {
    case STATE::SEARCH:
        for (auto &&har : harvesters)
        {
            if (map.pointInNeighborhood(getPosition(), har->getPosition(), 3))
            {
                _state = STATE::AIM;
                _food = har->getPosition();
            }
        }
        break;
    case STATE::AIM:
        for (auto it = harvesters.begin(); it != harvesters.end(); it++)
        {
            if (getPosition() == (*it)->getPosition())
            {
                _state = STATE::SEARCH;
                delete *it;
                harvesters.erase(it);
                // TODO: Système de barre de vie
            }
        }
        
        break;
    }
    move();
}