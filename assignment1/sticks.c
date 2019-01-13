#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>

int getUserChoice() {
  int num;
  printf("Player 1: How many sticks do you take (1-3)? ");
  scanf("%d", &num);
  while(num > 3 || num < 1) {
    printf("Invalid input, please input a number (1-3): ");
    scanf("%d", &num);
  }
  return num;
  /* TODO: Prompt the user "Player 1: How many sticks do you take (1-3)?" and return
     an integer. Check that the value is valid (1, 2, or 3) and print an error if 
     is not, then ask again until a valid number is entered. You can exit the program with
     exit(1);
  */
}

int getComputerChoice(int current_sticks) {

    /* get a pseudo-random integer between 1 and 3 (inclusive) */
    int rand_choice = rand() % 3 + 1;

    if (rand_choice > current_sticks) return current_sticks;

    /* Optionally replace with additional logic for the computer's strategy */

    return rand_choice;
}


int main(int argc, char** argv) 
{
  int user, computer, number_sticks;


  srand (time(NULL)); /* for reproducible results, you can call srand(1); */

  printf("Welcome to the game of sticks!\n");
  printf("How many sticks are there on the table initially (10-100)? ");
  scanf("%d", &number_sticks);

  /* TODO: check that num_sticks is between 10 and 100 (inclusive) and print 
    an error and exit, if it is not. */
  if (number_sticks < 10 || number_sticks > 100) {
    printf("Error, number needs to be between 10 and 100 (inclusive)\n");
    exit(1);
  }

  /* TODO: Main game loop:
    While some sticks remain:
      1. Human: Get number of sticks by calling getUserChoice
      2. Computer: get number of sticks by calling getComputerChoice
      3. Output the computer's choice, e.g., "Computer selects 3."
      3. Update number_sticks
      4. Print the current number of sticks, e.g., "There are 2 sticks on the board."
    After all the sticks are gone, output the result of the game, 
    e.g., "Computer wins." or "Computer loses."
   */
  int human_last_choice = 1;
  while(number_sticks > 0) {
    printf("\nThere are %d sticks on the board.\n", number_sticks);
    int human_choice = getUserChoice();
    number_sticks = number_sticks - human_choice;
    human_last_choice = 1;
    if(number_sticks == 0) {
      break;
    }

    printf("\nThere are %d sticks on the board.\n", number_sticks);
    int computer_choice = getComputerChoice(number_sticks);
    printf("Computer selects %d\n", computer_choice);
    number_sticks = number_sticks - computer_choice;
    human_last_choice = 0;
  }

  if (human_last_choice) {
    printf("You lose!\n");
  }
  else {
    printf("You win!\n");
  }

  return 0;
}
