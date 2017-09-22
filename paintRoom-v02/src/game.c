#include <cpctelera.h>

#include "game.h"

extern void play_MainMenu_Scene();

void initGame();
//void playMainMenuScene();

	
void run(){
	initGame();
	play_MainMenu_Scene();

}



//private functions definition
void initGame(){
	cpct_setVideoMode(1);
	cpct_disableFirmware();
	cpct_setBorder(HW_BLACK);

}

