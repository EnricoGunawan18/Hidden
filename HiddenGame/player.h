#pragma once

/**
* Player
*
*
*/

/* �v���C���[�̏�� */
enum {
	kPLAYERSTATE_NORMAL = 0,  // �ʏ���	
	kPLAYERSTATE_CRASH = 1,   // ����A�j���[�V�������
	kPLAYERSTATE_GAMEOVER = 2,// �Q�[���I�[�o�[�\��
	kPLAYERSTATE_SUCCESS = 3,

};

typedef struct pt {
	int state;/* 0..Normal/1..Crash/..*/
	int baseX, baseY;
	int radius;
	int collision;
	bool left_collision;
	bool right_collision;
	bool top_collision;
	bool bottom_collision;
	bool left_control;
	bool right_control;
	double x1, y1, x2, y2, x3, y3;

	int crashTmr;
	float c_radius;
	int gameoverTmr;/* �Q�[���I�[�o�[�^�C�}�[�@*/
} player_t;


int player_init( void );
int player_disp( void );
int player_finish( void );
player_t* getPlayerPtr(void);


