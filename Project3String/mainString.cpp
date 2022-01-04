#pragma warning(disable:4326)
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

#define razdel cout << "\n--------------------------------------------\n" << endl

class String;
String operator+(const String& left, const String& right);

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
	String buffer (left.get_size() + right.get_size() - 1);
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

//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str;		//Default constructor
	str.print();

	String str1 = "Hello";	//Single-argument constructor
	//str1.print();
	cout << str1 << endl;

	String str2 = str1;		//Copy constructor
	cout << str2 << endl;

	String str3;
	str3 = str2;	//Shallow copy - поверностное копирование
	cout << str3 << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef OPERATOR_PLUS_CHECK
	/*String str1 = "Hello";
str1 = str1;
cout << str1 << endl;*/

	String str1 = "Hello";
	String str2 = "World";
	razdel;
	String str3 = str1 + str2;
	razdel;
	cout << str3 << endl;
	/*razdel;
	str1 += str2;
	razdel;
	cout << str1 << endl;*/
#endif // OPERATOR_PLUS_CHECK

	/*String str1;*/	//Default constructor
	String str1(25);
	/*cout << str1 << endl;*/
	str1.print();
	String str2 = "Hello";	//Single-argement constructor
	/*cout << str2 << endl;*/
	str2.print();
	String str3("World");	//Single-argement constructor
	/*cout << str3 << endl;*/
	str3.print();
	String str4();	//Объект не создается,\
					а объявляется функция str4, которая ничего не принимает и возвращает объект класса String
	/*cout << str4 << endl;*/	//Не будет работать!
	String str5{};	//Явный вызов конструктора по умолчанию
	/*cout << str5 << endl;*/
	str5.print();
	String str6{ "Параметры в конструктор можно передавать в фигурных скобках" };	//Single-argement constructor
	/*cout << str6 << endl;*/
	str6.print();
	String str7 = str6;
	/*cout << str6 << endl;*/
	str7.print();
	cout << str2 + " " + str3 << endl;
}