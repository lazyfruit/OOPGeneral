#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Point;
//double distance(Point A, Point B);
double distance(const Point A, const Point B);

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
	//		Constructor
	Point()
	{
		x = 0;
		y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//		Operators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//		Increment/Decrement
	Point& operator++()	//Prefix increment
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point& operator++(int)	//Postfix increment
	{
		Point old = *this;	//Сохраняем текущее значение нашего объекта
		this->x++;
		this->y++;
		return old;
	}

	//		Methods:
	double distance(const Point& other)
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

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_y();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//		Operators
Point operator+(const Point& left, const Point& right)
{
	Point buffer;
	buffer.set_x(left.get_x() + right.get_x());
	buffer.set_y(left.get_y() + right.get_y());
	return buffer;
}
ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X = " << obj.get_x() << "\t" << "Y = " << obj.get_y();
	return os;
}
istream& operator>>(istream& is, Point& obj)
{
	double x, y;
	is >> x >> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}

#define razdel "\n----------------------------------\n"
//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK

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
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и B: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE
#ifdef CONSTRUCTORS_CHECK
	Point A;		//Default constructor
	A.print();

	Point B(2, 3);
	B.print();

	Point C = B;	//Copy constructor
	C.print();

	Point D;
	D = B;			//Copy assignment - оператор присваивания 
	D.print();
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	//Point (2,3) - явный вызов конструктора.\
	Создается временный безымянный объект, который существует только в пределах выражения и удаляется после завершения выражения.
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK
#ifdef ARITHMETICAL_OPERATORS_CHECK
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(3, 4);
	Point C = A + B;		//Чтобы научить оператор "+" складывать точки, его нужно перегрузить для класса "точка"
	C.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

	/*for (Point i(2, 3); i.get_x() < 10; i++)
	{
		i.print();
	}*/
	Point A(2, 3);
	Point B = ++A;
	/*A.print();
	B.print();*/

	cout << A << endl;
	cout << B << endl;

	cout << "Введите координаты точки A: ";
	cin >> A;
	cout << A << endl;
}