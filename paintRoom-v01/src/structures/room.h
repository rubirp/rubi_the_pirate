#ifndef _MATCH_H_
#define _MATCH_H_

typedef enum{
	RS_INIT = 0,
	RS_DRAWING,
	RS_PLAYING

}T_RoomSate;


typedef struct{
	T_RoomSate state;


}T_Room;



#endif