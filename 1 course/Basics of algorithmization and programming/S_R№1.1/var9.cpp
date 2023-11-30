#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int RandomLength(int& len)
{
	return len = 10 + rand() % (30 - 10 + 1);
}

int EnterN(int& N)
{
	cout << "\nВведи желаемое натуральное число: ";
	do
	{
		cin >> N;
		if (N < 1) cout << "\nЧисло должно быть больше 0\nВвод: ";
	} while (N < 1);
	return N;
}

void EnterKeyboard(string Name, int len)
{
	fstream file(Name);
	int num;
	for (int i = 0; i < len; i++)
	{
		cin >> num;
		file << num << " ";
	}

}

void EnterRandom(string Name, int len)
{
	fstream file(Name);
	int a, b, num;
	do
	{
		cout << "\nВведи диапазон [a;b]: ";
		cin >> a >> b;
		if (a > b) cout << "Левая граница не может быть больше правой\n";
		else if (a == b) cout << "Нежелательный диапазон\n";
	} while (a >= b);
	for (int i = 0; i < len; i++)
	{
		num = a + rand() % (b - a + 1);
		file << num << " ";
	}
}

void Output(string Name, int len)
{
	cout << "\nСодержимое файла: ";
	fstream file(Name);
	int num;
	for (int i = 0; i < len; i++)
	{
		if (!file.eof())
		{
			file >> num;
			cout << num << " ";
		}
	}
	cout << endl;
}

void Choose(string Name, int len, int& rep)
{
	cin.clear();
	int choice;
	if (rep != 0)
	{
		cout << "\nНеверный ввод\n\n";
	}
	rep++;
	cout << "\nВведи способ заполнения файла:\n"
		<< "1 - С клавиатуры\n"
		<< "2 - Случайными числами\n"
		<< "Ввод: ";
	cin >> choice;
	switch (choice)
	{
	case 1: EnterKeyboard(Name, len);
		break;
	case 2: EnterRandom(Name, len);
		break;
	default: Choose(Name, len, rep);
		break;
	}
	Output(Name, len);
}

void MessageAboutThreeInRowRisingNumbers(string Name, int len)
{
	cout << "\nЕсть ли в файле хотя бы 3 подряд возрастающих числа?\n";
	int row = 0, num1, num2 = 0, max = 0;
	fstream file(Name);

	for (int i = 0; i < len; i++)
	{
		if (!file.eof())
		{
			num1 = num2;
			file >> num2;

			if (num2 <= num1) row = 0;
			else
			{
				if (row != 0)
				{
					if (row == 1) cout << "\nРяд: " << num1 << " ";
					cout << num2 << " ";
				}
			}

			row++;
			if (row > max) max = row;
		}
	}
	if (max > 3) cout << "\n\nЕсть, их даже " << max << "\n\n";
	else if (max == 3) cout << "\n\nЕсть\n\n";
	else cout << "\n\nНет\n\n";
	system("pause");
}

void LookingForMaxNumberOnOddPlaces(string In, int lennew)
{
	system("pause");
	cout << "\nПоиск наибольшего числа на нечётных местах\n";
	fstream file(In);
	int num, index, max = -1000000;
	for (int i = 0; i < lennew; i++)
	{
		file >> num;
		if (i % 2 == 1)
			if (num > max) 
			{
				max = num;
				index = i;
			}
	}
	if (max != -1000000)
	{
		cout << "\nМаксимальное число: " << max
			<< "\nЕго индекс: " << index << endl;
	}
	else cout << "\nМаксимального числа на нечётных местах нет\n";
}

void NumbersLessThanN(string Name, string In, int len)
{
	fstream Fileout(Name);
	fstream Filein(In);
	int N, num, lennew = 0;
	cout << "\nЗапись в другой файл чисел, не превышающих абсолютное значение твоего числа.\n";
	EnterN(N);
	for (int i = 0; i < len; i++)
	{
		Fileout >> num;
		if (abs(num) < N)
		{
			Filein << num << " ";
			lennew++;
		}
	}
	Filein.close();
	if (lennew == 0)
	{
		cout << "\nНет чисел, не превышающих абсолютное значение твоего числа\n";
	}
	else 
	{
		cout << "\nЧисла есть и заполнены в файл\n";
		Output(In, lennew);
	}
	LookingForMaxNumberOnOddPlaces(In, lennew);
}

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 9\nФайловые потоки\n\n";
	int len, rep = 0;
	string file1 = "Input.txt";
	string file2 = "Output.txt";
	RandomLength(len);
	cout << "Длина последовательности (количество чисел) равна " << len << "\n\n";
	system("pause");
	Choose(file1, len, rep);
	MessageAboutThreeInRowRisingNumbers(file1, len);
	NumbersLessThanN(file1, file2, len);
	return 1;
}