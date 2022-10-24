#pragma once

/**
* Player
*
*
*/

/* �v���C���[�̏�� */


typedef struct gt {
	int state;/* 0..Normal/1..Crash/..*/
	int baseX, baseY;
	int radius;

	float c_radius;
} gamezone_t;


int gamezone_init( void );
int gamezone_disp( void );
int gamezone_finish( void );
gamezone_t* getGamezonePtr( void );
