#include <iostream>

using namespace std;

void in(int n) // правильный ли номер
{
	if (n<1)
	{
		cout << "\nНекорректный номер" << "\nВведи любой положительный номер последовательности: ";
		cin >> n;
		in(n);
	}
	else
	{
		cout << n;
	}
}

long long nod(long long a, long long b) //наибольший общий делитель
{
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

void sokr_drob(long long& a, long long& b) //сокращение дроби
{
	int del = nod(a, b);
	if (a != 0 || b != 0)
	{
		while (nod(a, b) != 1)
		{
			b /= del;
			a /= del;
		}
	}
}

void sum_drob(long long a, long long b, long long a1, long long b1, long long& noz, long long& sum_ch) //сумма двух дробей
{
	cout << "\n\n\n" << "a = " << a << "\n" << "b = " << b << "\n" << "a1 = " << a1 << "\n" << "b1 = " << b1;
	if (b == 0 || a == 0) // a/0 + a1/b1 = a1/b1 ; 0/b + a1/b1 = a1/b1
	{
		noz = b1;
		sum_ch = a1;
	}
	else if (b1 == 0 || a1 == 0) // a/b + a1/0 = a/b ; 0/b + 0/b1 = a/b
	{
		noz = b;
		sum_ch = a;
	}
	else if (b1 == 0 && a == 0) // 0/b + a1/0 = 0/0
	{
		noz = 0;
		sum_ch = 0;
	}
	else if (b == 0 && a1 == 0) // a/0 + 0/b1 = 0/0
	{
		noz = 0;
		sum_ch = 0;
	}
	else
	{
		noz = (b * b1) / nod(b, b1); //наименьший общий знаменатель
		a *= noz / b;
		a1 *= noz / b1;
		sum_ch = a + a1; //сумма числителей
	}
}

void tire(long long a, long long b, string& tir) //сколько цифр, столько чёрточек
{
	long long sum = 0,chislo;
	if (a >= b)
	{
		chislo = a;
		while (chislo > 1)
		{
			chislo /= 10;
			tir.insert(0, "-");
		}
	}
	else if (b >= a)
	{
		chislo = b;
		while (chislo > 1)
		{
			chislo /= 10;
			tir.insert(0, "-");
		}
	}
	else 
	{
		tir.insert(0, "-");
	}

}

void ch_p(int n) //числовая последовательность
{
	long long sum1=0, SUM1 = 0, noz = 0, sum_ch = 0, x = n - n + 1;
	long long a, b, a1,b1;
	string tir = "";
	while (x<n+1)
	{
		a = x - 1;
		b = x;
		a1 = x;
		b1 = x + 1;
		if (x%2==1)
		{
			if (x == 1)
			{
				b = 0;
			}
			sum_drob(sum1, SUM1, a, b, noz, sum_ch);
			sokr_drob(sum_ch, noz);
			tir = "";
			tire(sum_ch, noz, tir);
			sum1 = sum_ch;
			SUM1 = noz;
			cout << "\n\n" << x << ") Сумма двух подряд дробей: " << "\n             " << sum_ch << "\n             " << tir << "\n             " << noz;
			x++;
		}
		else
		{
			sum_drob(sum_ch, noz, a, b, noz, sum_ch);
			x += 1;
			sokr_drob(sum_ch, noz);
			sum1 = sum_ch;
			SUM1 = noz;
			tir = "";
			tire(sum_ch, noz, tir);
			cout << "\n\n" << x - 1 << ") Сумма двух подряд дробей: " << "\n             " << sum_ch << "\n             " << tir << "\n             " << noz;
		}
	}
	tir = "";
	sokr_drob(sum1, SUM1);
	tire(sum1, SUM1, tir);
	cout << "\n\nСумма последовательности = " << "\n             " << sum1 << "\n             " << tir << "\n             " << SUM1 << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\nВычисление последовательности по номеру.\n";
	int n=0;
	cout << "\nВведи любой положительный номер последовательности: ";
	while (n!=1488)
	{
		cin >> n;
		in(n);
		ch_p(n);
	}
}