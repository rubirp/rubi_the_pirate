#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <types.h>

#define LEVEL_DIM  20

typedef enum{
	LF_NONE 	= 1 << 0,
	LF_TILEMAP	= 1 << 1

}E_LevelFlags;

typedef struct{
	u8* tileMap;
	u8* colMap;
	E_LevelFlags flags;
	
}T_Level;


//
// public functions
//

void init_Level(u8 levelIndex);
void update_Level();
void draw_Level();

u8 getTileMapByPos(u8 x, u8 y);

#endif