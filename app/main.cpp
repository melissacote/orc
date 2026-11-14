

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "core/GameState.h"
#include "core/Map.h"
#include "core/MapParsing.h"

int main()
{
    const std::vector<std::string> layout =
        {
        "#########",
        "#.......#",
        "#..#.#..#",
        "#.......#",
        "#..#.#..#",
        "#.......#",
        "#########"
        };

    try
    {
        Map newMap = mapFromStrings(layout);
        std::cout << "Map is " << newMap.getWidth() << "x" << newMap.getHeight() << "\n";
        std::cout << "Map tile 1,1 is a Floor: " << (newMap.at(1, 1) == Tile::Floor) << "\n";
        std::cout << "Map tile 3,2 is a Wall: " << (newMap.at(3, 2) == Tile::Wall) << "\n";

        GameState state = GameState(std::move(newMap), {5, 5});
        std::cout << "GameState created successfully!\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
