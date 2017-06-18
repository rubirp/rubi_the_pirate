#include "menu.h"



//
// private functions declaration
//
void drawMainMenu();
void drawCredits();
void drawGameplay();


//
// variables declaration
//

T_Menu myMenu;


//
// private function definition
//
void drawMainMenu(){

	myMenu.pvmem = cpctm_screenPtr(CPCT_VMEM_START, 29, 128);
	cpct_drawStringM0("1.Play", myMenu.pvmem, 15, 1);
	
	
	myMenu.pvmem = cpctm_screenPtr(CPCT_VMEM_START, 22, 164);
	cpct_drawStringM0("2.Credits", myMenu.pvmem, 15, 1);

}

void drawCredits(){

}

void drawGameplay(){

}


//
// public function definition
//

void initMenu(){
	myMenu.pvmem = CPCT_VMEM_START;
	myMenu.state = MS_ON_MAINMENU;

	myMenu.draw = 1;
}



void updateMenu(){
	if(cpct_isAnyKeyPressed()){

		switch(myMenu.state) {
		   	case MS_ON_MAINMENU:
			   	if(cpct_isKeyPressed(Key_1)){
		   			myMenu.state = MS_ON_GAMEPLAY;
		   			myMenu.draw = 1;	
			   	}
			   	else if(cpct_isKeyPressed(Key_2)){
		   			myMenu.state = MS_ON_CREDITS;
		   			myMenu.draw = 1;	
			   	}
		   	break;

		   	case MS_ON_CREDITS:
			   	if(cpct_isKeyPressed(Key_Esc)){

		   			myMenu.state = MS_ON_MAINMENU;
		   			myMenu.draw = 1;
		   		}
		   	break;
		}
	}
}

void drawMenu(){
	if(myMenu.draw){
		switch(myMenu.state) {

		   	case MS_ON_MAINMENU:
		   		cpct_clearScreen(cpct_px2byteM0 (1,1));
		    	drawMainMenu();
		    break;

		    case MS_ON_GAMEPLAY:
		   		cpct_clearScreen(cpct_px2byteM0 (1,1));
		    	drawGameplay();
		    break;

		    case MS_ON_CREDITS:
		   		cpct_clearScreen(cpct_px2byteM0 (1,1));
		    	drawCredits();
		    break;
		}
		myMenu.draw = 0;
	}
}