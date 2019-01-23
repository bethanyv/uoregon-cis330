#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
#include "clock.h"

void initClock(ClockType *clock) {
  /*8 for height. 6 for length of each line(including null byte of string)*/
  clock->zero = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->zero[i] = (char *) malloc(6 * sizeof(char));
  }
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
  clock->four[0] = "|   |";
  clock->four[1] = "|   |";
  clock->four[2] = "\\   |";
  clock->four[3] = " ---|";
  clock->four[4] = "    |";
  clock->four[5] = "    |";
  clock->four[6] = "    |";
  clock->four[7] = "    |";

  clock->five = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->five[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->five[0] = "-----";
  clock->five[1] = "|    ";
  clock->five[2] = "|    ";
  clock->five[3] = "\\___ ";
  clock->five[4] = "    |";
  clock->five[5] = "    |";
  clock->five[6] = "    |";
  clock->five[7] = "\\___/";
  
  clock->six = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->six[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->six[0] = "/---\\";
  clock->six[1] = "|    ";
  clock->six[2] = "|    ";
  clock->six[3] = "|---\\";
  clock->six[4] = "|   |";
  clock->six[5] = "|   |";
  clock->six[6] = "|   |";
  clock->six[7] = "\\___/";

  clock->seven = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->seven[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->seven[0] = "/---\\";
  clock->seven[1] = "    |";
  clock->seven[2] = "    |";
  clock->seven[3] = "    /";
  clock->seven[4] = " --- ";
  clock->seven[5] = "  /  ";
  clock->seven[6] = "  |  ";
  clock->seven[7] = "  |  ";

  clock->eight = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->eight[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->eight[0] = "/---\\";
  clock->eight[1] = "|   |";
  clock->eight[2] = "|   |";
  clock->eight[3] = "|___|";
  clock->eight[4] = "|   |";
  clock->eight[5] = "|   |";
  clock->eight[6] = "|   |";
  clock->eight[7] = "\\___/";

  clock->nine = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->nine[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->nine[0] = "/---\\";
  clock->nine[1] = "|   |";
  clock->nine[2] = "|   |";
  clock->nine[3] = "\\___|";
  clock->nine[4] = "    |";
  clock->nine[5] = "    |";
  clock->nine[6] = "    |";
  clock->nine[7] = "\\___/";

  clock->colon = (char **) malloc ( 8 * sizeof(char*));
  for (int i = 0; i < 8; i++) {
    clock->colon[i] = (char *) malloc(6 * sizeof(char));
  }
  clock->colon[0] = "     ";
  clock->colon[1] = "     ";
  clock->colon[2] = "  #  ";
  clock->colon[3] = "     ";
  clock->colon[4] = "     ";
  clock->colon[5] = "  #  ";
  clock->colon[6] = "     ";
  clock->colon[7] = "     ";

}

void printClock(const time_t cur_time, const ClockType *clock) {
  char* str_time = ctime(&cur_time);
  char** numbers[8];

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

int main(int argc, char** argv) 
{
  ClockType myclock;
  initClock(&myclock);
  
  time_t now = time(NULL);
  printClock(now, &myclock);

  cleanClock(&myclock);
  return 0;
}
