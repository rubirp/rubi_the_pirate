#include <cpctelera.h>
#include "mainMenu.h"

#include "../game.h"
#include "../util.h"



T_Scene mainMenu_Scene;

extern void play_World_1_Scene();
extern void play_Credits_Scene();

void init_MainMenu_Scene();
void update_MainMenu_Scene();
void draw_MainMenu_Scene();


void play_MainMenu_Scene(){
	
	//ENTER SCENE
	init_MainMenu_Scene();

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
	/*
	__asm
		ld hl, g_grey_palette
		ld de, #0x04
		call cpct_setPalette_asm
	__endasm;
	*/
	cpct_setPalette(g_grey_palette, 4);


	cpct_clearScreen(0x00);
	draw_MainMenu_Scene();

	mainMenu_Scene.index = SI_MAINMENU;
	mainMenu_Scene.state = SS_IN;

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
	

	__asm
		_string: .asciz "1.Play"

		//string: .asciz "1.Play"
	   	;; We are going to call draw String, and we have to push parameters
	   	;; to the stack first (as the function recovers it from there).
	   	ld   hl, #_string  ;; HL = Pointer to the start of the string
	   	ld   de, #0xC000  ;; DE = Pointer to video memory location where the string will be drawn
	   	ld   bc, #0x0001  ;; B = Background colour, C = Foreground colour

	   	//call cpct_drawStringM1_asm ;; Call the string drawing function
	__endasm;

	//myMenu.pvmem = cpctm_screenPtr(CPCT_VMEM_START, 29, 128);
	//cpct_drawStringM1("1.Play",  cpctm_screenPtr(CPCT_VMEM_START, 29, 128), 1, 0);
	
	
	//myMenu.pvmem = cpctm_screenPtr(CPCT_VMEM_START, 22, 164);
	cpct_drawStringM1("2.Credits",cpctm_screenPtr(CPCT_VMEM_START, 29, 164), 1, 0);

	
}