#include <iostream>
#include <vector>
#include "Functions.h"




int main()
{
    while (gameover()) {
        display_board();
        player_turn();
        gameover();
    }
    if (turn == 'X' && draw == false) {
        std::cout << "Congratulations!Player with 'O' has won the game";
    }
    else if (turn == 'O' && draw == false) {
        std::cout << "Congratulations!Player with 'X' has won the game";
    }
    else
        std::cout << "GAME DRAW!!!";
}