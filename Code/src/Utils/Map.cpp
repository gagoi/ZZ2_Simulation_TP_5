/**
 * @file Map.cpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier d'implémentation de la classe Map
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Map.hpp"

Map::Map(int a, int b) :
    _width(a),
    _height(b)
{
    for (int i = 0; i < _width; i++)
    {
        _map.push_back(std::vector<char>());
        for (int j = 0; j < _height; j++)
        {
            _map[i].push_back('.');
        }
    }
}

Map::~Map()
{
}

char& Map::operator[](Point const & p)
{
    int x = p.x < 0 ? _width - (-p.x % _width) : p.x % _width;
    int y = p.y < 0 ? _height - (-p.y % _height) : p.y % _height;

    return _map[x][y];
}

char const & Map::operator[](Point const & p) const
{
    int x = p.x < 0 ? _width - (-p.x % _width) : p.x % _width;
    int y = p.y < 0 ? _height - (-p.y % _height) : p.y % _height;

    return _map[x][y];
}

char& Map::operator[](Point & p)
{
    p.x = p.x < 0 ? _width - (-p.x % _width) : p.x % _width;
    p.y = p.y < 0 ? _height - (-p.y % _height) : p.y % _height;

    return _map[p.x][p.y];
}

char const & Map::operator[](Point & p) const
{
    p.x = p.x < 0 ? _width - (-p.x % _width) : p.x % _width;
    p.y = p.y < 0 ? _height - (-p.y % _height) : p.y % _height;

    return _map[p.x][p.y];
}

void Map::clear()
{
    for (auto &&line : _map)
    {
        for (auto &&c : line)
        {
            c = '.';
        }
    }
}

Point Map::getDistances(Point const & p1, Point const & p2) const
{
    int dx = std::min(abs(p1.x - p2.x), (p2.x > p1.x ? (abs(_width - p2.x) + p1.x) : (abs(_width - p1.x) + p2.x)));
    int dy = std::min(abs(p1.y - p2.y), (p2.y > p1.y ? (abs(_height - p2.y) + p1.y) : (abs(_height - p1.y) + p2.y)));
    return Point(dx, dy);
}

Point Map::getDirection(Point const & point, Point const & dest) const
{
    int dx_1 = abs(point.x - dest.x);
    int dy_1 = abs(point.y - dest.y);
    int dx_2 = dest.x > point.x ? (_width - dest.x + point.x) : (_width - point.x + dest.x);
    int dy_2 = dest.y > point.y ? (_height - dest.y + point.y) : (_height - point.y + dest.y);

    Point dir(0, 0);
    if ((dx_1 > dx_2 ? dx_2 : dx_1) == (dy_1 > dy_2 ? dy_2 : dy_1))
    {
        dir.x = point.x > dest.x ? -1 : (point.x < dest.x ? 1 : 0);
        dir.y = point.y > dest.y ? -1 : (point.y < dest.y ? 1 : 0);
    }
    else if ((dx_1 > dx_2 ? dx_2 : dx_1) > (dy_1 > dy_2 ? dy_2 : dy_1))
    {
        dir.x = point.x > dest.x ? -1 : (point.x < dest.x ? 1 : 0);
    }
    else
    {
        dir.y = point.y > dest.y ? -1 : (point.y < dest.y ? 1 : 0);
    }

    if (dx_2 < dx_1)
        dir.x *= -1;
    if (dy_2 < dy_1)
        dir.y *= -1;

    return dir;
}

std::ostream& operator<<(std::ostream& out, Map const & m)
{
    int i = 0;
    std::cout << "   ";
    for (int j = 0; j < m._width; j++)
        std::cout << std::setw(3) << j;
    
    std::cout << std::endl;
    for (auto &&line : m._map)
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