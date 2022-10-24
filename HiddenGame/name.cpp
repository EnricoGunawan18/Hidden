#include "DxLib.h"
#include "mode.h"
#include "name.h"
#include "miniWinGame1.h"

char nameInsert[ 4 ];

int name_init( void ) {
	return modeseq_Increase;
}

int name_disp( void ) {

	if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
		return modeseq_Exit;
	}
	SetFontSize( 108 );
	DrawString( ( ScreenWidth / 2 ) - 210, ( ScreenHeight / 2 ) - 50, "Name : ", GetColor( 255, 255, 255 ) );

	KeyInputString( ( ScreenWidth / 2 ) - 210, ( ScreenHeight / 2 ) + 100, 3, nameInsert, FALSE );
	nameInsert[ 3 ] = '\0';

	if ( CheckHitKey( KEY_INPUT_RETURN ) ) {
		return modeseq_Increase;
	}

}

int name_finish( void ) {
	return modeseq_Skip;
}

char* name_insert( void ) {
	return nameInsert;
}