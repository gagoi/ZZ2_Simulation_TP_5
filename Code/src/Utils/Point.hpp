#ifndef POINT_HPP
#define POINT_HPP

struct Point
{
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
    bool operator==(Point const & p) { return x == p.x && y == p.y; }
    bool operator!=(Point const & p) { return !(*this != p); }
};


#endif