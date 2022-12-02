#include "human.h"

void Human::moves(const GameBoard board, int& drow , int& dcol) const  {

    board.Print();

    std::cout<<"enter row "<<std::endl;
    getnumber(drow);

    std::cout<<"enter column"<<std::endl;
    getnumber(dcol);


    return;

}


void Human::getnumber(int& num) const {

    std::cin>>num;
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Invalid,  reenter number "<<std::endl;
        std::cin >> num;
    }


}