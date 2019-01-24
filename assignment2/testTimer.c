#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
#include "timer.h"

int main(int argc, char** argv) {
	// initalize a clock and call init
	ClockType myclock;
	initClock(&myclock);
	int min;
	int sec;

	// get user input
	printf("How long should the timer run (MM:SS)? ");
	scanf("%d:%d", &min, &sec);

	// call init with the minutes and seconds and initalized clock
	initTimer(&myclock, min, sec);

	// free the timer
	cleanTimer(&myclock);
	return 0;
}