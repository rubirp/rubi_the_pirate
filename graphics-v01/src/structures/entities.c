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
   u8  hflip;
   u8  time;          		// Time that the sprite should be shown
*/

const T_AnimFrame g_allAnimFrames[45] = {
	//
	//Preso//
	//

	// Idle Frames
   { G_preso_idle_1,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 0 //
   { G_preso_idle_2,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 1 // 
   { G_preso_idle_3,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 2 // 
 
   // Walk Right Frames
   { G_preso_walkRL_1,  3,8,  1,0,  0,0,1,8,  0,  8 },  // 3 //
   { G_preso_walkRL_2,  3,8,  1,0,  0,0,1,8,  0,  8 },  // 4 //

   // Walk Left Frames
   { G_preso_walkRL_1,  3,8,  -1,0,  2,0,2,8,  0,  8 }, // 5 //
   { G_preso_walkRL_2,  3,8,  -1,0,  2,0,1,8,  0,  8 }, // 6 //

   // Walk Up Frames
   { G_preso_walkU,  4,8,  0,-2,  0,6,4,2,  1,  8 },    // 7 //


   // Walk Down Frames
   { G_preso_walkD,  4,8,  0,2,  0,0,4,2,  1,  8 },     // 8 //

	//
	//Preso//
	//



    //
	//Policia//
	//
   { G_policia_idle_1,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 9 //
   { G_policia_idle_2,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 10 // 
   { G_policia_idle_3,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 11 // 
 
   // Walk Right Frames
   { G_policia_walkRL_1,  3,8,  1,0,  0,0,1,8,  0,  8 },  // 12 //
   { G_policia_walkRL_2,  3,8,  1,0,  0,0,1,8,  0,  8 },  // 13 //

   // Walk Left Frames
   { G_policia_walkRL_1,  3,8,  -1,0,  2,0,2,8,  0,  8 }, // 14 //
   { G_policia_walkRL_2,  3,8,  -1,0,  2,0,1,8,  0,  8 }, // 15 //

   // Walk Up Frames
   { G_policia_walkU,  4,8,  0,-2,  0,6,4,2,  1,  8 },    // 16 //


   // Walk Down Frames
   { G_policia_walkD,  4,8,  0,2,  0,0,4,2,  1,  8 },     // 17 //


   	//
	//Policia//
	//


    //
	//Enfermero//
	//
   { G_enfermero_idle_1,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 18 //
   { G_enfermero_idle_2,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 19 // 
   { G_enfermero_idle_3,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 20 // 
 
   // Walk Right Frames
   { G_enfermero_walkRL_1,  3,8,  1,0,  0,0,1,8,  0,  8 },  // 21 //
   { G_enfermero_walkRL_2,  3,8,  1,0,  0,0,1,8,  0,  8 },  // 22 //

   // Walk Left Frames
   { G_enfermero_walkRL_1,  3,8,  -1,0,  2,0,2,8,  0,  8 }, // 23 //
   { G_enfermero_walkRL_2,  3,8,  -1,0,  2,0,1,8,  0,  8 }, // 24 //

   // Walk Up Frames
   { G_enfermero_walkU,  4,8,  0,-2,  0,6,4,2,  1,  8 },    // 25 //


   // Walk Down Frames
   { G_enfermero_walkD,  4,8,  0,2,  0,0,4,2,  1,  8 },     // 26 //


   	//
	//Enfermero//
	//


    //
	//Alguacil//
	//
   { G_alguacil_idle_1,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 27 //
   { G_alguacil_idle_2,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 28 // 
   { G_alguacil_idle_3,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 29 // 
 
   // Walk Right Frames
   { G_alguacil_walkRL_1,  3,8,  1,0,  0,0,1,8,  0,  8 },  // 30 //
   { G_alguacil_walkRL_2,  3,8,  1,0,  0,0,1,8,  0,  8 },  // 31 //

   // Walk Left Frames
   { G_alguacil_walkRL_1,  3,8,  -1,0,  2,0,2,8,  0,  8 }, // 32 //
   { G_alguacil_walkRL_2,  3,8,  -1,0,  2,0,1,8,  0,  8 }, // 33 //

   // Walk Up Frames
   { G_alguacil_walkU,  4,8,  0,-2,  0,6,4,2,  1,  8 },    // 34 //


   // Walk Down Frames
   { G_alguacil_walkD,  4,8,  0,2,  0,0,4,2,  1,  8 },     // 35 //


   	//
	//Alguacil//
	//



   //
	//Limpiadora//
	//
   { G_limpiadora_idle_1,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 36 //
   { G_limpiadora_idle_2,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 37 // 
   { G_limpiadora_idle_3,  4,8,  0,0,  0,0,0,0,  0,  10 },   // 38 // 
 
   // Walk Right Frames
   { G_limpiadora_walkRL_1,  3,8,  1,0,  0,0,1,8,  0,  8 },  // 39 //
   { G_limpiadora_walkRL_2,  3,8,  1,0,  0,0,1,8,  0,  8 },  // 40 //

   // Walk Left Frames
   { G_limpiadora_walkRL_1,  3,8,  -1,0,  2,0,2,8,  0,  8 }, // 41 //
   { G_limpiadora_walkRL_2,  3,8,  -1,0,  2,0,1,8,  0,  8 }, // 42 //

   // Walk Up Frames
   { G_limpiadora_walkU,  4,8,  0,-2,  0,6,4,2,  1,  8 },    // 43 //


   // Walk Down Frames
   { G_limpiadora_walkD,  4,8,  0,2,  0,0,4,2,  1,  8 },     // 44 //


   	//
	//Limpiadora//
	//

   

};


// Use a define for convenience
#define FF g_allAnimFrames

//
// All complete animations used in this example (NULL terminated, to know the end of the array)
//

T_AnimFrame* const g_preso_anim_Idle[5]	         = { &FF[1],  &FF[0],  &FF[1],  &FF[2],  0 };
T_AnimFrame* const g_preso_anim_WalkRight[5]     = { &FF[3],  &FF[4],  &FF[3],  &FF[4],  0 };
T_AnimFrame* const g_preso_anim_WalkLeft[5]      = { &FF[5],  &FF[6],  &FF[5],  &FF[6],  0 };
T_AnimFrame* const g_preso_anim_WalkUp[5]        = { &FF[7],  &FF[7],  &FF[7],  &FF[7],  0 };
T_AnimFrame* const g_preso_anim_WalkDown[5]      = { &FF[8],  &FF[8],  &FF[8],  &FF[8],  0 };

T_AnimFrame* const g_policia_anim_Idle[5]	     = { &FF[10], &FF[9],  &FF[10], &FF[11], 0 };
T_AnimFrame* const g_policia_anim_WalkRight[5]   = { &FF[12], &FF[13], &FF[12], &FF[13], 0 };
T_AnimFrame* const g_policia_anim_WalkLeft[5]    = { &FF[14], &FF[15], &FF[14], &FF[15], 0 };
T_AnimFrame* const g_policia_anim_WalkUp[5]      = { &FF[16], &FF[16], &FF[16], &FF[16], 0 };
T_AnimFrame* const g_policia_anim_WalkDown[5]    = { &FF[17], &FF[17], &FF[17], &FF[17], 0 };

T_AnimFrame* const g_enfermero_anim_Idle[5]	     = { &FF[20], &FF[18], &FF[19], &FF[20], 0 };
T_AnimFrame* const g_enfermero_anim_WalkRight[5] = { &FF[21], &FF[22], &FF[21], &FF[22], 0 };
T_AnimFrame* const g_enfermero_anim_WalkLeft[5]  = { &FF[23], &FF[24], &FF[23], &FF[24], 0 };
T_AnimFrame* const g_enfermero_anim_WalkUp[5]    = { &FF[25], &FF[25], &FF[25], &FF[25], 0 };
T_AnimFrame* const g_enfermero_anim_WalkDown[5]  = { &FF[26], &FF[26], &FF[26], &FF[26], 0 };

T_AnimFrame* const g_alguacil_anim_Idle[5]	     = { &FF[29], &FF[27], &FF[28], &FF[29], 0 };
T_AnimFrame* const g_alguacil_anim_WalkRight[5]  = { &FF[30], &FF[31], &FF[30], &FF[31], 0 };
T_AnimFrame* const g_alguacil_anim_WalkLeft[5]   = { &FF[32], &FF[33], &FF[32], &FF[33], 0 };
T_AnimFrame* const g_alguacil_anim_WalkUp[5]     = { &FF[34], &FF[34], &FF[34], &FF[34], 0 };
T_AnimFrame* const g_alguacil_anim_WalkDown[5]   = { &FF[35], &FF[35], &FF[35], &FF[35], 0 };

T_AnimFrame* const g_limpiadora_anim_Idle[5]	 = { &FF[38], &FF[37], &FF[36], &FF[38], 0 };
T_AnimFrame* const g_limpiadora_anim_WalkRight[5]= { &FF[39], &FF[40], &FF[39], &FF[40], 0 };
T_AnimFrame* const g_limpiadora_anim_WalkLeft[5] = { &FF[41], &FF[42], &FF[41], &FF[42], 0 };
T_AnimFrame* const g_limpiadora_anim_WalkUp[5]   = { &FF[43], &FF[43], &FF[43], &FF[43], 0 };
T_AnimFrame* const g_limpiadora_anim_WalkDown[5] = { &FF[44], &FF[44], &FF[44], &FF[44], 0 };

#undef FF



/*
   T_AnimFrame** frames;      // Vector containing all the frames of the animation
   u8            frame_id;  // Index of the current frame
   u8            time;      // Remaining time for this frame
   TAnimStatus   status;    // Status of the animation
*/

const T_Animation g_playerAnimation = { g_preso_anim_Idle, 0xFF, 1, AS_CYCLE };








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
			anim->frames = (T_AnimFrame**)g_preso_anim_Idle;
			anim->status= AS_CYCLE;

			// Check previous status
			if     (ent->status == ES_WALK_RIGHT) walkRight(ent);
			else if(ent->status == ES_WALK_LEFT)  walkLeft(ent);
			else if(ent->status == ES_WALK_UP)    walkUp(ent); 
			else if(ent->status == ES_WALK_DOWN)  walkDown(ent); 

		break; 

		case ES_WALK_RIGHT:
		   anim->frames = (T_AnimFrame**)g_preso_anim_WalkRight;
		break;  

		case ES_WALK_LEFT:
		   anim->frames = (T_AnimFrame**)g_preso_anim_WalkLeft;
		break;

		case ES_WALK_UP:
		   anim->frames = (T_AnimFrame**)g_preso_anim_WalkUp;
		break;  

		case ES_WALK_DOWN:
		   anim->frames = (T_AnimFrame**)g_preso_anim_WalkDown;
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
		ent->actionArea[3] = ent->actionArea[2];
		ent->actionArea[2] = ent->actionArea[1]; 
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


   //Flip sprite to left side if is necesary
   if(frame->mx < 0 || frame->hflip) cpct_hflipSpriteM0 (frame->width, frame->height, frame->sprite);
   // Dibujar Sprite
   cpct_drawSprite(frame->sprite, ent->videopos, frame->width, frame->height);
   //Flip sprite to left side if is necesary
   if(frame->mx < 0) cpct_hflipSpriteM0 (frame->width, frame->height, frame->sprite);


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