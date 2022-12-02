#include <stdexcept>
#include <iomanip>

#include "game_board.h"


GameBoard::GameBoard() {

   Print();
}

/*
* row in [0,2]
* col in [0,2]
* player in [1,2]
* board[row][col] == 0
* -> exception
*/

void GameBoard::errorhandler(int row, int col, int player){

    bool rowIsInvalid = (row < 0 || row > 2);
    bool colIsInvalid = (col < 0 || col > 2);
    bool playerschoices = (player < 1 || player > 2);
    if (rowIsInvalid || colIsInvalid){

        throw std::invalid_argument("row and column should be between 0 and 2!");
    }

    if (playerschoices) {

        throw std::invalid_argument("There can only be player 1 or player 2");
    }
}

std::array< std::array<int, 3> , 3> GameBoard::Get() const{

    return m_board_size;

}

// int GameBoard::Getposition(){

//     return m_drow, m_dcol, m_dplayer;

// }



void GameBoard::Set(int row, int col, int player) {

    std::cout <<"Position marked is row " << row << ", col " << col << " by player " << player << std::endl;
    std::cout<<std::endl;
    errorhandler(row, col, player);
    if (m_board_size[row][col] != 0){

        throw std::invalid_argument("Position already marked");
    }

    m_board_size[row][col] = player;
    if (m_board_size[row][col] != 0){
    Print();
    //checkwin(row, col, player);
    }    

}

void GameBoard::Print() const {

    for (int row =0 ; row<=2 ; row++){
        for(int col= 0; col<=2; col++){
            std::cout<<"|"<<std::setw(6)<<m_board_size[row][col]<<"|";
       
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/*
* Input:
*   lastrow:
*   lastcol:
*   lastplayer:
*
* Output:
*   if player wins then return true
*   else false
*
*/
bool GameBoard::checkwin(int lastrow, int lastcol, int lastplayer){

    errorhandler(lastrow, lastcol, lastplayer);

    if (m_board_size[lastrow][lastcol] != lastplayer){

        throw std::invalid_argument("  empty board positions left");
    }

    {
        bool win = true;
        for (int j = 0; j < 3; j++) {
            if (m_board_size[lastrow][j] != lastplayer) {
                win = false; 
                break;
            }
        }
        if (win) {
            return true;
        }
    }

    // second case: check whole column
    {
        
        bool win = true;
        for (int i = 0; i < 3; i++) {
            if (m_board_size[i][lastcol] != lastplayer) {
                win = false;
                break;
            }
        }
        if (win) {
            return true;
        }

    }

    // third case: check diagonal from top left to bottom right
    //todo//if (/* on diagonal*/)
    {
        
        bool win =true;
        for (int ij =0 ; ij<=2 ; ij++){
            if (m_board_size[ij][ij] != lastplayer) {
                win = false;
                break;
            }
        }    
        if (win) {
            return true;
        }

    }

    // fourth case: check diagonal from bottom left to top right
    //todo//if (/* on other diagonal*/)
    {
        bool win =true;
        // i+j = 2 for 3x3, 3 for 4x4, n-1 for nxn
        for (int i =0 ; i<=2 ; i++){

            int j = 2-i;
            if (m_board_size[i][j] != lastplayer) {
                win = false;
                break;
            }
        }    
        if (win) {
            return true;
        }
    }


    return false;
}
