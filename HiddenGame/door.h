#pragma once

typedef struct dt {
	int baseX, baseY;
	int radius;

	float c_radius;
} door_t;



int door_init( void );
int door_disp( void );
int door_finish( void );
door_t* getDoorPtr( void );
#pragma once
