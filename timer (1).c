#include "timer.h"


static double timer_get_wall_time( void ){
	struct timeval time;
	gettimeofday( &time, NULL );
	return ( double )time.tv_sec + ( double )time.tv_usec * .000001;
}

void timer_start( void ){
	start_time = timer_get_wall_time();
}

static void stop_timer( void ){
	stop_time = timer_get_wall_time();
}

static double read_timer ( void ){
	stop_timer();
	return stop_time - start_time;
}

bool timer_is_timed_out( int sec ){
	if ( read_timer() >= sec ){
		//printf( "Stop_time = %f\n", read_timer() );
		start_time = stop_time;				//resets time
		return true;
	}
	
	return false;
}


