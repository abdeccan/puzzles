/*
	Write a program that computes the third side of a triangle given its two other sides so that the area
	of the triange is maximum.

	Note: Hero's formula can be used for computing area of triangle.

	Note: Check if the area is max for a right angled triangle for any combination of sides & angles.
*/

#include <iostream>
#include <math.h>
int main()
{
	float side1 = 10, side2 = 7;
	float semiperi = 0;
	float area = 0, maxarea = 0, maxside = 1;
	for (float side = 1; side < side1 + side2 ; side++)
	{
		if ((side + side1 <= side2) || (side + side2 <= side1))
			continue;

		semiperi = (side  + side1 + side2) / 2;
		area = sqrt(semiperi*(semiperi - side1)*(semiperi - side2)*(semiperi - side));
		if (area > maxarea){
			maxarea = area;
			maxside = side;
		}
	}
	std::cout <<"\n Max side : "<<maxside<<" Max Area: "<<maxarea <<std::endl;	
	return 0;	
}