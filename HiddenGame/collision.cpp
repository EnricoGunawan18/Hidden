#include "stdio.h"
#include "DxLib.h"
#include "miniWinGame1.h"

#include "player.h"
#include "enemy1.h"
#include "enemy2.h"
#include "enemy3.h"
#include "enmBullet.h"
#include "collision.h"
#include "math.h"
#include "target.h"
#include "gameZone.h"
#include "door.h"
#include "mode.h"


#define POSITION_ENABLE 0

int collisionDetect( void ) {
	static float n = 1.2;
	enemy1_t* ep = getEnemy1Ptr( );
	enemy2_t* ep2 = getEnemy2Ptr( );
	enemy3_t* ep3 = getEnemy3Ptr( );
	player_t* pt = getPlayerPtr( );
	enmbullet_t* enp = getENMBulletLink( );
	target_t* tp = getTargetPtr( );
	gamezone_t* gt = getGamezonePtr( );
	door_t* dt = getDoorPtr( );

	enp = getENMBulletLink( );
	pt = getPlayerPtr( );
	tp = getTargetPtr( );
	ep = getEnemy1Ptr( );
	ep2 = getEnemy2Ptr( );
	ep3 = getEnemy3Ptr( );
	gt = getGamezonePtr( );
	dt = getDoorPtr( );

#if POSITION_ENABLE


#endif


	if ( pt && ep ) {

		int o1 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep->x1, ep->y1 );
		int o2 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep->x2, ep->y2 );
		int o3 = orientation( ep->x1, ep->y1, ep->x2, ep->y2, pt->x1, pt->y1 );
		int o4 = orientation( ep->x1, ep->y1, ep->x2, ep->y2, pt->x2, pt->y2 );

		if ( ( ( o3 >= 0 && o4 <= 0 ) || ( o3 <= 0 && o4 >= 0 ) )
			 && ( ( o1 >= 0 && o2 <= 0 ) || ( o1 <= 0 && o2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int p1 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep->x1, ep->y1 );
		int p2 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep->x2, ep->y2 );
		int p3 = orientation( ep->x1, ep->y1, ep->x2, ep->y2, pt->x2, pt->y2 );
		int p4 = orientation( ep->x1, ep->y1, ep->x2, ep->y2, pt->x3, pt->y3 );

		if ( ( ( p3 >= 0 && p4 <= 0 ) || ( p3 <= 0 && p4 >= 0 ) )
			 && ( ( p1 >= 0 && p2 <= 0 ) || ( p1 <= 0 && p2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int q1 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep->x1, ep->y1 );
		int q2 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep->x2, ep->y2 );
		int q3 = orientation( ep->x1, ep->y1, ep->x2, ep->y2, pt->x3, pt->y3 );
		int q4 = orientation( ep->x1, ep->y1, ep->x2, ep->y2, pt->x1, pt->y1 );

		if ( ( ( q3 >= 0 && q4 <= 0 ) || ( q3 <= 0 && q4 >= 0 ) )
			 && ( ( q1 >= 0 && q2 <= 0 ) || ( q1 <= 0 && q2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}
		/////////////////////////////////////////////////
		int r1 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep->x2, ep->y2 );
		int r2 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep->x3, ep->y3 );
		int r3 = orientation( ep->x2, ep->y2, ep->x3, ep->y3, pt->x1, pt->y1 );
		int r4 = orientation( ep->x2, ep->y2, ep->x3, ep->y3, pt->x2, pt->y2 );

		if ( ( ( r3 >= 0 && r4 <= 0 ) || ( r3 <= 0 && r4 >= 0 ) )
			 && ( ( r1 >= 0 && r2 <= 0 ) || ( r1 <= 0 && r2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int s1 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep->x2, ep->y2 );
		int s2 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep->x3, ep->y3 );
		int s3 = orientation( ep->x2, ep->y2, ep->x3, ep->y3, pt->x2, pt->y2 );
		int s4 = orientation( ep->x2, ep->y2, ep->x3, ep->y3, pt->x3, pt->y3 );

		if ( ( ( s3 >= 0 && s4 <= 0 ) || ( s3 <= 0 && s4 >= 0 ) )
			 && ( ( s1 >= 0 && s2 <= 0 ) || ( s1 <= 0 && s2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int t1 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep->x2, ep->y2 );
		int t2 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep->x3, ep->y3 );
		int t3 = orientation( ep->x2, ep->y2, ep->x3, ep->y3, pt->x3, pt->y3 );
		int t4 = orientation( ep->x2, ep->y2, ep->x3, ep->y3, pt->x1, pt->y1 );

		if ( ( ( t3 >= 0 && t4 <= 0 ) || ( t3 <= 0 && t4 >= 0 ) )
			 && ( ( t1 >= 0 && t2 <= 0 ) || ( t1 <= 0 && t2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}
		/////////////////////////////////////////////////

		int u1 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep->x3, ep->y3 );
		int u2 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep->x1, ep->y1 );
		int u3 = orientation( ep->x3, ep->y3, ep->x1, ep->y1, pt->x1, pt->y1 );
		int u4 = orientation( ep->x3, ep->y3, ep->x1, ep->y1, pt->x2, pt->y2 );

		if ( ( ( u3 >= 0 && u4 <= 0 ) || ( u3 <= 0 && u4 >= 0 ) )
			 && ( ( u1 >= 0 && u2 <= 0 ) || ( u1 <= 0 && u2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int v1 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep->x3, ep->y3 );
		int v2 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep->x1, ep->y1 );
		int v3 = orientation( ep->x3, ep->y3, ep->x1, ep->y1, pt->x2, pt->y2 );
		int v4 = orientation( ep->x3, ep->y3, ep->x1, ep->y1, pt->x3, pt->y3 );

		if ( ( ( v3 >= 0 && v4 <= 0 ) || ( v3 <= 0 && v4 >= 0 ) )
			 && ( ( v1 >= 0 && v2 <= 0 ) || ( v1 <= 0 && v2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int w1 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep->x3, ep->y3 );
		int w2 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep->x1, ep->y1 );
		int w3 = orientation( ep->x3, ep->y3, ep->x1, ep->y1, pt->x3, pt->y3 );
		int w4 = orientation( ep->x3, ep->y3, ep->x1, ep->y1, pt->x1, pt->y1 );

		if ( ( ( w3 >= 0 && w4 <= 0 ) || ( w3 <= 0 && w4 >= 0 ) )
			 && ( ( w1 >= 0 && w2 <= 0 ) || ( w1 <= 0 && w2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}


	}


	if ( pt && ep2 ) {

		int o1 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep2->x1, ep2->y1 );
		int o2 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep2->x2, ep2->y2 );
		int o3 = orientation( ep2->x1, ep2->y1, ep2->x2, ep2->y2, pt->x1, pt->y1 );
		int o4 = orientation( ep2->x1, ep2->y1, ep2->x2, ep2->y2, pt->x2, pt->y2 );

		if ( ( ( o3 >= 0 && o4 <= 0 ) || ( o3 <= 0 && o4 >= 0 ) )
			 && ( ( o1 >= 0 && o2 <= 0 ) || ( o1 <= 0 && o2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int p1 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep2->x1, ep2->y1 );
		int p2 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep2->x2, ep2->y2 );
		int p3 = orientation( ep2->x1, ep2->y1, ep2->x2, ep2->y2, pt->x2, pt->y2 );
		int p4 = orientation( ep2->x1, ep2->y1, ep2->x2, ep2->y2, pt->x3, pt->y3 );

		if ( ( ( p3 >= 0 && p4 <= 0 ) || ( p3 <= 0 && p4 >= 0 ) )
			 && ( ( p1 >= 0 && p2 <= 0 ) || ( p1 <= 0 && p2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int q1 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep2->x1, ep2->y1 );
		int q2 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep2->x2, ep2->y2 );
		int q3 = orientation( ep2->x1, ep2->y1, ep2->x2, ep2->y2, pt->x3, pt->y3 );
		int q4 = orientation( ep2->x1, ep2->y1, ep2->x2, ep2->y2, pt->x1, pt->y1 );

		if ( ( ( q3 >= 0 && q4 <= 0 ) || ( q3 <= 0 && q4 >= 0 ) )
			 && ( ( q1 >= 0 && q2 <= 0 ) || ( q1 <= 0 && q2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}
		/////////////////////////////////////////////////
		int r1 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep2->x2, ep2->y2 );
		int r2 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep2->x3, ep2->y3 );
		int r3 = orientation( ep2->x2, ep2->y2, ep2->x3, ep2->y3, pt->x1, pt->y1 );
		int r4 = orientation( ep2->x2, ep2->y2, ep2->x3, ep2->y3, pt->x2, pt->y2 );

		if ( ( ( r3 >= 0 && r4 <= 0 ) || ( r3 <= 0 && r4 >= 0 ) )
			 && ( ( r1 >= 0 && r2 <= 0 ) || ( r1 <= 0 && r2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int s1 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep2->x2, ep2->y2 );
		int s2 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep2->x3, ep2->y3 );
		int s3 = orientation( ep2->x2, ep2->y2, ep2->x3, ep2->y3, pt->x2, pt->y2 );
		int s4 = orientation( ep2->x2, ep2->y2, ep2->x3, ep2->y3, pt->x3, pt->y3 );

		if ( ( ( s3 >= 0 && s4 <= 0 ) || ( s3 <= 0 && s4 >= 0 ) )
			 && ( ( s1 >= 0 && s2 <= 0 ) || ( s1 <= 0 && s2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int t1 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep2->x2, ep2->y2 );
		int t2 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep2->x3, ep2->y3 );
		int t3 = orientation( ep2->x2, ep2->y2, ep2->x3, ep2->y3, pt->x3, pt->y3 );
		int t4 = orientation( ep2->x2, ep2->y2, ep2->x3, ep2->y3, pt->x1, pt->y1 );

		if ( ( ( t3 >= 0 && t4 <= 0 ) || ( t3 <= 0 && t4 >= 0 ) )
			 && ( ( t1 >= 0 && t2 <= 0 ) || ( t1 <= 0 && t2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}
		/////////////////////////////////////////////////

		int u1 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep2->x3, ep2->y3 );
		int u2 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep2->x1, ep2->y1 );
		int u3 = orientation( ep2->x3, ep2->y3, ep2->x1, ep2->y1, pt->x1, pt->y1 );
		int u4 = orientation( ep2->x3, ep2->y3, ep2->x1, ep2->y1, pt->x2, pt->y2 );

		if ( ( ( u3 >= 0 && u4 <= 0 ) || ( u3 <= 0 && u4 >= 0 ) )
			 && ( ( u1 >= 0 && u2 <= 0 ) || ( u1 <= 0 && u2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int v1 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep2->x3, ep2->y3 );
		int v2 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep2->x1, ep2->y1 );
		int v3 = orientation( ep2->x3, ep2->y3, ep2->x1, ep2->y1, pt->x2, pt->y2 );
		int v4 = orientation( ep2->x3, ep2->y3, ep2->x1, ep2->y1, pt->x3, pt->y3 );

		if ( ( ( v3 >= 0 && v4 <= 0 ) || ( v3 <= 0 && v4 >= 0 ) )
			 && ( ( v1 >= 0 && v2 <= 0 ) || ( v1 <= 0 && v2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int w1 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep2->x3, ep2->y3 );
		int w2 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep2->x1, ep2->y1 );
		int w3 = orientation( ep2->x3, ep2->y3, ep2->x1, ep2->y1, pt->x3, pt->y3 );
		int w4 = orientation( ep2->x3, ep2->y3, ep2->x1, ep2->y1, pt->x1, pt->y1 );

		if ( ( ( w3 >= 0 && w4 <= 0 ) || ( w3 <= 0 && w4 >= 0 ) )
			 && ( ( w1 >= 0 && w2 <= 0 ) || ( w1 <= 0 && w2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}


	}

	if ( pt && ep3 ) {

		int o1 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep3->x1, ep3->y1 );
		int o2 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep3->x2, ep3->y2 );
		int o3 = orientation( ep3->x1, ep3->y1, ep3->x2, ep3->y2, pt->x1, pt->y1 );
		int o4 = orientation( ep3->x1, ep3->y1, ep3->x2, ep3->y2, pt->x2, pt->y2 );

		if ( ( ( o3 >= 0 && o4 <= 0 ) || ( o3 <= 0 && o4 >= 0 ) )
			 && ( ( o1 >= 0 && o2 <= 0 ) || ( o1 <= 0 && o2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int p1 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep3->x1, ep3->y1 );
		int p2 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep3->x2, ep3->y2 );
		int p3 = orientation( ep3->x1, ep3->y1, ep3->x2, ep3->y2, pt->x2, pt->y2 );
		int p4 = orientation( ep3->x1, ep3->y1, ep3->x2, ep3->y2, pt->x3, pt->y3 );

		if ( ( ( p3 >= 0 && p4 <= 0 ) || ( p3 <= 0 && p4 >= 0 ) )
			 && ( ( p1 >= 0 && p2 <= 0 ) || ( p1 <= 0 && p2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int q1 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep3->x1, ep3->y1 );
		int q2 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep3->x2, ep3->y2 );
		int q3 = orientation( ep3->x1, ep3->y1, ep3->x2, ep3->y2, pt->x3, pt->y3 );
		int q4 = orientation( ep3->x1, ep3->y1, ep3->x2, ep3->y2, pt->x1, pt->y1 );

		if ( ( ( q3 >= 0 && q4 <= 0 ) || ( q3 <= 0 && q4 >= 0 ) )
			 && ( ( q1 >= 0 && q2 <= 0 ) || ( q1 <= 0 && q2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}
		/////////////////////////////////////////////////
		int r1 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep3->x2, ep3->y2 );
		int r2 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep3->x3, ep3->y3 );
		int r3 = orientation( ep3->x2, ep3->y2, ep3->x3, ep3->y3, pt->x1, pt->y1 );
		int r4 = orientation( ep3->x2, ep3->y2, ep3->x3, ep3->y3, pt->x2, pt->y2 );

		if ( ( ( r3 >= 0 && r4 <= 0 ) || ( r3 <= 0 && r4 >= 0 ) )
			 && ( ( r1 >= 0 && r2 <= 0 ) || ( r1 <= 0 && r2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int s1 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep3->x2, ep3->y2 );
		int s2 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep3->x3, ep3->y3 );
		int s3 = orientation( ep3->x2, ep3->y2, ep3->x3, ep3->y3, pt->x2, pt->y2 );
		int s4 = orientation( ep3->x2, ep3->y2, ep3->x3, ep3->y3, pt->x3, pt->y3 );

		if ( ( ( s3 >= 0 && s4 <= 0 ) || ( s3 <= 0 && s4 >= 0 ) )
			 && ( ( s1 >= 0 && s2 <= 0 ) || ( s1 <= 0 && s2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int t1 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep3->x2, ep3->y2 );
		int t2 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep3->x3, ep3->y3 );
		int t3 = orientation( ep3->x2, ep3->y2, ep3->x3, ep3->y3, pt->x3, pt->y3 );
		int t4 = orientation( ep3->x2, ep3->y2, ep3->x3, ep3->y3, pt->x1, pt->y1 );

		if ( ( ( t3 >= 0 && t4 <= 0 ) || ( t3 <= 0 && t4 >= 0 ) )
			 && ( ( t1 >= 0 && t2 <= 0 ) || ( t1 <= 0 && t2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}
		/////////////////////////////////////////////////

		int u1 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep3->x3, ep3->y3 );
		int u2 = orientation( pt->x1, pt->y1, pt->x2, pt->y2, ep3->x1, ep3->y1 );
		int u3 = orientation( ep3->x3, ep3->y3, ep3->x1, ep3->y1, pt->x1, pt->y1 );
		int u4 = orientation( ep3->x3, ep3->y3, ep3->x1, ep3->y1, pt->x2, pt->y2 );

		if ( ( ( u3 >= 0 && u4 <= 0 ) || ( u3 <= 0 && u4 >= 0 ) )
			 && ( ( u1 >= 0 && u2 <= 0 ) || ( u1 <= 0 && u2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int v1 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep3->x3, ep3->y3 );
		int v2 = orientation( pt->x2, pt->y2, pt->x3, pt->y3, ep3->x1, ep3->y1 );
		int v3 = orientation( ep3->x3, ep3->y3, ep3->x1, ep3->y1, pt->x2, pt->y2 );
		int v4 = orientation( ep3->x3, ep3->y3, ep3->x1, ep3->y1, pt->x3, pt->y3 );

		if ( ( ( v3 >= 0 && v4 <= 0 ) || ( v3 <= 0 && v4 >= 0 ) )
			 && ( ( v1 >= 0 && v2 <= 0 ) || ( v1 <= 0 && v2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}

		int w1 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep3->x3, ep3->y3 );
		int w2 = orientation( pt->x3, pt->y3, pt->x1, pt->y1, ep3->x1, ep3->y1 );
		int w3 = orientation( ep3->x3, ep3->y3, ep3->x1, ep3->y1, pt->x3, pt->y3 );
		int w4 = orientation( ep3->x3, ep3->y3, ep3->x1, ep3->y1, pt->x1, pt->y1 );

		if ( ( ( w3 >= 0 && w4 <= 0 ) || ( w3 <= 0 && w4 >= 0 ) )
			 && ( ( w1 >= 0 && w2 <= 0 ) || ( w1 <= 0 && w2 >= 0 ) ) ) {
			ep->state = kENEMYSTATE_ENGAGE;
			ep2->state = kENEMYSTATE_ENGAGE;
			ep3->state = kENEMYSTATE_ENGAGE;
		}


	}




	if ( tp && pt ) {
		if ( tp->state == kTARGETSTATE_NORMAL ) {
			int radius = pt->collision;
			int pointX = tp->baseX;
			int pointY = tp->baseY;
			if ( pt->state == kPLAYERSTATE_NORMAL ) {
				int deltaX = pointX - pt->baseX;
				int deltaY = pointY - ( pt->baseY - 35 );

				int delta = tp->radius * 2;
#if POSITION_ENABLE
				DrawCircle( pt->baseX, pt->baseY - 35, radius, GetColor( 0, 0, 255 ), 1 );
				DrawCircle( pointX, tp->baseY, tp->radius, GetColor( 0, 0, 255 ), 1 );
#endif
				if ( delta > sqrt( pow( deltaX, 2 ) + pow( deltaY, 2 ) ) ) {/* HIT! */
					tp->state = kTARGETSTATE_GET;
					ep->state = kENEMYSTATE_ENGAGE;
					ep2->state = kENEMYSTATE_ENGAGE;
					ep3->state = kENEMYSTATE_ENGAGE;
					///////////////////////////////////////////////////////////////////////////////////////////////////////////
					//pt->state = kPLAYERSTATE_SUCCESS;


				}
			}

		}
	}


	if ( dt && pt ) {
		if ( pt->state == kPLAYERSTATE_NORMAL ) {
			int radius = pt->collision;
			int pointX = dt->baseX;
			int pointY = dt->baseY;

#if POSITION_ENABLE
			DrawCircle( pointX, pointY, 40, GetColor( 255, 255, 0 ) );
#endif
#if POSITION_ENABLE
			//DrawCircle( pt->baseX, pt->baseY - 35, radius, GetColor( 255, 0, 0 ), 1 );
#endif

			int deltaX = pointX - pt->baseX;
			int deltaY = pointY - pt->baseY + 35;

			int delta = dt->radius * 2;
			if ( tp->state == kTARGETSTATE_GET && delta >= sqrt( pow( deltaX, 2 ) + pow( deltaY, 2 ) ) ) {/* HIT! */
				pt->state = kPLAYERSTATE_SUCCESS;
			}
		}
	}

	if ( enp && pt ) {
		if ( pt->state == kPLAYERSTATE_NORMAL ) {
			int pointX = pt->baseX;
			int pointY = pt->baseY - 30;
			do {
				if ( enp->state == kENMBULLETSTATE_NORMAL ) {
					int deltaX = enp->scrn.x - pointX;
					int deltaY = enp->scrn.y - pointY;
					int delta = deltaX * deltaX + deltaY * deltaY;
					if ( delta < ( enp->radius * enp->radius + pt->collision * pt->collision ) ) {/* HIT! */
						enp->state = kENMBULLETSTATE_CRASH;
						pt->state = kPLAYERSTATE_CRASH;
						pt->c_radius = 8.0;
						pt->crashTmr = 0;
					}
				}
				enp = getENMBulletNext( enp );
			} while ( enp != NULL );
		}
	}


	if ( ep && pt ) {
		if ( pt->state == kPLAYERSTATE_NORMAL ) {
			int radius = pt->collision;
			int pointX = ep->base_x;
			int pointY = ep->base_y;


			int deltaX = pointX - pt->baseX;
			int deltaY = pointY - pt->baseY + 35;

			int delta = ep->collision;

#if POSITION_ENABLE
			DrawCircle( pointX, pointY, ep->collision / 2, GetColor( 0, 255, 255 ) );
#endif

			if ( delta >= sqrt( pow( deltaX, 2 ) + pow( deltaY, 2 ) ) ) {/* HIT! */
				pt->state = kPLAYERSTATE_CRASH;
				pt->c_radius = 8.0;
				pt->crashTmr = 0;
			}
		}
	}

	if ( ep2 && pt ) {
		if ( pt->state == kPLAYERSTATE_NORMAL ) {
			int radius = pt->collision;
			int pointX = ep2->base_x;
			int pointY = ep2->base_y;

#if POSITION_ENABLE
			DrawCircle( pointX, pointY, 40, GetColor( 0, 255, 255 ) );
#endif


			int deltaX = pointX - pt->baseX;
			int deltaY = pointY - pt->baseY + 35;

			int delta = ep2->collision;
			if ( delta >= sqrt( pow( deltaX, 2 ) + pow( deltaY, 2 ) ) ) {/* HIT! */
				pt->state = kPLAYERSTATE_CRASH;
				pt->c_radius = 8.0;
				pt->crashTmr = 0;
			}
		}
	}

	if ( ep3 && pt ) {
		if ( pt->state == kPLAYERSTATE_NORMAL ) {
			int radius = pt->collision;
			int pointX = ep3->base_x;
			int pointY = ep3->base_y;

#if POSITION_ENABLE
			DrawCircle( pointX, pointY, 40, GetColor( 0, 255, 255 ) );
#endif


			int deltaX = pointX - pt->baseX;
			int deltaY = pointY - pt->baseY + 35;

			int delta = ep3->collision;
			if ( delta >= sqrt( pow( deltaX, 2 ) + pow( deltaY, 2 ) ) ) {/* HIT! */
				pt->state = kPLAYERSTATE_CRASH;
				pt->c_radius = 8.0;
				pt->crashTmr = 0;
			}
		}
	}

	if ( gt && pt ) {
		if ( pt->state == kPLAYERSTATE_NORMAL ) {
			int radius1 = pt->collision / 2;
			int radius2 = pt->collision;

			int pointX1 = pt->baseX - 30;
			int pointY1 = pt->baseY - 30;

			int pointX2 = pt->baseX + 30;
			int pointY2 = pt->baseY - 30;

			int pointX3 = pt->baseX;
			int pointY3 = pt->baseY - 60;

			int pointX4 = pt->baseX;
			int pointY4 = pt->baseY - 30;

			int deltaX1 = gt->baseX - pointX1;
			int deltaY1 = gt->baseY - pointY1;
			int delta = gt->radius - radius1;
			if ( delta <= sqrt( pow( deltaX1, 2 ) + pow( deltaY1, 2 ) ) ) {/* HIT! */
				pt->left_collision = true;
			} else {
				pt->left_collision = false;
			}

			int deltaX2 = gt->baseX - pointX2;
			int deltaY2 = gt->baseY - pointY2;
			if ( delta <= sqrt( pow( deltaX2, 2 ) + pow( deltaY2, 2 ) ) ) {/* HIT! */
				pt->right_collision = true;
			} else {
				pt->right_collision = false;
			}

			int deltaX3 = gt->baseX - pointX3;
			int deltaY3 = gt->baseY - pointY3;
			if ( delta <= sqrt( pow( deltaX3, 2 ) + pow( deltaY3, 2 ) ) ) {/* HIT! */
				pt->top_collision = true;
			} else {
				pt->top_collision = false;
			}

			int deltaX4 = gt->baseX - pointX4;
			int deltaY4 = gt->baseY - pointY4;
			int delta2 = gt->radius - radius2;
			if ( delta2 <= sqrt( pow( deltaX4, 2 ) + pow( deltaY4, 2 ) ) ) {/* HIT! */
				pt->bottom_collision = true;
			} else {
				pt->bottom_collision = false;
			}
		}
	}
	return 0;
}

double orientation( double x1, double y1, double x2, double y2, double x3, double y3 ) {

	int val = ( y2 - y1 ) * ( x3 - x2 ) - ( x2 - x1 ) * ( y3 - y2 );

	return val;
}



