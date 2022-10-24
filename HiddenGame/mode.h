#pragma once

/*
mode config
*/

enum {

	mode_TitleInit = 1,
	mode_TitleDisp,
	mode_TitleFinish,
	mode_GameInit,
	mode_GameDisp,
	mode_GameFinish,
	mode_SuccessInit,
	mode_SuccessDisp,
	mode_SuccessFinish,
	mode_NameInit,
	mode_NameDisp,
	mode_NameFinish,
	mode_FailInit,
	mode_FailDisp,
	mode_FailFinish,
	mode_ScoreInit,
	mode_ScoreDisp,
	mode_ScoreFinish,
	mode_Restart,


};


enum {
	modeseq_Thuru = 0,/* mode�J�ڕύX�Ȃ� */
	modeseq_Exit = -1,/* mode�J�ڏI�� */
	modeseq_Increase = 1,/* mode�J�ڎ��� */
	modeseq_Game = 2,/* mode�J�ڃQ�[����*/
	modeseq_Skip = 4,
	modeseq_IncreaseSkip = 5,
	modeseq_SevenSkip = 7,
};

int modeCtrl( int foo );