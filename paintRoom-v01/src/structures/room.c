#include <cpctelera.h>

#include "room.h"

#include "../tiles/tiles.h"
#include "../levels/prueba.h"

//
// private functions declaration
//



//
// variables declaration
//

T_Room myRoom;


//
// private function definition
//
void drawRoom(){
	u16 cont = 0;
	u8 col = 0;
	u8 fila = 0;

	while(cont < 20 * 20){
		
		cpct_drawTileAligned4x8(g_tileset[g_nivel_1[cont]], cpct_getScreenPtr(CPCT_VMEM_START, col, fila));
		

		col+=4;
		
		if(col == 80){
			fila+=8;
			col=0;
		}
		cont++;
	}
}


//
void initGameplay(){
	myRoom.state = RS_INIT;
}

void updateGameplay(){
	switch(myRoom.state){
		case RS_INIT:
		myRoom.state = RS_DRAWING;
		break;
	}
	
}

void drawGameplay(){
	switch(myRoom.state) {

	   	case RS_DRAWING:
	   		cpct_clearScreen(0);
	    	drawRoom();
	    	myRoom.state = RS_PLAYING;
	    break;
	    
	}
}