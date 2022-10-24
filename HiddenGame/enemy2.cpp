/**
*
*
*
*
*/
#include "stdio.h"
#include "DxLib.h"
#include "miniWinGame1.h"
#include "player.h"
#include "enemy2.h"
#include "enmBullet.h"
#define  _USE_MATH_DEFINES
#include "math.h"

static int base_x, base_y;
static enemy2_t* ep = NULL;
void enemy_body( enemy2_t* ep );
void enemy_flashlight( enemy2_t* ep );
void first_movement( enemy2_t* ep );
void second_movement( enemy2_t* ep );
void third_movement( enemy2_t* ep );
void fourth_movement( enemy2_t* ep );
void reset( enemy2_t* ep );
int GHandle2;
int GHandleF2;
double rotate2;
double rotatefl2;

enemy2_t* getEnemy2Ptr( void ) {
	return ep;
}


int enemy2_init( void ) {

	ep = ( enemy2_t* )malloc( sizeof( enemy2_t ) );
	ep->state = kENEMY2STATE_NORMAL;
	ep->base_x = 1160 - 100;
	ep->base_y = 563 - 100;
	ep->cnt = 0;
	ep->collision = 60;
	ep->vec_x1 = 1.395 * 3 / 4;
	ep->vec_y1 = 1.605 * 3 / 4;
	ep->vec_x2 = 1.45 * 3 / 4;
	ep->vec_y2 = 2.03 * 3 / 4;
	ep->vec_x3 = 2.47 * 3 / 4;
	ep->vec_y3 = 1.405 * 3 / 4;
	ep->vec_x4 = 0.375 * 3 / 4;
	ep->vec_y4 = 1.83 * 3 / 4;
	rotate2 = 13.5;
	rotatefl2 = 120;


	GHandle2 = LoadGraph( "enemy.png" );
	//GHandleF2 = LoadGraph( "flashlight.png" );

	return 0;
}

int enemy2_display( void ) {

	player_t* pt = getPlayerPtr( );


	switch ( ep->state ) {
	case kENEMY2STATE_NORMAL:

		if ( pt->state == kPLAYERSTATE_NORMAL ) {
			first_movement( ep );
			second_movement( ep );
			third_movement( ep );
			fourth_movement( ep );
			reset( ep );
		}

		enemy_body( ep );
		enemy_flashlight( ep );
		break;


	case kENEMY2STATE_ENGAGE:

		if ( pt->state == kPLAYERSTATE_NORMAL ) {


			if ( ep->base_x > pt->baseX ) {
				ep->base_x -= 2.8 / 2;
			} else if ( ep->base_x < pt->baseX ) {
				ep->base_x += 2.8 / 2;
			} else {

			}

			if ( ep->base_y > pt->baseY ) {
				ep->base_y -= 2.8 / 2;
			} else if ( ep->base_y < pt->baseY ) {
				ep->base_y += 2.8 / 2;
			} else {

			}
		}

		enemy_body( ep );

		if ( ep->cnt % 40 == 0 ) {
			enmBullet_Go( ep->base_x, ep->base_y );
		}
		ep->cnt++;
		break;
	}
	return 0;
}


void enemy_body( enemy2_t* ep ) {

	unsigned int col = 0xf0ffff;

	DrawRotaGraph( ep->base_x, ep->base_y, 0.6, rotate2, GHandle2, TRUE, FALSE );

}

void enemy_flashlight( enemy2_t* ep ) {

	ep->x1 = ep->base_x + ( 30 * cos( ( rotatefl2 + 25.68168152165 ) * 0.01745 ) );
	ep->y1 = ep->base_y + (30 * sin( ( rotatefl2 + 25.68168152165 ) * 0.01745 ) );
	ep->x2 = ep->x1 + ( 186 * cos( rotatefl2 * 0.01745 ) - 33.5 * sin( rotatefl2 * 0.01745 ) );
	ep->y2 = ep->y1 + ( 186 * sin( rotatefl2 * 0.01745 ) + 33.5 * cos( rotatefl2 * 0.01745 ) );
	ep->x3 = ep->x1 + ( 186 * cos( ( rotatefl2 + 25.68168152165 ) * 0.01745 ) - 33.5 * sin( ( rotatefl2 + 25.68168152165 ) * 0.01745 ) );
	ep->y3 = ep->y1 + ( 186 * sin( ( rotatefl2 + 25.68168152165 ) * 0.01745 ) + 33.5 * cos( ( rotatefl2 + 25.68168152165 ) * 0.01745 ) );

	DrawTriangle( ep->x1, ep->y1, ep->x2, ep->y2, ep->x3, ep->y3, GetColor( 255, 255, 255 ), TRUE );

	//DrawRotaGraph2( ep->base_x, ep->base_y, 133, -87, 0.36, rotate2, GHandleF2, TRUE, FALSE );
}



int enemy2_finish( void ) {
	free( ep ); ep = NULL;
	return 0;
}

void first_movement( enemy2_t* ep ) {

	if ( rotatefl2 < 120 || rotatefl2 >= 410 ) {
		rotatefl2 += 5;
		if ( rotatefl2 == 420 ) {
			rotatefl2 = 60;
		}
	}

	if ( rotate2 >= 18.6 && ep->vec_x1 != 0 && ep->vec_y1 != 0 ) {
		rotate2 += 0.1;
	}

	if ( ep->vec_x1 != 0 && ep->vec_y1 != 0 && rotate2 >= 19.8 ) {
		rotate2 = 13.5;
	}

	ep->base_x = ep->base_x - ep->vec_x1;
	if ( ep->base_x <= 881 - 100) {
		ep->vec_x1 = 0;
	}
	ep->base_y = ep->base_y + ep->vec_y1;
	if ( ep->base_y >= 884 - 100) {
		ep->vec_y1 = 0;
	}
}

void second_movement( enemy2_t* ep ) {

	if ( ep->vec_x1 == 0 && ep->vec_y1 == 0 ) {

		if ( rotatefl2 < 205 ) {
			rotatefl2 += 5;
		}

		if ( ep->vec_x2 != 0 && ep->vec_y2 != 0 ) {
			rotate2 += 0.1;
			if ( rotate2 >= 15 ) {
				rotate2 = 15;
			}
		}
		ep->base_x = ep->base_x - ep->vec_x2;
		if ( ep->base_x <= 591 - 100) {
			ep->vec_x2 = 0;
		}
		ep->base_y = ep->base_y - ep->vec_y2;
		if ( ep->base_y <= 478 - 100) {
			ep->vec_y2 = 0;
		}
	}
}

void third_movement( enemy2_t* ep ) {

	if ( ep->vec_x2 == 0 && ep->vec_y2 == 0 && ep->vec_x1 == 0 && ep->vec_y1 == 0 ) {

		if ( rotatefl2 < 295 ) {
			rotatefl2 += 5;
		}

		if ( ep->vec_x3 != 0 && ep->vec_y3 != 0 ) {

			rotate2 += 0.1;
			if ( rotate2 >= 16.55 ) {
				rotate2 = 16.55;
			}
		}


		ep->base_x = ep->base_x + ep->vec_x3;
		if ( ep->base_x >= 1085 - 100) {
			ep->vec_x3 = 0;
		}
		ep->base_y = ep->base_y - ep->vec_y3;
		if ( ep->base_y <= 197 - 100) {
			ep->vec_y3 = 0;
		}
	}
}

void fourth_movement( enemy2_t* ep ) {

	if ( ep->vec_x2 == 0 && ep->vec_y2 == 0 && ep->vec_x1 == 0 && ep->vec_y1 == 0 && ep->vec_x3 == 0 && ep->vec_y3 == 0 ) {

		if ( rotatefl2 < 410 ) {
			rotatefl2 += 5;

		}
		if ( rotatefl2 > 410 ) {
			rotatefl2 = 410;
		}

		if ( ep->vec_x4 != 0 && ep->vec_y4 != 0 ) {

			rotate2 += 0.1;
			if ( rotate2 >= 18.6 ) {
				rotate2 = 18.6;
			}
		}

		ep->base_x = ep->base_x + ep->vec_x4;
		if ( ep->base_x >= 1160 - 100) {
			ep->vec_x4 = 0;
		}
		ep->base_y = ep->base_y + ep->vec_y4;
		if ( ep->base_y >= 563 - 100) {
			ep->vec_y4 = 0;
		}

	}
}

void reset( enemy2_t* ep ) {


	if ( ep->vec_x2 == 0 && ep->vec_y2 == 0 && ep->vec_x1 == 0 && ep->vec_y1 == 0 && ep->vec_x3 == 0 && ep->vec_y3 == 0 && ep->vec_x4 == 0 && ep->vec_y4 == 0 ) {


		ep->vec_x1 = 1.395 * 3 / 4;
		ep->vec_y1 = 1.605 * 3 / 4;
		ep->vec_x2 = 1.45 * 3 / 4;
		ep->vec_y2 = 2.03 * 3 / 4;
		ep->vec_x3 = 2.47 * 3 / 4;
		ep->vec_y3 = 1.405 * 3 / 4;
		ep->vec_x4 = 0.375 * 3 / 4;
		ep->vec_y4 = 1.83 * 3 / 4;

	}
}


