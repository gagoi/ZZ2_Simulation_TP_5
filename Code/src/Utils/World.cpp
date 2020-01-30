#include "World.hpp"

std::mt19937 gen(256);

World* World::instance = nullptr;

World& World::getInstance()
{
    if (instance == nullptr)
        instance = new World();
    return *instance;
}

World::World() :
    _width(WORLD_WIDTH),
    _height(WORLD_HEIGHT)
{
    for (int i = 0; i < _width; i++)
    {
        _world.push_back(std::vector<Entity*>());
        for (int j = 0; j < _height; j++)
        {
            _world[i].push_back(nullptr);
        }
    }
}

World::~World() {}

void World::add(Entity* entity)
{
    Point p(entity->getPosition());
    if ((*this)[p] != nullptr) // Si la case est occupée
    {
        // TODO: Gerer le cas où la case est occupée
        //delete entity;
    }
    else
    {
        (*this)[p] = entity;
    }
}

bool World::findRandomPositionInEnvironment(std::vector<Entity*> env, int range, Entity::ENTITY_TYPE toFind, Point & pos)
{
    std::vector<Point> points;
    for (int i = -range; i <= range; i++)
    {
        for (int j = -range; j <= range; j++)
        {
            points.push_back(Point(i, j));
        }
    }

    std::vector<int> index;
    for (size_t i = 0; i < env.size(); i++)
    {
        if ((toFind == Entity::ENTITY_TYPE::NONE && env[i] == nullptr) || (env[i] != nullptr && env[i]->getType() == toFind))
        {
            index.push_back(i);
        }
    }
    
    if (index.size() > 0)
    {
        std::shuffle(index.begin(), index.end(), gen);
        pos = points[index[0]];
        return true;
    }
    return false;
}

std::vector<Entity*> World::getEnvironment(Point & origin, int range)
{
    std::vector<Entity*> env;
    refactorCoordonates(origin);

    for (int i = origin.x - range; i <= origin.x + range; i++)
    {
        for (int j = origin.y - range; j <= origin.y + range; j++)
        {
            env.push_back((*this)[Point(i, j)]);
        }
    }
    return env;
}

void World::updateMove(Entity * e, Point const & newPosition)
{
    (*this)[e->getPosition()] = nullptr;
    (*this)[newPosition] = e;
}

void World::updateKill(Entity * e)
{
    (*this)[e->getPosition()] = nullptr;
}

void World::refactorCoordonates(Point & p)
{
    p.x = p.x < 0 ? _width - (-p.x % _width) : p.x % _width;
    p.y = p.y < 0 ? _height - (-p.y % _height) : p.y % _height;
}

Entity*& World::operator[](Point const & p)
{
    int x = p.x < 0 ? _width - (-p.x % _width) : p.x % _width;
    int y = p.y < 0 ? _height - (-p.y % _height) : p.y % _height;

    return _world[x][y];
}

Entity* const & World::operator[](Point const & p) const
{
    int x = p.x < 0 ? _width - (-p.x % _width) : p.x % _width;
    int y = p.y < 0 ? _height - (-p.y % _height) : p.y % _height;

    return _world[x][y];
}

Entity*& World::operator[](Point & p)
{
    p.x = p.x < 0 ? _width - (-p.x % _width) : p.x % _width;
    p.y = p.y < 0 ? _height - (-p.y % _height) : p.y % _height;

    return _world[p.x][p.y];
}

Entity* const & World::operator[](Point & p) const
{
    p.x = p.x < 0 ? _width - (-p.x % _width) : p.x % _width;
    p.y = p.y < 0 ? _height - (-p.y % _height) : p.y % _height;

    return _world[p.x][p.y];
}

Point World::getDistances(Point const & p1, Point const & p2) const
{
    int dx = std::min(abs(p1.x - p2.x), (p2.x > p1.x ? (abs(_width - p2.x) + p1.x) : (abs(_width - p1.x) + p2.x)));
    int dy = std::min(abs(p1.y - p2.y), (p2.y > p1.y ? (abs(_height - p2.y) + p1.y) : (abs(_height - p1.y) + p2.y)));
    return Point(dx, dy);
}

Point World::getDirection(Point const & point, Point const & dest) const
{
    int dx_1 = abs(point.x - dest.x);
    int dy_1 = abs(point.y - dest.y);
    int dx_2 = dest.x > point.x ? (_width - dest.x + point.x) : (_width - point.x + dest.x);
    int dy_2 = dest.y > point.y ? (_height - dest.y + point.y) : (_height - point.y + dest.y);

    Point dir(0, 0);
    if ((dx_1 > dx_2 ? dx_2 : dx_1) == (dy_1 > dy_2 ? dy_2 : dy_1))
    {
        dir.x = point.x > dest.x ? -1 : (point.x < dest.x ? 1 : 0);
        dir.y = point.y > dest.y ? -1 : (point.y < dest.y ? 1 : 0);
    }
    else if ((dx_1 > dx_2 ? dx_2 : dx_1) > (dy_1 > dy_2 ? dy_2 : dy_1))
    {
        dir.x = point.x > dest.x ? -1 : (point.x < dest.x ? 1 : 0);
    }
    else
    {
        dir.y = point.y > dest.y ? -1 : (point.y < dest.y ? 1 : 0);
    }

    if (dx_2 < dx_1)
        dir.x *= -1;
    if (dy_2 < dy_1)
        dir.y *= -1;

    return dir;
}

std::ostream& operator<<(std::ostream& out, World const & m)
{
    int i = 0;
    std::cout << "   ";
    for (int j = 0; j < m._width; j++)
        std::cout << std::setw(3) << j;
    
    std::cout << std::endl;

    for (auto &&line : m._world)
    {
        std::cout << std::setw(2) << i++ << " ";
        for (auto &&o : line)
        {
            if (o)
                std::cout << std::setw(3) << *o;
            else
                std::cout << std::setw(3) << '.';
        }
        std::cout << std::endl;
    }
    return out;
}