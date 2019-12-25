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

    void update(std::vector<Harvester*> & harvesters, Map const & map);

private:    
    static std::mt19937 gen;
    static std::uniform_int_distribution<> move_distribution;
};

#endif