#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
//Чисто виртуальный метод - pure virtual function ("= 0" показывает что данная функция не имеет определения)
//vitual type name (parameters) = 0; - синтаксис объявления чисто виртуального метода

class Vehicle		//Класс "транспортные средства"
//Абстрактный класс
{
	unsigned int speed;
public:
	virtual void move()const = 0;	//Чисто виртуальный метод - pure virtual function ("= 0" показывает что данная функция не имеет определения)
	//Именно этот метод и делает класс абстрактным!
};

class GroundVehicle :public Vehicle		//Наземные транспортные средства
{	//Абстрактный класс

};

class WaterVehicle :public Vehicle		//Водные транспортные средства
{	//Абстрактный класс

};

class AirVehicle :public Vehicle		//Воздушные транспортные средства
{	//Абстрактный класс
	int height;		//Высота на которой может летать
};

class Bike :public GroundVehicle		//Мотоциклы
{	//Конкретный класс, поскольку он определяет чисто виртуальный метод move
public:
	void move()const //Если метод объявлен константным то в дочерних классах он так же должен быть константным!
	{
		cout << "Мотоцикл едет на двух колесах." << endl;
	}
};

class Car :public GroundVehicle
{	//Конкретный класс, поскольку он определяет чисто виртуальный метод move
public:
	void move()const //Если метод объявлен константным то в дочерних классах он так же должен быть константным!
	{
		cout << "Машина едет на четырех колесах" << endl;
	}
};

class Boat :public WaterVehicle
{	//Конкретный класс, поскольку он определяет чисто виртуальный метод move
public:
	void move()const  //Если метод объявлен константным то в дочерних классах он так же должен быть константным!
	{
		cout << "Лодка плывет." << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	
	//Vehicle V;			//Невозможно создать экземпляр абстрактного класса
	//GroundVehicle GV;	//Этот класс так же является абстрактным, поскольку он не определяет (~не использует, не описывает действие) метод move
	Bike HD;
	HD.move();
	Car BMW;
	BMW.move();
	Boat boat();
	boat.move();
}