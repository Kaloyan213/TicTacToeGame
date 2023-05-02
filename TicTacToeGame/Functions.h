#pragma once
#include <iostream>
#include <vector>

std::vector <std::vector <char>> board{ {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int choice;
int row, col;
char turn = 'X';
bool draw = false;

void display_board() {


    std::cout << "PLAYER - 1 [X]  PLAYER - 2 [O] \n \n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    std::cout << "     |     |     \n \n";
}

void player_turn() {
    if (turn == 'X') {
        std::cout << "Player - 1 [X]: ";
    }
    else if (turn == 'O') {
        std::cout << "Player - 2 [O]: ";
    }

    std::cin >> choice;


    switch (choice) {
    case 1: row = 0; col = 0; break;
    case 2: row = 0; col = 1; break;
    case 3: row = 0; col = 2; break;
    case 4: row = 1; col = 0; break;
    case 5: row = 1; col = 1; break;
    case 6: row = 1; col = 2; break;
    case 7: row = 2; col = 0; break;
    case 8: row = 2; col = 1; break;
    case 9: row = 2; col = 2; break;
    default:
        std::cout << "Invalid Move";
    }

    if (turn == 'X' && board.at(row).at(col) != 'X' && board.at(row).at(col) != 'O') {
        board.at(row).at(col) = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][col] != 'X' && board.at(row).at(col) != 'O') {
        board[row][col] = 'O';
        turn = 'X';
    }
    else {
        std::cout << "Box already filled!n Please choose another!";
        player_turn();
    }
    //display_board();
}

bool gameover() {
    for (int i = 0; i < 3; i++)
        if (board.at(i).at(0) == board.at(i).at(1) && board.at(i).at(0) == board[i][2] || board.at(0).at(i) == board.at(1).at(i) && board.at(0).at(i) == board.at(2).at(i))
            return false;


    if (board.at(0).at(0) == board.at(1).at(1) && board.at(0).at(0) == board.at(2).at(2) || board.at(2).at(2) == board.at(1).at(1) && board.at(0).at(2) == board.at(2).at(0))
        return false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board.at(i).at(j) != 'X' && board.at(i).at(j) != 'O')
                return true;

    draw = true;
    return false;
}
