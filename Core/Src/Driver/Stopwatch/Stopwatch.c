/*
 * Stopwatch.c
 *
 *  Created on: 2022. 10. 9.
 *      Author: jhKim
 */

#include "Stopwatch.h"

typedef struct _stopwatch
{
	int stopwatch_msec;
	int stopwatch_sec;
	int stopwatch_min;
}Stopwatch;

int gTime = 0;

void Stopwatch_SetTime(int time)
{
	gTime = time;
}

void Stopwatch_DispTime()
{

}
