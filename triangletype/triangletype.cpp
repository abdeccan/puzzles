//
// Given three lengths, write a program to tell if it could form a triangle.
// If yes, print the type of triangle: Isoceles or Equilateral or Scalene.
// Additionally, also print if its a right triangle.
//
#include <iostream>
using namespace std;

int main ()
{
	cout << "Enter the sides of triangle:" << endl;
	int side1 = 0, side2 = 0, side3 = 0;
	cin >> side1;
	cin >> side2;
	cin >> side3;
	cout << "Sides are " << side1 << side2 << side3 << endl;
	return 0;
}