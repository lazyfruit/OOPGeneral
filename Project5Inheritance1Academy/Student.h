#pragma once
#include "Human.h"

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const;
	const string& get_group()const;

	double get_rating()const;
	void set_speciality(const string& speciality);
	void set_group(const string& group);
	void set_rating(double rating);
	//Constuctors:

	Student(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating);

	~Student();
	//Methods:
	void print()const;
};