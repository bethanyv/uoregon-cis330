#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
#include "clock.h"

void initClock(ClockType *clock) {
  /* 8 for height. 6 for length of each line (including null byte of string)*/
  //allocated for each 2d array
  clock->zero = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->zero[i] = (char *) malloc(6 * sizeof(char));
  }
  // use strcpy because I malloced, don't want to overwrite, but want to write into 
  // the memory I allocated
  strcpy(clock->zero[0], "/---\\");
  strcpy(clock->zero[1], "|   |");
  strcpy(clock->zero[2], "|   |");
  strcpy(clock->zero[3], "|   |");
  strcpy(clock->zero[4], "|   |");
  strcpy(clock->zero[5], "|   |");
  strcpy(clock->zero[6], "|   |");
  strcpy(clock->zero[7], "\\___/");

  clock->one = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->one[i] = (char *) malloc(6 * sizeof(char));
  }
  strcpy(clock->one[0], " /|  ");
  strcpy(clock->one[1], "  |  ");
  strcpy(clock->one[2], "  |  ");
  strcpy(clock->one[3], "  |  ");
  strcpy(clock->one[4], "  |  ");
  strcpy(clock->one[5], "  |  ");
  strcpy(clock->one[6], "  |  ");
  strcpy(clock->one[7], " _|_ ");

  clock->two = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->two[i] = (char *) malloc(6 * sizeof(char));
  }
  strcpy(clock->two[0], " /'\\ ");
  strcpy(clock->two[1], "   | ");
  strcpy(clock->two[2], "   | ");
  strcpy(clock->two[3], "  /  ");
  strcpy(clock->two[4], " /   ");
  strcpy(clock->two[5], "|    ");
  strcpy(clock->two[6], "|    ");
  strcpy(clock->two[7], "|___ ");

  clock->three = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->three[i] = (char *) malloc(6 * sizeof(char));
  }
  strcpy(clock->three[0], "----\\");
  strcpy(clock->three[1], "    |");
  strcpy(clock->three[2], "   / ");
  strcpy(clock->three[3], "  -  ");
  strcpy(clock->three[4], "   \\ ");
  strcpy(clock->three[5], "    |");
  strcpy(clock->three[6], "    |");
  strcpy(clock->three[7], "____/");

  clock->four = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->four[i] = (char *) malloc(6 * sizeof(char));
  }
  strcpy(clock->four[0], "|   |");
  strcpy(clock->four[1], "|   |");
  strcpy(clock->four[2], "\\   |");
  strcpy(clock->four[3], " ---|");
  strcpy(clock->four[4], "    |");
  strcpy(clock->four[5], "    |");
  strcpy(clock->four[6], "    |");
  strcpy(clock->four[7], "    |");

  clock->five = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->five[i] = (char *) malloc(6 * sizeof(char));
  }
  strcpy(clock->five[0], "-----");
  strcpy(clock->five[1], "|    ");
  strcpy(clock->five[2], "|    ");
  strcpy(clock->five[3], "\\___ ");
  strcpy(clock->five[4], "    |");
  strcpy(clock->five[5], "    |");
  strcpy(clock->five[6], "    |");
  strcpy(clock->five[7], "\\___/");
  
  clock->six = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->six[i] = (char *) malloc(6 * sizeof(char));
  }
  strcpy(clock->six[0], "/---\\");
  strcpy(clock->six[1], "|    ");
  strcpy(clock->six[2], "|    ");
  strcpy(clock->six[3], "|---\\");
  strcpy(clock->six[4], "|   |");
  strcpy(clock->six[5], "|   |");
  strcpy(clock->six[6], "|   |");
  strcpy(clock->six[7], "\\___/");

  clock->seven = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->seven[i] = (char *) malloc(6 * sizeof(char));
  }
  strcpy(clock->seven[0], "/---\\");
  strcpy(clock->seven[1], "    |");
  strcpy(clock->seven[2], "    |");
  strcpy(clock->seven[3], "    /");
  strcpy(clock->seven[4], " --- ");
  strcpy(clock->seven[5], "  /  ");
  strcpy(clock->seven[6], "  |  ");
  strcpy(clock->seven[7], "  |  ");

  clock->eight = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->eight[i] = (char *) malloc(6 * sizeof(char));
  }
  strcpy(clock->eight[0], "/---\\");
  strcpy(clock->eight[1], "|   |");
  strcpy(clock->eight[2], "|   |");
  strcpy(clock->eight[3], "|___|");
  strcpy(clock->eight[4], "|   |");
  strcpy(clock->eight[5], "|   |");
  strcpy(clock->eight[6], "|   |");
  strcpy(clock->eight[7], "\\___/");

  clock->nine = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->nine[i] = (char *) malloc(6 * sizeof(char));
  }
  strcpy(clock->nine[0], "/---\\");
  strcpy(clock->nine[1], "|   |");
  strcpy(clock->nine[2], "|   |");
  strcpy(clock->nine[3], "\\___|");
  strcpy(clock->nine[4], "    |");
  strcpy(clock->nine[5], "    |");
  strcpy(clock->nine[6], "    |");
  strcpy(clock->nine[7], "\\___/");

  clock->colon = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->colon[i] = (char *) malloc(6 * sizeof(char));
  }
  strcpy(clock->colon[0], "     ");
  strcpy(clock->colon[1], "     ");
  strcpy(clock->colon[2], "  #  ");
  strcpy(clock->colon[3], "     ");
  strcpy(clock->colon[4], "     ");
  strcpy(clock->colon[5], "  #  ");
  strcpy(clock->colon[6], "     ");
  strcpy(clock->colon[7], "     ");
}

void printClock(const time_t cur_time, const ClockType *clock) {
  // grab the time in a string
  char* str_time = ctime(&cur_time);
  // initialize character array for the digits needed (including colon)
  char** numbers[8];

  // go through all the numbers for time we want
  // depending on the digit/colon it holds
  // assign that to the clock ascii digit
  for(int k = 0; k < 8; k++) {
    if(str_time[k+11] == '0') {
      numbers[k] = clock->zero;
    }
    else if(str_time[k+11] == '1') {
      numbers[k] = clock->one;
    }
    else if(str_time[k+11] == '2') {
      numbers[k] = clock->two;
    }
    else if(str_time[k+11] == '3') {
      numbers[k] = clock->three;
    }
    else if(str_time[k+11] == '4') {
      numbers[k] = clock->four;
    }
    else if(str_time[k+11] == '5') {
      numbers[k] = clock->five;
    }
    else if(str_time[k+11] == '6') {
      numbers[k] = clock->six;
    }
    else if(str_time[k+11] == '7') {
      numbers[k] = clock->seven;
    }
    else if(str_time[k+11] == '8') {
      numbers[k] = clock->eight;
    }
    else if(str_time[k+11] == '9') {
      numbers[k] = clock->nine;
    }
    else {
      numbers[k] = clock->colon;
    }
  }

  // print the upper part of all the numbers (ascii) and then next iteration,
  // print a level down (so it's a horizontal clock)
  for(int i = 0; i < 8; i++) {
    printf("%s", numbers[0][i]);
    printf("%s", numbers[1][i]);
    printf("%s", numbers[2][i]);
    printf("%s", numbers[3][i]);
    printf("%s", numbers[4][i]);
    printf("%s", numbers[5][i]);
    printf("%s", numbers[6][i]);
    printf("%s", numbers[7][i]);
    printf("\n");
  }
}

// clean the inner arrays of the clock's digits
void cleanClock(ClockType *clock) {
  for(int i = 0; i < 8; i++) {
    free(clock->zero[i]);
    free(clock->one[i]);
    free(clock->two[i]);
    free(clock->three[i]);
    free(clock->four[i]);
    free(clock->five[i]);
    free(clock->six[i]);
    free(clock->seven[i]);
    free(clock->eight[i]);
    free(clock->nine[i]);
    free(clock->colon[i]);
  }
  // free the array that held all the digit lines of the clock
  free(clock->zero);
  free(clock->one);
  free(clock->two);
  free(clock->three);
  free(clock->four);
  free(clock->five);
  free(clock->six);
  free(clock->seven);
  free(clock->eight);
  free(clock->nine);
  free(clock->colon);
}
