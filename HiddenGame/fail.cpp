#include "DxLib.h"
#include "mode.h"
#include "fail.h"
#include "miniWinGame1.h"
#include "player.h"

bool Retry = true;

int fail_init( void ) {
	return modeseq_Increase;
}

int fail_disp( void ) {

	if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
		return modeseq_Exit;
	}
	SetFontSize( 108 );
	DrawString( ( ScreenWidth / 2 ) - 210, ( ScreenHeight / 2 ) - 200, "Failed", GetColor( 255, 255, 255 ) );

	SetFontSize( 72 );
	DrawString( ( ScreenWidth / 2 ) - 380, ( ScreenHeight / 2 ) + 50, "Press R to Restart", GetColor( 255, 255, 255 ) );
	DrawString( ( ScreenWidth / 2 ) - 420, ( ScreenHeight / 2 ) + 150, "Press Enter to Title", GetColor( 255, 255, 255 ) );

	if ( CheckHitKey( KEY_INPUT_R ) ) {
	return modeseq_Increase;
	}
	if ( CheckHitKey( KEY_INPUT_RETURN ) ) {
		Retry = false;
		return modeseq_Increase;
	}

}

int fail_finish( void ) {
	player_finish( );
	if ( Retry == true ) {
	return modeseq_Skip;
	} else {
		Retry = true;
		return modeseq_IncreaseSkip;
	}
}