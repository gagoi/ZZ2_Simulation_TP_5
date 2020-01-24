#include <random>
#include "System.hpp"
#include "Entities/Agent/Harvester.hpp"
#include "Entities/Agent/Hunter.hpp"
#include "Utils/World.hpp"

extern std::mt19937 gen;
std::uniform_int_distribution<> dis_x(0, World::WORLD_WIDTH);
std::uniform_int_distribution<> dis_y(0, World::WORLD_HEIGHT);

void testHunterMove();

int main()
{
    /*System& s = System::getInstance();
    World& w = World::getInstance();

    Base* base = new Base(Point(5, 5), 5);
    Hunter* hunter = new Hunter(Point(0, 0));

    w.add(base);
    s.addAgent(hunter);
    for (int i = 0; i < 15; i++)    
        s.addAgent(new Harvester(Point(dis_x(gen), dis_y(gen)), base));

    std::cout << s;
    for (int i = 0; i < 20; i++)
    {
        std::cout << "------------------------------------------------------" << std::endl;
        s.update();
        std::cout << s;
    }*/
    testHunterMove();
    
    return 0;
}

void testHunterMove()
{
    System& s = System::getInstance();
    World& w = World::getInstance();

    for (int i = 0; i < World::WORLD_WIDTH; i++)
    {
        for (int j = 0; j < World::WORLD_HEIGHT; j++)
        {
            if (i == 10 && j == 10)
                s.addAgent(new Hunter(Point(i, j)));
            else if (i == 8 && j == 10)
            {}
            else
                w.add(new Base(Point(i, j), 5));
        }
    }

    std::cout << s;
    for (int i = 0; i < 2; i++)
    {
        std::cout << "------------------------------------------------------" << std::endl;
        s.update();
        std::cout << s;
    }
}