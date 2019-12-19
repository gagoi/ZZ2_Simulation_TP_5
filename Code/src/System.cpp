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
}

void System::addEntity(Entity* entity)
{
    _entities.push_back(entity);
    _entities[_entities.size() - 1]->draw(_display);
}

char& System::operator[](Point const & p)
{
    return _display[p.x][p.y];
}

std::ostream& operator<<(std::ostream& out, System const & sys)
{
    for (auto &&line : sys._display)
    {
        for (auto &&c : line)
        {
            std::cout << c << ' ';
        }
        std::cout << std::endl;
    }
    return out;
}