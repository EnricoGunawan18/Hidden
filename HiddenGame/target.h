#pragma once

/**
* Player
*
*
*/

/* �v���C���[�̏�� */
enum {
	kTARGETSTATE_NORMAL = 0,  	
	kTARGETSTATE_GET = 1, 

};


typedef struct tt {
	int state;/* 0..Normal/1..Crash/..*/
	int baseX, baseY;
	int radius;

	float c_radius;
} target_t;


int target_init( void );
int target_disp( void );
int target_finish( void );
target_t* getTargetPtr( void );
#pragma once
