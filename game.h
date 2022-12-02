#pragma once


#include "human.h"
#include "computer.h"

#include <vector>

class Game {

public:

    Game(Computer player1, Computer player2);

    void Run();

private:

    std::vector<Computer> m_players;
    GameBoard m_board;

};
