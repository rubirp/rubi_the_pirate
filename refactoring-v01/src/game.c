#include <cpctelera.h>
#include "game.h"
#include "util.h"
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

const T_Game myGame = {
	.state = GS_IN_MENU
};


//
// private function definition
//

void initCPC(){
	cpct_disableFirmware();
	cpct_setVideoMode(0);
	cpct_setBorder(HW_BLACK);
	cpct_setPalette(g_palette, 16);

	//Aparte
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

