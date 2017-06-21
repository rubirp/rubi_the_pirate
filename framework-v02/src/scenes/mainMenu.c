#include <cpctelera.h>
#include "mainMenu.h"

#include "../game.h"




T_Scene mainMenu_Scene;

extern void play_World_1_Scene();
extern void play_Credits_Scene();

void init_MainMenu_Scene();
void update_MainMenu_Scene();
void draw_MainMenu_Scene();


void play_MainMenu_Scene(){
	
	//ENTER SCENE
	cpct_clearScreen(cpct_px2byteM0 (1,1));
	init_MainMenu_Scene();
	draw_MainMenu_Scene();

	//IN SCENE
	while(mainMenu_Scene.state == SS_IN){
		cpct_scanKeyboard_f();
		update_MainMenu_Scene();
	}

	//EXIT SCENE
	if(mainMenu_Scene.index == SI_WORLD_1) 	play_World_1_Scene();
	else 									play_Credits_Scene();
	
}





void init_MainMenu_Scene(){
	mainMenu_Scene.index = SI_MAINMENU;
	mainMenu_Scene.state = SS_ENTER;

}

void update_MainMenu_Scene(){
	if(cpct_isAnyKeyPressed()){

	   	if(cpct_isKeyPressed(Key_1)){
	   		mainMenu_Scene.index = SI_WORLD_1;
   			mainMenu_Scene.state = SS_EXIT;

	   	}
	   	else if(cpct_isKeyPressed(Key_2)){
   			mainMenu_Scene.index = SI_CREDITS;
   			mainMenu_Scene.state = SS_EXIT;
	   	}
	}

}

void draw_MainMenu_Scene(){
	//myMenu.pvmem = cpctm_screenPtr(CPCT_VMEM_START, 29, 128);
	cpct_drawStringM0("1.Play",  cpctm_screenPtr(CPCT_VMEM_START, 29, 128), 15, 1);
	
	
	//myMenu.pvmem = cpctm_screenPtr(CPCT_VMEM_START, 22, 164);
	cpct_drawStringM0("2.Credits",cpctm_screenPtr(CPCT_VMEM_START, 22, 164), 15, 1);

	mainMenu_Scene.state = SS_IN;
}