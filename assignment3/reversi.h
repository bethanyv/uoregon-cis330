#ifndef REVERSI_H_
#define REVERSI_H_

typedef enum {
		empty, // 0
		black, // 1
		white, // 2
	} piece;

typedef struct {
	piece** pieces;
	piece turn;
	int size;
} BoardType;

typedef struct {
	int i;
	int j;
} indexType;

// Initialize the board
void initBoard(BoardType *board, const int size); // Matrix of pieces here

// run the game
void runGame(BoardType *board); // ask players for what they want to do, place pieces

// set the beginning pieces in the center
void setPieces(BoardType *board);

// Print the board in a easy to read way
void printBoard(const BoardType *board);

// place the piece where the user specified by checking if it's valid and flipping
// if a piece is placed, return 1. Else return 0 
int placePiece(const BoardType *board, const piece color, const int x, const int y);

// check if there is a valid vertical move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int verticalValid(const BoardType *board, const int start_index_i, const int start_index_j, const piece color);

// check if there is a valid horizontal move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
int horizontalValid(const BoardType *board, const int start_index_i, const int start_index_j, const piece color);

// check if there is a valid diagonal move - if it is, return the 
// indexes of other piece closing off opponent's pieces. If not, return original points from call
indexType diagonalValid(const BoardType *board, const int x, const int y, const piece color);

// check if there are ANY valid moves available for a player (piece will be a color)
// call all valid functions and if all of them return -1, no moves left
int anyValidMoves(const BoardType *board, const piece color);

// flip the pieces in between the indexes
void horizontalFlip(const BoardType *board, const int start_index_j, const int end_index_j, const int index_i, const piece color);

// flip the pieces in between the indexes
void verticalFlip(const BoardType *board, const int start_index_i, const int end_index_i, const int index_j, const piece color);

// flip the pieces in between the indexes
void diagonalFlip(const BoardType *board, indexType from, indexType to, const piece color);

// counts number of black pieces
int countBlack(const BoardType *board);

// counts number of white pieces
int countWhite(const BoardType *board);

// Free up any dynamically allocated memory
void cleanBoard(BoardType *board);

#endif /* CLOCK_H_ */