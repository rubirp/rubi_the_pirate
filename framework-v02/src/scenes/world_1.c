#include <cpctelera.h>
#include "world_1.h"

#include "../game.h"
#include "../tiles/tiles.h"
#include "../levels/prueba.h"




T_Scene world_1_Scene;

extern void play_MainMenu_Scene();

void init_World_1_Scene();
void update_World_1_Scene();
void draw_World_1_Scene();


void play_World_1_Scene(){

	//ENTER SCENE
	cpct_clearScreen(cpct_px2byteM0 (1,1));
	init_World_1_Scene();
	draw_World_1_Scene();

	//IN SCENE
	while(world_1_Scene.state == SS_IN){
		cpct_scanKeyboard_f();
		update_World_1_Scene();
	}

	//EXIT SCENE
	play_MainMenu_Scene();
	
}





void init_World_1_Scene(){
	world_1_Scene.index = SI_WORLD_1;
	world_1_Scene.state = SS_ENTER;

}

void update_World_1_Scene(){

	


}

void draw_World_1_Scene(){
	u8 col = 0;
	u8 fila = 0;

	u16 cont = 0;
	while(cont < 20 * 20){
		
		cpct_drawTileAligned4x8(g_tileset[g_nivel_1[cont]], cpct_getScreenPtr(CPCT_VMEM_START, col, fila));
		

		col+=4;
		
		if(col == 80){
			fila+=8;
			col=0;
		}
		cont++;
	}

	world_1_Scene.state = SS_IN;
}