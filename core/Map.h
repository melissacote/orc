#ifndef MAP_H
#define MAP_H
#include <vector>

enum class Tile
{
    Wall,
    Floor
};

class Map
{
    int width;
    int height;
    std::vector<Tile> tiles;

public:
    Map(int width, int height, const std::vector<Tile> &tiles);

    bool inBounds(int x, int y) const;
    Tile at(int x, int y) const;
    int getWidth() const;
    int getHeight() const;
};



#endif //MAP_H
