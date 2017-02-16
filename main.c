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

int main() {
    if( !esm_initialize_elevator() ){
    	return 1;
    }
    printf("Press STOP button to stop elevator and exit program.\n");
    
    while (1) {
        // Change direction when we reach top/bottom floor
        if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
            elev_set_motor_direction(DIRN_DOWN);
        } else if (elev_get_floor_sensor_signal() == 0) {
            elev_set_motor_direction(DIRN_UP);
        }
	
        em_poll_timer();
	em_poll_floor_indicators();

        if (elev_get_stop_signal()) {
            elev_set_motor_direction( DIRN_STOP );
            break;
        }
    }

    return 0;
}


//int prev_stop_button_state
//static void em_poll_stop_button(){
	//if ( elev_get_stop_signal() == PRESSED && prev_stop_button_status == NOT_PRESSED){
		printf("Test stop function\n");
	//}
//}

static void em_poll_timer(){
	if ( timer_is_timed_out( 3 ) ){
		esm_door_closed();
		printf( "Door closed\n" );	
	}
}

//static void em_poll_order_buttons()
static void em_poll_floor_indicators(){
	if( elev_get_floor_sensor_signal() != -1 ){
		esm_floor_passed( elev_get_floor_sensor_signal() );
		printf( "Floor %d passed\n", elev_get_floor_sensor_signal() + 1 );		
	}
}

#endif // #ifndef __INCLUDE_TIMER_H__
