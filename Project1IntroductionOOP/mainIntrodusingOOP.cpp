#include<iostream>
using namespace std;

/*struct*/ class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//		Methods:
	double distance(Point other)
	{
		/*double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;*/
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
		//pow - возведение в степень; sqrt(square root) - квадратный корень
	}
	void print()const
	{
		cout << "X = " << x << "\t" << "Y = " << y << endl;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_y();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define DISTANCE

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	//int a;		//Объявление переменной 'a' типа 'int'
	Point A;		//Объявление переменной 'A' типа 'Point'
					//Объявление (создание) экземпляра (объекта) 'A' структуры 'Point'
	A.x = 2; A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B;
	B.set_x(3);
	B.set_y(4);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Размер объекта: " << sizeof(B) << endl;

	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;

	cout << "Расстояние между точками A и B: " << distance(A, B) << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
#endif // DISTANCE


}