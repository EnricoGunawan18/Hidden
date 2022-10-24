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
#include "math.h"
#include "mode.h"


static int baseX, baseY;
player_t* pt = NULL;
void player_body(player_t* pt);
int GHandleP;
double RotateP;
double rotatepl;


player_t* getPlayerPtr(void) {
	return pt;
}

/*
�v���C���[������


*/
int player_init(void) {
	/* ������ */
	pt = (player_t*)malloc(sizeof(player_t));

	pt->state = kPLAYERSTATE_NORMAL;
	pt->baseX = /*630*/630;
	pt->baseY = /*800*/800;
	pt->collision = 30;
	RotateP = 0;
	pt->left_collision = false;
	pt->right_collision = false;
	pt->top_collision = false;
	rotatepl = 0;

	GHandleP = LoadGraph("player.png");

	return 0;
}

int player_disp(void) {
	/* ���� */
	/* �ړ� */
	/* �\�� */
	/**
	*
	*
	*    /\
	*   /  \
	*  /    \
	* /______\
	*
	*    ��baseX
	*
	*/

	switch (pt->state) {

	case kPLAYERSTATE_NORMAL:
	{
		if (CheckHitKey(KEY_INPUT_LEFT)) {/* left arrow on */
			if (pt->left_collision == true || (pt->top_collision == true && pt->baseX < ScreenWidth / 2)) {
			}
			else {
				pt->baseX = pt->baseX - 3;
				if (CheckHitKey(KEY_INPUT_UP) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0) {
					/*if ( RotateP >= 1.6 && RotateP < 4.7 ) {
						RotateP += 0.05;
						if ( RotateP >= 4.7 ) {
							RotateP = 4.7;
						}
					} else if ( RotateP > 6.3 ) {
						RotateP -= 6.3;
					} else if ( RotateP < 0 ) {
						RotateP += 6.3;
					} else {
						RotateP -= 0.05;
					}*/
					if (rotatepl >= 90 && rotatepl <= 270) {
						rotatepl += 5;
						if (rotatepl >= 270) {
							rotatepl = 270;
						}
					}
					else if (rotatepl > 360) {
						rotatepl -= 360;
					}
					else if (rotatepl < 0) {
						rotatepl += 360;
					}
					else {
						rotatepl -= 5;
					}

				}
			}
		}

		if (CheckHitKey(KEY_INPUT_RIGHT)) {/* right arrow on */
			if (pt->right_collision == true || (pt->top_collision == true && pt->baseX > ScreenWidth / 2)) {

			}
			else {
				pt->baseX = pt->baseX + 3;
				if (CheckHitKey(KEY_INPUT_UP) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0) {

					/*if ( RotateP > 1.6 && RotateP <= 4.7 ) {
						RotateP -= 0.05;
						if ( RotateP <= 1.6 ) {
							RotateP = 1.6;
						}
					} else if ( RotateP > 6.3 ) {
						RotateP -= 6.3;
					} else if ( RotateP < 0 ) {
						RotateP += 6.3;
					} else {
						RotateP += 0.05;
					}*/

					if (rotatepl >= 90 && rotatepl <= 270) {
						rotatepl -= 5;
						if (rotatepl <= 90) {
							rotatepl = 90;
						}
					}
					else if (rotatepl > 360) {
						rotatepl -= 360;
					}
					else if (rotatepl < 0) {
						rotatepl += 360;
					}
					else {
						rotatepl += 5;
					}
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_UP)) {/* up arrow on */
			if (pt->top_collision == false) {
				pt->baseY = pt->baseY - 3;/* �����x*/
				if (CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {

					/*if ( RotateP >= 3.1 ) {
						RotateP += 0.05;
						if ( RotateP >= 6.3 ) {
							RotateP = 0;
						}
					} else if ( RotateP > 6.3 ) {
						RotateP -= 6.3;
					} else {
						RotateP -= 0.05;
						if ( RotateP <= 0 ) {
							RotateP = 0;
						}
					}*/

					if (rotatepl >= 180) {
						rotatepl += 5;
						if (rotatepl >= 360) {
							rotatepl = 0;
						}
					}
					else if (rotatepl > 360) {
						rotatepl -= 360;
					}
					else {
						rotatepl -= 5;
						if (rotatepl <= 0) {
							rotatepl = 0;
						}
					}

				}
				else if (CheckHitKey(KEY_INPUT_RIGHT)) {
					/*if ( RotateP >= 1.6 / 2 && RotateP < 3.1 + 1.6 / 2 ) {
						RotateP -= 0.05;
						if ( RotateP <= 1.6 / 2 ) {
							RotateP = 1.6 / 2;
						}
					} else if ( RotateP >= 6.3 ) {
						RotateP -= 6.3;
					} else if ( RotateP < 0 ) {
						RotateP += 6.3;
					} else {
						RotateP += 0.05;
					}*/

					if (rotatepl >= 45 && rotatepl < 225) {
						rotatepl -= 5;
						if (rotatepl <= 45) {
							rotatepl = 45;
						}
					}
					else if (rotatepl >= 360) {
						rotatepl -= 360;
					}
					else if (rotatepl < 0) {
						rotatepl += 360;
					}
					else {
						rotatepl += 5;
					}

				}
				else if (CheckHitKey(KEY_INPUT_LEFT)) {

					if (rotatepl <= 315 && rotatepl > 135) {
						rotatepl += 5;
						if (rotatepl >= 315) {
							rotatepl = 315;
						}
					}
					else if (rotatepl > 360) {
						rotatepl -= 360;
					}
					else if (rotatepl < 0) {
						rotatepl += 360;
					}
					else {
						rotatepl -= 5;
					}

				}
			}
		}
		if (CheckHitKey(KEY_INPUT_DOWN)) {/* down arrow on */
			if (pt->bottom_collision == false) {
				pt->baseY = pt->baseY + 3;/* �����x*/
				if (CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0) {
					/*if ( RotateP >= 0 && RotateP < 3.1 ) {
						RotateP += 0.05;
						if ( RotateP >= 3.1 ) {
							RotateP = 3.1;
						}
					} else if ( RotateP >= 6.3 ) {
						RotateP -= 6.3;
					} else if ( RotateP < 0 ) {
						RotateP += 6.3;
					} else {
						RotateP -= 0.05;
						if ( RotateP <= 3.1 ) {
							RotateP = 3.1;
						}
					}*/

					if (rotatepl >= 0 && rotatepl < 180) {
						rotatepl += 5;
						if (rotatepl >= 180) {
							rotatepl = 180;
						}
					}
					else if (rotatepl >= 360) {
						rotatepl -= 360;
					}
					else if (rotatepl < 0) {
						rotatepl += 360;
					}
					else {
						rotatepl -= 5;
						if (rotatepl <= 180) {
							rotatepl = 180;
						}
					}

				}
				else if (CheckHitKey(KEY_INPUT_RIGHT)) {

					if (rotatepl < 315 && rotatepl >= 135) {
						rotatepl -= 5;
						if (rotatepl <= 135) {
							rotatepl = 135;
						}
					}
					else if (rotatepl >= 360) {
						rotatepl -= 360;
					}
					else if (rotatepl < 0) {
						rotatepl += 360;
					}
					else {
						rotatepl += 5;
					}

				}
				else if (CheckHitKey(KEY_INPUT_LEFT)) {
					/*if ( RotateP > 1.6 / 2 && RotateP < 3.1 + 1.6 / 2 ) {
						RotateP += 0.05;
						if ( RotateP >= 3.1 + 1.6 / 2 ) {
							RotateP = 3.1 + 1.6 / 2;
						}
					} else if ( RotateP > 6.3 ) {
						RotateP -= 6.3;
					} else if ( RotateP < 0 ) {
						RotateP += 6.3;
					} else {
						RotateP -= 0.05;
					}*/

					if (rotatepl > 45 && rotatepl <= 225) {
						rotatepl += 5;
						if (rotatepl >= 225) {
							rotatepl = 225;
						}
					}
					else if (rotatepl > 360) {
						rotatepl -= 360;
					}
					else if (rotatepl < 0) {
						rotatepl += 360;
					}
					else {
						rotatepl -= 5;
					}

				}
			}
		}
		player_body(pt);
	}
	break;

	case kPLAYERSTATE_CRASH:// ����A�j���[�V�������
		pt->crashTmr++;
		if (pt->crashTmr < 60) {
			int x1 = pt->baseX - pt->crashTmr * (pt->crashTmr & 8) * 2;
			int x2 = pt->baseX + pt->crashTmr * (pt->crashTmr & 8) * 2;
			int x3 = pt->baseX;
			int y1 = pt->baseY;
			int y2 = pt->baseY;
			int y3 = pt->baseY - pt->crashTmr * (pt->crashTmr & 8) * 2;
			int cc = (60 - pt->crashTmr) * 4;
			unsigned int col = (cc << 16) | (cc << 8) | (cc);
			DrawTriangle(x1, y1, x2, y2, x3, y3, col, false);
			if (pt->c_radius < ScreenWidth) {
				DrawCircle(pt->baseX, pt->baseY, pt->c_radius, 0xffc000, false);/*collision circle*/
				pt->c_radius = pow(pt->c_radius, 1.05);
			}
			else {
			}

		}
		else {
			pt->state = kPLAYERSTATE_GAMEOVER;
			pt->gameoverTmr = 0;
		}
		break;
	case kPLAYERSTATE_GAMEOVER: // �Q�[���I�[�o�[�\��
		/*if ( pt->gameoverTmr & 4 ) {
			DrawString( ScreenWidth / 2,
						ScreenHeight / 2,
						"GAME OVER",
						GetColor( 255, 210, 192 ) );
		}
		pt->gameoverTmr++;
		if ( pt->gameoverTmr > 60 * 5 ) {*/
		return 1;
		//}
		break;
	case kPLAYERSTATE_SUCCESS:
		return 1;
		break;
	}

	return 0;
}


/*
* �v���C���[�\��
*
*
*/
void player_body(player_t* pt) {

	pt->x1 = pt->baseX + (30 * sin(rotatepl * 0.01745));
	pt->y1 = pt->baseY - 35 + (-35 * cos(rotatepl * 0.01745));
	pt->x2 = pt->baseX + (-30 * cos(rotatepl * 0.01745) - (30 * sin(rotatepl * 0.01745)));
	pt->y2 = pt->baseY - 35 + (-30 * sin(rotatepl * 0.01745) + (30 * cos(rotatepl * 0.01745)));
	pt->x3 = pt->baseX + (30 * cos(rotatepl * 0.01745) - (30 * sin(rotatepl * 0.01745)));
	pt->y3 = pt->baseY - 35 + (30 * sin(rotatepl * 0.01745) + (30 * cos(rotatepl * 0.01745)));

	DrawTriangle(pt->x1, pt->y1, pt->x2, pt->y2, pt->x3, pt->y3, GetColor(255, 255, 255), TRUE);


	//DrawRotaGraph( pt->baseX, pt->baseY - 35, 0.37, RotateP, GHandleP, TRUE, FALSE );

}


int player_finish(void) {
	free(pt); pt = NULL;
	return 0;
}
