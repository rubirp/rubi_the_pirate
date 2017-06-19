#include <cpctelera.h>
#include "game.h"

#include "tiles/tiles.h"

//
// private functions declaration
//


void initCPC(); // set cpc initial settings

extern void initMenu();
extern void initGameplay();

extern void updateMenu(T_Game* game);
extern void updateGameplay();

extern void drawMenu();
extern void drawGameplay();

//
// variables declaration
//

T_Game myGame; // My Struct Game;
//const u8 g_palette[16] = { 0x52, 0x54, 0x5c, 0x5d, 0x56, 0x46, 0x57, 0x5e, 0x40, 0x4e, 0x42, 0x53, 0x59, 0x4a, 0x43, 0x4b };


//
// private function definition
//

void initCPC(){
	cpct_disableFirmware();
	cpct_setVideoMode(0);
	cpct_setBorder(HW_BLACK);
	cpct_setPalette(g_palette, 16);
}


//
// public function definition
//

void init(){
	initCPC();
	initMenu();
	initGameplay();
}

void run(){
	
	init();
	//myGame.is_running = 1;

	//Bucle principal del juego
	while(1){

		processInput();

		update();

		if(1){
			cpct_waitVSYNC();
			draw();
		}
	}

   
  

}

void processInput(){
	cpct_scanKeyboard_f();
	

}


void update(){
	switch(myGame.state) {

		case GS_IN_MENU:
	   		updateMenu(&myGame);
		break;

		case GS_IN_GAMEPLAY:    	
	   		updateGameplay();
		break;
	}
	
}

void draw(){
	switch(myGame.state) {
		
		case GS_IN_MENU:
	   		drawMenu();
		break;

		case GS_IN_GAMEPLAY:    	
	   		drawGameplay();
		break;
	}
	
	
}

