#include <stdio.h>

#define true 1
#define false 0


//States of elevator
//Emergency stop state

typedef enum Floor { FLOOR1, FLOOR2, FLOOR3, FLOOR4 } Floor;


typedef struct {
	Floor floor;
	int buttonPressed;
} button;

/*
- Hold track of direction
- Between floors? Necessary?
- Emergency stop button?
*/

//Easier to separate stop button from the rest
//buttons[0, 1] => goto Floor 1, etc.
//Hold track of direction in additon
//Have to combine floor polling with floor direction to calculate stop algorithm
//

button buttons[10] = { 
						{ FLOOR1, 0 },	//B_UP floor 1 == buttons[0]
						{ FLOOR1, 0 },	//B_FL floor 1

						{ FLOOR2, 0 },	//B_DW floor 2
						{ FLOOR2, 0 },	//B_UP floor 2
						{ FLOOR2, 0 },	//B_FL floor 2

						{ FLOOR3, 0 },	//B_DW floor 3
						{ FLOOR3, 0 },	//B_UP floor 3
						{ FLOOR3, 0 },	//B_FL floor 3

						{ FLOOR4, 0 },	//B_DW floor 4
						{ FLOOR4, 0 }	//B_FL floor 4
};


int main(void) {


	return 0;
}