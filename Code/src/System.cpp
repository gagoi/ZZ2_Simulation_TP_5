#include "System.hpp"

System::System(int w, int h) :
    _width(w),
    _height(h),
    _map(_width, _height)
{
}

System::~System()
{
    for (auto &&agent : _agents)
    {
        delete agent;
    }    
}

void System::addAgent(Agent* agent)
{
    _agents.push_back(agent);
}

void System::update()
{
    // Updates
    for (auto &&agent : _agents)
    {
        agent->update();
    }
    
    // Clear
    _map.clear();

    // Render
    for (auto &&agent : _agents)
    {
        agent->draw(_map);
    }

    std::cout << "------------------------------------------------------" << std::endl;
}

std::ostream& operator<<(std::ostream& out, System const & sys)
{
    out << sys._map;
    return out;
}