/* For test on Linux:
user@host:~$ g++ -o fractals fractals.cpp -lgraph
user@host:~$ ./fractals
*/

#include <graphics.h>
#include <iostream>
#include <math.h>
#include "KochCurve.h"


int main() 
{
	int gd = DETECT, gm;

	initgraph(&gd, &gm, NULL);

	KochCurve test(10, getmaxx(), getmaxy());
	test.draw(0);

	getch();
	closegraph();
	return 0; 
} 
