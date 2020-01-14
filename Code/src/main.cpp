#include <random>
#include "System.hpp"
#include "Entities/Agent/Harvester.hpp"
#include "Utils/World.hpp"

std::mt19937 gen(256);
std::uniform_int_distribution<> dis_x(0, World::WORLD_WIDTH);
std::uniform_int_distribution<> dis_y(0, World::WORLD_HEIGHT);

int main()
{
    System s;

    Base* base = new Base(Point(5, 5), 5);

    s.addAgent(new Hunter(Point(0, 0)));
    for (int i = 0; i < 15; i++)    
        s.addAgent(new Harvester(Point(dis_x(gen), dis_y(gen)), base));

    

    for (int i = 0; i < 20; i++)
    {
        s.update();
        std::cout << s;
    }
    
    return 0;
}