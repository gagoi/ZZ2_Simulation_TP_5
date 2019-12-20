#include "System.hpp"

System::System(int w, int h) :
    _width(w),
    _height(h)
{
    for (int i = 0; i < _width; i++)
    {
        _display.push_back(std::vector<char>());
        for (int j = 0; j < _height; j++)
        {
            _display[i].push_back('.');
        }
    }
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
    for (auto &&line : _display)
        for (auto &&c : line)
            c = '.';

    // Render
    for (auto &&agent : _agents)
    {
        agent->draw(_display);
    }

    std::cout << "------------------------------------------------------" << std::endl;
}

char& System::operator[](Point const & p)
{
    return _display[p.x][p.y];
}

std::ostream& operator<<(std::ostream& out, System const & sys)
{
    int i = 0;
    std::cout << "   ";
    for (int j = 0; j < sys._width; j++)
        std::cout << std::setw(3) << j;
    
    std::cout << std::endl;
    for (auto &&line : sys._display)
    {
        std::cout << std::setw(2) << i++ << " ";
        for (auto &&c : line)
        {
            std::cout << std::setw(3) << c;
        }
        std::cout << std::endl;
    }
    return out;
}