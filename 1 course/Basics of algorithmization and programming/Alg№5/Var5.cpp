#include <iostream>
#include <fstream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <list>
#include <set>

using namespace std;

int vvod(int& len) //проверка допустимости значения длины
{
	cout << "\nВведи желаемую длину последовательности: ";
	cin >> len;
	if (len <= 0)
	{
		cout << "\nОшибка: данная длина не допустима\n";
		return vvod(len);
	}
	else return 1;
}

int check(int& min, int& max) //проверка
{
	cout << "\nВведи желаемый диапазон ([a;b]): ";
	cin >> min >> max;
	if (min > max)
	{
		cout << "\nОшибка: левая граница больше правой\n";
		return check(min, max);
	}
	else return 1;
}

int GetRandomNumber(int min, int max)
{
	// Получить случайное число - формула
	int num = min + rand() % (max - min + 1);
	return num;
}

bool vvin(const char Name[], int len, int min, int max) //Заполнение
{
	ofstream inn("C:\\Users\\slava\\source\\repos\\Alg№5\\Alg№5");
	inn.open(Name);
	int i;
	if (inn)
	{
		for (i = 0; i < len; i++)
		{
			inn << GetRandomNumber(min, max);
			if (i != len - 1)
			{
				inn << "\n";
			}
		}
		cout << "\nФайл " << Name << " заполнен\n";
		return 1;
	}
	else
	{
		cout << "\nОшибка: Файл не открылся\n";
		return 0;
	}
	inn.close();
}

void Print(const char Name[]) //Вывод
{
	ifstream outt("C:\\Users\\slava\\source\\repos\\Alg№5\\Alg№5");
	outt.open(Name);
	if (outt.is_open())
	{
		if (outt.eof())
		{
			cout << "\nОшибка: файл пустой\n";
		}
		else
		{
			cout << "\nСодержимое файла " << Name << ": ";
			while (!outt.eof())
			{
				string str;
				getline(outt, str);
				cout << str << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "\nОшибка: Файл не открылся\n";
	}
	outt.close();
}

void sort(const char Name[], list <string>& srt) //Исключение повторных чисел
{
	ifstream outg("C:\\Users\\slava\\source\\repos\\Alg№5\\Alg№5");
	outg.open(Name);
	list <string> lenlist;
	if (outg.is_open())
	{
		if (outg.eof())
		{
			cout << "\nОшибка: файл пустой\n";
		}
		else
		{
			list <string> unik;
			while (!outg.eof())
			{
				string str;
				getline(outg, str);
				unik.push_back(str);
			}
			lenlist.assign(unik.begin(), unik.end());
			set <string> s;
			unik.remove_if([&](string n) {return (s.find(n) == s.end()) ? (s.insert(n), false) : true;}); //Херобора
			srt.assign(unik.begin(), unik.end());
			if (lenlist.size() == srt.size())
			{
				cout << "\nПовторяющихся чисел нет\n";
			}
			else cout << "\nПовторяющиеся числа исключены\n";
		}
	}
	else
	{
		cout << "\nОшибка: Файл не открылся\n";
	}
	outg.close();
}

void fill(const char Name[], list <string> srt)
{
	ofstream ing("C:\\Users\\slava\\source\\repos\\Alg№5\\Alg№5");
	ing.open(Name);
	int fuck = 0;
	if (ing)
	{
		for (auto i : srt)
		{
			if (fuck != 0)
			{
				ing << "\n";
			}
			fuck = 1;
			ing << i;
		}
		cout << "\nФайл " << Name << " заполнен\n";
	}
	else
	{
		cout << "\nОшибка: Файл не открылся\n";
	}
	ing.close();
}

void binin(const char Name1[], const char Name2[])
{
	ifstream from("C:\\Users\\slava\\source\\repos\\Alg№5\\Alg№5");
	ofstream to("C:\\Users\\slava\\source\\repos\\Alg№5\\Alg№5", ios::binary);
	from.open(Name1);
	to.open(Name2);
	string n;
	char c[100];
	int sum = 0;
	while (!from.eof())
	{
		from >> n;
		to.write((char*)&n, sizeof n);
		sum++;
	}
	cout << "\nБинарный файл " << Name2 << " заполнен\n";
	cout << "Количество элементов в файле: " << sum << endl;
	from.close();
	to.close();
}

void PrintBin(const char Name[]) //Вывод
{
	ifstream outb("C:\\Users\\slava\\source\\repos\\Alg№5\\Alg№5", ios::binary);
	outb.open(Name);
	if (outb.is_open())
	{
		cout << "\nСодержимое бинарного файла " << Name << ": ";
		string str;
		while (outb.read(reinterpret_cast<char*>(&str), sizeof(string)))
		{
			cout << str << " ";
		}
		cout << endl;
		outb.close();
	}
	else
	{
		cout << "\nОшибка: бинарный файл не открылся\n";
	}
}


int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\nЗаполнение файла числами и отбор уникальных в другой файл\n";
	// Установить генератор случайных чисел
	srand((unsigned)time(NULL));
	int len;
	list <string> srt;
	do
	{
		if (vvod(len) == 1)
		{
			int min;
			int max;
			if (check(min, max) == 1)
			{
				cout << "\nЗаполнение файла генератором чисел:";
				vvin("f.txt", len, min, max);
				cout << "\nВывод содержимого файла:";
				Print("f.txt");
				cout << "\nИсключение повторяющихся чисел файла:";
				sort("f.txt", srt);
				cout << "\nЗаполнение файла уникальными числами:";
				fill("g.txt", srt);
				cout << "\nВывод содержимого файла:";
				Print("g.txt");
				cout << "\nЗаполнение в бинарный файл:";
				binin("g.txt", "Output.txt");
				cout << "\nВывод бинарного файла:";
				PrintBin("Output.txt");
			}
		}
	} while (len == 0);
}