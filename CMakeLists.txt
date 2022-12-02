set (CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

add_executable(TicTacToe main.cpp game_board.cpp game.cpp human.cpp computer.cpp)

add_executable(TicTacToe_Test unittest/unittest.cpp game_board.cpp game.cpp human.cpp computer.cpp)
target_link_libraries(TicTacToe_Test
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      )
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK) 
