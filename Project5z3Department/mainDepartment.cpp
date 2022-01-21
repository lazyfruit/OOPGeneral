#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

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
		set_last_name(last_name);//»нициализаци€ в теле конструктора
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
		os.width(20);
		os << left;
		os << typeid(*this).name() << "|";
		os.width(15);	//«адает ширину пол€, в которое будет выводитьс€ следующее значение (в скобках указываетс€ количество знакопозиций)
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
	virtual ifstream& input(ifstream& is)
	{
		std::getline(is, last_name, '|');
		std::getline(is, first_name, '|');
		string age_buffer;
		std::getline(is, age_buffer, '|');
		this->age = std::stoi(age_buffer);	//stoi() - преобразует строку в число
		return is;
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
ifstream& operator>>(ifstream& is, Human& obj)
{
	return obj.input(is);
}

class Employee :public Human
{
	std::string position;//«анимаема€ должность
public:
	const std::string& get_position()const
	{
		return position;
	}
	void set_posotion(const std::string& position)
	{
		this->position = position;
	}
	Employee(const string& last_name, const string& first_name, unsigned int age,
		const std::string& position)
		:Human(last_name, first_name, age)
	{
		this->position = position;//»нициализаци€ в теле конструктора (1 вариант)
		cout << "EConstructor:\t" << this << endl;
	}
	~Employee()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	ostream& print(ostream& os)const
	{
		Human::print(os);
		os.width(10);
		os << left;
		os << position;
		return os;
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		os.width(10);
		os << left;
		os << position << "|";
		return os;
	}
	istream& input(istream& is)
	{
		Human::input(is);
		is >> position;
		return is;
	}
	ifstream& input(ifstream& is)
	{
		Human::input(is);
		std::getline(is, position, '|');
		return is;
	}
	virtual double count_salary()const = 0;
};

class ResidentEmployee :public Employee
{
	double salary;
public:
	double get_salary()const
	{
		return salary;
	}
	void set_salary(double salary)
	{
		this->salary = salary;
	}
	ResidentEmployee(const string& last_name, const string& first_name, unsigned int age,
		const std::string& position,
		double salary)
		:Employee(last_name, first_name, age, position)
	{
		set_salary(salary);//»нициализаци€ в теле конструктора (2 вариант)
		cout << "RConstructor;\t" << this << endl;
	}
	~ResidentEmployee()
	{
		cout << "RDestructor:\t" << this << endl;
	}
	ostream& print(ostream& os)const
	{
		Human::print(os);
		os.width(16);
		os << left;
		os << salary;
		return os;
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		os.width(10);
		os << left;
		os << salary << "RUB" << "|";
		return os;
	}
	istream& input(istream& is)
	{
		Human::input(is);
		is >> salary;
		return is;
	}
	ifstream& input(ifstream& is)
	{
		Human::input(is);
		string salary_buffer;
		std::getline(is, salary_buffer, '|');
		this->salary = std::stod(salary_buffer);
		return is;
	}
	double count_salary()const
	{
		return salary;
	}
};

class HourEmployee :public Employee
{
	double rate;	//—тавка за час
	int complete_hour;	// оличество отработанных часов
public:
	HourEmployee(const string& last_name, const string& first_name, unsigned int age,
		const std::string& position,
		double rate,
		int complete_hour)
		:Employee(last_name, first_name, age, position), rate(rate), complete_hour(complete_hour)//»нициализаци€ в имени конструктора
	{
		cout << "HEConstructor;\t" << this << endl;
	}
	~HourEmployee()
	{
		cout << "HEDestructor;\t" << this << endl;
	}
	ostream& print(ostream& os)const
	{
		Human::print(os);
		os.width(10);
		os << left;
		os << rate;
		os.width(5);
		os << left;
		os << complete_hour;
		return os;
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		os.width(10);
		os << left;
		os << rate << "RUB" << "|";
		os.width(5);
		os << left;
		os << complete_hour << "hour" << "|";
		return os;
	}
	istream& input(istream& is)
	{
		Human::input(is);
		is >> rate;
		is >> complete_hour;
		return is;
	}
	ifstream& input(ifstream& is)
	{
		Human::input(is);
		string rate_buffer;
		std::getline(is, rate_buffer, '|');
		this->rate = std::stod(rate_buffer);
		string complete_hour_buffer;
		std::getline(is, complete_hour_buffer, '|');
		this->complete_hour = std::stod(complete_hour_buffer);
		return is;
	}
	double count_salary()const
	{
		return rate * complete_hour;
	}
};

void SaveToFile(/*const*/ Employee* department[], const int size, const string& filename);
void Print(/*const*/ Employee* department[], const int size);
Employee** LoadFromFile(const std::string& filename);
Employee* HumanFactory(const std::string& human_type);

void main()
{
	setlocale(LC_ALL, "");
	//Generalisation
	Employee* department[] =
	{
		new HourEmployee("Pinkman", "Jessie", 22, "Helper", 1000, 20),
		new HourEmployee("Versetti", "Tommy", 30, "Killer", 5000, 10),
		new ResidentEmployee("White", "Walter", 50, "Chemist", 150000),
		new ResidentEmployee("Diaz", "Ricardo", 55, "Director", 825000),
		new ResidentEmployee("Schrader", "Hank", 42, "Detective", 10000),
		new HourEmployee("Eistein", "Albert", 143, "Researcher", 3000, 15)
	};
	double total_money = 0;
	//Specialisation
	cout << endl;
	for (int i = 0; i < sizeof(department) / sizeof(department[0]); i++)
	{
		cout << *department[i] << "salary: " << department[i]->count_salary() << endl;
		total_money += department[i]->count_salary();
	}
	cout << "\nTotal money: " << setprecision(15) << total_money << " RUB" << endl;	//setprecision(15) - определ€ет точность выведени€ 15 знаков
	for (int i = 0; i < sizeof(department) / sizeof(department[0]); i++)
	{
		delete department[i];
	}
}

void SaveToFile(Employee* department[], const int size, const string& filename)
{
	ofstream fout(filename);
	for (int i = 0; i < size; i++)
	{
		fout << *department[i] << endl;
	}
	fout.close();
}
void Print(Employee* department[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *department[i] << endl;
	}
}
Employee** LoadFromFile(const std::string& filename)
{
	ifstream fin(filename);
	if (fin.is_open())
	{
		std::string buffer;
		int n = 0;
		while (!fin.eof())
		{
			std::getline(fin, buffer);
			cout << fin.tellg() << endl;
			n++;
		}
		Employee** department = new Employee * [n] {};
		fin.clear();
		fin.seekg(ios::beg, 0);
		cout << fin.tellg() << endl;
		string human_type;
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, human_type, '|');
			department[i] = HumanFactory(human_type);
			fin >> *department[i];
		}
		fin.close();
		return department;
	}
	else
	{
		cerr << "Error: File not found!" << endl;
	}
	return nullptr;
}
Employee* HumanFactory(const std::string& human_type)
{
	if (human_type.find("class ResidentEmployee") != string::npos) return new ResidentEmployee("last_name", "first_name", 0, "spec", 0);
	if (human_type.find("HourEmployee") != string::npos) return new HourEmployee("last_name", "first_name", 0, "spec", 0, 0);
	return nullptr;
}