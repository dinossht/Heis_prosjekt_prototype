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
///----------States----------//
//set initial values
static esm_states esm_state = -1;
static floors floor_number = -1;
static elev_motor_direction_t motor_direction = 0;
static floors_between floor_between = -1;
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
	//motor_direction = DIRN_DOWN;
	esm_state = INITIALIZE;	
	floor_number = elev_get_floor_sensor_signal();
	printf( "Current floor = floor%d\n", floor_number );
	elev_set_floor_indicator( floor_number );	
	return 1;
}

void esm_door_closed(){
	elev_set_door_open_lamp(off);
	esm_state = IDLE;
}

void esm_open_door(){
	elev_set_door_open_lamp(on);
	timer_start();
}

void esm_floor_passed( int floor ){
	esm_state = SERVICING_FLOOR;
	//dummy function for testing
}


void esm_stop_button_pressed(){
	printf(" Stop button is pressed!\n" );
	esm_state = EMERGENCY_STOP;
	elev_set_stop_lamp( on );
	elev_set_motor_direction(DIRN_STOP);
	//op_clear_all_orders();  not implemented yet

	if ( elev_get_floor_sensor_signal() == -1 ) {		//between floors
		
	}
	else {												//at floor
		elev_set_door_open_lamp( on );
	}
	
}

void esm_stop_button_released(){
	printf(" Stop button is released!\n" );
	timer_start();
	if (elev_get_floor_sensor_signal() == -1) {
		esm_state = IDLE;
	}
	else {
		esm_state = SERVICING_FLOOR;
	}

	
}


static elev_motor_direction_t esm_get_motor_direction() {
	return motor_direction;
}

static void esm_update_floor(int floor_num) {
	floor_number = floor_num;
}

static void esm_update_motor_direction(elev_motor_direction_t motor_dir) {
	motor_direction = motor_dir;
}

static floors floors esm_get_current_floor(){
	return floor_number;
}



