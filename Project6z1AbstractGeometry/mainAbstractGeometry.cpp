#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

enum Color	//enum - перечисление. Перечисление - набор именованных констант типа int
{
	//console_gray = 0x88,	//0x88 - шестнадцатеричный код цвета
	//console_blue = 0x99,
	//console_green = 0xAA,
	//console_red = 0xCC,
	//console_white = 0xFF
	
	//console_gray,	//0x88 - шестнадцатеричный код цвета
	//console_blue,
	//console_green,
	//console_red,
	//console_white

	console_gray = 0x88,	//0x88 - шестнадцатеричный код цвета
	console_blue = 0x99,
	console_green = 0xAA,
	console_red = 0xCC,
	console_white = 0xFF,
	console_default = 0x07
};

//const char* console_color[] =
//{
//	"08",
//	"19",
//	"2A",
//	"4C",
//	"7F"
//};

class Shape
{
protected:
	Color color;
public:
	Shape(Color color) :color(color)
	{
		cout << "ShConstructor:\t" << this << endl;
	}
	virtual ~Shape()
	{
		cout << "ShDestructor:\t" << this << endl;
	}
	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
};

class Square :public Shape
{
	double side;
public:
	double get_side(double side)
	{
		return side;
	}
	void set_side(double side)
	{
		if (side <= 0)side = 1;
		this->side = side;
	}
	Square(double side, Color color) :Shape(color)
	{
		set_side(side);
	}
	~Square()
	{

	}
	double get_area()const
	{
		return side * side;
	}
	double get_perimeter()const
	{
		return side * 4;
	}
	void draw()const
	{
		/*std::string command = std::string("color ") + console_color[color];
		cout << command << endl;
		system(command.c_str());*/
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
		//SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|BACKGROUND_RED);
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, Color::console_default);
	}
};

class Rectangle :public Shape
{
	double side1;
	double side2;
public:
	double get_side1()const
	{
		return side1;
	}
	double get_side2()const
	{
		return side2;
	}
	void set_side1(double side1)
	{
		if (side1 <= 0)side1 = 1;
		this->side1 = side1;
	}
	void set_side2(double side2)
	{
		if (side2 <= 0)side2 = 2;
		this->side2 = side2;
	}
	Rectangle(double side1, double side2, Color color):Shape(color)
	{
		set_side1(side1);
		set_side2(side2);
	}
	~Rectangle()
	{

	}
	double get_area()const
	{
		return side1 * side2;
	}
	double get_perimetr()const
	{
		return (side1 + side2) * 2;
	}
	void draw()const
	{
		//1. Получаем окно консоли:
		HWND hwnd = GetConsoleWindow();
		//2. Создаем контекст устройства, полученного окна:
		HDC hdc = GetDC(hwnd);
		//3. Создаем карандаш:
		HPEN hPen = CreatePen(PS_SOLID, 5, color);	//PS_SOLID - сплошная линия, 5 - толщина линии в пикселях, color - цвет
		//4. Прежде чем мы можем рисовать, нужно выбрать чем и на чем рисовать:
		SelectObject(hdc, hPen);

		::Rectangle(hdc, 100, 100, 200, 200);

		//?. УдаНужно удалить карандаш:
		DeleteObject(hPen);
		//?. Все контексты устройств нужно удалять, чтобы освободить занимаемые ими ресурсы:
		ReleaseDC(hwnd, hdc);
	}

};

void main()
{
	setlocale(LC_ALL, "");

	//Shape shape;
	Square square(5, Color::console_red);
	cout << "\nПлощадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << "\n" << endl;
	square.draw(); cout << endl;


}