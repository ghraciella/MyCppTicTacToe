#pragma once
#include <iostream>
#include "game_board.h"

class Player {

    public:
        virtual void moves(const GameBoard board, int& drow , int& dcol) const = 0;

};
