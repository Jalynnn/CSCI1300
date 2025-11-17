#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator once
    srand(time(0));

    // Create a board
    Board board;

    cout << "Initial board:" << endl;
    board.displayBoard();

    // Move player 1 a few steps
    cout << "\nMoving player 1 by 5 steps:" << endl;
    for (int i = 0; i < 5; i++) {
        board.movePlayer(0); // Player index 0
    }
    board.displayBoard();

    // Move player 2 a few steps
    cout << "\nMoving player 2 by 3 steps:" << endl;
    for (int i = 0; i < 3; i++) {
        board.movePlayer(1); // Player index 1
    }
    board.displayBoard();

    // Print player positions
    cout << "\nPlayer 1 position: " << board.getPlayerPosition(0) << endl;
    cout << "Player 2 position: " << board.getPlayerPosition(1) << endl;

    return 0;
}
