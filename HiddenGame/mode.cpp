/*
���[�h����
*/

#include "DxLib.h"
#include "mode.h" /*���[�h�ݒ�*/
#include "title.h"
#include "game.h"
#include "success.h"
#include "fail.h"
#include "score.h"
#include "name.h"

static int modeNum = 0; /*���݂̃��[�h�ԍ�*/
static int inGame = false;
int modeCtrl( int foo ) {
	int ret = FALSE;

	switch ( modeNum ) {

	case mode_TitleInit:
	{
		ret = title_init( );
	} break;
	case mode_TitleDisp:
	{
		ret = title_disp( );
	} break;
	case mode_TitleFinish:
	{
		ret = title_finish( );
	} break;
	case mode_GameInit:
	{
		inGame = true;
		ret = game_init( );
	} break;
	case mode_GameDisp:
	{
		ret = game_disp( );
	} break;
	case mode_GameFinish:
	{
		ret = game_finish( );
	} break;
	case mode_SuccessInit:
	{
		ret = success_init( );
	} break;
	case mode_SuccessDisp:
	{
		ret = success_disp( );
	} break;
	case mode_SuccessFinish:
	{
		ret = success_finish( );
	} break;
	case mode_NameInit:
	{
		ret = name_init( );
	} break;
	case mode_NameDisp:
	{
		ret = name_disp( );
	} break;
	case mode_NameFinish:
	{
		ret = name_finish( );
	} break;
	case mode_FailInit:
	{
		ret = fail_init( );
	} break;
	case mode_FailDisp:
	{
		ret = fail_disp( );
	} break;
	case mode_FailFinish:
	{
		ret = fail_finish( );
	} break;
	case mode_ScoreInit:
	{
		ret = score_init( );
	} break;
	case mode_ScoreDisp:
	{
		ret = score_disp( );
	} break;
	case mode_ScoreFinish:
	{
		ret = score_finish( );
	} break;
	case mode_Restart:
	{
		modeNum = mode_GameInit;
	} break;

	default:
	{
		modeNum = mode_TitleInit;
	} break;
	}

#if DEBUG
	DrawFormatString( 0, 0, GetColor( 255, 255, 255 ), ( const TCHAR* )"MODE: %d", modeNum );
#endif

	if ( ret > modeseq_Thuru ) {
		modeNum = modeNum + ret;
		ret = 0;
	} else if ( ret < modeseq_Thuru ) {
		return ret;
	}

	return ret;
}
