#pragma once

/**
*
*
*
*
*/

#define ENEMY_TYPE_1 true

enum {
	kENEMYSTATE_NORMAL = 0,
	kENEMYSTATE_ENGAGE = 1,
};



typedef struct et {
	int init_x, init_y;/* ��ʏ�̏����ʒu */
	double base_x, base_y;/* �ʒu */
	int coli_x, coli_y;/* �R���W�����̈�ړ����x */
	int coli_x2, coli_y2;
	int collision;
	double vec_x1, vec_y1;
	double vec_x2, vec_y2;
	double vec_x3, vec_y3;
	double x1, y1, x2, y2, x3, y3;

	unsigned int cnt;/* Up �J�E���^�[ */
	unsigned int id;/* ID */
	int state;
	et* nextEnemy;
} enemy1_t;



int enemy1_init( void );
int enemy1_display( void );
int enemy1_finish( void );/* �G�̏I���� */
enemy1_t* getEnemy1Ptr( void );

