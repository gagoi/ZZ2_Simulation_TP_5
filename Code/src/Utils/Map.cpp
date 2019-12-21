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