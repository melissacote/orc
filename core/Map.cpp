#include "Map.h"
#include <stdexcept>

Map::Map(int width, int height, const std::vector<Tile> &tiles)
    : width(width), height(height), tiles(tiles)
{
    if (width <= 0 || height <= 0)
    {
        throw std::invalid_argument("Map::Map(): width and height must be positive integers");
    }
    if (tiles.size() != static_cast<std::size_t>(width) * static_cast<std::size_t>(height))
    {
        throw std::invalid_argument("Map::Map(): tiles.size() != width * height");
    }
}


bool Map::inBounds(const int x, const int y) const
{
    return x >= 0 && y >= 0 && x < width && y < height;
}


Tile Map::at(const int x, const int y) const
{
    if (!inBounds(x, y))
    {
        throw std::out_of_range("Map::at: (" + std::to_string(x) + ", " + std::to_string(y) + ") is out of bounds");
    }
    return tiles[y * width + x];
}

int Map::getWidth() const
{
    return width;
}

int Map::getHeight() const
{
    return height;
}
