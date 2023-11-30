#include <iostream>
#include <math.h>


using namespace std;

double del(long double a, long double sum)
{
	cout << "\nДелитель = " << sqrt(a) << "\nЧисло = " << a  << "\n\n";
	for (long double del = sqrt(a); a > 1; sum += a)
	{
		a /= del;
		cout << "Число = " << a << "\n\n";
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\nПолучение суммы из промежуточных результатов деления одного числа определённое кол-во раз\n\n";
	long double a;
	long double sum = 0;
	int i = 1;
	do
	{
		cout << "Введи любое число = ";
		cin >> a;
		if (a == 1488)
		{
			i = a;
		}
		else
		{
			cout << "Сумма = " << del(a, sum) << "\n\n";
		}
	} while (i != a);
}