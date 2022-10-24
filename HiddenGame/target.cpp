/**
*
*
*
*
*/
#include "stdio.h"
#include "DxLib.h"
#include "miniWinGame1.h"
#include "target.h"
#include "math.h"

static int baseX, baseY;
target_t* tt = NULL;
void target_body( target_t* tt );
int TargetPic;


target_t* getTargetPtr( void ) {
	return tt;
}

/*
�v���C���[������


*/
int target_init( void ) {
	/* ������ */
	tt = ( target_t* )malloc( sizeof( target_t ) );

	TargetPic = LoadGraph( "targetstar.png" );
	tt->state = kTARGETSTATE_NORMAL;
	tt->baseX = ScreenWidth / 2;
	tt->baseY = ScreenHeight / 2;
	tt->radius = 48;
	return 0;
}



/*
* �v���C���[�\��
*
*
*/
int target_disp( void ) {

	switch ( tt->state ) {

	case kTARGETSTATE_NORMAL:

		target_body( tt );
		return 0;
		break;

	case kTARGETSTATE_GET:
		return 1;
		break;
	}
}

void target_body( target_t* tt ) {
	int x1 = tt->baseX - 50;
	int x2 = tt->baseX + 50;
	int y1 = tt->baseY - 50;
	int y2 = tt->baseY + 40;
	unsigned int col = 0xf0ffff;
	DrawExtendGraph( x1, y1, x2, y2, TargetPic, TRUE );

}

/*
�v���C���[�I��


*/
int target_finish( void ) {
	free( tt ); tt = NULL;
	return 0;
}
