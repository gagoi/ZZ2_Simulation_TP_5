#ifndef HUNTER_HPP
#define HUNTER_HPP

#include <random>
#include "../Entity.hpp"
#include "Harvester.hpp"

class Hunter : public Entity
{
public:
    Hunter(Point const & p, char c = 'M');
    ~Hunter();

    void move();
    void update(std::vector<Harvester*> & harvesters, Map const & map);

private:
    enum class STATE
    {
        SEARCH,
        AIM
    };

    STATE _state;
    Point _food;
    
    static std::mt19937 gen;
    static std::uniform_int_distribution<> move_distribution;
};

#endif