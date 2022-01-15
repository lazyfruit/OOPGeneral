#include<iostream>
using namespace std;

class Vehicle		//Класс "транспортные средства"
//Абстрактный класс
{
	unsigned int speed;
public:
	virtual void move() const = 0;	//Чисто виртуальный метод
	//Именно этот метод и делает класс абстрактным!
};

class GroundVehicle :public Vehicle		//Наземные транспортные средства
//Абстрактный класс
{

};

class WaterVehicle :public Vehicle		//Водные транспортные средства
//Абстрактный класс
{

};

class AirVehicle :public Vehicle		//Воздушные транспортные средства
//Абстрактный класс
{
	int height;		//Высота на которой может летать
};

class Bike :public GroundVehicle		//Мотоциклы
//Конкретный класс, поскольку он определяет чисто виртуальный метод move
{
public:
	void move()const
	{
		cout << "Мотоцикл ездит на двух колесах." << endl;
	}
};

class Car :public GroundVehicle
{
public:
	void move()const
	{
		cout << "Машина едет на 4 колесах" << endl;
	}
};

class Boat :public WaterVehicle
{
	void move()const
	{
		cout << "Лодка плывет." << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	
	//Vehicle V;			//Невозможно создать экземпляр абстрактного класса
	//GroundVehicle GV;	//Этот класс так же является абстрактным, поскольку он не определяет метод move
	Bike HD;
	HD.move();
	Car BMW;
	BMW.move();
}