#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

#define tab "\t"
#define razdel cout << "\n--------------------------------------------\n" << endl

class Matrix
{
	int rows;
	int cols;
	int** arr;
public:
	int get_rows()const
	{
		return rows;
	}
	int get_cols()const
	{
		return cols;
	}
	//		Constructors
	Matrix(int rows = 2, int cols = 2)
	{
		this->rows;
		this->cols;
		this->arr = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int [cols] {};
		}
		cout << "Constructors:\t" << this << endl;
	}
	Matrix(int n):Matrix(1, n)
	{
		/*this->rows = 1;*/
		/*this->cols = n;*/
	}
	Matrix(const Matrix& other):Matrix(other.rows, other.cols)
	{
		/*this->rows = other.rows;
		this->cols = other.cols;*/
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->arr[i][j] = other.arr[i][j];
			}
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
		cout << "Destructor:\t" << this << endl;
	}
	//		Operators
	Matrix& operator=(const Matrix& other)
	{

	}
	const int* operator[](int i)const
	{
		return arr[i];
	}
	int* operator[](int i)
	{
		return arr[i];
	}
	//		Methods
	void print()const
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");

	Matrix A(3, 4);
	for (int i = 0; i < A.get_rows(); i++)
	{
		for (int j = 0; j < A.get_cols(); j++)
		{
			A[i][j] = rand() % 100;
		}
	}
	A.print();
	Matrix B;
	B = A;
	B.print();
}