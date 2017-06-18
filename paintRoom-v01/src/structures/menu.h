#ifndef _MENU_H_
#define _MENU_H_

#include <cpctelera.h>

typedef enum{
	MS_ON_MAINMENU = 0,
	MS_ON_CREDITS,
	MS_ON_GAMEPLAY

}T_MenuState;

typedef struct{
	u8* pvmem;
	T_MenuState state;

	u8 draw;

}T_Menu;



#endif