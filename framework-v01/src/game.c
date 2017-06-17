#include <cpctelera.h>
#include "game.h"

//
// private functions declaration
//

void initCPC(); // set cpc initial settings

//
//private variables declaration
//

T_Game myGame; // My Struct Game;


//
// private function definition
//

void initCPC(){
	cpct_disableFirmware();
	cpct_setVideoMode(0);
	cpct_setBorder(HW_BLACK);
	//cpct_setPalette(g_palette, 16);
   	cpct_setVideoMode(0);
}


//
// public function definition
//

void init(){
	initCPC();

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
	/*
	switch(myGame.status) {

		case GS_IN_MENU:
	   		updateMenu();
		break;

		case GS_IN_GAMEPLAY:    	
	   		//updateGameplay();
		break;
	}
	*/
}

void draw(){
/*	
	switch(myGame.status) {
		
		case GS_IN_MENU:
	   		drawMenu();
		break;

		case GS_IN_GAMEPLAY:    	
	   		//drawGameplay();
		break;
	}
	*/
	
}

