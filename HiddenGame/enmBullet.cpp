/**
* �G����������e
*
*
*
*/
#include "stdio.h"
#include "DxLib.h"
#include "miniWinGame1.h"
#include "player.h"
#include "enmBullet.h"
#include "math.h"

#if ENMBULETTE_TYPE_1


static enmbullet_t* bp = NULL; /* �G�̒e(enemy bullet)�̐擪�̃|�C���^ */
static unsigned long id = 0;

/*
* Enemy Bullet�̐擪�̃|�C���^��Ԃ�
*/
enmbullet_t* getENMBulletLink( void ) 
{
	return bp;
}

/*
* Enemy Bullet�̐擪�̃|�C���^��ݒ肷��
*/
enmbullet_t* setENMBulletLink( enmbullet_t* bn ) 
{
	bp = bn;
	return bp;
}

/*
* Enemy Bullet�̎��̃|�C���^��擾����
*/
enmbullet_t* getENMBulletNext( enmbullet_t* bp ) 
{
	return bp->nextEnmBullet;
}


/*
* Enemy Bullet�̐V�����̈��擾����
*/
static enmbullet_t* getNewEp( void ) 
{
	enmbullet_t* en;
	en = ( enmbullet_t* )malloc( sizeof( enmbullet_t ) );
	if ( en == NULL ) return NULL;
	en->nextEnmBullet = NULL;
	en->id = id++;
	en->cnt = 0;
	en->state = kENMBULLETSTATE_NORMAL;
	en->c_radius = en->radius = 8;
	return en;
}

/*
* Enemy Bullet������N���X�g�ɒǉ�����
*/
static enmbullet_t* appendEp( enmbullet_t* et ) 
{
	enmbullet_t* en = getENMBulletLink( );/* �擪�̃|�C���^���炤 */
	if ( en == NULL ) 
	{/* �擪�ɒǉ����� */
		et = setENMBulletLink( et );
		return et;
	}
	do { /* �Ō��������āA�ǉ����� */
		if ( en->nextEnmBullet == NULL ) 
		{
			en->nextEnmBullet = et;   /* �Ō�̃f�[�^�ɒǉ����� */
			et->nextEnmBullet = NULL; /* ���g�̎����Ȃ����Ƃ���� NULL������ */
			break;
		}
		en = en->nextEnmBullet;/* ����T�� */
	} while ( 1 );
	return en;
}

/*
*Enemy Bullet����X�g����͂���
*/
static enmbullet_t* linkOutEp( enmbullet_t* en ) 
{
	enmbullet_t* ep = getENMBulletLink( );
	if ( ep == en ) 
	{/*�擪�� */
		return setENMBulletLink( en->nextEnmBullet );
	}
	do {
		/* ���g��w�������|�C���^��T�� */
		if ( ep->nextEnmBullet == en ) 
		{/* �������̂ŁA���g�̎��̃|�C���^����g������|�C���^�Ɠ���ւ��� */
			ep->nextEnmBullet = en->nextEnmBullet;
			free( en );/* ���g�̃�������J������ */
			break;
		}
		ep = ep->nextEnmBullet;/* ���̃|�C���^��擾���� */
		if ( ep == NULL ) 
		{/* �Ō�܂ŗ���������̂ŏI�� */
			break;
		}
	} while ( 1 );
	return ep;
}


/*
*Enemy Bullet�𔭐�������
*  �܂�A�G�̒e�̔��ˁI
*
* initX,initY�͒e�̔����ʒu
*
*/
int enmBullet_Go( int initX, int initY ) 
{
	/* �G�̒e�̃������̈��擾���� */
	enmbullet_t* et = getNewEp( );
	appendEp( et );/* Enemy Bullet Link�ɉ����� */

	/* �v���C���[����擾���� */
	player_t* pt = getPlayerPtr( );
	et->tag.x = pt->baseX;/* player�̈ʒu��L�� */
	et->tag.y = pt->baseY - 30;
	et->scrn.x = initX;/* �����ʒu */
	et->scrn.y = initY;

	/* �e�̋O����v�Z���� */
	float x, y, r;
	float nx, ny;
	/* �ڕW�_(�v���C���[�̈ʒu) - �N�_(���g�̈ʒu) => �ړ���������x�N�g�� */
	x = et->tag.x - et->scrn.x;
	y = et->tag.y - et->scrn.y;
	/* �����x�N�g���̐��K�� Normalize */
	r = sqrt(x * x + y * y);

	nx = x / r;
	ny = y / r;
	/* �ړ����鑬���@*/
	et->velo.x = 2 * nx;
	et->velo.y = 2 * ny;

	return 0;
}


/*
          LOGICAL | BIT
    INV             ~
    NOT   !
	AND		&&		&
	OR		||		|
	XOR				^

*/

/*
* Enemy Bullet�̕`��
*/

void enmBullet_draw( enmbullet_t* ef ) 
{
	if ( ef->nextEnmBullet != NULL ) 
	{/* �ċN�Ăяo������ă����N�̌�납��`�悷�� */
		enmBullet_draw( ef->nextEnmBullet );
	}

	switch ( ef->state ) 
	{
        case kENMBULLETSTATE_NORMAL: /* �ʏ��� */
		{
          if (ef->scrn.y > (ScreenHeight - 120)) 
		  {
			//ef->velo.y = -1 * ef->velo.y;
          }
          if ((ef->scrn.y < (0)) || (ef->scrn.y > ScreenHeight)) 
		  {/* ��ʊO�ɏo���̂ŏI�������� */
            linkOutEp(ef); /* temination */
            return;
          }
		  /* �ړ� */
		  ef->scrn.x += ef->velo.x;
          ef->scrn.y += ef->velo.y;
		  /* �`�� */
          DrawCircle(ef->scrn.x, ef->scrn.y, 4, 0xff0000, true);
        } 
		break;

        case kENMBULLETSTATE_CRASH: 	/* �j���� */
		{/* �j�󂵂��̂ŏI�� */
          linkOutEp(ef); /* temination */
          return;
        } 
		break;
	}
}

/*
*Enemy Bullet�̍X�V����
*/
int enmBullet_update( void ) 
{
	enmbullet_t* en = getENMBulletLink( );/* �擪�̃|�C���^���炤 */
	if ( en != NULL ) 
	{/* �`���Ăяo�� */
		enmBullet_draw( en );
	}
	return 0;
}

/*
*Enemy Bullet�̃������̉��
*/
static void enmBullet_free( enmbullet_t* ef ) 
{
	if ( ef->nextEnmBullet != NULL ) {
		enmBullet_free( ef->nextEnmBullet );
	}
	free( ef );
}

/*
*Enemy Bullet�̏���������
*/
int enmBullet_init( ) 
{
	setENMBulletLink( NULL );
	id = 0;
	return 0;
}

/*
*Enemy Bullet�̏I��������
*/
int enmBullet_finish( void )
{
	enmbullet_t* en = getENMBulletLink( );/* �擪�̃|�C���^���炤 */
	if ( en != NULL ) 
	{/* ��� */
		enmBullet_free( en );
	}
	setENMBulletLink( NULL );
	return 0;
}



int goEnmBullet( int x, int y )/* �G�̕��o */
{
	return 0;
}


#endif
