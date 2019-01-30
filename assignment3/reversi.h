#ifndef REVERSI_H_
#define REVERSI_H_

typedef enum {
		empty; // 0
		black; // 1
		white; // 2
	} piece;

typedef struct {
	piece** pieces;
	int turn;
	int size;
} BoardType;

// Initialize the board
void initBoard(BoardType *board, const int size); // Matrix of pieces here

// run the game
void runGame(BoardType *board); // ask players for what they want to do, place pieces

// set the beginning pieces in the center
void setPieces(BoardType *board);

// Print the board in a easy to read way
void printBoard(const BoardType *board, const int size);

// place the piece where the user specified by checking if it's valid and flipping
// if a piece is placed, return 1. Else return 0 
int placePiece(const BoardType *board, const enum piece, const int x, int const y);

// check if there is a valid vertical move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int verticalValid(const int start_index);

// check if there is a valid horizontal move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int horizontalValid(const int start_index);

// check if there is a valid diagonal move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int diagonalValid(const int start_index);

// check if there are ANY valid moves available for a player (piece will be a color)
// call all valid functions and if all of them return -1, no moves left
int anyValidMoves(const BoardType *board, const enum piece);

// flip the pieces in between the indexes
void horizontalFlip(const int start_index, const int end_index);

// flip the pieces in between the indexes
void verticalFlip(const int start_index, const int end_index);

// flip the pieces in between the indexes
void diagonalFlip(const int start_index, const int end_index);

// counts number of black pieces
int countBlack(const BoardType *board);

// counts number of white pieces
int countWhite(const BoardType *board);

// Free up any dynamically allocated memory
void cleanBoard(BoardType *board);

#endif /* CLOCK_H_ */