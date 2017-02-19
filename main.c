#ifndef __INCLUDE_TIMER_H__
#define __INCLUDE_TIMER_H__

#include "elev.h"
#include <stdio.h>
#include "timer.h"
//#include "esm.h"

//static void em_poll_order_buttons( void );		//loop through 
static void em_poll_floor_indicators( void );
static void em_poll_stop_button( void );
static void em_poll_timer( void );

static bool waiting_for_timer = false;		//used to check if timer is started. if started: dont move

int main() {
	//initialize and exit if error occurs
    if( !esm_initialize_elevator() ){
    	return 1;
    }
    printf("Press STOP button to stop elevator and exit program.\n");
    

	
    while (1) {
		em_poll_stop_button();	
        em_poll_timer();
		em_poll_floor_indicators();

	label: end_main_loop;
    }

	
    return 0;
}

//stop sequence not tested!

static int prev_stop_button_state = NOT_PRESSED;

static void em_poll_stop_button(){
	if ( elev_get_stop_signal() == PRESSED && prev_stop_button_status == NOT_PRESSED){
		printf("Test stop function\n");
		esm_stop_button_pressed();
		prev_stop_button_state = PRESSED;
		goto end_main_loop;
	}
	else if (elev_get_stop_signal() == PRESED && prev_stop_button_state == PRESSED){		//knapp holdes inne	
		goto end_main_loop;
	}
	else if (elev_get_stop_signal() == NOT_PRESED && prev_stop_button_state == PRESSED){		//knapp slippes
		esm_stop_button_released();
		waiting_for_timer = true;
		prev_stop_button_state = NOT_PRESSED;		

	}
}

static void em_poll_timer(){
	if ( timer_is_timed_out( 3 ) ){
		esm_door_closed();
		printf( "Door closed\n" );
		waiting_for_timer = false;
	}
}


static void em_poll_floor_indicators(){
	if( elev_get_floor_sensor_signal() != -1 ){
		esm_floor_passed( elev_get_floor_sensor_signal() );
		printf( "Floor %d passed\n", elev_get_floor_sensor_signal() + 1 );		
	}
}

//static void em_poll_order_buttons()

#endif // #ifndef __INCLUDE_TIMER_H__
