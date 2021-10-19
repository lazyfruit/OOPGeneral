#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
};

void main()
{
	setlocale(LC_ALL, "");

	Point A;
	A.x = 2; A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
}