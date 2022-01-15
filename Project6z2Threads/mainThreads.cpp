#include<iostream>
#include<thread>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define line "\n______________________________________________________________\n"
#define sleep /*Sleep(10);*/ /*Sleep(100);*/ Sleep(1000);

bool finish = false;
void Hello()
{
	while (!finish)
	{
		//cout << "Hello";
		cout << "-";
		sleep
	}
}
void World()
{
	while (!finish)
	{
		//cout << "World";
		cout << "+";
		sleep
	}
}
void Goodbye()
{
	while (!finish)
	{
		//cout << "Goodbye";
		cout << "=";
		sleep
	}
}
void Dream()
{
	while (!finish)
	{
		//cout << "Dream";
		cout << "/";
		sleep
	}
}

void main()
{
	setlocale(LC_ALL, "");

	cout << "Для начала работы программы нажмите \"Enter\". Для завершения повторно нажмите \"Enter\"." << endl; cin.get();
	//Вывод в поток
	std::thread hello_thread(Hello);
	std::thread world_thread(World);
	std::thread goodbye_thread(Goodbye);
	std::thread dream_thread(Dream);

	cin.get(); finish = true;//Условие выхода из потока

	//Высвобождение потока
	world_thread.join();
	hello_thread.join();
	goodbye_thread.join();
	dream_thread.join();
}