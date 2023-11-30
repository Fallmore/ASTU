#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void CheckIn(int& a, int& b)
{
	cout << "\nВведи размер матрицы [i][j]: ";
	cin >> a >> b;
	if (a < 1 || b < 1)
	{
		cout << "\nРазмер не должен иметь отрицательных чисел!\n";
		CheckIn(a, b);
	}
}

void Enter(int** Name, int len, int width)
{
	int num;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << "Введи " << j + 1 << "-е число " << i + 1 << "-го столбика: ";
			cin >> num;
			Name[i][j] = num;
		}
	}
}

void Enter(int** Name, int len, int width, int a, int b)
{
	int num;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < width; j++)
		{
			num = a + rand() % (b - a + 1);
			Name[i][j] = num;
		}
	}
}

void Enter(int** Name, int len, int width, string File)
{
	ifstream out(File);
	if (out.is_open())
	{

		int count = 0, temp;
		while (!out.eof())// пробегаем пока не встретим конец файла eof
		{
			out >> temp;//в пустоту считываем из файла числа
			count++;// увеличиваем счетчик числа чисел
		}
		out.clear();
		out.seekg(0, ios::beg);
		int count_space = 0;
		char symbol;
		while (!out.eof())//на всякий случай цикл ограничиваем концом файла
		{
			//теперь нам нужно считывать не числа, а посимвольно считывать данные
			out.get(symbol);//считали текущий символ
			if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
			if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
		}
		int n = count / (count_space + 1);//число строк
		int m = count_space + 1;
		if (n < len || m < width)
		{
			cout << "\nВ файле меньше чисел, чем размер матрицы";
			CheckIn(len, width);
			Enter(Name, len, width, File);
		}
	}
	out.clear();
	out.seekg(0, ios::beg);
	string waste;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < width; j++)
		{
			out >> Name[i][j];
		}
		getline(out, waste);
	}
}

void Output(int** Name, int len, int width)
{
	cout << "Вывод элементов массива." << "\nЭлементы массива:\n";
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << setw(6) << Name[i][j] << " ";
		}
		cout << "\n";
	}
}

void Output(int* Name, int len)
{
	cout << "\nПростые числа: ";
	for (int i = 0; i < len; i++)
	{
		cout << Name[i] << " ";
	}
}

int SimpleNum(int a)
{
	int d = 1, sum = 0;
	for (d = 1; d <= a; d++)
	{
		if (a % d == 0)
		{
			sum++;
		}
	}
	return sum;
}

void SumSimpleNumbers(int** Name, int len, int width)
{
	int sum = 0, SumOfNum = 0, k = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (SimpleNum(Name[i][j]) == 2 || SimpleNum(Name[i][j]) == 1)
			{
				sum += Name[i][j];
				SumOfNum++;
			}
		}
	}

	int* mas1 = new int[SumOfNum];
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (SimpleNum(Name[i][j]) == 2 || SimpleNum(Name[i][j]) == 1)
			{
				if (k < SumOfNum)
				{
					mas1[k] = Name[i][j];
					k++;
				}
			}
		}
	}
	cout << "\nКоличество чисел: " << SumOfNum;
	cout << "\nСумма чисел: " << sum;
	Output(mas1, SumOfNum);
	delete[] mas1;
}

void FindNegativeLine(int** Name, int len, int width)
{
	int True = 0, num = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (Name[i][j] < 0)
			{
				num++;
			}
			else num = 0;
		}
		if (num == width)
		{
			True++;
		}
		else num = 0;
	}
	if (True != 0) cout << "\n\nВ данном массиве есть " << True << " строк отрицательных чисел" << endl;
	else cout << "\n\nВ данном массиве нет строк отрицательных чисел" << endl;
}

void Choice(int** Name, int len, int width, int& rep)
{
	int choice;
	int a, b;
	string FileName = "Output.txt";

	if (rep != 0)
	{
		cout << "\nНеверный способ\n";
	}
	rep++;

	cout << "Введи способ заполнения повторно:\n"
		<< "1 - С клавиатуры\n"
		<< "2 - Случайными числами\n"
		<< "3 - Из файла\n"
		<< "Ввод: ";

	cin >> choice;
	switch (choice)
	{
	case 1: Enter(Name, len, width);
		break;
	case 2:
		do
		{
			cout << "\nВведи диапазон [a;b]: ";
			cin >> a >> b;
			if (a > b) cout << "Левая граница не может быть больше правой\n";
			else if (a == b) cout << "Нежелательный диапазон\n";
		} while (a >= b);
		Enter(Name, len, width, a, b);
		break;
	case 3: Enter(Name, len, width, FileName);
		break;
	default: Choice(Name, len, width, rep);
		break;
	}
	Output(Name, len, width);
	SumSimpleNumbers(Name, len, width);
	FindNegativeLine(Name, len, width);
}

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\nНахождение суммы и количества простых чисел в массиве\n"
		<< "и определение строки отрицательных чисел\n\n";

	int i, j, repeat = 0;

	CheckIn(i, j);

	int** mas = new int* [i];
	for (int x = 0; x < i; ++x) {
		mas[x] = new int[j];
	}

	Choice(mas, i, j, repeat);

	for (int x = 0; x < i; ++x) {
		delete[] mas[x];
	}
	delete[] mas;

	return 0;
}