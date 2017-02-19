#include <elev.h>

#define TYPES 3;
#define TRUE 1;
#define FALSE 0;

typedef int bool;


/*
bool order_button_list[N_FLOORS][TYPES] = {
	{ BUTTON_CALL_UP1, BUTTON_CALL_DOWN1, BUTTON_COMMAND1 },
	{ BUTTON_CALL_UP2, BUTTON_CALL_DOWN2, BUTTON_COMMAND2 },
	{ BUTTON_CALL_UP3, BUTTON_CALL_DOWN3, BUTTON_COMMAND3 },
	{ BUTTON_CALL_UP4, BUTTON_CALL_DOWN4, BUTTON_COMMAND4 },
}

*/
extern bool order_button_list[N_FLOORS][TYPES];
// om ordre legges til på en knapp: endre verdi til 1

void op_print_order_button_list( void );

void op_clear_all_orders(void);

void op_update_order_list(elev_button_type_t button_type, int floor, int status); //floor 0-indeksert, status = on or off
//må kalles for å nullstille ordre når den er utført - stopper i etasjen

bool op_order_available( void );

int op_number_of_orders( void ); 

bool op_is_order_at_floor( int floor );

//gir motor direction når etasjeføler er på (1) - bestemmer om heis skal stoppe eller fortsette
elev_motor_direction_t op_get_next_move( elev_motor_direction_t current_motor_dir, int current_floor );	//current = which floor elevator is at now.
