#pragma once

#include <stdexcept>

#include "player.h"


class Computer: public Player{

    public:

        Computer();

        void moves(const GameBoard board, int& row, int& col) const override;




}; 