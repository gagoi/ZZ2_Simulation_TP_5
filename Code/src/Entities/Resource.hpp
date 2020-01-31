#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include "Entity.hpp"
#include "../colors.hpp"

class Resource : public Entity
{
public:
    Resource(Point const & p, char c = 'R');
    ~Resource();

    std::string getColor() const override { return COLOR_BLUE; }

    virtual ENTITY_TYPE getType() const { return ENTITY_TYPE::RESOURCE; }

private:
    
};

#endif