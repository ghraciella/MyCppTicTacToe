#pragma once

#include <iostream>
#include <array>


class GameBoard{

public:

    GameBoard();

    void Set(int row, int col, int player);

    std::array< std::array<int, 3> , 3> Get() const;

    //int Getposition();

    void Print() const;

    bool checkwin(int lastrow, int lastcol, int lastplayer);

private:

    //int m_board_size[3][3] = { };

    std::array< std::array<int, 3> , 3> m_board_size{ };

    void errorhandler(int row, int col, int player) ;
};


