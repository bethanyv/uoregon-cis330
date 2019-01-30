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
	// if it is vertical valid
	int boo = 0; // 0 if nothing has been valid. 1 if something is valid
	int vertical_valid = verticalValid(board, x, y, color);
	int horizontal_valid = horizontalValid(board, x, y, color);
	if(vertical_valid != -1) {
		// TODO: Here, flip the pieces with board,x,y,vertical_valid,y,color
		boo = 1;
	}
	if(horizontal_valid != -1) {
		// TODO: Here, flip the pieces with board,x,y,vertical_valid,y,color
		boo = 1;
	}

	if(boo) {
		board->pieces[x][y] = color;
	}
	if(!boo) {
		printf("%s\n", "Invalid move! Please try again");
	}
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
// i index (because for vertical, j is the same) 
// of other piece closing off opponent's pieces. If not, return -1
int verticalValid(const BoardType *board, const int start_index_i, const int start_index_j, const piece color) {
	int increasing = start_index_i + 1;
	int decreasing = start_index_i - 1;
	int to_count = start_index_i;

	if(increasing < board->size) {
		// increasing first
		while(board->pieces[increasing][start_index_j] != color) {
			if(board->pieces[increasing][start_index_j] == empty) {
				to_count = start_index_i;
				break;
			}
			increasing++;
			if(increasing == board->size || board->pieces[increasing][start_index_j] == color) {
				break;
			}
		}
		if(increasing - 1 != start_index_i) {
			to_count = increasing;
			return to_count;
		}
	}
	// decreasing
	if(decreasing > -1) {
		while(board->pieces[decreasing][start_index_j] != color) {
			if(board->pieces[decreasing][start_index_j] == empty) {
				to_count = start_index_i;
				break;
			}
			decreasing--;
			if(decreasing == -1 || board->pieces[decreasing][start_index_j] == color) {
				break;
			}
		}
		if(decreasing + 1 != start_index_i) {
			to_count = decreasing;
			return to_count;
		}
	}
	// if the start_index_i didn't change, that means there is no legal move, return -1
	return -1;
}

// check if there is a valid horizontal move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int horizontalValid(const BoardType *board, const int start_index_i, const int start_index_j, const piece color) {
	int increasing = start_index_j + 1;
	int decreasing = start_index_j - 1;
	int to_count = start_index_j;

	if(increasing < board->size) {
		// increasing first
		while(board->pieces[start_index_i][increasing] != color) {
			if(board->pieces[start_index_i][increasing] == empty) {
				to_count = start_index_j;
				break;
			}
			increasing++;
			if(increasing == board->size || board->pieces[start_index_i][increasing] == color) {
				break;
			}
		}
		if(increasing - 1 != start_index_j) {
			to_count = increasing;
			return to_count;
		}
	}
	// decreasing
	if(decreasing > -1) {
		while(board->pieces[start_index_i][decreasing] != color) {
			if(board->pieces[start_index_i][decreasing] == empty) {
				to_count = start_index_j;
				break;
			}
			decreasing--;
			if(decreasing == -1 || board->pieces[start_index_i][decreasing] == color) {
				break;
			}
		}
		if(decreasing + 1 != start_index_j) {
			to_count = decreasing;
			return to_count;
		}
	}
	// if the start_index_i didn't change, that means there is no legal move, return -1
	return -1;
}

// check if there is a valid diagonal move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int diagonalValid(const BoardType *board, const int start_index_i, const int start_index_j, const piece color) {
	return 0;
}

// check if there are ANY valid moves available for a player (piece will be a color)
// call all valid functions and if all of them return -1, no moves left
int anyValidMoves(const BoardType *board, const piece color) {
	return 0;
}

// flip the pieces in between the indexes
void horizontalFlip(const BoardType *board, const int start_index_i, const int start_index_j, const int end_index_i, const int end_index_j, const piece color) {

}

// flip the pieces in between the indexes
void verticalFlip(const BoardType *board, const int start_index_i, const int start_index_j, const int end_index_i, const int end_index_j, const piece color) {

}

// flip the pieces in between the indexes
void diagonalFlip(const BoardType *board, const int start_index_i, const int start_index_j, const int end_index_i, const int end_index_j, const piece color) {

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
	placePiece(&board, black, -1, -4);
	//printf("%d", verticalValid(&board, 1, 2,black));
	printBoard(&board);

	cleanBoard(&board);
	return 0;
}