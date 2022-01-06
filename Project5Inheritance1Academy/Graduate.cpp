#include"Graduate.h"

const string& Graduate::get_name_of_project()const
{
	return name_of_project;
}
void Graduate::set_name_of_project(const string& name_of_project)
{
	this->name_of_project = name_of_project;
}

//Constructors:
Graduate::Graduate(const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, const string& group, double rating,
	const string& name_of_project)

	:Student(last_name, first_name, age, speciality, group, rating)
{
	set_name_of_project(name_of_project);
	cout << "GConstructor:\t" << this << endl;
}
Graduate::~Graduate()
{
	cout << "GDestructor:\t" << this << endl;
}
//Methods:
void Graduate::print()const
{
	Student::print();
	cout << "Название дипломной работы: " << name_of_project << endl;
}