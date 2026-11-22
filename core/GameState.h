#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Map.h"
#include "Position.h"

class GameState
{
    Map m_map;
    Position m_playerPosition;

public:
    GameState(Map map, Position playerPosition);
    const Map& getMap() const;
    const Position& getPlayerPosition() const;
};



#endif //GAMESTATE_H
