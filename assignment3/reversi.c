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
	int x, y;
	int count_bad_turns = 2;
	while(count_bad_turns) {

		int x = anyValidMoves(board, board->turn);
		printf("%d\n", x);
		if(fullBoard(board)) {
			break;
		}
		// if there are no valid moves, move to next player
		if(!anyValidMoves(board, board->turn)) {
			printf("No valid moves for Player %d\n", board->turn);
			if(board->turn == white) {
				board->turn = black;
			}
			else{
				board->turn = white;
			}
			count_bad_turns--;
			continue;
		}

		printBoard(board);

		printf("\nPlayer %d turn, ", board->turn);
		
		printf("input 2 numbers (0-%d) for row and column: ", board->size - 1);
		scanf("%d %d", &x, &y);
		while(x < 0 || x > board->size - 1 || y < 0 || y > board->size - 1) {
			printf("\n%s", "Invalid input, please input again (Too big or small of an index): ");
			scanf("%d %d", &x, &y);
		}
		while(board->pieces[x][y] != empty) {
			printf("\n%s", "Invalid input, please input again (Full spot): ");
			scanf("%d %d", &x, &y);
		}

		int boo = placePiece(board, board->turn, x, y);
		while(!boo && anyValidMoves(board, board->turn) && !fullBoard(board)) {
			printf("\n%s", "Invalid move! Please try again (there are available moves!): ");
			scanf("%d %d", &x, &y);
			if(board->pieces[x][y] != empty) {
				continue;
			}
			if(!anyValidMoves(board,board->turn)) {
				if(board->turn == white) {
					board->turn = black;
				}
				else{
					board->turn = white;
				}
				break;
			}
			boo = placePiece(board, board->turn, x, y);
		}
		// if there was a move made
		if(boo) {
			count_bad_turns = 2;
			if(board->turn == white) {
				board->turn = black;
			}
			else{
				board->turn = white;
			}
		}
	}
	printBoard(board);
	printf("\nGAME OVER!\n");
	int player1_score = countBlack(board);
	int player2_score = countWhite(board);
	printf("\nPlayer 1 > %d", player1_score);
	printf("\nPlayer 2 > %d\n", player2_score);
	if(player1_score > player2_score) {
		printf("\nPLAYER 1 WINS");
	}
	else{
		printf("\nPLAYER 2 WINS!!\n");
	}
} 

// will say if the board is full. RETURN 1 IF FULL, else return 0
int fullBoard(BoardType *board) {
	int count = 0;
	for(int i = 0; i < board->size; i++) {
		for(int j = 0; j < board->size; j++) {
			if(board->pieces[i][j] != empty) {
				count++;
			}
		}
	}
	if(count == board->size*board->size) {
		return 1;
	}
	else {
		return 0;
	}
}
// place the piece where the user specified by checking if it's valid and flipping 
// if a piece is placed, return 1. Else return 0
int placePiece(const BoardType *board, const piece color, const int x, const int y) {
	// if it is vertical valid
	int boo = 0; // 0 if nothing has been valid. 1 if something is valid (like a boolean)
	indexType from;
	from.i = x;
	from.j = y;
	int vertical_valid = verticalValid(board, x, y, color);
	int horizontal_valid = horizontalValid(board, x, y, color);
	indexType diagonal_valid = diagonalValid(board, x, y, color);


	if(vertical_valid != -1) {
		verticalFlip(board, x, vertical_valid, y, color);
		boo = 1;
	}
	if(horizontal_valid != -1) {
		horizontalFlip(board, y, horizontal_valid, x, color);
		boo = 1;
	}

	if(diagonal_valid.i != x && diagonal_valid.j != y) {
		diagonalFlip(board, diagonal_valid, from, color);
		boo = 1;
	}

	if(boo) {
		board->pieces[x][y] = color;
		return 1;
	}
	else {
		return 0;
	}
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

int verticalValid(const BoardType *board, const int start_index_i, const int start_index_j, const piece color) {
	// check if there is a valid vertical move - if it is, return the 
	// i index of ending piece that closes space we want to flip
	// (because for vertical, j is the same) 
	// If no legal move, return -1

	int increasing = start_index_i + 1;
	int decreasing = start_index_i - 1;
	int to_count = start_index_i;
	int boo = 0;

	// to ensure we don't get a seg fault and index to the wrong location
	if(increasing < board->size && increasing > -1) {
		// increasing first, while the spot directly below the spot of the
		// selected space isn't the color of the player making the move
		while(board->pieces[increasing][start_index_j] != color) {
			// if the spot is empty though, set the count to the beginning index to try decreasing
			// break this loop so it doesn't continue
			if(increasing == board->size || board->pieces[increasing][start_index_j] == empty) {
				to_count = start_index_i;
				boo = 1;
				break;
			}
			// increase index going vertically down to look at next spot
			increasing++;
			// if increasing went off the board, or we hit another of out pieces, break
			if(increasing == board->size) {
				boo = 1;
			}
			if(increasing == board->size || board->pieces[increasing][start_index_j] == color) {
				break;
			}
		}
		// then check if the start index isn't the same as our new increasing value
		// if it is, then set to_count equal to it and return so we don't go through the opposite way unnessesarily 
		if(increasing - 1 != start_index_i && !boo) {
			to_count = increasing;
			return to_count;
		}
	}
	boo = 0;
	// decreasing
	// make sure the initial decreasing index (one above the want to be placed piece) isn't out of range
	if(decreasing > -1 && decreasing < board->size) {
		// while the next piece isn't our color, continue searching for our end piece
		while(board->pieces[decreasing][start_index_j] != color) {
			// if the piece above it is empty, set index back to original starting point and break loop so it doesn't continue
			if(decreasing == -1 || board->pieces[decreasing][start_index_j] == empty) {
				to_count = start_index_i;
				boo = 1;
				break;
			}
			// decrease by one to look at the next piece
			decreasing--;
			// check to make sure we won't try to index somewhere we shouldn't, and check if the next piece is the player's
			// if either of these are true, break because we are done
			if(decreasing == -1) {
				boo = 1;
			}
			if(decreasing == -1 || board->pieces[decreasing][start_index_j] == color) {
				break;
			}
		}
		// check to make sure decreasing isn't the same as the starting index after running
		if(decreasing + 1 != start_index_i && !boo) {
			// set to_count to current index we want and return it
			to_count = decreasing;
			return to_count;
		}
	}
	// if the start_index_i didn't change, that means there is no legal move vertically, return -1
	return -1;
}

int horizontalValid(const BoardType *board, const int start_index_i, const int start_index_j, const piece color) {
	// check if there is a valid horizontal move - if it is, return the 
	// index of other piece closing off opponent's pieces. If not, return -1
	int increasing = start_index_j + 1;
	int decreasing = start_index_j - 1;
	int to_count = start_index_j;
	int boo = 0;

	// same logic as vertical, just switch the counting part to all moving the 
	// j index since it's horizontal and i stays the same
	if(increasing < board->size && increasing > -1) {
		// increasing first, while the piece to the right is not equal to the 
		// player's color, continue going to see if move is legal
		while(board->pieces[start_index_i][increasing] != color) {
			// if it's empty, break loop with to_count as the original index
			if(increasing == board->size || board->pieces[start_index_i][increasing] == empty) {
				to_count = start_index_j;
				boo = 1;
				break;
			}
			// increase counter to look at next piece to count up indexes
			increasing++;
			// if the counter goes off the board or hits the color we are looking for, break
			// when we break we will have the index we were looking for of the "end" piece
			if(increasing == board->size) {
				boo = 1;
			}
			if(increasing == board->size || board->pieces[start_index_i][increasing] == color) {
				break;
			}
		}
		// check to make sure the new index stored in increasing variable isn't the starting index
		if(increasing - 1 != start_index_j && !boo) {
			// if it is, return it
			to_count = increasing;
			return to_count;
		}
	}
	boo = 0;
	// decreasing, make sure the index of the piece to left are in the range
	if(decreasing > -1 && decreasing < board->size) {
		// while the next piece isn't the color we are looking for, keep looking
		while(board->pieces[start_index_i][decreasing] != color) {
			// if it's empty though, set to_count back to starting index
			if(decreasing == -1 || board->pieces[start_index_i][decreasing] == empty) {
				to_count = start_index_j;
				boo = 1;
				break;
			}
			// decrease to look at next piece
			decreasing--;
			// ensure that next piece isn't off the board and isn't the color we are looking for
			// if it is, break so we have the current index
			if(decreasing == -1) {
				boo = 1;
			}
			if(decreasing == -1 || board->pieces[start_index_i][decreasing] == color) {
				break;
			}
		}
		// check to make sure new index isn't the beginning index and return it
		if(decreasing + 1 != start_index_j && !boo) {
			to_count = decreasing;
			return to_count;
		}
	}
	// if the start_index_i didn't change, that means there is no legal move, return -1
	return -1;
}

// check if there is a valid diagonal move - if it is, return the 
// index of other piece closing off opponent's pieces. If not, return -1
indexType diagonalValid(const BoardType *board, const int x, const int y, const piece color) {
	int start_index_i = x; 
	int start_index_j = y; 
	indexType to_return;
	int boo = 0;

	int up = start_index_i - 1;
	int left = start_index_j - 1;
	int down = start_index_i + 1;
	int right = start_index_j + 1;
	
	// FIRST we do left up diagonal
	// same logic as vertical, just switch the counting part to all moving the 
	// j index since it's horizontal and i stays the same
	if(up < board->size && up > -1 && left < board->size && left > -1) {
		// increasing first, while the piece to the right is not equal to the 
		// player's color, continue going to see if move is legal
		while(board->pieces[up][left] != color) {
			// if it's empty, break loop with to_count as the original index
			if(board->pieces[up][left] == empty || up == -1 || left == -1) {
				to_return.i = start_index_i;
				to_return.j = start_index_j;
				boo = 1;
				break;
			}
			// increase counter to look at next piece to count up indexes
			up--;
			left--;
			// if the counter goes off the board or hits the color we are looking for, break
			// when we break we will have the index we were looking for of the "end" piece
			if(up == -1 || left == -1) {
				boo = 1;
			}
			if(up == -1 || left == -1 || board->pieces[up][left] == color) {
				break;
			}
		}
		if(up + 1 != start_index_i && left + 1 != start_index_j && !boo) {
			to_return.i = up;
			to_return.j = left;
			return to_return;
		}
		// check to make sure the new index stored in increasing variable isn't the starting index
	}
	boo = 0;
	up = start_index_i - 1;
	left = start_index_j - 1;
	// LEFT DOWN
	if(down < board->size && down > -1 && left < board->size && left > -1) {
		// increasing first, while the piece to the right is not equal to the 
		// player's color, continue going to see if move is legal
		while(board->pieces[down][left] != color) {
			// if it's empty, break loop with to_count as the original index
			if(board->pieces[down][left] == empty || down == board->size || left == -1) {
				to_return.i = start_index_i;
				to_return.j = start_index_j;
				boo = 1;
				break;
			}
			// increase counter to look at next piece to count up indexes
			down++;
			left--;
			// if the counter goes off the board or hits the color we are looking for, break
			// when we break we will have the index we were looking for of the "end" piece
			if(down == board->size || left == -1) {
				boo = 1;
			}
			if(down == board->size || left == -1 || board->pieces[down][left] == color) {
				break;
			}
		}
		if(down - 1 != start_index_i && left + 1 != start_index_j && !boo) {
			to_return.i = down;
			to_return.j = left;
			return to_return;
		}
	}
	left = start_index_j - 1;
	down = start_index_i + 1;
	boo = 0;
	// RIGHT UP
	if(up < board->size && up > -1 && right < board->size && right > -1) {
		// increasing first, while the piece to the right is not equal to the 
		// player's color, continue going to see if move is legal
		while(board->pieces[up][right] != color) {
			// if it's empty, break loop with to_count as the original index
			if(board->pieces[up][right] == empty || up == -1 || right == board->size) {
				to_return.i = start_index_i;
				to_return.j = start_index_j;
				boo = 1;
				break;
			}
			// increase counter to look at next piece to count up indexes
			up--;
			right++;
			// if the counter goes off the board or hits the color we are looking for, break
			// when we break we will have the index we were looking for of the "end" piece
			if(up == -1 || right == board->size) {
				boo = 1;
			}
			if(up == -1 || right == board->size || board->pieces[up][right] == color) {
				break;
			}
		}
		if(up + 1 != start_index_i && right - 1 != start_index_j && !boo) {
			to_return.i = up;
			to_return.j = right;
			return to_return;
		}
		// check to make sure the new index stored in increasing variable isn't the starting index
	}
	right = start_index_j + 1;
	up = start_index_i - 1;
	boo = 0;
	// // RIGHT DOWN
	if(down < board->size && down > -1 && right < board->size && right > -1) {
		// increasing first, while the piece to the right is not equal to the 
		// player's color, continue going to see if move is legal
		while(board->pieces[down][right] != color) {
			// if it's empty, break loop with to_count as the original index
			if(down == board->size || board->pieces[down][right] == empty || right == board->size) {
				to_return.i = start_index_i;
				to_return.j = start_index_j;
				boo = 1;
				break;
			}
			// increase counter to look at next piece to count up indexes
			down++;
			right++;
			// if the counter goes off the board or hits the color we are looking for, break
			// when we break we will have the index we were looking for of the "end" piece
			if(down == board->size || right == board->size) {
				boo = 1;
			}
			if(down == board->size || right == board->size || board->pieces[down][right] == color) {
				break;
			}
		}
		if(down - 1 != start_index_i && right - 1 != start_index_j && !boo) {
			to_return.i = down;
			to_return.j = right;
			return to_return;
		}
		// check to make sure the new index stored in increasing variable isn't the starting index
	}
	return to_return;
}

// check if there are ANY valid moves available for a player (piece will be a color)
// call all valid functions and if all of them return -1, no moves left
// returns 0 if no valid move, return 1 if valid move
int anyValidMoves(const BoardType *board, const piece color) {
	for(int i = 0; i < board->size; i++) {
		for(int j = 0; j < board->size; j++) {
			if(board->pieces[i][j] == empty) {
				if(horizontalValid(board, i, j, color) != -1) {
					printf("Horizontal valid\n");
					return 1;
				}
				if(verticalValid(board, i, j, color) != -1) {
					printf("Vertical valid\n");
					return 1;
				}
				if(diagonalValid(board, i, j, color).i != i && diagonalValid(board, i, j, color).j != j) {
					printf("Diagonal valid\n");
					return 1;
				}
			}
		}
	}
	return 0;
}

// flip the pieces in between the indexes
void horizontalFlip(const BoardType *board, const int start_index_j, const int end_index_j, const int index_i, const piece color) {
	int lower, higher;
	if(start_index_j < end_index_j) {
		lower = start_index_j;
		higher = end_index_j;
	}
	else {
		lower = end_index_j;
		higher = start_index_j;
	}

	for(int j = lower; j < higher; j++) {
		board->pieces[index_i][j] = color;
	}
}

// flip the pieces in between the indexes
void verticalFlip(const BoardType *board, const int start_index_i, const int end_index_i, const int index_j, const piece color) {
	int lower, higher;
	if(start_index_i < end_index_i) {
		lower = start_index_i;
		higher = end_index_i;
	}
	else {
		lower = end_index_i;
		higher = start_index_i;
	}

	for(int i = lower; i < higher; i++) {
		board->pieces[i][index_j] = color;
	}
}

// flip the pieces in between the indexes
void diagonalFlip(const BoardType *board, const indexType from, const indexType to, const piece color) {
	int loweri, lowerj, higheri, higherj;
	if(from.i < to.i) {
		int l = from.j;
		for(int k = from.i; k < to.i; k++) {
			if(from.j < to.j) {
				board->pieces[k][l] = color;
				l++;
			}
			if(from.j > to.j) {
				board->pieces[k][l] = color;
				l--;
			}
		}
	}
	if(from.i > to.i) {
		int l = from.j;
		for(int k = from.i; k > to.i; k--) {
			if(from.j < to.j) {
				board->pieces[k][l] = color;
				l++;
			}
			if(from.j > to.j) {
				board->pieces[k][l] = color;
				l--;
			}
		}
	}
	
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
	runGame(&board);
	// placePiece(&board, black, -1,-1);
	//printf("%d", verticalValid(&board, 1, 2,black));
	//printBoard(&board);

	cleanBoard(&board);
	return 0;
}