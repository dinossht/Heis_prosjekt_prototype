#include "elev.h"
#include "timer.h"

enum stop_status{
		RELEASED = -1,
		NOT_PRESSED = 0,
		PRESSED = 1
};

//int current_stop_button_stauts = NOT_PRESSED;
int prev_stop_button_status = NOT_PRESSED;

//go to to defined floor and update current state and current floor and LED
int esm_initialize_elevator( void );

void esm_door_closed( void );

void esm_open_door( void );

void esm_floor_passed( int floor );

void esm_stop_button_pressed( void );

void esm_stop_button_released( void );

static elev_motor_direction_t esm_get_motor_direction( void );

static void esm_update_floor(floors floor_num );

static void esm_update_motor_direction(elev_motor_direction_t motor_dir);

static floors esm_get_current_floor( void );
















