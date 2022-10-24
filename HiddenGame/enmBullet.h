#pragma once

/**
*
*
*
*
*/

#define ENMBULETTE_TYPE_1 true


enum {
	kENMBULLETSTATE_NORMAL = 0,
	kENMBULLETSTATE_CRASH = 1,
};


typedef struct eb {
	Vector2f scrn;/* ��ʏ�̈ʒu */
	Vector2f velo;/* �ړ����x */
	Vector2f tag;/* ��ʏ�̖ڕW�ʒu */
	int radius;
	unsigned int id;
	unsigned int cnt;/* Up �J�E���^�[ */
	unsigned int bcnt;/*�N���b�V�����̃J�E���^*/
	int state;
	float c_radius;
	eb* nextEnmBullet;
} enmbullet_t;

enmbullet_t* getENMBulletPtr( void );

int enmBullet_Go( int initX, int initY );
int enmBullet_update( void );


int enmBullet_init( enmbullet_t* p, int baseX, int baseY );
/* �G�̒e�̏����� */
int enmBullet_disp( void );/* �G�̒e�̕\��*/
int enmBullet_finish( void );/* �G�̒e�̏I���� */
int goENMBullet( int x, int y );/* �G�̒e�̕��o */

enmbullet_t* getENMBulletLink(void);
enmbullet_t* setENMBulletLink(enmbullet_t* bn);
enmbullet_t* getENMBulletNext(enmbullet_t* bp);


