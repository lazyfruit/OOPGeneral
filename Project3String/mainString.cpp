#pragma warning(disable:4326)
#include<iostream>
#include"String.h"

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