#include "DxLib.h"
#include "miniWinGame1.h"
#include "mode.h"
#include "title.h"

int title_init( void ) {
	return modeseq_Increase;
}

int title_disp( void ) {

	if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
		return modeseq_Exit;
	}

	SetFontSize( 108 );
	DrawString( ( ScreenWidth / 2 ) - 210, ( ScreenHeight / 2 ) - 150, "Hidden", GetColor( 255, 255, 255 ) );

	SetFontSize( 72 );
	DrawString( ( ScreenWidth / 2 ) - 370, ( ScreenHeight / 2 ) + 100, "Press Enter to Start", GetColor( 255, 255, 255 ) );

	WaitTimer( 60 );

	if ( CheckHitKey( KEY_INPUT_RETURN ) ) {
		return modeseq_Increase;
	}


}

int title_finish( void ) {

	return modeseq_Increase;
}