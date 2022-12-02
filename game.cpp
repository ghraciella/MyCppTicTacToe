#include "game.h"


Game::Game(Computer player1, Computer player2){
    m_players.push_back(player1);
    m_players.push_back(player2);
    m_board = GameBoard();
}


void Game::Run() {

    bool somebodywon = false;

    while(!somebodywon){

        for (std::vector<Computer>::size_type i = 0; i != m_players.size(); i++){
            int row = -1;
            int col = -1;
            bool good = false;
            int pos = 0;

            while(!good && pos<9){
                try {
                    m_players.at(i).moves( m_board,  row , col);
                    m_board.Set(row, col, i+1);
                    std::cout<<"Next player's turn"<<std::endl; 
                    std::cout<<std::endl; 


                    good = true;

                }
                catch (const std::exception& e) {
                    std::cout << "Recheck the integers entered"<<std::endl;
                    std::cout << e.what() << std::endl;
                }
                pos++;


            }   

            // if(pos == 9 && m_board.Get().at(row).at(col) != 0){
            //     std::cout<<"It is a draw, tight moves!"<<std::endl; 
            //     return;             

            // }   


          
            somebodywon = m_board.checkwin(row,col,i+1);


            if(somebodywon){
                std::cout<<"player "<<i+1<<" won"<<std::endl;
                return;
            }

            else if(m_board.Get().at(row).at(col) != 0 && pos == 9 ){
                std::cout<<"It is a draw, tight moves!"<<std::endl; 
                return;
            }

            


        }
        

    }  

    return;     

}
