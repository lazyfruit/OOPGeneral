#pragma once
#include "Human.h"

class Teacher : public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_peciality()const;
	unsigned int get_experience()const;
	void set_speciality(const string& speciality);
	void set_experience(unsigned int experience);
	//Constructors:
	Teacher(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience);
	~Teacher();
	//Methods:
	void print()const;
};