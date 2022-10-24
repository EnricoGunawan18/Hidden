/*
	�^�C�g�����
*/

#include "DxLib.h"
#include "miniWinGame1.h"
#include "mode.h"
#include "game.h"
#include "time.h"
#include "player.h"
#include "enmBullet.h"
#include "enemy1.h"
#include "enemy2.h"
#include "enemy3.h"
#include "collision.h"
#include "gameZone.h"
#include "target.h"
#include "door.h"

static clock_t startTm;
static int timeScore = 0;

/* Game Mode ������ */
int game_init( void ) {
	startTm = clock( );

	player_init( );/* �v���C���[�̏����� */
	enemy1_init( );/* �G�̏����� */
	enemy2_init( );/* �G�̏����� */
	enemy3_init( );/* �G�̏����� */
	gamezone_init( );
	target_init( );
	door_init( );
	return modeseq_Increase;
}

/* Game Mode ���s*/
static int num = 0;
int game_disp( void ) {
	clock_t elaps = ( clock( ) - startTm ) / CLOCKS_PER_SEC;
	int player_state;
	gamezone_disp( );
	target_disp( );
	enemy1_display( );
	enemy2_display( );
	enemy3_display( );
	door_disp( );
#if DEBUG
	DrawFormatString( 0, 16, GetColor( 255, 255, 255 ), ( const TCHAR* )"GAME DISPLAY MODE:ELAPS TIME: %d", elaps );
#endif

	num++;

	SetFontSize( 24 );
	DrawFormatString( 128, 128,
					  GetColor( 255, 255, 255 ),
					  ( const TCHAR* )"PRESS ESC KEY TO EXIT" );

	DrawFormatString( 128, 256, GetColor( 255, 255, 255 ), ( const TCHAR* )"%d", elaps );

	if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
		return modeseq_Exit;
	}


	player_state = player_disp( );
	enmBullet_update( );

	collisionDetect( );

	timeScore = elaps;


	if ( player_state > 0 ) {
		return modeseq_Increase;
	}

	return 0;


	return modeseq_Increase;
}

int game_finish( void ) {
	player_t* pt = getPlayerPtr( );
	enemy1_finish( );
	enemy2_finish( );
	enemy3_finish( );
	enmBullet_finish( );
	gamezone_finish( );
	target_finish( );
	door_finish( );

	if ( pt->state == kPLAYERSTATE_SUCCESS ) {
		return modeseq_Increase;
	} else if ( pt->state == kPLAYERSTATE_GAMEOVER ) {
		return modeseq_SevenSkip;
	}
}


int get_score( void ) {
	return timeScore;
}

