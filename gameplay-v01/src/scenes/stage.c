#include <cpctelera.h>
#include "stage.h"


#include "../game.h"

#include "../util.h"

#include "../structures/level.h"
#include "../structures/entities.h"





extern void play_MainMenu_Scene();



// Varaibles & Structures
T_Scene stage_Scene;





//
// main scene functions
//

void play_Stage_Scene(){
	

	//ENTER SCENE
	init_Stage_Scene();

	//IN SCENE
	while(stage_Scene.state == SS_IN)
	{
		cpct_scanKeyboard();
		update_Stage_Scene();
		draw_Stage_Scene();
	}

	//EXIT SCENE
	play_MainMenu_Scene();
	
	
}








void init_Stage_Scene(){
	u8 level = 1;
	stage_Scene.index = SI_STAGE;
	stage_Scene.state = SS_IN;

	cpct_setVideoMode(0);
	cpct_setPalette(g_palette, 16);
	cpct_clearScreen(0);

	init_Level(level);
	init_Entities(level);



	
}

void update_Stage_Scene(){
	update_Level();
	update_Entities();
   


}




void draw_Stage_Scene(){
	cpct_waitVSYNC();
	
	draw_Level();
	draw_Entities();


}


//
// private funtions
//

void init_Player(){

}



