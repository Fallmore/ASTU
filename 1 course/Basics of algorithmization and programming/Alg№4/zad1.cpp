#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;



void a_b(long double& a, long double& b) //проверка отрезка
{
	while (a > b)
	{
		cout << "\nа не может быть меньше b\n";
		cout << "¬веди границы отрезка [a,b]\n" << "¬веди a = ";
		cin >> a;
		cout << "¬веди b = ";
		cin >> b;
		a_b(a, b);
	}
}

 long double f(long double a) //функци€
{
	 long double y = powl(a, 5) + powl(a, 4) + powl(a, 3) + powl(a, 2) + a - 2;
	return y;
}

 long double hord(long double a, long double b, long double eps, long double& c) //пересечение функцией оси у
{
/*	c = a - f(a) * ((b - a) / (f(b) - f(a)));            
	cout << "\n c = " << c;
	if (fabsl(f(c)) <= eps)
	{
		return c;
	}
	else if (fabsl(f(c)) > eps)
	{
		if (f(c) > 0)
		{
			b = c;
			return hord (a, b, eps, c);
		}
		if (f(c) < 0)
		{
			a = c;
			return hord(a, b, eps, c);3
		}
	} */
	for (c = a - f(a) * ((b - a) / (f(b) - f(a))); fabsl(f(c)) > eps; hord(a, b, eps, c))
	{
		cout << "\n c = " << c;
		a = c;
	}
	return c;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "—амодуров ƒ»Ќ–Ѕ-11/2\n¬ариант 5\nќписание рекурсивной функции на отрезке\n\ny = x^5 + x^4 + x^3 + x^2 + x - 2\n\nf(x) - непрерывна€ и монотонна€ на отрезке [a,b]!!\nf(a)*f(b) < 0!!!\n";
	long double a, b, eps;
	cout << "\n¬веди границы отрезка [a,b]\n" << "¬веди a = ";
	cin >> a;
	cout << " ¬веди b = ";
	cin >> b;
	long double c = 0;
	a_b(a, b);
	cout << a << "\n" << b << "\n¬веди желаемую тобой точность больше нул€ = ";
	cin >> eps; 
	
	cout << "\n\nкорень уравнени€ = " << setprecision(100) << hord(a, b, eps, c); 
}
