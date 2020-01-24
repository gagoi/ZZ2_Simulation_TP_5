#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include "../Entities/Entity.hpp"
#include "../Utils/Point.hpp"

class IObserver
{
public:
    virtual void updateMove(Entity* e, Point const & newPosition) = 0;
    virtual void updateDelete(Entity* e) = 0;
};

#endif