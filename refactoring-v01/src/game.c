#include <cpctelera.h>

#include "game.h"

extern void play_MainMenu_Scene();

void initGame();

	
void run(){
	initGame();
	play_MainMenu_Scene();

}



//private functions definition
void initGame(){

	__asm
		ld c, #0x01
		call cpct_setVideoMode_asm
		call cpct_disableFirmware_asm
	__endasm;

	cpct_setBorder(HW_BLACK);

}

