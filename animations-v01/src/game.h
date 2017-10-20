#ifndef _GAME_H_
#define _GAME_H_

typedef enum SceneIndex
{
	SI_MAINMENU = 0,
	SI_CREDITS,
	SI_STAGE

}T_SceneIndex;


typedef enum SceneState
{
	SS_ENTER = 0,
	SS_IN,
	SS_EXIT

}T_SceneState;

typedef struct Scene
{
	T_SceneIndex index;
	T_SceneState state;

}T_Scene;


void run();



#endif