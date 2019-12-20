#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include "Point.hpp"

class Map
{
public:
    Map(int a, int b);
    ~Map();

    int getWidth() const { return _width; }
    int getHeight() const { return _height; }

    char& operator[](Point const & p);
    char const & operator[](Point const & p) const;

    friend std::ostream& operator<<(std::ostream& out, Map const & m);

private:
    int _width;
    int _height;
    std::vector<std::vector<char>> _map;
};

#endif