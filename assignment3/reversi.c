#include "reversi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the board
void initBoard(BoardType *board, const int size) {
	// allocate memory for the board depending on the size the player chose
	board->pieces = (piece **) malloc ( size * sizeof(piece*));
	for (int i = 0; i < size; i++) {
		board->pieces[i] = (piece *) malloc(size * sizeof(piece));
	}
	board->turn = black;
	board->size = size;

	// fill the board with empty for now
	for (int i = 0; i < size; i ++) {
		for (int j = 0; j < size; j ++) {
			board->pieces[i][j] = empty;
		}
	}
}

// ask players for what they want to do, place pieces
void runGame(BoardType *board) {

} 

// place the piece where the user specified by checking if it's valid and flipping 
// if a piece is placed, return 1. Else return 0
int placePiece(const BoardType *board, const piece color, const int x, const int y) {
	return 0;
}

// set the beginning pieces in the center
void setPieces(BoardType *board) {

}

// Print the board in a easy to read way
void printBoard(const BoardType *board, const int size) {

}

// check if there is a valid vertical move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int verticalValid(const int start_index) {
	return 0;
}

// check if there is a valid horizontal move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int horizontalValid(const int start_index) {
	return 0;
}

// check if there is a valid diagonal move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int diagonalValid(const int start_index) {
	return 0;
}

// check if there are ANY valid moves available for a player (piece will be a color)
// call all valid functions and if all of them return -1, no moves left
int anyValidMoves(const BoardType *board, const piece color) {
	return 0;
}

// flip the pieces in between the indexes
void horizontalFlip(const int start_index, const int end_index) {

}

// flip the pieces in between the indexes
void verticalFlip(const int start_index, const int end_index) {

}

// flip the pieces in between the indexes
void diagonalFlip(const int start_index, const int end_index) {

}

// counts number of black pieces
int countBlack(const BoardType *board) {
	return 0;
}

// counts number of white pieces
int countWhite(const BoardType *board) {
	return 0;
}

// Free up any dynamically allocated memory
void cleanBoard(BoardType *board) {
	for(int i = 0; i < board->size; i++) {
		free(board->pieces[i]);
	}
	// free the array that held all the digit lines of the clock
	free(board);
}

int main(int argc, char const *argv[]) {
	/*
	Ask players for input, 
	make the board (init), 
	initalize the first few pieces (setpieces)
	runGame (calls print board every turn)
	*/
	int size = 8;
	BoardType board;
	initBoard(&board, size);

	// practice printing
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			piece x = (&board)->pieces[i][j];
			printf("%d ", x);
		}
		printf("\n");
	}

	cleanBoard(&board);
	return 0;
}