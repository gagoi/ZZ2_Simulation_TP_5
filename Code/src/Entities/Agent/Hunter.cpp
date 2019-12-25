#include "Hunter.hpp"

std::mt19937 Hunter::gen(253);
std::uniform_int_distribution<> Hunter::move_distribution(-2, 2);

Hunter::Hunter(Point const & p, char c) :
    Entity(p, c)
{
}

Hunter::~Hunter()
{
}

void Hunter::update(std::vector<Harvester*> & harvesters, Map const & map)
{
    bool moved = false;
    for (auto it = harvesters.begin(); it != harvesters.end() && !moved; it++)
    {
        Point d = map.getDistances(getPosition(), (*it)->getPosition());
        if (d.x <= 2 && d.y <= 2) // Si il y a un Harvester dans un voisinage de Moore d'ordre 2
        {
            // On se déplace et on mange le récolteur
            _position = (*it)->getPosition();
            delete *it;
            harvesters.erase(it);
            // TODO: Système de barre de vie
            moved = true;
        }
        else if (d.x <= 3 && d.y <= 3) // Sinon si on voit le Harvester (voisinage de Moore d'ordre 3) mais qu'on est trop loin pour le manger
        {
            // On se déplace vers lui
            _position += map.getDirection(_position, (*it)->getPosition()) * 2;
            moved = true;
        }
    }
    if (!moved)
        _position = Point(move_distribution(gen), move_distribution(gen));
}