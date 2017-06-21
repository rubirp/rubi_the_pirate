#include <cpctelera.h>
#include "credits.h"

#include "../game.h"


T_Scene credits_Scene;

extern void play_MainMenu_Scene();

void init_Credits_Scene();
void update_Credits_Scene();
void draw_Credits_Scene();


void play_Credits_Scene(){

	//ENTER SCENE
	cpct_clearScreen(cpct_px2byteM0 (1,1));
	init_Credits_Scene();
	draw_Credits_Scene();

	//IN SCENE
	while(credits_Scene.state == SS_IN){
		cpct_scanKeyboard_f();
		update_Credits_Scene();
	}

	//EXIT SCENE
	play_MainMenu_Scene();
	
}



void init_Credits_Scene(){
	credits_Scene.index = SI_CREDITS;
	credits_Scene.state = SS_ENTER;

}

void update_Credits_Scene(){

	if(cpct_isAnyKeyPressed()){

	   	if(cpct_isKeyPressed(Key_Esc)){
	   		credits_Scene.index = SI_WORLD_1;
   			credits_Scene.state = SS_EXIT;
		}
	}

}

void draw_Credits_Scene(){

	credits_Scene.state = SS_IN;
}