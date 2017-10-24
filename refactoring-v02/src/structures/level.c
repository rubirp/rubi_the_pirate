#include <cpctelera.h>

#include "level.h"

#include "../levels/lvl_01.h"
#include "../tiles/tileset.h"



// Varaibles & Structures
T_Level level;



//
// private funtions
//
void drawTileMap();





void init_Level(u8 levelIndex){
	if(levelIndex == 1)
	{
		level.tileMap = g_lvl_01;
	}
	else if (levelIndex == 2)
	{

	}

	level.flags = LF_TILEMAP; 

}


void update_Level(){
	
}

void draw_Level(){
	if(level.flags)
	{
		if(level.flags & LF_TILEMAP) drawTileMap();
	}
}


u8 getTileMapByPos(u8 x, u8 y){
	return level.tileMap[x + (y*LEVEL_DIM)];
}




//
// private funtions
//
void drawTileMap(){
	u16 cont = 0;
	u8 col = 0;
	u8 fila = 0;

	while(cont < LEVEL_DIM * LEVEL_DIM ){
		
		cpct_drawTileAligned4x8(g_tileset[level.tileMap[cont]], cpct_getScreenPtr(CPCT_VMEM_START, col, fila));
		

		col+=4;
		
		if(col == 80){
			fila+=8;
			col=0;
		}
		cont++;
	}

	level.flags ^= LF_TILEMAP;
}