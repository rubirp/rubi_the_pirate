#include <cpctelera.h>
#include "game.h"


void initCPC();


void initCPC(){
	cpct_disableFirmware();
	cpct_setVideoMode(0);
	cpct_setBorder(HW_BLACK);
	//cpct_setPalette(g_palette, 16);
   	cpct_setVideoMode(0);
}


void init(){
	initCPC();
}

void run(){
	
	init();

	//Bucle principal del juego
	while(1){

		processInput();

		update();

		
			cpct_waitVSYNC();
			draw();
		
	}

   
  

}

void processInput(){

	cpct_scanKeyboard_f();
	

}


void update(){
	
	 
}

void draw(){	
	
	
}