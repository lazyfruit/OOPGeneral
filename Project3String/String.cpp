#include"String.h"
//Определение класса - Class definition
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//		Constructors:
String::String(int size) :size(size)/*Инициализация в заголовке*/, str(new char[size] {})/*Выделение памяти в заголовке*/
{
	/*this->size = size;*/
	/*this->str = new char[size] {};*/
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char* str) :size(strlen(str) + 1), str(new char[size] {})
{
	/*this->size = strlen(str) + 1;*/
	/*this->str = new char[size] {};*/
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :size(other.size), str(new char[size] {})
{
	/*this->size = other.size;*/
	/*this->str = new char[size] {};*/
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{//Shallow copy - поверхностное копирование
 //Конструктор переноса должен работать так, как НЕ должен работать коструктор копирования
	/*this->size = other.size;*/
	/*this->str = other.str;*/
	other.str = nullptr;
	other.size = 0;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}
//		Operators
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	//Deep copy (глубокое копирование):
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssigment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	other.size;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}
//:: - глобальное пространство имен (global scope)
::String operator+(const String& left, const String& right)
{
	String buffer(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//buffer.get_str()[i] = left.get_str()[i];
		buffer[i] = left[i];
	//	  l-value = r-value;
	for (int i = 0; i < right.get_size(); i++)
		//buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		buffer[i + left.get_size() - 1] = right[i];

	return buffer;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
//Конец определение класса - Class definition end