#include <random>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include "System.hpp"
#include "Entities/Agent/Harvester.hpp"
#include "Entities/Agent/Hunter.hpp"
#include "Utils/World.hpp"

enum DRAW_MODE {
    MODE_LOG, MODE_DRAW, MODE_LOG_FILE, MODE_LOG_FILE_AND_DRAW
};

extern std::mt19937 gen;
std::uniform_int_distribution<> dis_x(0, World::WORLD_WIDTH);
std::uniform_int_distribution<> dis_y(0, World::WORLD_HEIGHT);

void testHunterMove();
void testHarvesterMove();

DRAW_MODE mode = MODE_LOG;
std::fstream log_file;


void getDrawMode(int, char **);
void draw(System const &);

int main(int argc, char ** argv)
{
    getDrawMode(argc, argv);

    if (mode == MODE_LOG_FILE || mode == MODE_LOG_FILE_AND_DRAW)
        log_file = std::fstream("output.log");

    System& s = System::getInstance();
    World& w = World::getInstance();

    Base* base = new Base(Point(5, 5), 5);
    Hunter* hunter = new Hunter(Point(0, 0));

    w.add(base);
    s.addAgent(hunter);
    for (int i = 0; i < 15; i++)    
        s.addAgent(new Harvester(Point(dis_x(gen), dis_y(gen)), base));

    for (int i = 0; i < 20; i++)
    {
        s.update();
        draw(s);
    }
    
    if (mode == MODE_LOG_FILE || mode == MODE_LOG_FILE_AND_DRAW)
        log_file.close();

    return 0;
}

void draw(System const & s)
{
    switch (mode)
    {
    case MODE_DRAW:
        #if defined(_WIN32)
        system("CLS");
        #else
        system("clear");
        #endif 
        std::cout << s;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        break;
    case MODE_LOG:
        std::cout << s;
        break;
    case MODE_LOG_FILE:
        log_file << s;
        break;
    case MODE_LOG_FILE_AND_DRAW:
        log_file << s;
        #if defined(_WIN32)
        system("CLS");
        #else
        system("clear");
        #endif
        std::cout << s;
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