#include<iostream>
using namespace std;
/*
1. �������� ���� ArrayValueCalculator
2. �������� ����� doCalc.�� ���� �� ������ �������� �������� �������� ����� ������� 4�4.
3. ��� �������� ������ ������ ������ � ����� doCalc ��������� �������� ������� ArraySizeException.
4. ����� doCalc ������� �������� �� ���� ���������� ������ � ����������� � int � ����������.ϳ��� ���������� ������������� ����� ������� ��������� ��������� � ������ int.
5.���� � ������� ������� ������ ������������ �� �������(���������, � ������ ������ ������ ��� ����� ������ �����), ��� �������� ������� ArrayDataException, � ����������� � ����� ���� ������ ������ ����� ���.
6. � ����� main() ��������� ��������� �����, �������� ������ ������� ArraySizeException �� ArrayDataException, �� ������� ��������� ����������.
7. * ��������� ������������� ��� ������ ���������� ��������� ���������� ����������.
8. * ��� ����� ������� � ������ ������������, ����� �� ����� �������, �� ����������� ������(���������) ��������, �� ����������������.*/
class ArraySizeException
{
public:
	void output();
};
void ArraySizeException::output()
{
	cout << "ArraySizeException" << endl;
}

class ArrayDataException
{
	int i, j;
public:
	ArrayDataException(int, int);
	void output();
};

ArrayDataException::ArrayDataException(int a, int b)
{
	i = a;
	j = b;
}

void ArrayDataException::output()
{
	cout << "ArrayDataException" << endl;
	cout << "Error in line " << i << " column " << j << endl;
}
class ArrayValueCalculator
{
public:
	template <typename T, std::size_t m, std::size_t n>
	void doCalc(T(&a)[m][n]);
};
template <typename T, std::size_t m, std::size_t n>
void ArrayValueCalculator::doCalc(T(&a)[m][n])
{
	int sum = 0;
	int cas;
	int j = 0, i = 0, g;
	for (auto& r1 : a)
	{
		j++;
		for (auto& r2 : r1)
		{
			i++;
			g = i / j;
			cout << r2 << ' ';
			cas = atoi(r2.c_str());
			char ch = static_cast<char>(cas);
			sum += cas;

			if (cas == 0)
			{
				throw new ArrayDataException(j, g);
			}

		}
		cout << endl;
	}
	if (m * n != 16)
	{
		throw new ArraySizeException();
	}
	cout << sum;
}
int main()
{
	setlocale(LC_ALL, "ru");
	string array1[3][4] = { {"1","2","3","4"},
						   {"5","6","7","8"},
						   {"9","10","11","12"} };
	string array[4][4] = { {"1","3","3","4"},
						   {"5","6","r","8"},
						   {"9","10","11","12"},
						   {"13","14","15","16"} };
	ArrayValueCalculator a;
	try
	{
		a.doCalc(array);
	}
	catch (ArraySizeException* Exemption)
	{
		Exemption->output();
	}
	catch (ArrayDataException* Exemption)
	{
		Exemption->output();
	}
}

