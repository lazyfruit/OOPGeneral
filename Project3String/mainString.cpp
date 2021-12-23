#pragma warning(disable:4326)
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

#define razdel cout << "\n--------------------------------------------\n" << endl

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;	//Размер строки в байтах
	char* str;	//Адрес строки в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//		Constructors:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{//Shallow copy - поверхностное копирование
	 //Конструктор переноса должен работать так, как НЕ должен работать коструктор копирования
		this->size = other.size;
		this->str = other.str;
		cout << "MoveConstructor:\t" << this << endl;
		other.str = nullptr;
		other.size = 0;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	//		Operators
	String& operator=(const String& other)
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
	String& operator=(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		other.size;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};
String operator+(const String& left, const String& right)
{
	String buffer = left.get_size() + right.get_size() - 1;
	for (int i = 0; i < left.get_size(); i++)
		//buffer.get_str()[i] = left.get_str()[i];
		buffer[i] = left[i];
	//	  l-value = r-value;
	for (int i = 0; i < right.get_size(); i++)
		//buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		buffer[i + left.get_size() - 1] = right[i];

	return buffer;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK

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
}