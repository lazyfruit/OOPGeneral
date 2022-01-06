#pragma once
#include "Student.h"

class Graduate :public Student
{
	string name_of_project;

public:
	const string& get_name_of_project()const;
	void set_name_of_project(const string& name_of_project);
	//Constructors:
	Graduate(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& name_of_project);
	~Graduate();
	//Methods:
	void print()const;
};