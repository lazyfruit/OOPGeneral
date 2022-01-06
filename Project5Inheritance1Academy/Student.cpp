#include "Student.h"

const string& Student::get_speciality()const
{
	return speciality;
}
const string& Student::get_group()const
{
	return group;
}

double Student::get_rating()const
{
	return rating;
}
void Student::set_speciality(const string& speciality)
{
	this->speciality = speciality;
}
void Student::set_group(const string& group)
{
	this->group = group;
}
void Student::set_rating(double rating)
{
	this->rating = rating;
}
//Constuctors:

Student::Student(const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, const string& group, double rating)
	:Human(last_name, first_name, age)	//Делегируем конструктор базового класса
{
	set_speciality(speciality);
	set_group(group);
	set_rating(rating);
	cout << "SConstructor:\t" << this << endl;
}

Student::~Student()
{
	cout << "SDestructor:\t" << this << endl;
}
//Methods:
void Student::print()const
{
	Human::print();
	cout << "Специальность: " << speciality
		<< ", группа: " << group
		<< ", успеваемость: " << rating << endl;
}