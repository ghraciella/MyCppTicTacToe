
#define BOOST_TEST_MODULE MyTicTacToeTest
#include <boost/test/unit_test.hpp>

#include "../game_board.h"

BOOST_AUTO_TEST_CASE( testGameBoardSet )
{
    GameBoard board = GameBoard();

    // TODO:
    // exception tests
    BOOST_CHECK_THROW( board.Set(0,0,0), std::invalid_argument );
    BOOST_CHECK_THROW( board.Set(0,0,3), std::invalid_argument );
    BOOST_CHECK_THROW( board.Set(-1,0,1), std::invalid_argument );
    BOOST_CHECK_THROW( board.Set(3,0,1), std::invalid_argument );
    BOOST_CHECK_THROW( board.Set(0,-1,1), std::invalid_argument );
    BOOST_CHECK_THROW( board.Set(0,3,1), std::invalid_argument );
    BOOST_CHECK_THROW( board.Set(2,1,0), std::invalid_argument );

    // logic tests
    board.Set(0,0,1);   
    BOOST_CHECK( board.Get().at(0).at(0) != 9 );
    BOOST_CHECK_EQUAL( board.Get().at(0).at(0), 1 );
    board.Set(2,1,2);   
    BOOST_CHECK( board.Get().at(2).at(1) == 2 );   
    board.Set(0,2,1);   
    BOOST_CHECK( board.Get().at(0).at(2) !=-1 );        
    board.Set(1,1,2);   
    BOOST_CHECK( board.Get().at(1).at(1) != 1 );  
    BOOST_CHECK_EQUAL( board.Get().at(1).at(1), 2 );
    board.Set(2,2,2);   
    BOOST_CHECK( board.Get().at(2).at(2) !=3); 
    board.Set(2,0,2);   
    BOOST_CHECK( board.Get().at(2).at(0) !=3 );     



    // BOOST_CHECK( board.Get().at(0).at(1) != -1 );
    // BOOST_CHECK( board.Get().at(0).at(2) != 3 );
    // BOOST_CHECK( board.Get().at(1).at(0) != 1.5 );
    // BOOST_CHECK( board.Get().at(1).at(1) != 100 );
    // BOOST_CHECK( board.Get().at(1).at(2) != 0.8 );
    // BOOST_CHECK( board.Get().at(2).at(0) != 0.00254 );
    // BOOST_CHECK( board.Get().at(2).at(1) != 1E6 );
    // BOOST_CHECK( board.Get().at(2).at(2) != 7.8676544 );


}



BOOST_AUTO_TEST_CASE( testGameBoardCheckWin )
{
    GameBoard board = GameBoard();

    BOOST_CHECK_THROW( board.checkwin(0,0,0), std::invalid_argument );
    BOOST_CHECK_THROW( board.checkwin(0,0,3), std::invalid_argument );
    BOOST_CHECK_THROW( board.checkwin(-1,0,1), std::invalid_argument );
    BOOST_CHECK_THROW( board.checkwin(3,0,1), std::invalid_argument );
    BOOST_CHECK_THROW( board.checkwin(0,-1,1), std::invalid_argument );
    BOOST_CHECK_THROW( board.checkwin(0,3,1), std::invalid_argument );

    // TODO
    // logic tests
    //BOOST_CHECK( !board.checkwin(2,0,1) );

    // invalid checkwin
    BOOST_CHECK_THROW( board.checkwin(0,0,1), std::invalid_argument );

    board.Set(0,0,1);
    BOOST_CHECK( ! board.checkwin(0,0,1) );
    board.Set(2,1,2);
    BOOST_CHECK( ! board.checkwin(2,1,2) );   
    board.Set(0,2,1);   
    BOOST_CHECK( ! board.checkwin(0,2,1) ); 
    board.Set(1,1,2);
    BOOST_CHECK( ! board.checkwin(1,1,2) ); 
    board.Set(1,2,1);      
    BOOST_CHECK( ! board.checkwin(1,2,1) ); 
    board.Set(2,2,2);   
    BOOST_CHECK( ! board.checkwin(2,2,2) ); 

    board.Set(2,0,2);   
    BOOST_CHECK( board.checkwin(2,0,2) );
    board.Set(0,1,1);
    BOOST_CHECK( board.checkwin(0,1,1) );
}