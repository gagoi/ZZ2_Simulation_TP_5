#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <set>
#include "IObserver.hpp"
#include "../Entities/Entity.hpp"

class Observable
{
public:
    void addObserver(IObserver* o)
    {
        _listObserver.insert(o);
    }

    void notifyMove(Entity * e, Point const & newPosition)
    {
        for (auto it = _listObserver.begin(); it != _listObserver.end(); it++)
        {
            (*it)->updateMove(e, newPosition);
        }
    }

    void notifyDelete(Entity * e)
    {
        for (auto it = _listObserver.begin(); it != _listObserver.end(); it++)
        {
            (*it)->updateDelete(e);
        }
    }

private:
    std::set<IObserver*> _listObserver;
};

#endif