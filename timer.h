//#ifndef __TIMER_H__
//#define __TIMER_H__
#include <stdio.h>
#include <sys/time.h>

typedef int bool;
#define true 1
#define false 0

static double start_time = 0;
static double stop_time = 0;
//git bash test
void timer_start( void );
bool timer_is_timed_out( int sec );	//Resets timer at the same time

//#endif
