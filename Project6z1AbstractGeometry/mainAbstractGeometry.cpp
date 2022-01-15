#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<thread>
//#include<string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define mintab "  "
#define line "\n______________________________________________________________\n"

namespace Geometry	//Пространство имен "Geometry"
{
	enum Color	//enum - перечисление. Перечисление - набор именованных констант типа int
	{
		//Цвета консоли (console color)
		console_gray = 0x88,	//0x88 - шестнадцатеричный код цвета
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_white = 0xFF,
		console_default = 0x07,

		//console_gray,	//0x88 - шестнадцатеричный код цвета
		//console_blue,
		//console_green,
		//console_red,
		//console_white

		//Цвета Windows
		red = 0x000000FF,
		green = 0x0000FF00,
		dark_green = 0x0000AA00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,
		white = 0x00FFFFFF
		//	Разбивка:
		//			0x00			-		00		-		00		-		FF
		//			ExEE			-		EE		-		EE		-		EE, где E - element
		//Альфа-канал(прозрачность)	-	   синий	-	  зеленый	-	  красный
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
		//Цвет
		Color color;
		//Ширина линии
		unsigned int width;
		//Начальные координаты для отрисовки фигуры
		unsigned int start_x;
		unsigned int start_y;
	public:
		unsigned int get_width()const
		{
			return width;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		void set_width(unsigned int width)
		{
			if (width > 20)width = 20;
			this->width = width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x > 500)start_x = 500;
			this->start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y > 300)start_y = 300;
			this->start_y;
		}
		Shape(Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100)
			:color(color)
		{
			set_width(width);
			set_start_x(start_x);
			set_start_y(start_y);
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
		Square(double side, 
			Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100)
			:Shape(color, width, start_x, start_y)
		{
			set_side(side);
			cout << "SqConstructor:\t" << this << endl;
		}
		~Square()
		{
			cout << "SqDestructor:\t" << this << endl;
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
			SetConsoleTextAttribute(hConsole, Color::red);
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
		Rectangle(double side1, double side2, 
			Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100)
			:Shape(color, width, start_x, start_y)
		{
			set_side1(side1);
			set_side2(side2);
			cout << "RecConstructor:\t" << this << endl;
		}
		~Rectangle()
		{
			cout << "RecDestructor:\t" << this << endl;
		}
		double get_area()const
		{
			return side1 * side2;
		}
		double get_perimeter()const
		{
			return (side1 + side2) * 2;
		}
		void draw()const
		{
			//GDI (Graphics Device Interface) - Интерфейс графического устройства
			//1. Получаем окно консоли:
			HWND hwnd = GetConsoleWindow(); 
			//HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			//2. Создаем контекст устройства, полученного окна:
			HDC hdc = GetDC(hwnd);
			//3. Создаем карандаш:
			HPEN hPen = CreatePen(PS_SOLID, 5, color /*RGB(0, 255, 0)*/);	//PS_SOLID - сплошная линия, 5 - толщина линии в пикселях, color - цвет
			//4. Прежде чем мы можем рисовать, нужно выбрать чем и на чем рисовать:
			SelectObject(hdc, hPen);
			//5. Чтобы закрасить фигуру нужно создать и применить кисть:
			HBRUSH hBrush = CreateSolidBrush(color /*RGB(0, 150, 0)*/);
			//6. Выбираем кисть чтобы закрасить:
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, start_x, start_y, start_x + /*side1*/ side2, start_y + /*side2*/ side1);

			//7. Нужно удалить кисть:
			DeleteObject(hBrush);
			//?. Нужно удалить карандаш:
			DeleteObject(hPen);
			//?. Все контексты устройств нужно удалять, чтобы освободить занимаемые ими ресурсы:
			ReleaseDC(hwnd, hdc);
		}
		void start_draw()const
		{
			while (!true)
			{
				draw();
			}
		}
	};

	class Triangle :public Shape
	{//Задаем класс абстрактным, поскольку существуют разные типы треугольника
	public:
		Triangle(Color color, unsigned int width, unsigned int start_x, unsigned int start_y)
			:Shape(color, width, start_x, start_y)
		{

		}
		~Triangle()
		{

		}
		virtual double get_height()const = 0;	//Но мы знаем что у всех треугольников есть высота
	};
	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(side / 2, 2));
		}
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
		}
		double get_area()const
		{
			return side * side * sqrt(3) / 4;
		}
		double get_perimeter()const
		{
			return side * 3;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			const POINT points[] =
			{
				{start_x, start_y + this->get_height()},
				{start_x + side, start_y + this->get_height()},
				{start_x + side / 2, start_y}
			};
			Polygon(hdc, points, sizeof(points) / sizeof(POINT));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void start_draw()const
		{
			while (!true)
			{
				draw();
			}
		}
		EquilateralTriangle(double side, 
			Color color = Color::white, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100)
			:Triangle(color, width, start_x, start_y)
		{
			set_side(side);
			cout << "ETonstructor:\t" << this << endl;
		}
		~EquilateralTriangle()
		{
			cout << "ETDestructor:\t" << this << endl;
		}
	};
}

//#define FULLSCREEN_CONSOLE
//#define SQUARE
#define RECTANGLE
#define TRIANGLE

//CONSOLE_SCREEN_BUFFER_INFO

void main()
{
	setlocale(LC_ALL, "");

#ifdef FULLSCREEN_CONSOLE
	//Открытие окна консоли на весь экран
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buffer = { 80, 50 };
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN, &buffer);
#endif // FULLSCREEN_CONSOLE


	//Shape shape;
#ifdef SQUARE
		Geometry::Square square(5, Geometry::Color::red);
	cout << "\n" << mintab << "Рисуем квадрат" << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << "\n" << endl;
	square.draw(); cout << endl;
	//system("pause");//Приостанавливает выполнение программы и для продолжения ожидает нажатие любой клавиши
	cout << "Для продолжения нажмите \"Enter\"" << endl; cin.get();//Приостанавливает выполнение программы и для продолжения ожидает нажатие клавиши Enter
	cout << line << endl;
#endif // SQUARE
	
	char key;

#ifdef RECTANGLE
	Geometry::Rectangle rect1(50, 70, Geometry::Color::yellow, 5, 200, 100);
	cout << "\n" << mintab << "Рисуем прямоугольник" << endl;
	cout << rect1.get_area() << endl;
	cout << rect1.get_perimeter() << endl;
	key = 0;
	//while (key != ' ')
	//{
	//	rect1.draw();
	//	if (_kbhit())key = _getch();//Отслеживает нажатие клавиши
	//}
	std::thread rect1_thread(&Geometry::Rectangle::start_draw, rect1);//Вывод прямоугольника в потоке
	cout << "Для продолжения нажмите \"Enter\"" << endl; cin.get();
	cout << line << endl;
#endif // RECTANGLE

#ifdef TRIANGLE
	Geometry::EquilateralTriangle et(50, Geometry::Color::green, 5, 100, 100);
	cout << et.get_height() << endl;
	cout << et.get_area() << endl;
	cout << et.get_perimeter() << endl;
	key = 0;
	/*while (key != ' ')
	{
		et.draw();
		if (_kbhit())key = _getch();
	}*/
	std::thread et_thread(&Geometry::EquilateralTriangle::start_draw, et);//Вывод треугольника в потоке
	cout << "Для продолжения нажмите \"Enter\"" << endl; cin.get();
	cout << line << endl;
#endif // TRIANGLE

	cin.get();
	rect1_thread.join();
	et_thread.join();
	//Реализация генерации фигур через функцию схожую с HumanFactory
}