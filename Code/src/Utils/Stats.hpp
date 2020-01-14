#include <fstream>
#include <exception>
#include <iostream>

class Stats
{
private:
    std::ofstream _log;
public:
    Stats(const char * filename);
    template <typename T>
    friend Stats& operator<<(Stats &, T);
};

template <typename T>
Stats& operator<<(Stats &, T);