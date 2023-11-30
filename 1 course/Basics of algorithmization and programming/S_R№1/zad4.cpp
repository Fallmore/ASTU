#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double delta_x = 0.4, delta_y = 0.4;


void f(double x, double y, double a, double b, double c, double d) //—ама функци€
{

	x = a;
	while (x <= b) //¬ывод первой строки X на консоль
	{
		cout << setw(6) << x << " ";
		x += delta_x;
		if (fabs(x) < 0.01) //язык считает не 0, а что-то маленькое, поэтому просто замен€ю на ноль это число
		{
			x = 0;
		}
	}
	x = a;
	y = c;
	long double Z = 0;
	while (y <= d) //ѕеребирание значений y
	{
		cout << "\n--------------------------------------------------------------------------------------";
		if (fabs(y) < 0.01) //язык считает не 0, а что-то маленькое, поэтому просто замен€ю на ноль это число
		{
			y = 0;
			cout << "\n" << setw(4) << y << "     |";
		}
		else
		{
			cout << "\n" << setw(4) << y << "     |";
		}
		while (x <= b) //ѕеребирание значений x
		{
			if (fabs(x) < 0.01) //язык считает не 0, а что-то маленькое, поэтому просто замен€ю на ноль это число
			{
				x = 0;
			}
			if (pow(x, 2) + pow(y, 2) >= 4 || x == 0  || y == 0) //ќƒ«
			{
				cout << setw(6) << "*" << " ";
			}
			else //«начение ф-ции
			{
				Z = sqrt(4 - pow(x, 2) - pow(y, 2)) / (x * y);
				cout << setw(6) << setprecision(2) << Z << " ";
			}
			x += delta_x;
		}
		x = a;
		y += delta_y;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "—амодуров ƒ»Ќ–Ѕ-11/2\n¬ариант 9\n“абулирование функции\n";
	double a, b, c, d;
	do
	{
		cout << "\n¬веди отрезок [a,b] - ";
		cin >> a >> b;
	} while (a >= b);
	do
	{
		cout << "\n¬веди отрезок [c,d] - ";
		cin >> c >> d;
	} while (c > d);	
	double x = 0, y = 0;
	cout << "\n\n-2 <= x <= 2;     -2 <= y <= 2;    Z(x,y) = sqrt(4-x*x-y*y)/(x*y)"; //¬ывод дано

	cout << "\n\n  \\    X |\n"; //ѕросто вывод заголовка на консоль
	cout << "    \\    |\n";
	cout << "  Y   \\  |";
	f(x, y,a,b,c,d);
	cout << "\n--------------------------------------------------------------------------------------\n\n";
}