#include <stdio.h>
#include "esm.h"




enum esm_states{
		INITIALIZE = 0,
		MOVING,
		SERVICING_FLOOR,
		IDLE,
		EMERGENCY_STOP
};

enum floors{
		FLOOR1 = 0,
		FLOOR2,
		FLOOR3,
		FLOOR4
};

enum floors_between{
		FLOOR1_2 = 0,
		FLOOR2_3,
		FLOOR3_4		
};
///----------States----------///
static int esm_state = -1;	
static int floor_number = -1;
static int motor_direction = 0;
static int floor_between = -1;
///--------------------------///

	
int esm_initialize_elevator(){
	// Initialize hardware
    	if (!elev_init()) {
        	printf("Unable to initialize elevator hardware!\n");
        	return 0;
    	}
	do{
		elev_set_motor_direction( DIRN_DOWN );	
	} while( elev_get_floor_sensor_signal() == -1 ); //-1 == nofloor
	elev_set_motor_direction( DIRN_STOP );	
	esm_state = INITIALIZE;	
	floor_number = elev_get_floor_sensor_signal();
	printf( "Current floor = floor%d\n", floor_number );
	elev_set_floor_indicator( floor_number );	
	return 1;
}

void esm_door_closed(){
	elev_set_door_open_lamp(0);
}

void esm_open_door(){
	elev_set_door_open_lamp(1);
	timer_start();
}

void esm_floor_passed( int floor ){
	//dummy function for testing
}


void esm_stop_button_pressed(){
	printf(" Stop button is pressed!\n" );
	//dummy function for testing
}
void esm_stop_button_released(){
	printf(" Stop button is released!\n" );
	//dummy function for testing
}





