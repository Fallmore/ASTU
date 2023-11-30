#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\n\nВычисление значения функции^";
	double a = 1.5;
	cout << "\n\nнезивисимая переменная = " << a;
	int xn = 1;
	cout << "\nначальная точка = " << xn;
	double xk = 2.5;
	cout << "\nконечная точка = " << xk;
	int N = 15;
	cout << "\nколичество точек между значениями = " << N;
	double h = (xk - xn) / N;
	cout << "\nшаг разбиения = " << h;
	double x = xn;
	double y = 1 / (exp(a * x) + 2 * exp(a));
	cout << "\n\n         x        " << "|" << "           y";
	cout << "\n__________________________________________";
	do 
	{
		y = 1 / (exp(a * x) + 2 * exp(a));
		cout << "\n       " << setw(4) << x << "       |       " << y;
		x += h;
	} while (x < xk + 0.1);
}