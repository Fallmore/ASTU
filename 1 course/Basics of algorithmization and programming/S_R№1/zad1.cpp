#include <iostream>
#include <math.h>

using namespace std;

long double f1(long double x)
{
	return 1 + pow(x, 2);
}

long double f2(long double x)
{
	return 1/x + pow(x, 2);
}

long double f3(long double x)
{
	return sqrt(x) - pow(x, 2);
}

long double f4(long double x)
{
	return 5 * exp(-x);
}

void _main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 9\nВычисление значения неэлементарной функции";
	long double x, y = 0;
	int choice;
	cout << "\n\nПри x > 25   у = 1 + х^2\nПри 8 < x <= 25   у = 1/x + х^2\nПри 2 < x <= 8   у = x^(1/2) - х^2\nПри x < 2   у = 5 * e^(-x)\n\n";
	cout << "Введи х = ";
	cin >> x;
	cout << "Выбери способ: \n1.Полное ветвление\n2.Краткое ветвление\n3.Условная операция\n";
	cin >> choice;
	while (choice < 1 || choice > 4)
	{
		cout << "Выбери способ: \n1.Полное ветвление\n2.Краткое ветвление\n3.Условная операция\n";
		cin >> choice;
	}
	switch (choice)
	{
	case 1: 
		if (x > 25)
		{
			cout << "\ny = " << f1(x);
		}
		else if (x > 8 && x <= 25)
		{
			cout << "\ny = " << f2(x);
		}
		else if (x > 2 && x <= 8)
		{
			cout << "\ny = " << f3(x);
		}
		else if (x < 2)
		{
			cout << "\ny = " << f4(x);
		}
		break;
	case 2:
		if (x > 25)
		{
			cout << "\ny = " << f1(x);
		}
		if (x > 8 && x <= 25)
		{
			cout << "\ny = " << f2(x);
		}
		if (x > 2 && x <= 8)
		{
			cout << "\ny = " << f3(x);
		}
		if (x < 2)
		{
			cout << "\ny = " << f4(x);
		}
		break;
	case 3: (x > 25) ? y = f1(x)
		: ((x > 8 && x <= 25) ? y = f2(x)
			: ((x > 2 && x <= 8) ? y = f3(x) : y = f4(x)));
		cout << "\ny = " << y;
		break;
	}
}