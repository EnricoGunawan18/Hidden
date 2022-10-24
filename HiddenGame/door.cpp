#include "stdio.h"
#include "DxLib.h"
#include "miniWinGame1.h"
#include "door.h"

static int baseX, baseY;
door_t* dt = NULL;
void door_body( door_t* dt );
int DoorPic;


door_t* getDoorPtr( void ) {
	return dt;
}

int door_init( void ) {
	dt = ( door_t* )malloc( sizeof( door_t ) );

	DoorPic = LoadGraph( "door.png" );
	dt->baseX = 630;
	dt->baseY = 800;
	dt->radius = 40;
	return 0;
}



int door_disp( void ) {

	door_body( dt );

	return 0;
}

void door_body( door_t* dt ) {
	int x1 = dt->baseX - 40;
	int x2 = dt->baseX + 40;
	int y1 = dt->baseY - 40;
	int y2 = dt->baseY + 40;
	unsigned int col = 0xf0ffff;
	DrawExtendGraph( x1, y1, x2, y2, DoorPic, TRUE );

}

int door_finish( void ) {
	free( dt ); dt = NULL;
	return 0;
}
