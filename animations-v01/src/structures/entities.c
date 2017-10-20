#include <cpctelera.h>

#include "entities.h"

#include "../structures/level.h"
#include "../sprites/sprites.h"


#include "../debug.h"

//cpctm_createTransparentMaskTable(g_AlphaTable, 0x0100, M0, 0);


/*
   u8* sprite;        		// Sprite associated to this frame
   u8  width, height; 		// Sprite dimensions in bytes
   i8  mx, my;        		// Pixel movements, in bytes, to be executed at the start of this Frame
   i8  ex, ey, ew, eh;      // Pixel bytes to erase (ew, eh=width and height of box to be eliminated, ex=X displacement, in bytes, from the top-left corner)
   u8  time;          		// Time that the sprite should be shown
*/

const T_AnimFrame g_allAnimFrames[11] = {
	// Idle Frames
   { G_idle_1,  4,8,  0,0,  0,0,0,0,  10 },  // 0 //
   { G_idle_2,  4,8,  0,0,  0,0,0,0,  10 },  // 1 // 
   { G_idle_3,  4,8,  0,0,  0,0,0,0,  10 },  // 2 // 

   // Walk Right Frames
   { G_walkR_1,  3,8,  1,0,  0,0,1,8,  8 }, // 3 //
   { G_walkR_2,  3,8,  1,0,  0,0,1,8,  8 }, // 4 //

   // Walk Left Frames
   { G_walkL_1,  3,8,  -1,0,  2,0,2,8,  8 }, // 5 //
   { G_walkL_2,  3,8,  -1,0,  2,0,1,8,  8 }, // 6 //

   // Walk Up Frames
   { G_walkU_1,  4,8,  0,-2,  0,6,4,2,  8 }, // 7 //
   { G_walkU_2,  4,8,  0,-2,  0,6,4,2,  8 }, // 8 //

   // Walk Down Frames
   { G_walkD_1,  4,8,  0,2,  0,0,4,2,  8 },  // 9 //
   { G_walkD_2,  4,8,  0,2,  0,0,4,2,  8 }   // 10 //
   

};


// Use a define for convenience
#define FF g_allAnimFrames

//
// All complete animations used in this example (NULL terminated, to know the end of the array)
//

T_AnimFrame* const g_anim_Idle[5]	   = { &FF[1],  &FF[0],  &FF[1],  &FF[2],  0 };
T_AnimFrame* const g_anim_WalkRight[5] = { &FF[3],  &FF[4],  &FF[3],  &FF[4],  0 };
T_AnimFrame* const g_anim_WalkLeft[5]  = { &FF[5],  &FF[6],  &FF[5],  &FF[6],  0 };
T_AnimFrame* const g_anim_WalkUp[5]    = { &FF[7],  &FF[8],  &FF[7],  &FF[8],  0 };
T_AnimFrame* const g_anim_WalkDown[5]  = { &FF[9],  &FF[10], &FF[9],  &FF[10], 0 };

#undef FF



/*
   T_AnimFrame** frames;      // Vector containing all the frames of the animation
   u8            frame_id;  // Index of the current frame
   u8            time;      // Remaining time for this frame
   TAnimStatus   status;    // Status of the animation
*/

const T_Animation g_playerAnimation = { g_anim_Idle, 0xFF, 1, AS_CYCLE };








/*
	T_Animation* 	anim;     
   	u8* 			videopos; 
    u8 				tile_x;
	u8 				tile_y;
	u8 				actionArea[8];
	E_EntityStatus 	status;
	E_EntityFlags   flags;

*/

const T_Entity g_player = { &g_playerAnimation, CPCT_VMEM_START, 6, 7,
	{0,0,0,0,0,0,0,0},
	ES_IDLE, EF_SPRITE };





//
// functions
//

void init_Entities(u8 levelIndex){
	initPlayer();


}

void update_Entities(){
	updatePlayer();
	updateEntity(&g_player);

}

void draw_Entities(){
	if(g_player.flags)
	{
		if(g_player.flags & EF_SPRITE) drawEntity(&g_player);
	}
		
		

	
}



T_Entity* getPlayer()
{
	return (T_Entity*)g_player;
}



i8 updateAnimation(T_Animation* anim) {
   i8 newframe = 0;

   // Update only if animation is not paused or finished
   if (anim->status != AS_PAUSE && anim->status != AS_END) {

      // Update time and, If time has finished for this frame, get next
      if ( ! --anim->time ) {
         T_AnimFrame* frame;

         // Check next frame
         newframe = 1;
         frame = anim->frames[ ++anim->frame_id ]; 

         // If frame is not null, we have a new frame, else animation may have ended or may recycle
         if (frame) {
            // It is a valid frame, so set new frame values
            anim->time = frame->time;  // Get animation cycles for this frame
         } else if ( anim->status == AS_CYCLE ) {
            // Recycle to first frame
            anim->frame_id = 0;        // Next frame_id is first one of this animation
            anim->time     = anim->frames[0]->time; // Restore animation cycles for the first frame
         } else {
            // End animation
            anim->status = AS_END;  // Animation set to end status
            --anim->frame_id;       // frame_id decremented to leave animation permanently on last frame
         }
      }
   }

   // Report if a new frame has started
   return newframe;
}


void updateEntity(T_Entity *ent) {
   T_Animation* anim = ent->anim;

   

   if ( updateAnimation(anim) ) {
      if ( anim->status != AS_END ) {
         T_AnimFrame* frame = anim->frames[anim->frame_id];
         ent->flags |= EF_SPRITE;

         // Move on X and Y if required
         if (frame->mx) ent->videopos += frame->mx;
         if (frame->my) ent->videopos = cpct_getScreenPtr(CPCT_VMEM_START, ent->tile_x*4, (ent->tile_y*8)+((anim->frame_id+1)*frame->my));
         
      } else {
      	setAction(ent, ES_IDLE);
      }
   }

}


void setAction(T_Entity *ent, E_EntityStatus newstatus) {
    T_Animation* anim = ent->anim;
	anim->status= AS_PLAY;

	// Initialize new status
	switch (newstatus) {
		case ES_IDLE:  
			anim->frames = (T_AnimFrame**)g_anim_Idle;
			anim->status= AS_CYCLE;

			// Check previous status
			if     (ent->status == ES_WALK_RIGHT) walkRight(ent);
			else if(ent->status == ES_WALK_LEFT)  walkLeft(ent);
			else if(ent->status == ES_WALK_UP)    walkUp(ent); 
			else if(ent->status == ES_WALK_DOWN)  walkDown(ent); 

		break; 

		case ES_WALK_RIGHT:
		   anim->frames = (T_AnimFrame**)g_anim_WalkRight;
		break;  

		case ES_WALK_LEFT:
		   anim->frames = (T_AnimFrame**)g_anim_WalkLeft;
		break;

		case ES_WALK_UP:
		   anim->frames = (T_AnimFrame**)g_anim_WalkUp;
		break;  

		case ES_WALK_DOWN:
		   anim->frames = (T_AnimFrame**)g_anim_WalkDown;
		break; 
	}

	ent->status = newstatus;

	// Set values as if this was -1 frame (previous to initial 0 frame)
	// This will make updateAnimation jump to frame 0 on first update, executing frame 0 moves on enter.
	anim->frame_id = 0xFF;
	anim->time = 1;
   
}


void initPlayer(){
	T_Entity* pl = getPlayer();	

	pl->videopos =
		cpct_getScreenPtr(CPCT_VMEM_START, pl->tile_x*4, pl->tile_y*8);

}
	


void updatePlayer(){
		
	if(g_player.status == ES_IDLE && cpct_isAnyKeyPressed() )
	{
		if 		(cpct_isKeyPressed(Key_CursorRight)	&& g_player.actionArea[D_RIGHT] == 0)
			setAction(&g_player, ES_WALK_RIGHT);

		else if (cpct_isKeyPressed(Key_CursorLeft) && g_player.actionArea[D_LEFT] == 0)
			setAction(&g_player, ES_WALK_LEFT);

		else if (cpct_isKeyPressed(Key_CursorUp) && g_player.actionArea[D_UP] == 0) 
			setAction(&g_player, ES_WALK_UP);

		else if (cpct_isKeyPressed(Key_CursorDown) && g_player.actionArea[D_DOWN] == 0) 
			setAction(&g_player, ES_WALK_DOWN);
	}

	
}



void walkRight(T_Entity *ent){

	if(ent->actionArea[D_RIGHT] == 0)
	{

		ent->tile_x++;

		//Persistant Info
		ent->actionArea[0] = 0;
		ent->actionArea[1] = ent->actionArea[2]; 
		ent->actionArea[2] = ent->actionArea[3]; 
		ent->actionArea[7] = ent->actionArea[6]; 
		ent->actionArea[6] = ent->actionArea[5]; 

		//New info
		ent->actionArea[3] = getTileMapByPos(ent->tile_x + 1, ent->tile_y - 1);
		ent->actionArea[4] = getTileMapByPos(ent->tile_x + 1, ent->tile_y);
		ent->actionArea[5] = getTileMapByPos(ent->tile_x + 1, ent->tile_y + 1);
	 	
	}
}


void walkLeft(T_Entity *ent){

	if(ent->actionArea[D_LEFT] == 0)
	{

		ent->tile_x--;

		//Persistant Info
		ent->actionArea[2] = ent->actionArea[1]; 
		ent->actionArea[3] = ent->actionArea[2]; 
		ent->actionArea[4] = 0;
		ent->actionArea[5] = ent->actionArea[6]; 
		ent->actionArea[6] = ent->actionArea[7]; 

		//New info
		ent->actionArea[1] = getTileMapByPos(ent->tile_x - 1, ent->tile_y - 1);
		ent->actionArea[0] = getTileMapByPos(ent->tile_x - 1, ent->tile_y);
		ent->actionArea[7] = getTileMapByPos(ent->tile_x - 1, ent->tile_y + 1);
	 
	}
}

void walkUp(T_Entity *ent){

	if(ent->actionArea[D_UP] == 0)
	{

		ent->tile_y--;

		//Persistant Info
		ent->actionArea[5] = ent->actionArea[4];
		ent->actionArea[4] = ent->actionArea[3];	 
		ent->actionArea[6] = 0; 
		ent->actionArea[7] = ent->actionArea[0]; 
		ent->actionArea[0] = ent->actionArea[1]; 

		//New info
		ent->actionArea[1] = getTileMapByPos(ent->tile_x - 1, ent->tile_y -1);
		ent->actionArea[2] = getTileMapByPos(ent->tile_x , ent->tile_y -1);
		ent->actionArea[3] = getTileMapByPos(ent->tile_x + 1, ent->tile_y -1);
	 	
	}
}

void walkDown(T_Entity *ent){

	if(ent->actionArea[D_DOWN] == 0)
	{

		ent->tile_y++;

		//Persistant Info
		ent->actionArea[1] = ent->actionArea[0];
		ent->actionArea[0] = ent->actionArea[7];	 
		ent->actionArea[2] = 0; 
		ent->actionArea[3] = ent->actionArea[4]; 
		ent->actionArea[4] = ent->actionArea[5]; 

		//New info
		ent->actionArea[5] = getTileMapByPos(ent->tile_x + 1, ent->tile_y +1);
		ent->actionArea[6] = getTileMapByPos(ent->tile_x , ent->tile_y +1);
		ent->actionArea[7] = getTileMapByPos(ent->tile_x - 1, ent->tile_y +1);
		
	}
}



void drawEntity  (T_Entity* ent){
	
   // Get the entity values from its current animation status
   T_Animation* anim  = ent->anim;
   T_AnimFrame* frame = anim->frames[anim->frame_id];

   // Borrar rastro
   if (frame->ew){
   		u8* mem = cpct_getScreenPtr(CPCT_VMEM_START, (ent->tile_x*4) +( ((anim->frame_id)*frame->mx)+ frame->ex), (ent->tile_y*8)+( ((anim->frame_id)*frame->my)+ frame->ey) );
   		cpct_drawSolidBox(mem, 0x00, frame->ew, frame->eh);
   } 

   // Dibujar Sprite
   cpct_drawSprite(frame->sprite, ent->videopos, frame->width, frame->height);

   //cpct_drawSpriteMaskedAlignedTable(frame->sprite, ent->videopos, frame->width, frame->height, g_AlphaTable);

   ent->flags ^= EF_SPRITE;





   /*
   	pu8("IZQ:" ,g_player.actionArea[0], 1);
	pu8("DSI:" ,g_player.actionArea[1], 2);
	pu8("ARR:" ,g_player.actionArea[2], 3);
	pu8("DSD:" ,g_player.actionArea[3], 4);
	pu8("DER:" ,g_player.actionArea[4], 5);
	pu8("DID:" ,g_player.actionArea[5], 6);
	pu8("ABJ:" ,g_player.actionArea[6], 7);
	pu8("DII:" ,g_player.actionArea[7], 8);
	*/


 
}