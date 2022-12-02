#include "computer.h"

#include <iostream>
#include <cstdlib>
#include <ctime>



Computer::Computer() {

    std::srand(std::time(NULL));
}

//int randomindex = rand()%9;

void Computer::moves(const GameBoard board, int& row, int& col) const {

    int randrowindex = std::rand()%3;
    int randcolindex = std::rand()%3;

    int count = 0;
    while (board.Get().at(randrowindex).at(randcolindex) != 0 && count<9){

        randrowindex = std::rand()%3;
        randcolindex = std::rand()%3;

        count++;

        if (count == 10){

            throw std::logic_error("too much");
            //exit(0);
        }


    }

        row = randrowindex;
        col = randcolindex;


    

}