#include "DxLib.h"
#include "mode.h"
#include "score.h"
#include "miniWinGame1.h"
#include "game.h"
#include "name.h"
#include "string.h"
#include <stdio.h>

static int score[ 6 ] = { 999,999,999,999,999,999 };
//const char* name[ 6 ] = { "AAA", "BBB", "CCC", "DDD", "EEE", "FFF" };
static char name[ 7 ][ 4 ] = { "AAA", "BBB", "CCC", "DDD", "EEE", "FFF","\0" };


int newScore;
char* newName = NULL;
bool Retry1 = true;


int score_init( void ) {
	newScore = get_score( );
	newName = name_insert( );
	return modeseq_Increase;
}

int score_disp( void ) {


	if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
		return modeseq_Exit;
	}

	int temp = 0;
	char temp1[ 1 ][ 4 ];

	for ( int i = 0; i < 6; i++ ) {
		if ( score[ i ] > newScore ) {
			temp = score[ i ];
			score[ i ] = newScore;
			newScore = temp;

			//temp1 = name[ i ];
			//name[ i ] = newName;
			//newName = temp1;
			if ( newName ) {

				temp1[ 0 ][ 0 ] = name[ i ][ 0 ];
				temp1[ 0 ][ 1 ] = name[ i ][ 1 ];
				temp1[ 0 ][ 2 ] = name[ i ][ 2 ];
				temp1[ 0 ][ 3 ] = '\0';

				name[ i ][ 0 ] = *( newName + 0 );
				name[ i ][ 1 ] = newName[ 1 ];
				name[ i ][ 2 ] = newName[ 2 ];
				name[ i ][ 3 ] = '\0';

				*( newName + 0 ) = temp1[ 0 ][ 0 ];
				newName[ 1 ] = temp1[ 0 ][ 1 ];
				newName[ 2 ] = temp1[ 0 ][ 2 ];
				newName[ 3 ] = '\0';

			}
		}
	}

	SetFontSize( 72 );
	DrawString( ( ScreenWidth / 2 ) - 300, 20, "Press R to Restart", GetColor( 255, 255, 255 ) );
	DrawString( ( ScreenWidth / 2 ) - 350, 75, "Press Enter to Title", GetColor( 255, 255, 255 ) );

	DrawString( 50, 150, "Rank", GetColor( 255, 255, 255 ) );
	DrawFormatString( ( ScreenWidth / 2 ) - 50, 150, GetColor( 255, 255, 255 ), "Name" );
	DrawFormatString( ScreenWidth - 250, 150, GetColor( 255, 255, 255 ), "Time" );

	for ( int i = 0; i < 6; i++ ) {
		DrawFormatString( 50, 250 + ( 100 * i ), GetColor( 255, 255, 255 ), "%d", i + 1 );
		//DrawFormatString( (ScreenWidth / 2 ) - 50, 350 + ( 100 * i ), GetColor( 255, 255, 255 ), "%s",name[i] );
		DrawString( ( ScreenWidth / 2 ) - 50, 250 + ( 100 * i ), name[ i ], GetColor( 255, 255, 255 ) );
		DrawFormatString( ScreenWidth - 250, 250 + ( 100 * i ), GetColor( 255, 255, 255 ), "%d", score[ i ] );
	}

	WaitTimer( 60 );

	if ( CheckHitKey( KEY_INPUT_R ) ) {
		return modeseq_Increase;
	}
	if ( CheckHitKey( KEY_INPUT_RETURN ) ) {
		Retry1 = false;
		return modeseq_Increase;
	}

}

int score_finish( void ) {
	if ( Retry1 == true ) {
		return modeseq_Increase;
	} else {
		Retry1 = true;
		return modeseq_Game;
	}
}



int last_place( void ) {

	return score[ 5 ];

}