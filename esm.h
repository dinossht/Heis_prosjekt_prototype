#include "elev.h"
#include "timer.h"

enum stop_status{
		RELEASED = 1,
		NOT_PRESSED = 0,
		PRESSED = -1
};

int current_stop_button_stauts = NOT_PRESSED;
int prev_stop_button_status = NOT_PRESSED;

//Come to defined floor and update current state and current floor and LED
int esm_initialize_elevator( void );

void esm_door_closed( void );

void esm_open_door( void );

void esm_floor_passed( int floor );

void esm_stop_button_pressed( void );

void esm_stop_button_released( void );

















