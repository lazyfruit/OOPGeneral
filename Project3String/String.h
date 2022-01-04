#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

#define razdel cout << "\n--------------------------------------------\n" << endl

class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

//Объявление класса - Class declaration
class String
{
	int size;	//Размер строки в байтах
	char* str;	//Адрес строки в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//		Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();
	//		Operators
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	const char& operator[](int i)const;
	char& operator[](int i);
	void print()const;
};
//Конец объявления класса - Class declaration end