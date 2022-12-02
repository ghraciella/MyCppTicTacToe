#pragma once

#include <stdexcept>

#include "player.h"


class Human: public Player{

public:

    void moves(const GameBoard board, int& drow , int& dcol) const override;

private:

    void getnumber(int& num) const;

};