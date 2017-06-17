#ifndef _GAME_H_
#define _GAME_H_

typedef enum {
   GS_IN_MENU = 0,
   GS_IN_GAMEPLAY,
  // GS_BACK4MATCH,

  // GS_NUMGAMESTATUS

} T_GameStatus;

typedef struct Game{
	T_GameStatus status;
   
} T_Game;



	//funciones principales del juego
	void init();
	void run();

	void processInput();
	void update();
	void draw();


	//void exit();



#endif