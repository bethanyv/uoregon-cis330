#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>

int getUserChoice() {
  int num;
  printf("Player 1: How many sticks do you take (1-3)? ");
  scanf("%d", &num);

  // if input is invalid, ask again
  while(num > 3 || num < 1) { 
    printf("Invalid input, please input a number (1-3): ");
    scanf("%d", &num);
  }
  return num;
}

int getComputerChoice(int current_sticks) {
    /* get a pseudo-random integer between 1 and 3 (inclusive) */
    int rand_choice = rand() % 3 + 1;

    if (rand_choice > current_sticks) return current_sticks;

    return rand_choice;
}


int main(int argc, char** argv) 
{
  int user, computer, number_sticks;

  srand (time(NULL));

  printf("Welcome to the game of sticks!\n");
  printf("How many sticks are there on the table initially (10-100)? ");
  scanf("%d", &number_sticks);

  /* if sticks on table initially don't fit in with range 10-100, 
  print error and quit*/
  if (number_sticks < 10 || number_sticks > 100) {
    printf("Error, number needs to be between 10 and 100 (inclusive)\n");
    exit(1);
  }

  // treat this as a boolean value to see who took the last stick
  int human_last_choice = 1;  
  
  // do following loop until some player picks up last of sticks
  while(number_sticks > 0) {
    printf("\nThere are %d sticks on the board.\n", number_sticks);
    int human_choice = getUserChoice();

    number_sticks = number_sticks - human_choice;
    human_last_choice = 1;

    // if human picked up last of sticks, break while loop
    if(number_sticks <= 0) {
      break;
    }

    // same steps for computer choice, update boolean value to 0 (imitate false)
    printf("\nThere are %d sticks on the board.\n", number_sticks);
    int computer_choice = getComputerChoice(number_sticks);
    printf("Computer selects %d\n", computer_choice);

    number_sticks = number_sticks - computer_choice;
    human_last_choice = 0;
  }

  // depending on boolean value, human either wins or loses!
  if (human_last_choice) {
    printf("You lose!\n");
  }
  else {
    printf("You win!\n");
  }

  return 0;
}
