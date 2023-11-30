#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void Eps(double& eps) //Ввод точности
{
	cout << "\n\nВведи точность, положительную и близкую к нулю = ";
	cin >> eps;
	if (eps <= 0 || eps >= 1)
	{
		cout << "\n\nНеправильная точность";
		Eps(eps);
	}
}

int Piw(int a, int n) //Типа возведение в степень
{
	for (int i = 0; i <= n; i++) a *= a;
	return a;
}

long double An(int n, double x) //Формула члена ряда
{
	long double S = Piw(-1,n)*(n/(n+1));
	return 1;
}

void _main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 4\nФункция для вычисления приближённой суммы с заданной точностью\n";
	double x;
	cout << "Введи х = ";
	cin >> x;
	double eps;
	Eps(eps);
	int n = 0;

}