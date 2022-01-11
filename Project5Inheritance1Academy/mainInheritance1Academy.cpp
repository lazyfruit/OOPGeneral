#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>	//???
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
		os.width(10);	//Задает ширину поля, в которое будет выводиться следующее значение (в скобках указывается количество знакопозиций)
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
		os.width(10);	//Задает ширину поля, в которое будет выводиться следующее значение (в скобках указывается количество знакопозиций)
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
	std::string position;	//Занимаемая должность
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
		const std::string& position) :Human(last_name, first_name, age)
	{
		this->position = position;
		cout << "EConstructor:\t" << this << endl;
	}
	~Employee()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	virtual double count_salary()const
	{
		return 0;
	}
};

class ResidentEmployee :public Employee
{
	double salary;
public:
	ResidentEmployee(const string& last_name, const string& first_name, unsigned int age,
		const std::string& position,
		double salary):Employee(last_name, first_name, age, position)
	{
		this->salary = salary;
		cout << "RConstructor;\t" << this << endl;
	}
	~ResidentEmployee()
	{
		cout << "RDestructor:\t" << this << endl;
	}
	double count_salary()const
	{
		return salary;
	}
};

class HourEmployee :public Employee
{
	double rate;	//Ставка за час
	int complete_hour;	//Количество отработанных часов
public:
	HourEmployee(const string& last_name, const string& first_name, unsigned int age,
		const std::string& position,
		double rate,
		int complete_hour) :Employee(last_name, first_name, age, position), rate(rate), complete_hour(complete_hour)
	{
		cout << "HEConstructor;\t" << this << endl;
	}
	~HourEmployee()
	{
		cout << "HEDestructor;\t" << this << endl;
	}
	double count_salary()const
	{
		return rate * complete_hour;
	}
};

void SaveToFile(/*const*/ Human* group[], const int size, const string& filename);
void Print(/*const*/ Human* group[], const int size);
Human** LoadFromFile(const std::string& filename);
Human* HumanFactory(const std::string& human_type);

//#define OLD_CODE

void main()
{
	setlocale(LC_ALL, "");

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
	for (int i = 0; i < sizeof(department) / sizeof(department[0]); i++)
	{
		cout << *department[i] << "salary: " << department[i]->count_salary() << endl;
		total_money += department[i]->count_salary();
	}
	cout << "Total money: " << setprecision(15) << total_money << " USD" << endl;	//setprecision(15) - определяет точность выведения 15 знаков
	for (int i = 0; i < sizeof(department) / sizeof(department[0]); i++)
	{
		delete department[i];
	}

#ifdef OLD_CODE
	//Generalisation:
	const Human* group[] =
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

	/*ofstream fout("Group.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	system("notepad Group.txt");*/
	string filename = "Group.txt";
	SaveToFile(group, sizeof(group) / sizeof(group[0]), "Group.txt");
	system((string("notepad ") + filename).c_str());
	//1. string("notepad ") - преобразуем строковую константу "notepad " в объект класса std::string
	//2. streng("nitepad ") + filename - выполняем конкатенацию двух объектов класса std::string
	//3. (std::string).c_str() - метод c_str() возвращает содержимое объекта std::string\
	в виде обычной NULL Terminated line (C-string), т.е. в виде массива элементов char.

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
	//cout << sizeof(group) / sizeof(Human*) << endl;

	/*Human human("last_name", "first_name", 0);
	cout << "Кто к нам пришел: ";
	cin >> human;
	cout << human << endl;*/

	/*Student stud("", "", 0, "", "", 0);
	cout << "Кто к нам пришел: ";
	cin >> stud;
	cout << stud << endl;*/

	/*LoadFromFile("Group.txt");*/
	Human** group = LoadFromFile("Group.txt");
	Print(group, 6);
#endif // OLD_CODE
}

#ifdef OLD_CODE
void SaveToFile(/*const*/ Human* group[], const int size, const string& filename)
{
	ofstream fout(filename);	//ofstream (output file stream)
	for (int i = 0; i < size; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
}
void Print(/*const*/ Human* group[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *group[i] << endl;
	}
}
Human** LoadFromFile(const std::string& filename)
{
	ifstream fin(filename);	//ifstream (input file strem)
	if (fin.is_open())
	{
		//1) Вычисляем размер файла:
		std::string buffer;	//В этот буфер будем читать строки из файла
		int n = 0;	//Количество строк в файле
		while (!fin.eof())	//eof (end of file)
		{
			std::getline(fin, buffer);
			cout << fin.tellg() << endl;	//Проверяем действующую позицию курсора
			n++;
		}
		//2) Выделяем память под массив группу:
		Human** group = new Human * [n] {};
		//3) Возвращаем курсор в начало файла для того чтобы заново его прочитать:
		fin.clear();	//Очищаем поток - сбрасывает позицию курсора (потому что...)
		fin.seekg(/*0*/ ios::beg, 0);
		cout << fin.tellg() << endl;	//Проверяем действующую позицию курсора
		//4) Заново читаем файл и загружаем его содержимое в массив объектов:
		string human_type;
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, human_type, '|');
			/*cout << buffer << endl;*/
			group[i] = HumanFactory(human_type);
			fin >> *group[i];
			cout << *group[i];	//Проверка у Кати
		}
		fin.close();
		return group;
	}
	else
	{
		cerr << "Error: File not found!" << endl;
	}
	return nullptr;	//Если файл прочитать не удалось, возвращаем указатель на 0
}
Human* HumanFactory(const std::string& human_type)	//Пораждающий паттерн проектирования - Фабрика (если нужно создавать много разных объектов
													//которые являются подтипами какого-то типа
{
	if (human_type.find("class Student") != string::npos)return new Student("last_name", "first_name", 0, "spec", "group", 0);
	if (human_type.find("class Graduate") != string::npos)return new Graduate("last_name", "first_name", 0, "spec", "group", 0, "subject");
	if (human_type.find("class Teacher") != string::npos)return new Teacher("last_name", "first_name", 0, "spec", 0);
	return nullptr;
}
#endif // OLD_CODE
