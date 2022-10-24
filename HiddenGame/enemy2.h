#pragma once

/**
*
*
*
*
*/

#define ENEMY_TYPE_1 true

enum {
	kENEMY2STATE_NORMAL = 0,
	kENEMY2STATE_ENGAGE = 1,
};



typedef struct et2 {
	int init_x, init_y;/* 画面上の初期位置 */
	double base_x, base_y;/* 位置 */
	int coli_x, coli_y;/* コリジョン領域移動速度 */
	int coli_x2, coli_y2;
	int collision;
	double vec_x1, vec_y1;
	double vec_x2, vec_y2;
	double vec_x3, vec_y3;
	double vec_x4, vec_y4;
	double x1, y1, x2, y2, x3, y3;


	unsigned int cnt;/* Up カウンター */
	unsigned int id;/* ID */
	int state;
	et2* nextEnemy;
} enemy2_t;



int enemy2_init( void );
int enemy2_display( void );
int enemy2_finish( void );/* 敵の終了化 */
enemy2_t* getEnemy2Ptr( void );

#pragma once
