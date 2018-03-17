/*
Author: Ilay Pilosof
ID: 304961519
Date: 12/11/2016
Purpose: The program calculates a ball Volume from his radius
*/

#include <stdio.h>
#include <math.h>
#define PI 3.14
void main() {
	double radius;
	double volume;
	printf("Input radius : ");
	scanf("%lf", &radius);
	// calculate the volume
	volume = (4 * PI * pow(radius, 3)) / 3;
	printf("Volume : %.2lf\n", volume);

}