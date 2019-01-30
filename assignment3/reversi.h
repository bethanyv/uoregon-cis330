#ifndef REVERSI_H_
#define REVERSI_H_

typedef enum {
		blank; // 0
		black; // 1
		white; // 2
	} piece;

typedef struct {
	piece** pieces;
} BoardType;

// Initialize the board
void initBoard(BoardType *board, int size); // Matrix of pieces here

// run the game
void runGame(BoardType *board); // ask players for what they want to do, place pieces

// set the beginning pieces in the center
void setPieces(BoardType *board);

// Print the board in a easy to read way
void printBoard(const BoardType *board, size);

// Free up any dynamically allocated memory
void cleanBoard(BoardType *board);

#endif /* CLOCK_H_ */