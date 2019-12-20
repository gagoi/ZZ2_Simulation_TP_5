#include <random>
#include "System.hpp"
#include "Entities/Agent/Harvester.hpp"
#include "Utils/Map.hpp"

constexpr int SYS_W = 20;
constexpr int SYS_H = 20;

std::mt19937 gen(256);
std::uniform_int_distribution<> dis_x(0, SYS_W);
std::uniform_int_distribution<> dis_y(0, SYS_H);

int main()
{
    /*
    System s(SYS_W, SYS_H);

    s.addAgent(new Harvester(Point(dis_x(gen), dis_y(gen)), Point(2, 2)));
    for (int i = 0; i < 20; i++)
    {
        s.update();
        std::cout << s;
    }
    */
   Map m(10, 10);

    m[Point(2, 1)] = 'c';
   std::cout << "m[(2, 1)] = c " << std::endl;
    m[Point(5, 5)] = 'd';
   std::cout << "m[(5, 5)] = d " << std::endl;
    m[Point(0, 0)] = 'e';
   std::cout << "m[(0, 0)] = e " << std::endl;
    m[Point(-1, 0)] = 'f';
   std::cout << "m[(-1, 0)] = f " << std::endl;
    m[Point(12, 2)] = 'g';
   std::cout << "m[(12, 2)] = g " << std::endl;
    m[Point(-14, 6)] = 'h';
   std::cout << "m[(-14, 6)] = h " << std::endl;

   std::cout << m;

    return 0;
}