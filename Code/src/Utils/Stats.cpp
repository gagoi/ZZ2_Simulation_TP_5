#include "Stats.hpp"

Stats::Stats(const char * filename):
    _log(std::ofstream(filename))
{
    if (!_log)
        throw std::invalid_argument("Impossible d'ouvrir le fichier.");
}

template <typename T>
Stats& operator<<(Stats & stats, T t)
{
    stats._log << t << std::endl;
    return stats;
}