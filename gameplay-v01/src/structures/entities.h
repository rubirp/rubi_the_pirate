#ifndef _ENTITIES_H_
#define _ENTITIES_H_

#include <types.h>

typedef struct{
    u8 tile_x;
	u8 tile_y;
	u8 *lpscreen;
	u8 *pscreen;
	u8 *sprite;

}T_Entity;


typedef enum{
	D_LEFT	= 0,
	D_RIGHT	= 4,
	D_UP	= 2,
	D_DOWN	= 6

}E_Direction;


typedef enum{
	PF_NONE 	= 1 << 0,
	PF_SPRITE	= 1 << 1

}E_PlayerFlags;

typedef enum{
	PS_IDLE 	= 0,
	PS_WALKING

}E_PlayerStatus;

typedef struct{
    T_Entity entity;
    u8 actionArea[8];
    u8 step;
    E_Direction direction;
    E_PlayerStatus status;
    E_PlayerFlags flags;
	
}T_Player;



//
// Public functions
//
void init_Entities(u8 levelIndex);
void update_Entities();
void draw_Entities();


#endif