#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//					Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	//				Methods:
	virtual /*void*/ ostream& print(ostream& os)const
	{
		//cout << last_name << " " << first_name << " " << age << " лет.\n";
		//return os << last_name << " " << first_name << ", " << age << " лет,\n";
		os.width(10);	//«адает ширину пол€, в которое будет выводитьс€ следующее значение (в скобках указываетс€ количество знакопозиций)
		os << std::left; os << last_name;
		os.width(10); os << std::left; os << first_name;
		os.width(5); os << std::left; os << age;
		return os;
	}
	virtual ofstream& print(ofstream& os)const
	{
		os.width(15);
		os << left;
		os << typeid(*this).name() << "|";
		os.width(10);	//«адает ширину пол€, в которое будет выводитьс€ следующее значение (в скобках указываетс€ количество знакопозиций)
		os << std::left;
		os << last_name << "|";
		os.width(10);
		os << std::left;
		os << first_name << "|";
		os.width(5);
		os << std::left;
		os << age << "|";
		/*os << std::to_string(age) + ",";*/
		return os;
	}
	virtual istream& input(istream& is)
	{
		return is >> last_name >> first_name >> age;
	}
};
ostream& operator<<(ostream& os, const Human& obj)
{
	/*obj.print(os);
	return os;*/
	return obj.print(os);
}
ofstream& operator<<(ofstream& os, const Human& obj)
{
	return obj.print(os);
}
istream& operator>>(istream& is, Human& obj)
{
	return obj.input(is);
}

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	//				Constructors:
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating
	) :Human(last_name, first_name, age)	//ƒелегируем конструктор базового класса
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//				Methods:
	/*void*/ ostream& print(ostream& os)const
	{
		Human::print(os);
		// /*cout*/ return os << "—пециальность: " << speciality
		// << ", группа: " << group
		// << ", успеваемость: " << rating /*<< endl*/;
		os.width(25); os << left; os << speciality;
		os.width(8); os << left; os << group;
		os.width(5); os << internal; os << rating; os << "%";
		return os;
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		os.width(25); os << left; os << speciality << "|";
		os.width(8); os << left; os << group << "|";
		os.width(5); os << internal; os << rating; os << "%" << "|";
		return os;
	}
	virtual istream& input(istream& is)
	{
		Human::input(is);
		is >> speciality >> group >> rating;
		return is;
	}
};

class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//					Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	/*void*/ ostream& print(ostream& os)const
	{
		Human::print(os);
		// /*cout*/ return os << "—пециальность: " << speciality << ", опыт преподавани€: " << experience /*<< endl*/;
		os.width(33); os << left; os << speciality;
		os.width(5); os << right; os << experience << "y";
		return os;
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		os.width(34); os << left; os << speciality << "|";
		os.width(5); os << right; os << experience << "y" << "|";
		return os;
	}
};

class Graduate :public Student
{
	string subject;
public:
	const string& get_subject()const
	{
		return subject;
	}
	void set_subject(const string& subject)
	{
		this->subject = subject;
	}
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& subject
	) :Student(last_name, first_name, age, speciality, group, rating)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	/*void*/ ostream& print(ostream& os)const
	{
		Student::print(os);
		// /*cout*/ return os << ", тема диплома: " << subject /*<< endl*/;
		return os << left << "  " << subject;
	}
	ofstream& print(ofstream& os)const
	{
		Student::print(os);
		os << left << "  " << subject;
		return os;
	}
};

//#define INHERITANCE
#define OUTPUT_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE
	Human h("Montana", "Antonio", 35);
	h.print();

	Student s("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 93);
	s.print();

	Teacher t("White", "Walter", 50, "Chemistry", 25);
	t.print();

	Graduate g("Schrader", "Hank", 42, "Cryminalistic", "OBN", 95, "How to catch Heisenberg");
	g.print();
#endif // INHERITANCE

#ifdef OUTPUT_CHECK
	//Generalisation:
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 93),//upcast
		new Student("Versetti", "Tommy", 30, "Cryminal", "Vice", 90),//upcast
		new Teacher("White", "Walter", 50, "Chemistry", 25),//upcast
		new Student("Diaz", "Ricardo", 55, "Weapon distribution", "Vice", 80),
		new Graduate("Schrader", "Hank", 42, "Cryminalistic", "OBN", 95, "How to catch Heisenberg"),
		new Teacher("Eistein", "Albert", 143, "Atronomy", 120)
	};

	//Specialisation:
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << "\n--------------------------------------------------------\n";
		//group[i]->print();
		cout << *group[i] << endl;
	}
	cout << "\n--------------------------------------------------------\n";

	ofstream fout("Group.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	system("notepad Group.txt");

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
	//cout << sizeof(group) / sizeof(Human*) << endl;  
#endif // OUTPUT_CHECK

	/*Human human("last_name", "first_name", 0);
	cout << " то к нам пришел: ";
	cin >> human;
	cout << human << endl;*/

	/*Student stud("", "", 0, "", "", 0);
	cout << " то к нам пришел: ";
	cin >> stud;
	cout << stud << endl;*/
}