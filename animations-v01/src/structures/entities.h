#ifndef _ENTITIES_H_
#define _ENTITIES_H_

#include <types.h>

//
// Possible statuses of an animation
//
typedef enum {
	AS_END = 0, // Animation has ended	
   	AS_PLAY,    // Playing till the last frame
   	AS_CYCLE,   // Playing continuosly
  	AS_PAUSE    // Paused, waiting to continue
  

} E_AnimStatus;

//
// Description of an animation frame
//
typedef struct {
   u8* sprite;            // Sprite associated to this frame
   u8  width, height;     // Sprite dimensions in bytes
   i8  mx, my;            // Pixel movements, in bytes,         to be executed at the start of this Frame
   i8  ex ,ey, ew, eh;    // Pixel bytes to erase (ew, eh=width and height of box to be eliminated, ex=X displacement, in bytes, from the top-left corner)
   u8  time;              // Time that the sprite should be shown

} T_AnimFrame;

//
// Describes an Animation as a secuence of sprites, controlled by time
//   Time is measured in main loop cycles
//
typedef struct {
   T_AnimFrame** frames;    // Vector containing all the frames of the animation
   u8            frame_id;  // Index of the current frame
   u8            time;      // Remaining time for this frame
   E_AnimStatus  status;    // Status of the animation

} T_Animation;



typedef enum{
	ES_NONE = 0,
	ES_IDLE,
	ES_WALK_RIGHT,
	ES_WALK_LEFT,
	ES_WALK_UP,
	ES_WALK_DOWN
	

}E_EntityStatus;


typedef enum{
	D_LEFT	= 0,
	D_RIGHT	= 4,
	D_UP	= 2,
	D_DOWN	= 6

}E_Direction;


typedef enum{
	EF_NONE 	= 1 << 0,
	EF_SPRITE	= 1 << 1

}E_EntityFlags;


typedef struct{
	T_Animation* 	anim;     
   	u8* 			videopos; 
    u8 				tile_x;
	u8 				tile_y;
	u8 				actionArea[8];
	E_EntityStatus 	status;
	E_EntityFlags   flags;


}T_Entity;



//
// functions
//
	 void init_Entities(u8 levelIndex);
	 void update_Entities();
	 void draw_Entities();


T_Entity* getPlayer();
  	   i8 moveEntityY (T_Entity* ent, i8 my);
  	 void updatePlayer();
  	   i8 updateAnimation(T_Animation* anim);
	 void updateEntity(T_Entity *ent);
	 void setAction(T_Entity *ent, E_EntityStatus newstatus);

	 void walkRight(T_Entity *ent);
	 void walkLeft(T_Entity *ent);
	 void walkUp(T_Entity *ent);
	 void walkDown(T_Entity *ent);
        
     void drawEntity  (T_Entity* ent);


#endif