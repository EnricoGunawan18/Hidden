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
#include "enemy3.h"
#include "enmBullet.h"
#define  _USE_MATH_DEFINES
#include "math.h"

static int base_x, base_y;
static enemy3_t* ep = NULL;
void enemy_body( enemy3_t* ep );
void enemy_flashlight( enemy3_t* ep );
void first_movement( enemy3_t* ep );
void second_movement( enemy3_t* ep );
void third_movement( enemy3_t* ep );
void fourth_movement( enemy3_t* ep );
void reset( enemy3_t* ep );
int GHandle3;
int GHandleF3;
double rotate3;
double rotatefl3;


enemy3_t* getEnemy3Ptr( void ) {
	return ep;
}


int enemy3_init( void ) {

	ep = ( enemy3_t* )malloc( sizeof( enemy3_t ) );
	ep->state = kENEMY3STATE_NORMAL;
	ep->base_x = 806 - 100;
	ep->base_y = 338 - 100;
	ep->cnt = 0;
	ep->collision = 60;
	ep->vec_x1 = 2.58 * 3 / 4;
	ep->vec_y1 = 1.52 * 3 / 4;
	ep->vec_x2 = 3.525 * 3 / 4;
	ep->vec_y2 = 0.47 * 3 / 4;
	ep->vec_x3 = 1.1 * 3 / 4;
	ep->vec_y3 = 1.725 * 3 / 4;
	ep->vec_x4 = 0.155 * 3 / 4;
	ep->vec_y4 = 2.775 * 3 / 4;
	rotate3 = 5.2;
	rotatefl3 = 365;


	GHandle3 = LoadGraph( "enemy.png" );
	//GHandleF3 = LoadGraph( "flashlight.png" );



	return 0;
}

int enemy3_display( void ) {

	player_t* pt = getPlayerPtr( );


	switch ( ep->state ) {
	case kENEMY3STATE_NORMAL:

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


	case kENEMY3STATE_ENGAGE:

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


void enemy_body( enemy3_t* ep ) {

	unsigned int col = 0xf0ffff;

	DrawRotaGraph( ep->base_x, ep->base_y, 0.6, rotate3, GHandle3, TRUE, FALSE );

}

void enemy_flashlight( enemy3_t* ep ) {

	ep->x1 = ep->base_x + (30 * cos( ( rotatefl3 + 25.68168152165 ) * 0.01745 ) );
	ep->y1 = ep->base_y + ( 30 * sin( ( rotatefl3 + 25.68168152165 ) * 0.01745 ) );
	ep->x2 = ep->x1 + ( 186 * cos( rotatefl3 * 0.01745 ) - 33.5 * sin( rotatefl3 * 0.01745 ) );
	ep->y2 = ep->y1 + ( 186 * sin( rotatefl3 * 0.01745 ) + 33.5 * cos( rotatefl3 * 0.01745 ) );
	ep->x3 = ep->x1 + ( 186 * cos( ( rotatefl3 + 25.68168152165 ) * 0.01745 ) - 33.5 * sin( ( rotatefl3 + 25.68168152165 ) * 0.01745 ) );
	ep->y3 = ep->y1 + ( 186 * sin( ( rotatefl3 + 25.68168152165 ) * 0.01745 ) + 33.5 * cos( ( rotatefl3 + 25.68168152165 ) * 0.01745 ) );

	DrawTriangle( ep->x1, ep->y1, ep->x2, ep->y2, ep->x3, ep->y3, GetColor( 255, 255, 255 ), TRUE );


	//DrawRotaGraph2( ep->base_x, ep->base_y, 133, -87, 0.36, rotate3, GHandleF3, TRUE, FALSE );
}


int enemy3_finish( void ) {
	free( ep ); ep = NULL;
	return 0;
}

void first_movement( enemy3_t* ep ) {

	if ( ep->vec_x1 != 0 && ep->vec_y1 != 0 ) {
		rotate3 += 0.1;
		if ( rotatefl3 < 365 ) {
			rotatefl3 += 5;
		}
	}

	if ( ep->vec_x1 != 0 && ep->vec_y1 != 0 && rotate3 >= 5.2 ) {
		rotate3 = 5.2;
	}

	ep->base_x = ep->base_x + ep->vec_x1;
	if ( ep->base_x >= 1322 - 100) {
		ep->vec_x1 = 0;
	}
	ep->base_y = ep->base_y + ep->vec_y1;
	if ( ep->base_y >= 642 - 100) {
		ep->vec_y1 = 0;
	}
}

void second_movement( enemy3_t* ep ) {

	if ( ep->vec_x1 == 0 && ep->vec_y1 == 0 ) {

		if ( ep->vec_x2 != 0 && ep->vec_y2 != 0 ) {
			if ( rotatefl3 < 525 ) {
				rotatefl3 += 5;
			}
		}

		if ( ep->vec_x2 != 0 && ep->vec_y2 != 0 ) {
			rotate3 += 0.1;
			if ( rotate3 >= 8 ) {
				rotate3 = 8;
			}
		}
		ep->base_x = ep->base_x - ep->vec_x2;
		if ( ep->base_x <= 617 - 100) {
			ep->vec_x2 = 0;
		}
		ep->base_y = ep->base_y - ep->vec_y2;
		if ( ep->base_y <= 548 - 100) {
			ep->vec_y2 = 0;
		}
	}
}

void third_movement( enemy3_t* ep ) {

	if ( ep->vec_x2 == 0 && ep->vec_y2 == 0 && ep->vec_x1 == 0 && ep->vec_y1 == 0 ) {

		if ( ep->vec_x3 != 0 && ep->vec_y3 != 0 ) {
			if ( rotatefl3 > 400 ) {
				rotatefl3 -= 5;
			}
		}
		

		if ( ep->vec_x3 != 0 && ep->vec_y3 != 0 ) {
			rotate3 -= 0.1;
			if ( rotate3 <= 5.8 ) {
				rotate3 = 5.8;
			}
		}
		ep->base_x = ep->base_x + ep->vec_x3;
		if ( ep->base_x >= 837 - 100) {
			ep->vec_x3 = 0;
		}
		ep->base_y = ep->base_y + ep->vec_y3;
		if ( ep->base_y >= 893 - 100) {
			ep->vec_y3 = 0;
		}
	}
}

void fourth_movement( enemy3_t* ep ) {

	if ( ep->vec_x2 == 0 && ep->vec_y2 == 0 && ep->vec_x1 == 0 && ep->vec_y1 == 0 && ep->vec_x3 == 0 && ep->vec_y3 == 0 ) {

		if ( rotatefl3 > 245 ) {
			rotatefl3 -= 5;
		}

		if ( ep->vec_x4 != 0 && ep->vec_y4 != 0 ) {
			rotate3 -= 0.1;
			if ( rotate3 <= 3.1 ) {
				rotate3 = 3.1;
			}
		}
		ep->base_x = ep->base_x - ep->vec_x4;
		if ( ep->base_x <= 806 - 100) {
			ep->vec_x4 = 0;
		}
		ep->base_y = ep->base_y - ep->vec_y4;
		if ( ep->base_y <= 338 - 100) {
			ep->vec_y4 = 0;
		}
	}
}

void reset( enemy3_t* ep ) {

	if ( ep->vec_x2 == 0 && ep->vec_y2 == 0 && ep->vec_x1 == 0 && ep->vec_y1 == 0 && ep->vec_x3 == 0 && ep->vec_y3 == 0 && ep->vec_x4 == 0 && ep->vec_y4 == 0 ) {
		ep->vec_x1 = 2.58 * 3 / 4;
		ep->vec_y1 = 1.52 * 3 / 4;
		ep->vec_x2 = 3.525 * 3 / 4;
		ep->vec_y2 = 0.47 * 3 / 4;
		ep->vec_x3 = 1.1 * 3 / 4;
		ep->vec_y3 = 1.725 * 3 / 4;
		ep->vec_x4 = 0.155 * 3 / 4;
		ep->vec_y4 = 2.775 * 3 / 4;
	}
}
