#include "MapParsing.h"

#include <stdexcept>

namespace
{
    Tile charToTile(char c)
    {
        switch (c)
        {
            case '.':
                return Tile::Floor;
            case '#':
                return Tile::Wall;
            default:
                throw std::invalid_argument(std::string("charToTile: unknown character '") + c + "'");
        }
    }
}

Map mapFromStrings(const std::vector<std::string> &rows)
{
    if (rows.empty())
    {
        throw std::invalid_argument("mapFromStrings(): map is empty");
    }

    const int height = static_cast<int>(rows.size());
    const int width = static_cast<int>(rows[0].size());

    std::vector<Tile> tiles;
    for (const std::string &row : rows)
    {
        if (static_cast<int>(row.size()) != width)
        {
            throw std::invalid_argument("mapFromStrings(): row size does not match map width");
        }
        for (const char c : row)
        {
            tiles.push_back(charToTile(c));
        }
    }

    return {width, height, tiles};
}


