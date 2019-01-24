#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
#include "clock.h"

int main(int argc, char** argv) {
	// initialize a clock
	ClockType myclock;
	initClock(&myclock);

	// grab the current time
	time_t now = time(NULL);
	// print the clock with the current time
	printClock(now, &myclock);

	// free the memory
	cleanClock(&myclock);
	return 0;
}