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
};



#endif //GAMESTATE_H
