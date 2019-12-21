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
    System s(SYS_W, SYS_H);

    for (int i = 0; i < 15; i++)    
        s.addAgent(new Harvester(Point(dis_x(gen), dis_y(gen)), Point(2, 2)));
    for (int i = 0; i < 20; i++)
    {
        s.update();
        std::cout << s;
    }

    return 0;
}