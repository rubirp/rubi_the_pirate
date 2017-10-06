#include <cpctelera.h>

#include "entities.h"

#include "../characters/player.h"
#include "../structures/level.h"

#include "../tiles/tileset.h"



#include "../debug.h"




cpctm_createTransparentMaskTable(g_AlphaTable, 0x0100, M0, 0);


// Varaibles & Structures
T_Player player;

//
// private funtions
//
void initPlayer();
void updatePlayer();
void drawPlayer();


void initPlayerMovement(E_Direction dir);
void doPlayerMovement();







void init_Entities(u8 levelIndex){
	initPlayer();



}

void update_Entities(){
	updatePlayer();
}

void draw_Entities(){
	if(player.flags)
	{
		if(player.flags & PF_SPRITE) drawPlayer();
	}
}





//
// private funtions
//
void initPlayer(){

	player.entity.tile_x = 5;
	player.entity.tile_y = 5;
	player.entity.pscreen =
		cpct_getScreenPtr(CPCT_VMEM_START, player.entity.tile_x*4, player.entity.tile_y*8);

	player.entity.lpscreen = player.entity.pscreen;
	player.entity.sprite = g_player;
	player.step = 0;
	player.direction = D_RIGHT;
	player.status = PS_IDLE;
	player.flags = PF_SPRITE;
}

void updatePlayer(){
	
	switch(player.status){
		case PS_IDLE:
			if(cpct_isAnyKeyPressed()){

				if(cpct_isKeyPressed(Key_CursorLeft)) 		initPlayerMovement(D_LEFT);
				else if(cpct_isKeyPressed(Key_CursorRight)) initPlayerMovement(D_RIGHT);
				else if(cpct_isKeyPressed(Key_CursorUp))	initPlayerMovement(D_UP);
				else if(cpct_isKeyPressed(Key_CursorDown)) 	initPlayerMovement(D_DOWN);	
			
			}
		break;
			
		case PS_WALKING:
			doPlayerMovement();	

		break;
	}
	
}


void initPlayerMovement(E_Direction dir){

	if(player.actionArea[dir] == 0)
	{
		player.direction = dir;
	 	player.status = PS_WALKING;
	}

}


void doPlayerMovement(){
	//Estoy andando
	if(player.step++ < 4)
	{

		player.entity.lpscreen = player.entity.pscreen;
		
		if      (player.direction == D_LEFT)  
			player.entity.pscreen--;

		else if (player.direction == D_RIGHT)
		 	player.entity.pscreen++;

		else if (player.direction == D_UP)
			player.entity.pscreen =
				cpct_getScreenPtr(CPCT_VMEM_START, player.entity.tile_x*4, (player.entity.tile_y*8) - (player.step*2));	

		else
			player.entity.pscreen =
				cpct_getScreenPtr(CPCT_VMEM_START, player.entity.tile_x*4, (player.entity.tile_y*8) + (player.step*2));	



		player.flags = PF_SPRITE;
	}
	// Llego al tile destino (4 pasos/steps) y actualizo la posicion y el area del player
	else
	{
		if (player.direction == D_LEFT)
		{
			player.entity.tile_x--;

			//Persistant Info
			player.actionArea[2] = player.actionArea[1]; 
			player.actionArea[3] = player.actionArea[2]; 
			player.actionArea[4] = 0;
			player.actionArea[5] = player.actionArea[6]; 
			player.actionArea[6] = player.actionArea[7]; 

			//New info
			player.actionArea[1] = getTileMapByPos(player.entity.tile_x - 1, player.entity.tile_y - 1);
			player.actionArea[0] = getTileMapByPos(player.entity.tile_x - 1, player.entity.tile_y);
			player.actionArea[7] = getTileMapByPos(player.entity.tile_x - 1, player.entity.tile_y + 1);
		}
		else if(player.direction == D_RIGHT)
		{
			player.entity.tile_x++;

			//Persistant Info
			player.actionArea[0] = 0;
			player.actionArea[1] = player.actionArea[2]; 
			player.actionArea[2] = player.actionArea[3]; 
			player.actionArea[7] = player.actionArea[6]; 
			player.actionArea[6] = player.actionArea[5]; 

			//New info
			player.actionArea[3] = getTileMapByPos(player.entity.tile_x + 1, player.entity.tile_y - 1);
			player.actionArea[4] = getTileMapByPos(player.entity.tile_x + 1, player.entity.tile_y);
			player.actionArea[5] = getTileMapByPos(player.entity.tile_x + 1, player.entity.tile_y + 1);
		}
		else if(player.direction == D_UP)
		{
			player.entity.tile_y--;

			//Persistant Info
			player.actionArea[5] = player.actionArea[4];
			player.actionArea[4] = player.actionArea[3];	 
			player.actionArea[6] = 0; 
			player.actionArea[7] = player.actionArea[0]; 
			player.actionArea[0] = player.actionArea[1]; 

			//New info
			player.actionArea[1] = getTileMapByPos(player.entity.tile_x - 1, player.entity.tile_y -1);
			player.actionArea[2] = getTileMapByPos(player.entity.tile_x , player.entity.tile_y -1);
			player.actionArea[3] = getTileMapByPos(player.entity.tile_x + 1, player.entity.tile_y -1);
		}
		else
		{
			player.entity.tile_y++;

			//Persistant Info
			player.actionArea[1] = player.actionArea[0];
			player.actionArea[0] = player.actionArea[7];	 
			player.actionArea[2] = 0; 
			player.actionArea[3] = player.actionArea[4]; 
			player.actionArea[4] = player.actionArea[5]; 

			//New info
			player.actionArea[5] = getTileMapByPos(player.entity.tile_x + 1, player.entity.tile_y +1);
			player.actionArea[6] = getTileMapByPos(player.entity.tile_x , player.entity.tile_y +1);
			player.actionArea[7] = getTileMapByPos(player.entity.tile_x - 1, player.entity.tile_y +1);
		}

		player.step = 0;
		player.status = PS_IDLE;

		player.entity.lpscreen = player.entity.pscreen;

	}

	
}

void drawPlayer(){

	cpct_drawSolidBox (player.entity.lpscreen, cpct_px2byteM0(7, 7), 4, 8);

	cpct_drawSpriteMaskedAlignedTable(player.entity.sprite, player.entity.pscreen, G_PLAYER_W, G_PLAYER_H, g_AlphaTable);
	
	player.flags ^= PF_SPRITE;

/*
	pu8("IZQ:" ,player.actionArea[0], 1);
	pu8("DSI:" ,player.actionArea[1], 2);
	pu8("ARR:" ,player.actionArea[2], 3);
	pu8("DSD:" ,player.actionArea[3], 4);
	pu8("DER:" ,player.actionArea[4], 5);
	pu8("DID:" ,player.actionArea[5], 6);
	pu8("ABJ:" ,player.actionArea[6], 7);
	pu8("DII:" ,player.actionArea[7], 8);
*/
	

}