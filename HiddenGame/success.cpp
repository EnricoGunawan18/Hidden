#include "DxLib.h"
#include "mode.h"
#include "success.h"
#include "time.h"
#include "miniWinGame1.h"
#include "player.h"
#include "score.h"
#include "game.h"

static clock_t startTm;
int lastPlace;
int nowScore;

int success_init( void ) {
	startTm = clock( );
	lastPlace = last_place();
	nowScore = get_score( );
	return modeseq_Increase;
}

int success_disp( void ) {
	clock_t elaps = ( clock( ) - startTm ) / CLOCKS_PER_SEC;


	if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
		return modeseq_Exit;
	}
	SetFontSize( 108 );
	DrawString( ( ScreenWidth / 2 ) - 210, ( ScreenHeight / 2 ) - 50, "Success", GetColor( 255, 255, 255 ) );


	if ( elaps < 3 ) {
		return 0;
	}

	return modeseq_Increase;

}

int success_finish( void ) {
	player_finish( );
	if ( lastPlace >= nowScore ) {
		return modeseq_Increase;
	} else {
		return modeseq_SevenSkip;
	}

}