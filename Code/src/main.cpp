/*
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

    Base* base = new Base(Point(5, 5), 5);

    for (int i = 0; i < 15; i++)    
        s.addHarvester(new Harvester(Point(dis_x(gen), dis_y(gen)), base));
    s.addHunter(new Hunter(Point(0, 0)));
    for (int i = 0; i < 20; i++)
    {
        s.update();
        std::cout << s;
    }
    
    return 0;
}

void testGetDirection()
{
    Map m(10, 10);

    Point c(6, 6);
    Point p(6, 0);

    m[c] = 'B';
    m[p] = 'p';

    std::cout << m;
    while (c != p)
    {
        p += m.getDirection(p, c);
        m.clear();
        m[c] = 'B';
        m[p] = 'p';
        std::cout << m;
    }
}*/
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}