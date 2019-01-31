#include "reversi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	// make the board from specified board size, set initial pieces, and run the game. Clean after 
	int size;

	printf("Please enter the size of the board (4-16): ");
	scanf("%d", &size);

	while(size < 4 || size > 16) {
		printf("Invalid board size, please input again (4-16)\n");
		printf("Please enter the size of the board: ");
		scanf("%d", &size);
	}

	BoardType board;
	initBoard(&board, size);
	setPieces(&board);
	runGame(&board);

	cleanBoard(&board);
	return 0;
}