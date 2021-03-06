#include <cpctelera.h>
#include "mainMenu.h"

#include "../game.h"
#include "../util.h"



T_Scene mainMenu_Scene;

extern void play_Stage_Scene();
extern void play_Credits_Scene();




//
// main scene functions
//
void play_MainMenu_Scene(){
	
	//ENTER SCENE
	init_MainMenu_Scene();

	//IN SCENE
	while(mainMenu_Scene.state == SS_IN)
	{
		cpct_scanKeyboard_f();
		update_MainMenu_Scene();
	}

	//EXIT SCENE
	if(mainMenu_Scene.index == SI_STAGE) play_Stage_Scene();
	else 								 play_Credits_Scene();
	
}





void init_MainMenu_Scene(){
	
	mainMenu_Scene.index = SI_MAINMENU;
	mainMenu_Scene.state = SS_IN;

	cpct_setPalette(g_grey_palette, 4);
	cpct_clearScreen(0x00);
	draw_MainMenu_Scene();

	
	

}

void update_MainMenu_Scene(){
	if(cpct_isAnyKeyPressed()){

	   	if(cpct_isKeyPressed(Key_1)){
	   		mainMenu_Scene.index = SI_STAGE;
   			mainMenu_Scene.state = SS_EXIT;

	   	}
	   	else if(cpct_isKeyPressed(Key_2)){
   			mainMenu_Scene.index = SI_CREDITS;
   			mainMenu_Scene.state = SS_EXIT;
	   	}
	}

}

void draw_MainMenu_Scene(){

	cpct_drawStringM1("1.Play",  cpctm_screenPtr(CPCT_VMEM_START, 29, 128), 1, 0);
	cpct_drawStringM1("2.Credits",cpctm_screenPtr(CPCT_VMEM_START, 29, 164), 1, 0);

	
}