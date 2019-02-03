#include "reversi.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

// Initialize the board
void initBoard(BoardType *board, const int size) {
	// allocate memory for the board depending on the size the player chose
	board->pieces = (piece **) malloc ( size * sizeof(piece*));
	for (int i = 0; i < size; i++) {
		board->pieces[i] = (piece *) malloc(size * sizeof(piece));
	}
	// initialize first player to black
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
	// count bad turns is for checking if both players haven't made a move consecutively, 
	// (no more valid moves for both)
	int count_bad_turns = 2;
	// while a turn has been made recently (even if one hasn't placed, the other can)
	// if it's 0, that means both players can't place, so exit
	while(count_bad_turns) {
		// if the board is full, break the loop
		if(fullBoard(board)) {
			break;
		}
		// if there are no valid moves, move to next player
		if(!anyValidMoves(board, board->turn)) {
			std::cout << "No valid moves for Player" << board->turn << "\n";
			switchPlayer(board);
			// decrement bad turns so we know one has been made
			count_bad_turns--;
			continue;
		}

		printBoard(board);

		std::cout << "\nPlayer " << board->turn << " turn, input 2 numbers (0-" << board->size - 1 << ") for row and column: ";
		std::cin >> x >> y;

		// while the input is not within the board size, ask again
		while(x < 0 || x > board->size - 1 || y < 0 || y > board->size - 1) {
			std::cout << "\nInvalid input, please input again (Too big or small of an index): ";
			std::cin >> x >> y;
		}
		// while the specified area is full, ask again
		while(board->pieces[x][y] != empty) {
			std::cout << "\nInvalid input, please input again (Full spot): ";
			std::cin >> x >> y;
		}

		// treat boo like a boolean, if a piece is placed, set boo to "true" (1)
		// if a piece couldn't be placed there, it will be set to "false" (0)
		int boo = placePiece(board, board->turn, x, y);
		// while a piece wan't placed and there are still valid moves, ask for a different input
		while(!boo && anyValidMoves(board, board->turn)) {
			std::cout << "\nInvalid move! Please try again (there are available moves!): ";
			std::cin >> x >> y;
			// if outside the board size, ask again
			if(x < 0 || x > board->size - 1 || y < 0 || y > board->size - 1) {
				continue;
			}
			// if it's full, ask again
			if(board->pieces[x][y] != empty) {
				continue;
			}
			if(!anyValidMoves(board,board->turn)) {
				switchPlayer(board);
				break;
			}
			boo = placePiece(board, board->turn, x, y);
		}
		// if there was a move made, reset count bad turns so the game is on track again and switch player turn
		if(boo) {
			count_bad_turns = 2;
			switchPlayer(board);
		}
	}
	// once out of the while loop, the game is over, print board again
	// and print finishing scores and who wins
	printBoard(board);
	std::cout << "\nGAME OVER!\n";
	int player1_score = countBlack(board);
	int player2_score = countWhite(board);
	std::cout << "\nPlayer 1 > " << player1_score;
	std::cout << "\nPlayer 2 > " << player2_score << "\n";
	if(player1_score > player2_score) {
		std::cout << "\nPLAYER 1 WINS\n";
	}
	else{
		std::cout << "\nPLAYER 2 WINS!!\n";
	}
} 

// switch the player's turn
void switchPlayer(BoardType *board) {
	if(board->turn == white) {
		board->turn = black;
	}
	else{
		board->turn = white;
	}
}

// will say if the board is full. Returns 1 if full, else will return 0
int fullBoard(BoardType *board) {
	// if a empty spot is found, return 0
	for(int i = 0; i < board->size; i++) {
		for(int j = 0; j < board->size; j++) {
			if(board->pieces[i][j] == empty) {
				return 0;
			}
		}
	}
	return 1;
}

// place the piece where the user specified by checking if it's valid and flipping 
// if a piece is placed, return 1. Else return 0
int placePiece(const BoardType *board, const piece color, const int x, const int y) {
	int boo = 0; // 0 if nothing has been valid. 1 if something is valid (like a boolean)
	// struct for containing i and j indexes of a spot
	indexType from;
	from.i = x;
	from.j = y;
	// check all if valids
	int vertical_valid = verticalValid(board, x, y, color);
	int horizontal_valid = horizontalValid(board, x, y, color);
	indexType left_diagonal_valid = leftUpDiagonalValid(board, x, y, color);
	indexType right_diagonal_valid = rightUpDiagonalValid(board, x, y, color);

	// if vertically valid, flip those pieces vertically and set boo = 1 (true)
	if(vertical_valid != -1) {
		verticalFlip(board, x, vertical_valid, y, color);
		boo = 1;
	}
	// if horizontal valid, flip horizontal pieces, set boo = 1
	if(horizontal_valid != -1) {
		horizontalFlip(board, y, horizontal_valid, x, color);
		boo = 1;
	}
	// if diagonal valid at the indexes i and j are not equal to original (if it changed,
	// which means there is a valid diagonal place) flip
	if(left_diagonal_valid.i != x && left_diagonal_valid.j != y) {
		diagonalFlip(board, left_diagonal_valid, from, color);
		boo = 1;
	}
	if(right_diagonal_valid.i != x && right_diagonal_valid.j != y) {
		diagonalFlip(board, right_diagonal_valid, from, color);
		boo = 1;
	}
	// if something was valid, place the piece that was desired (which
	// we know is valid because boo = 1, which means we were able to flip
	// return 1 if a piece was placed
	if(boo) {
		board->pieces[x][y] = color;
		return 1;
	}
	// otherwise return 0
	else {
		return 0;
	}
}

// set the beginning pieces in the center
void setPieces(BoardType *board) {
	// to set pieces in middle, find size/2 and place at 
	// (size / 2) and (size / 2) - 1 in both x and y coordinates
	// will be offset for odd board sizes
	int size = board->size;
	board->pieces[size/ 2][size / 2] = white;
	board->pieces[(size / 2) - 1][size / 2] = black;
	board->pieces[(size / 2) - 1][(size / 2) - 1] = white;
	board->pieces[size / 2][(size / 2) - 1] = black;
}

// Print the board in a easy to read way (with indexes along axiis)
void printBoard(const BoardType *board) {
	// print scores every time board is printed
	std::cout << "\nPlayer 1 > " << countBlack(board) << "     Player 2 > " << countWhite(board) " \n\n";

	// print initial space for empty corner before indexes
	std::cout << "  ";
	// print the j indexes across the top
	for(int k = 0; k < board->size; k++) {
		std::cout << k << " ";
	}
	// new line before printing every line of board with i index
	std::cout << "\n";
	for(int i = 0; i < board->size; i++) {
		// start with printing i so players know where the index is
		std::cout << i << " ";
		// iterate through each piece in the i row to print them
		for(int j = 0; j < board->size; j++) {
			piece x = board->pieces[i][j];
			// if they are black, print X; if white, print O; if empty, print .
			if(x == black) {
				std::cout << "X ";
			}
			else if(x == white) {
				std::cout << "O ";
			}
			else {
				std::cout << ". ";
			}
		}
		// new line before next row
		std::cout << "\n";
	}
}

int verticalValid(const BoardType *board, const int start_index_i, const int start_index_j, const piece color) {
	// check if there is a valid vertical move - if it is, return the 
	// i index of ending piece that closes space we want to flip
	// (because for vertical, j is the same as initial index) 
	// If no legal move, return -1

	int increasing = start_index_i + 1;
	int decreasing = start_index_i - 1;
	int to_count = start_index_i;
	int boo = 0;

	// to ensure we don't get a seg fault and index to the wrong location
	if(increasing < board->size && increasing > -1) {
		// increasing first, while the spot directly below the spot of the
		// selected space isn't the color of the player making the move
		while(increasing == board->size || board->pieces[increasing][start_index_j] != color) {
			// if the spot is empty though, set the count to the beginning index to try decreasing instead
			// break this loop so it doesn't continue
			if(board->pieces[increasing][start_index_j] == empty) {
				to_count = start_index_i;
				boo = 1;
				break;
			}
			// increase index going vertically down to look at next spot 
			increasing++;
			// if increasing went off the board, or we hit another of out pieces, break
			// with boo as 1 so we don't update returning index
			if(increasing == board->size) {
				boo = 1;
			}
			// if we hit the "end" (the color we want), break
			if(increasing == board->size || board->pieces[increasing][start_index_j] == color) {
				break;
			}
		}
		// then check if the start index isn't the same as our new increasing value (not the piece we started with)
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
			// if the counter goes off the board, break
			// when we break we will have the index we were looking for of the "end" piece
			if(increasing == board->size) {
				boo = 1;
			}
			// if color piece we want is found, break
			if(board->pieces[start_index_i][increasing] == color) {
				break;
			}
		}
		// check to make sure the new index stored in increasing variable isn't the starting index and return
		if(increasing - 1 != start_index_j && !boo) {
			to_count = increasing;
			return to_count;
		}
	}
	// reset boo for decreasing. Will only get here if no horizontal increasing was found
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
			// ensure that next piece isn't off the board
			// if it is, break so we have the current index
			if(decreasing == -1) {
				boo = 1;
			}
			// if we find our other piece, break
			if(decreasing == -1 ||  board->pieces[start_index_i][decreasing] == color) {
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
// in both leftUp and rightUp function

indexType leftUpDiagonalValid(const BoardType *board, const int x, const int y, const piece color) {
	// check left up and right down diagonal (so we can fill in several diagonals in a big game board)
	int start_index_i = x; 
	int start_index_j = y; 
	// create an indexType to return index of endpoint in diagonal
	indexType to_return;
	// use as boolean value to see if there is an incorrect index
	int boo = 0;

	// starting index values to start looking
	int up = start_index_i - 1;
	int left = start_index_j - 1;
	int down = start_index_i + 1;
	int right = start_index_j + 1;

	// First we do left up diagonal
	// same logic as vertical, just switch the counting part to all moving the 
	// indexes by one. In left up, undex by decreasing j and decreasing i for correct indexes
	if(up < board->size && up > -1 && left < board->size && left > -1) {
		// increasing first, while the piece to the right is not equal to the 
		// player's color, continue going to see if move is legal
		while(board->pieces[up][left] != color) {
			// if it's empty, break loop with to_count as the original index
			// update boo so we don't change indexes later - make 1 to mark difference
			if(up == -1 || left == -1 || board->pieces[up][left] == empty) {
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
				to_return.i = start_index_i;
				to_return.j = start_index_j;
				boo = 1;
			}
			// if we hit the color we want, break
			if(up == -1 || left == -1 || board->pieces[up][left] == color) {
				break;
			}
		}
		// if the previous piece isn't the original and no incorrect places hit
		// update the returned indexes to the new values up and left
		if(up + 1 != start_index_i && left + 1 != start_index_j && !boo) {
			to_return.i = up;
			to_return.j = left;
			return to_return;
		}
	}
	// "reset" boo for next part, might've been "incorrect move" up above, so reset for right down
	boo = 0;
	to_return.i = start_index_i;
	to_return.j = start_index_j;
	// right down diagonal
	// same logic as left up, index by increasing j and increasing i for correct indexes
	if(down < board->size && down > -1 && right < board->size && right > -1) {
		// increasing first, while the piece to the right is not equal to the 
		// player's color, continue going to see if move is legal
		while(board->pieces[down][right] != color) {
			// if it's empty, break loop with to_count as the original index
			if(down == board->size || right == board->size || board->pieces[down][right] == empty) {
				to_return.i = start_index_i;
				to_return.j = start_index_j;
				boo = 1;
				break;
			}
			// increase counter to look at next piece to count up indexes
			down++;
			right++;
			// if the counter goes off the board, break
			// when we break we will have the index we were looking for of the "end" piece
			if(down == board->size || right == board->size) {
				to_return.i = start_index_i;
				to_return.j = start_index_j;
				boo = 1;
			}
			// if we hit the color, we will have the index we were looking for of the "end" piece
			if(down == board->size || right == board->size || board->pieces[down][right] == color) {
				break;
			}
		}
		// if we aren't off the board and haven't made an "incorrect spot look"
		// and that we aren't in the starting index points, update
		// returned indexes to down and right
		if(down - 1 != start_index_i && right - 1 != start_index_j && !boo) {
			to_return.i = down;
			to_return.j = right;
			return to_return;
		}
	}
	// return initial values if doesn't hit earlier return
	return to_return;
}

indexType rightUpDiagonalValid(const BoardType *board, const int x, const int y, const piece color) {
	// check right up and left down diagonal (so we can fill in several diagonals in a big game board)
	int start_index_i = x; 
	int start_index_j = y; 
	// so we can return both indexes needed for placing the piece
	indexType to_return;
	int boo = 0;

	int up = start_index_i - 1;
	int left = start_index_j - 1;
	int down = start_index_i + 1;
	int right = start_index_j + 1;

	// LEFT DOWN - same logic as other function, increasing down to go down, decrease left to go left
	if(down < board->size && down > -1 && left < board->size && left > -1) {
		// increasing first, while the piece to the right is not equal to the 
		// player's color, continue going to see if move is legal
		while(board->pieces[down][left] != color) {
			// if it's empty, break loop with to_count as the original index
			if(down == board->size || left == -1 || board->pieces[down][left] == empty) {
				to_return.i = start_index_i;
				to_return.j = start_index_j;
				boo = 1;
				break;
			}
			// increase counter to look at next piece to count up indexes
			down++;
			left--;
			// if the counter goes off the board, break
			if(down == board->size || left == -1) {
				to_return.i = start_index_i;
				to_return.j = start_index_j;
				boo = 1;
			}
			// when we break we will have the index we were looking for of the "end" piece
			if(down == board->size || left == -1 || board->pieces[down][left] == color) {
				break;
			}
		}
		// ensure we aren't looking at the initial piece we started with
		// and didn't make an "incorrect look" and update returned values to 
		// down and left
		if(down - 1 != start_index_i && left + 1 != start_index_j && !boo) {
			to_return.i = down;
			to_return.j = left;
			return to_return;
		}
	}
	// "reset" boo so it doesn't interfere when looking through right up
	boo = 0;
	to_return.i = start_index_i;
	to_return.j = start_index_j;
	// RIGHT UP - same logic as above, just decrease up to keep going up and
	// increase right to keep going right
	if(up < board->size && up > -1 && right < board->size && right > -1) {
		// increasing first, while the piece to the right is not equal to the 
		// player's color, continue going to see if move is legal
		while(board->pieces[up][right] != color) {
			// if it's empty, break loop with to_count as the original index
			if(up == -1 || right == board->size || board->pieces[up][right] == empty) {
				to_return.i = start_index_i;
				to_return.j = start_index_j;
				boo = 1;
				break;
			}
			// increase counter to look at next piece to count up indexes
			up--;
			right++;
			// if the counter goes off the board, break
			if(up == -1 || right == board->size) {
				to_return.i = start_index_i;
				to_return.j = start_index_j;
				boo = 1;
			}
			// when we break we will have the index we were looking for of the "end" piece
			if(up == -1 || right == board->size || board->pieces[up][right] == color) {
				break;
			}
		}
		// as long as right and up aren't the initial piece looked at,
		// update returned values to up and right
		if(up + 1 != start_index_i && right - 1 != start_index_j && !boo) {
			to_return.i = up;
			to_return.j = right;
			return to_return;
		}
	}
	// return initial values if doesn't hit earlier return
	return to_return;
}

// check if there are ANY valid moves available for a player (piece will be a color of player playing)
// call all valid functions and if all of them return -1 which means no moves left
// if there is a valid move, return; returns 0 if no valid move
int anyValidMoves(const BoardType *board, const piece color) {
	for(int i = 0; i < board->size; i++) {
		for(int j = 0; j < board->size; j++) {
			// as long as the spot looking at is empty, check that space for the certain color
			if(board->pieces[i][j] == empty) {
				if(horizontalValid(board, i, j, color) != -1) {
					return 1;
				}
				if(verticalValid(board, i, j, color) != -1) {
					return 1;
				}
				if(leftUpDiagonalValid(board, i, j, color).i != i && leftUpDiagonalValid(board, i, j, color).j != j) {
					return 1;
				}
				if(rightUpDiagonalValid(board, i, j, color).i != i && rightUpDiagonalValid(board, i, j, color).j != j) {
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
	// lower and higher are for iterating through using ++, just start at the lower number for the for loop
	if(start_index_j < end_index_j) {
		lower = start_index_j;
		higher = end_index_j;
	}
	else {
		lower = end_index_j;
		higher = start_index_j;
	}
	// for each index wanted, flip the pieces, index_i doesn't change because vertically no i index changes
	for(int j = lower; j < higher; j++) {
		board->pieces[index_i][j] = color;
	}
}

// flip the pieces in between the indexes
void verticalFlip(const BoardType *board, const int start_index_i, const int end_index_i, const int index_j, const piece color) {
	int lower, higher;
	// lower and higher are for iterating through using ++, just start at the lower number for the for loop
	if(start_index_i < end_index_i) {
		lower = start_index_i;
		higher = end_index_i;
	}
	else {
		lower = end_index_i;
		higher = start_index_i;
	}

	for(int i = lower; i < higher; i++) {
		// for each index wanted, flip the pieces, index_j doesn't change because vertically no j index changes
		board->pieces[i][index_j] = color;
	}
}

// flip the pieces in between the indexes
void diagonalFlip(const BoardType *board, const indexType from, const indexType to, const piece color) {
	// if the from point i is less than the to point i, iterate with ++ on i (moving down board)
	if(from.i < to.i) {
		// l for keeping track of j, don't want another for loop because then it'll fill too many places
		int l = from.j;
		for(int k = from.i; k < to.i; k++) {
			// if from point j is less than to point j (the from piece is to the left of to), 
			// iterate j with ++ since going right
			if(from.j < to.j) {
				board->pieces[k][l] = color;
				l++;
			}
			// otherwise if from point j is greater then to point j (the from piece is to the right of to),
			// iterate with j -- since we are going left
			if(from.j > to.j) {
				board->pieces[k][l] = color;
				l--;
			}
		}
	}
	// if the from point i is greater than the to point i, iterate with -- on i (moving up board)
	if(from.i > to.i) {
		int l = from.j;
		for(int k = from.i; k > to.i; k--) {
			// if from point j is less than to point j (the from piece is to the left of to), 
			// iterate j with ++ since going right
			if(from.j < to.j) {
				board->pieces[k][l] = color;
				l++;
			}
			// otherwise if from point j is greater then to point j (the from piece is to the right of to),
			// iterate with j -- since we are going left
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
	// iterate through board and count any black pieces found
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
	// iterate through board and count any white pieces found
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
	// free the array that held all the pieces
	free(board->pieces);
}