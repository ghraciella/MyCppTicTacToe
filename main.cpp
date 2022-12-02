
#include <cstring>
#include "game_board.h"
#include "human.h"
#include "game.h"
#include "computer.h"





int main()

{

Game game = Game(Computer(), Computer());
game.Run();



}
