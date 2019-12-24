#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include "Entity.hpp"

class Resource : public Entity
{
public:
    Resource(Point const & p, char c = 'R');
    ~Resource();

private:
    
};

#endif