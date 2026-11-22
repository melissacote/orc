#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

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

        std::cout << "Player position X: " << state.getPlayerPosition().x << "\n";
        std::cout << "Player position Y: " << state.getPlayerPosition().y << "\n";

        sf::RenderWindow window(sf::VideoMode({640u, 480u}), "Orc");

        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
            }

            window.clear();
            window.display();
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
