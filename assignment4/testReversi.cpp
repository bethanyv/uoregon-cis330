#include "reversi.h"
#include <iostream>

int main(int argc, char const *argv[]) {
	// make the board from specified board size, set initial pieces, and run the game. Clean after 
	int size;

	std::cout << "Please enter the size of the board (4-16): ";
	std::cin >> size;

	while(size < 4 || size > 16) {
		std::cout << "Invalid board size, please input again (4-16)\n";
		std::cout << "Please enter the size of the board: ";
		std::cin >> size;
	}

	BoardType board(size);
	board.setPieces();
	board.runGame();

	return 0;
}