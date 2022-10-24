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
#include "enemy1.h"
#include "enmBullet.h"
#define  _USE_MATH_DEFINES
#include "math.h"

static int base_x, base_y;
static enemy1_t* ep = NULL;
void enemy_body(enemy1_t* ep);
void enemy_flashlight(enemy1_t* ep);
void first_movement(enemy1_t* ep);
void second_movement(enemy1_t* ep);
void third_movement(enemy1_t* ep);
void reset(enemy1_t* ep);
int GHandle;
int GHandleF;
double rotate;
double rotatefl1;

enemy1_t* getEnemy1Ptr(void) {
	return ep;
}


int enemy1_init(void) {

	ep = (enemy1_t*)malloc(sizeof(enemy1_t));
	ep->state = kENEMYSTATE_NORMAL;
	ep->base_x = 729-100;
	ep->base_y = 734 - 100;
	ep->cnt = 0;
	ep->collision = 60;
	ep->vec_x1 = 2.28 * 3 / 4;
	ep->vec_y1 = 0.85 * 3 / 4;
	ep->vec_x2 = 1.735 * 3 / 4;
	ep->vec_y2 = 1.34 * 3 / 4;
	ep->vec_x3 = 0.545 * 3 / 4;
	ep->vec_y3 = 2.19 * 3 / 4;
	rotate = 10.6;
	rotatefl1 = 315;

	GHandle = LoadGraph("enemy.png");
	//GHandleF = LoadGraph( "flashlight.png" );

	return 0;
}

int enemy1_display(void) {

	player_t* pt = getPlayerPtr();


	switch (ep->state) {
	case kENEMYSTATE_NORMAL:

		if (pt->state == kPLAYERSTATE_NORMAL) {
			first_movement(ep);
			second_movement(ep);
			third_movement(ep);
			reset(ep);
		}

		enemy_body(ep);
		enemy_flashlight(ep);
		break;


	case kENEMYSTATE_ENGAGE:

		if (pt->state == kPLAYERSTATE_NORMAL) {


			if (ep->base_x > pt->baseX) {
				ep->base_x -= 2.8 / 2;
			}
			else if (ep->base_x < pt->baseX) {
				ep->base_x += 2.8 / 2;
			}
			else {

			}

			if (ep->base_y > pt->baseY) {
				ep->base_y -= 2.8 / 2;
			}
			else if (ep->base_y < pt->baseY) {
				ep->base_y += 2.8 / 2;
			}
			else {

			}
		}

		enemy_body(ep);

		if (ep->cnt % 40 == 0) {
			enmBullet_Go(ep->base_x, ep->base_y);
		}
		ep->cnt++;
		break;
	}
	return 0;
}


void enemy_body(enemy1_t* ep) {

	unsigned int col = 0xf0ffff;


	DrawRotaGraph(ep->base_x, ep->base_y, 0.6, rotate, GHandle, TRUE, FALSE);

}

void enemy_flashlight(enemy1_t* ep) {

	ep->x1 = ep->base_x + (30 * cos((rotatefl1 + 25.68168152165) * 0.01745));
	ep->y1 = ep->base_y + (30 * sin((rotatefl1 + 25.68168152165) * 0.01745));
	ep->x2 = ep->x1 + (186 * cos(rotatefl1 * 0.01745) - 33.5 * sin(rotatefl1 * 0.01745));
	ep->y2 = ep->y1 + (186 * sin(rotatefl1 * 0.01745) + 33.5 * cos(rotatefl1 * 0.01745));
	ep->x3 = ep->x1 + (186 * cos((rotatefl1 + 25.68168152165) * 0.01745) - 33.5 * sin((rotatefl1 + 25.68168152165) * 0.01745));
	ep->y3 = ep->y1 + (186 * sin((rotatefl1 + 25.68168152165) * 0.01745) + 33.5 * cos((rotatefl1 + 25.68168152165) * 0.01745));
	//DEBUG LOG
	//DrawLine( ep->base_x, ep->base_y, ep->x1, ep->y1, GetColor( 255, 0, 0 ), TRUE );
	//DrawLine( ep->x1, ep->y1, ep->x2, ep->y2, GetColor( 255, 0, 0 ), TRUE );
	//DrawLine( ep->x2, ep->y2, ep->x3, ep->y3, GetColor( 255, 0, 0 ), TRUE );
	//DrawLine( ep->x1, ep->y1, ep->x3, ep->y3, GetColor( 255, 0, 0 ), TRUE );


	//DrawCircle( ( ep->base_x + 80 ) * cos( rotateflx ), ( ep->base_y ) * sin( 360 + rotatefly ), 40, col, TRUE );

	DrawTriangle(ep->x1, ep->y1, ep->x2, ep->y2, ep->x3, ep->y3, GetColor(255, 255, 255), TRUE);


	//DEBUG LOG 2
	//DrawRotaGraph2( ep->base_x, ep->base_y, 133, -87, 0.36, rotate, GHandleF, TRUE, FALSE );
}


int enemy1_finish(void) {
	free(ep); ep = NULL;
	return 0;
}

void first_movement(enemy1_t* ep) {

	if (rotatefl1 <= 80 || rotatefl1 > 315) {
		rotatefl1 -= 5;
		if (rotatefl1 == 0) {
			rotatefl1 = 360;
		}
	}
	if (rotate <= 6.5 && ep->vec_x1 != 0 && ep->vec_y1 != 0) {
		rotate -= 0.1;
	}

	if (ep->vec_x1 != 0 && ep->vec_y1 != 0 && rotate <= 4.1) {
		rotate = 10.6;
	}


	ep->base_x = ep->base_x + ep->vec_x1;
	if (ep->base_x >= 1185 - 100) {
		ep->vec_x1 = 0;
	}
	ep->base_y = ep->base_y - ep->vec_y1;
	if (ep->base_y <= 564 - 100) {
		ep->vec_y1 = 0;
	}
}


void second_movement(enemy1_t* ep) {

	if (ep->vec_x1 == 0 && ep->vec_y1 == 0) {

		if (rotatefl1 > 210) {
			rotatefl1 -= 5;
		}

		if (ep->vec_x2 != 0 && ep->vec_y2 != 0) {
			rotate -= 0.1;
			if (rotate <= 8.8) {
				rotate = 8.8;
			}
		}
		ep->base_x = ep->base_x - ep->vec_x2;
		if (ep->base_x <= 838 - 100) {
			ep->vec_x2 = 0;
		}
		ep->base_y = ep->base_y - ep->vec_y2;
		if (ep->base_y <= 296 - 100) {
			ep->vec_y2 = 0;
		}
	}
}




void third_movement(enemy1_t* ep) {

	if (ep->vec_x2 == 0 && ep->vec_y2 == 0 && ep->vec_x1 == 0 && ep->vec_y1 == 0) {
		if (rotatefl1 > 80) {
			rotatefl1 -= 5;
		}
		if (rotatefl1 < 80) {
			rotatefl1 = 80;
		}

		if (ep->vec_x3 != 0 && ep->vec_y3 != 0) {
			rotate -= 0.1;
			if (rotate <= 6.5) {
				rotate = 6.5;
			}
		}
		ep->base_x = ep->base_x - ep->vec_x3;
		if (ep->base_x <= 729 - 100) {
			ep->vec_x3 = 0;
		}
		ep->base_y = ep->base_y + ep->vec_y3;
		if (ep->base_y >= 734 - 100) {
			ep->vec_y3 = 0;
		}
	}
}


void reset(enemy1_t* ep) {

	if (ep->vec_x2 == 0 && ep->vec_y2 == 0 && ep->vec_x1 == 0 && ep->vec_y1 == 0 && ep->vec_x3 == 0 && ep->vec_y3 == 0) {
		ep->vec_x1 = 2.28 * 3 / 4;
		ep->vec_y1 = 0.85 * 3 / 4;
		ep->vec_x2 = 1.735 * 3 / 4;
		ep->vec_y2 = 1.34 * 3 / 4;
		ep->vec_x3 = 0.545 * 3 / 4;
		ep->vec_y3 = 2.19 * 3 / 4;
	}
}



