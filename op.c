#include <op.h>

order_button_list[N_FLOORS][TYPES] = {
	{ 0, 0, 0 },		//tre typer knapper for etasje 1
	{ 0, 0, 0 },		//tre typer knapper for etasje 2
	{ 0, 0, 0 },
	{ 0, 0, 0 },
}


//slippe å kopiere iterasjon i flere funskjoner??????

void op_print_order_button_list(void)
{
	for (int row = 0; i < N_FLOORS; row++) {
		for (int col = 0; i < TYPES; col++) {
			printf("%d  ", order_button_list[row][col]);
		}
		printf("\n");
	}
}

void op_clear_all_orders(void) {
	for (int row = 0; i < N_FLOORS; row++) {
		for (int col = 0; i < TYPES; col++) {
			order_button:list[row][col] = 0;
		}
	}
}

void op_update_order_list(elev_button_type_t button_type, int floor, int status) {
	order_button_list[floor][button_type] = status;
}

bool op_order_available(void) {
	for (int row = 0; i < N_FLOORS; row++) {
		for (int col = 0; i < TYPES; col++) {

			if (order_button_list[row][col] == 1) {
				return TRUE;
			}

		}
	}
	return FALSE;
}

int op_number_of_orders(void){
	int count = 0;
	for (int row = 0; i < N_FLOORS; row++) {
		for (int col = 0; i < TYPES; col++) {
			if (order_button_list[row][col] = 1) {
				count++;
			}
		}
	}
	return count;
}

bool op_is_order_at_floor(int floor){
		for (int col = 0; i < TYPES; col++) {
			if (order_button_list[floor][col] == 1) {
				return true;
			}
		}
		return false;
}


elev_motor_direction_t op_get_next_move(elev_motor_direction_t current_motor_dir, int current_floor){
	//skal stoppe i en etasje når den har command-bestilling til etasjen
	//skal stoppe i en etasje om den har utside-bestilling i samme retning som motoren har nå
	//skal ikke stoppe om utside-bestilling har motsatt retning av motoren UTENOM NÅR den ikke har bestilling forbi den etasjen
	if (op_is_order_at_floor(current_floor) == false){		//finnes ordre i passert etasje? om nei: fortsett i samme retning
		return current_motor_dir;
	}
	else{


		if (op_number_of_orders() == 0 || op_number_of_orders() == 1) {
			return DIRN_STOP;
		}
	}



}