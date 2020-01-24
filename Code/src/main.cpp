#include <random>
#include "System.hpp"
#include "Entities/Agent/Harvester.hpp"
#include "Entities/Agent/Hunter.hpp"
#include "Utils/World.hpp"

extern std::mt19937 gen;
std::uniform_int_distribution<> dis_x(0, World::WORLD_WIDTH);
std::uniform_int_distribution<> dis_y(0, World::WORLD_HEIGHT);

int main()
{
    System& s = System::getInstance();

    Base* base = new Base(Point(5, 5), 5);
    Hunter* hunter = new Hunter(Point(0, 0));

    s.addAgent(hunter);
    for (int i = 0; i < 15; i++)    
        s.addAgent(new Harvester(Point(dis_x(gen), dis_y(gen)), base));

    std::cout << s;

    auto env = World::getInstance().getEnvironment(hunter->getPosition(), 3);
    std::cout << "ENV:" << std::endl;
    for (auto &&e : env)
    {
        if (e)
            std::cout << e << ' ';
        else
            std::cout << "null ";
    }
    std::cout << std::endl;
    

    for (int i = 0; i < 20; i++)
    {
        s.update();
        std::cout << s;
    }
    
    return 0;
}