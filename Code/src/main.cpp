/**
 * @file main.cpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
 * @brief Fichier contenant le main, qui lance la simulation
 * @version 0.1
 * @date 2020-02-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <random>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include "System.hpp"
#include "Entities/Agent/Harvester.hpp"
#include "Entities/Agent/Hunter.hpp"
#include "Entities/Resource.hpp"
#include "Utils/World.hpp"

enum DRAW_MODE {
    MODE_LOG, MODE_DRAW, MODE_LOG_FILE, MODE_LOG_FILE_AND_DRAW
};

std::uniform_int_distribution<> dis_x(0, World::WORLD_WIDTH);
std::uniform_int_distribution<> dis_y(0, World::WORLD_HEIGHT);

DRAW_MODE mode = MODE_LOG;
std::ofstream log_file;


void getDrawMode(int, char **);
void draw(World const &);

int main(int argc, char ** argv)
{
    getDrawMode(argc, argv);

    if (mode == MODE_LOG_FILE || mode == MODE_LOG_FILE_AND_DRAW)
        log_file = std::ofstream("output.log");
        
    System& s = System::getInstance();
    World& w = World::getInstance();

    Hunter* hunter = new Hunter(Point(0, 0));
    Hunter* hunter2 = new Hunter(Point(39, 39));
    s.addAgent(hunter);
    s.addAgent(hunter2);

    Base* base1 = new Base(Point(dis_x(World::gen), dis_y(World::gen)), 0);
    w.add(base1);
    for (int i = 0; i < 4000; i++)    
        s.addAgent(new Harvester(Point(dis_x(World::gen), dis_y(World::gen)), base1));
/*
    Base* base2 = new Base(Point(dis_x(World::gen), dis_y(World::gen)), 0);
    w.add(base2);
    for (int i = 0; i < 30; i++)    
        s.addAgent(new Harvester(Point(dis_x(World::gen), dis_y(World::gen)), base2));

    Base* base3 = new Base(Point(dis_x(World::gen), dis_y(World::gen)), 0);
    w.add(base3);
    for (int i = 0; i < 30; i++)    
        s.addAgent(new Harvester(Point(dis_x(World::gen), dis_y(World::gen)), base3));
*/
    for (int i = 0; i < 8000; i++)    
        w.add(new Resource(Point(dis_x(World::gen), dis_y(World::gen))));

    for (int i = 0; i < 500; i++)
    {
        s.update();
        //std::cout << "UPDATE " << i << std::endl;
        draw(w);
    }
    
    if (mode == MODE_LOG_FILE || mode == MODE_LOG_FILE_AND_DRAW)
        log_file.close();

    System::deleteInstance();
    World::deleteInstance();

    return 0;
}

void draw(World const & w)
{
    switch (mode)
    {
    case MODE_DRAW:
        #if defined(_WIN32)
        execl
        system("CLS");
        #else
        system("clear");
        #endif 
        std::cout << w;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        break;
    case MODE_LOG:
        std::cout << w;
        break;
    case MODE_LOG_FILE:
        log_file << w;
        break;
    case MODE_LOG_FILE_AND_DRAW:
        log_file << w;
        #if defined(_WIN32)
        system("CLS");
        #else
        system("clear");
        #endif
        std::cout << w;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        break;
    }
}

void getDrawMode(int argc, char ** argv) 
{
    if (argc != 2)
        mode = MODE_LOG;
    else 
    {
        std::string arg = std::string(argv[1]);
        if (arg == "--log")
            mode = MODE_LOG;
        else if (arg == "--draw")
        {
            mode = MODE_DRAW;
        }
        else if (arg == "--log-file")
            mode = MODE_LOG_FILE;
        else if (arg == "--log-draw")
            mode = MODE_LOG_FILE_AND_DRAW;
        else
        {
            std::cout << "Use only with : <--draw | --log | --log-file | --log-draw>" << std::endl;
            exit(1);
        }
    }
}