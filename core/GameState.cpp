#include "GameState.h"

#include <stdexcept>
#include <utility>

GameState::GameState(Map map, const Position playerPosition)
    : m_map(std::move(map)), m_playerPosition(playerPosition)
{
    if (!m_map.inBounds(m_playerPosition.x, m_playerPosition.y))
    {
        throw std::invalid_argument("GameState::GameState starting player position is out of bounds of the map.");
    }

    if (m_map.at(m_playerPosition.x, m_playerPosition.y) != Tile::Floor)
    {
        throw std::invalid_argument("GameState::GameState starting player position is not a Floor tile.");
    }
}

