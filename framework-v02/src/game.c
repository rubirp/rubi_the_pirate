#include <cpctelera.h>

#include "game.h"
#include "util.h"

extern void play_MainMenu_Scene();

void initGame();
void playMainMenuScene();

	
void run(){
	initGame();


}



//private functions definition
void initGame(){
	cpct_disableFirmware();
	cpct_setVideoMode(0);
	cpct_setBorder(HW_BLACK);
	cpct_setPalette(g_palette, 16);

	play_MainMenu_Scene();
}

