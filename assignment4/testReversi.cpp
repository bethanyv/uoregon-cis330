#include "reversi.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	// make the board from specified board size, set initial pieces, and run the game. Clean after 
	int size;

	cout << "Please enter the size of the board (4-16): ";
	cin >> size;

	while(size < 4 || size > 16) {
		cout << "Invalid board size, please input again (4-16)\n";
		cout << "Please enter the size of the board: ";
		cin >> size;
	}

	BoardType board;
	initBoard(&board, size);
	setPieces(&board);
	runGame(&board);

	cleanBoard(&board);
	return 0;
}