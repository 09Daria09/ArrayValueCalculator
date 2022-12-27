#include<iostream>
using namespace std;
/*
1. Створити Клас ArrayValueCalculator
2. Створити метод doCalc.На вхід до методу подається двомірний рядковий масив розміром 4х4.
3. При передачі масиву іншого розміру в метод doCalc необхідно викинути виняток ArraySizeException.
4. Метод doCalc повинен пройтися за всіма елементами масиву і перетворити в int і підсумувати.Після загального підсумовування метод повертає фінальний результат у вигляді int.
5.Якщо в якомусь елементі масиву перетворення не вдалося(наприклад, в комірці лежить символ або текст замість числа), тоді викинути виняток ArrayDataException, з деталізацією в якому саме комірці лежать невірні дані.
6. У методі main() викликати отриманий метод, обробити можливі винятки ArraySizeException та ArrayDataException, та вивести результат розрахунку.
7. * Необхідно дотримуватись усіх правил збереження контексту викинутого виключення.
8. * При вилові винятків у процесі перетворення, взяти до уваги винятки, що викидаються іншими(сторонніми) методами, що використовуються.*/
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

