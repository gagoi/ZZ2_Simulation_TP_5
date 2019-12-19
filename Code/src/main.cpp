#include "System.hpp"
#include "Entities/Agent/Harvester.hpp"

int main()
{
    System s(20, 20);

    std::cout << s;

    s.addEntity(new Harvester(Point(10, 10), Point(2, 2)));
    
    std::cout << s;

    return 0;
}