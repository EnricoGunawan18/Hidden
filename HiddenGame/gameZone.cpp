/**
*
*
*
*
*/
#include "stdio.h"
#include "DxLib.h"
#include "miniWinGame1.h"
#include "gameZone.h"
#include "math.h"
//#include "player.h"


static int baseX, baseY;
gamezone_t* gt = NULL;
void gamezone_body( gamezone_t* gt );


gamezone_t* getGamezonePtr( void ) {
	return gt;
}

/*
�v���C���[������


*/
int gamezone_init( void ) {
	/* ������ */
	gt = ( gamezone_t* )malloc( sizeof( gamezone_t ) );

	gt->baseX = ScreenWidth / 2;
	gt->baseY = ScreenHeight / 2;
	gt->radius = 400;
	return 0;
}



/*
* �v���C���[�\��
*
*
*/
int gamezone_disp( void ) {
	gamezone_body( gt );
	return 0;
}

void gamezone_body( gamezone_t* gt ) {
	int x1 = gt->baseX;
	int x2 = gt->baseX;
	int x3 = gt->baseX;
	int y1 = gt->baseY;
	int y2 = gt->baseY;
	int y3 = gt->baseY;
	unsigned int col = 0xf0ffff;
	DrawCircle( gt->baseX, gt->baseY, gt->radius, col, false );

}

/*
�v���C���[�I��


*/
int gamezone_finish( void ) {
	free( gt ); gt = NULL;
	return 0;
}
