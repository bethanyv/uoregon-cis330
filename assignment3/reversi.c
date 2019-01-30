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
	// to set pieces in middle, find size/2 and place at 
	// (size / 2) and (size / 2) - 1 in both x and y coordinates
	int size = board->size;
	board->pieces[size/ 2][size / 2] = white;
	board->pieces[(size / 2) - 1][size / 2] = black;
	board->pieces[(size / 2) - 1][(size / 2) - 1] = white;
	board->pieces[size / 2][(size / 2) - 1] = black;
}

// Print the board in a easy to read way
void printBoard(const BoardType *board) {
	// printf("Player 1 > 2     Player 2 > 2");
	// TODO: uncomment this when countBlack is done
	printf("\nPlayer 1 > %d     Player 2 > %d", countBlack(board), countWhite(board));
	printf("\n\n");

	// print initial space for empty corner before indexes
	printf("  ");
	// print the j indexes across the top
	for(int k = 0; k < board->size; k++) {
		printf("%d ", k);
	}
	// new line before printing every line of board with i index
	printf("\n");
	for(int i = 0; i < board->size; i++) {
		// start with printing i so players know where the index is
		printf("%d ", i);
		// iterate through each piece in the i row to print them
		for(int j = 0; j < board->size; j++) {
			piece x = board->pieces[i][j];
			// if they are black, print X; if white, print O; if empty, print .
			if(x == black) {
				printf("%s ", "X");
			}
			else if(x == white) {
				printf("%s ", "O");
			}
			else {
				printf(". ");
			}
		}
		// new line before next row
		printf("\n");
	}
}

// check if there is a valid vertical move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int verticalValid(const int start_index_i, const int start_index_j) {
	return 0;
}

// check if there is a valid horizontal move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int horizontalValid(const int start_index_i, const int start_index_j) {
	return 0;
}

// check if there is a valid diagonal move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int diagonalValid(const int start_index_i, const int start_index_j) {
	return 0;
}

// check if there are ANY valid moves available for a player (piece will be a color)
// call all valid functions and if all of them return -1, no moves left
int anyValidMoves(const BoardType *board, const piece color) {
	return 0;
}

// flip the pieces in between the indexes
void horizontalFlip(const int start_index_i, const int start_index_j, const int end_index_i, const int end_index_j) {

}

// flip the pieces in between the indexes
void verticalFlip(const int start_index_i, const int start_index_j, const int end_index_i, const int end_index_j) {

}

// flip the pieces in between the indexes
void diagonalFlip(const int start_index_i, const int start_index_j, const int end_index_i, const int end_index_j) {

}

// counts number of black pieces
int countBlack(const BoardType *board) {
	int count = 0;
	for(int i = 0; i < board->size; i++) {
		for(int j = 0; j < board->size; j++) {
			if(board->pieces[i][j] == black) {
				count += 1;
			}
		}
	}
	return count;
}

// counts number of white pieces
int countWhite(const BoardType *board) {
	int count = 0;
	for(int i = 0; i < board->size; i++) {
		for(int j = 0; j < board->size; j++) {
			if(board->pieces[i][j] == white) {
				count += 1;
			}
		}
	}
	return count;
}

// Free up any dynamically allocated memory
void cleanBoard(BoardType *board) {
	for(int i = 0; i < board->size; i++) {
		free(board->pieces[i]);
	}
	// free the array that held all the digit lines of the clock
	free(board->pieces);
}

int main(int argc, char const *argv[]) {
	/*
	Ask players for input, 
	make the board (init), 
	initalize the first few pieces (setpieces)
	runGame (calls print board every turn)
	*/
	int size;

	printf("Please enter the size of the board: ");
	scanf("%d", &size);

	while(size < 4 || size > 16) {
		printf("Invalid board size, please input again (4-16)\n");
		printf("Please enter the size of the board: ");
		scanf("%d", &size);
	}

	BoardType board;
	initBoard(&board, size);
	setPieces(&board);
	printBoard(&board);

	cleanBoard(&board);
	return 0;
}