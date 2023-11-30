#include <iostream>
#include <string>

using namespace std;

struct drob
{
	long long chislitel = 0;
	long long znamenatel = 0;

public:
	string tir;
	long long nod(drob A) //наибольший общий делитель
	{
		long long a, b;
		a = A.chislitel; b = A.znamenatel;

		while (a && b)
			if (a > b) a %= b;
			else b %= a;
		return a + b;
	}

	void sokr_drob(drob& C) //сокращение дроби
	{
		long long a, b;
		a = C.chislitel; b = C.znamenatel;

		long long del = nod(C);
		if (a != 0 || b != 0)
		{
			while (nod(C) != 1)
			{
				C.znamenatel /= del;
				C.chislitel /= del;
			}
		}
	}

	void sum_drob(drob A, drob B, drob& C) //сумма двух дробей
	{
		long long a, b, a1, b1;
		a = A.chislitel; b = A.znamenatel;
		a1 = B.chislitel; b1 = B.znamenatel;
		cout << "\n\n\n" << "a = " << a << "\n" << "b = " << b << "\n" << "a1 = " << a1 << "\n" << "b1 = " << b1;
		if (b == 0 || a == 0) // a/0 + a1/b1 = a1/b1 ; 0/b + a1/b1 = a1/b1
		{
			C.znamenatel = b1;
			C.chislitel = a1;
		}
		else if (b1 == 0 || a1 == 0) // a/b + a1/0 = a/b ; 0/b + 0/b1 = a/b
		{
			C.znamenatel = b;
			C.chislitel = a;
		}
		else if (b1 == 0 && a == 0) // 0/b + a1/0 = 0/0
		{
			C.znamenatel = 0;
			C.chislitel = 0;
		}
		else if (b == 0 && a1 == 0) // a/0 + 0/b1 = 0/0
		{
			C.znamenatel = 0;
			C.chislitel = 0;
		}
		else
		{
			drob D; D.chislitel = b; D.znamenatel = b1;
			C.znamenatel = (b * b1) / nod(D); //наименьший общий знаменатель

			A.chislitel *= C.znamenatel / b;
			B.chislitel *= C.znamenatel / b1;
			C.chislitel = A.chislitel + B.chislitel; //сумма числителей
		}
	}

	void tire(drob C, string& tir) //сколько цифр, столько чёрточек
	{
		long long sum = 0, chislo, a, b;
		a = C.chislitel; b = C.znamenatel;

		if (a != 0 && b != 0)
		{
			if (a >= b)
			{
				chislo = a;
				while (chislo >= 1)
				{
					chislo /= 10;
					tir.insert(0, "-");
				}
			}
			else if (b >= a)
			{
				chislo = b;
				while (chislo >= 1)
				{
					chislo /= 10;
					tir.insert(0, "-");
				}
			}
		}
		else
		{
			tir.insert(0, "-");
		}

	}

	void ch_p(drob A, drob B, drob C, int n) //числовая последовательность
	{
		long long sum1 = 0, SUM1 = 0, noz = 0, sum_ch = 0, x = n - n + 1;
		long long signum = 1;
		string tir = "";
		while (x < n + 1)
		{
			if (x % 2 == 0) signum = 1;
			else signum = -1;

			B.chislitel = (x - 1) * signum;
			B.znamenatel = x * (x + 1);
			if (x % 2 == 1)
			{
				if (x == 1)
				{
					B.znamenatel;
				}
				sum_drob(A, B, C);
				sokr_drob(C);
				A.chislitel = C.chislitel;
				A.znamenatel = C.znamenatel;

				if (sum1 == 0) noz = 0;

				tir = "";
				tire(C, tir);
				cout << "\n\n" << x << ") Сумма двух подряд дробей: " << "\n             " << C.chislitel << "\n             " << tir << "\n             " << C.znamenatel;
				x++;
			}
			else
			{
				sum_drob(C, B, C);
				x += 1;
				sokr_drob(C);
				A.chislitel = C.chislitel;
				A.znamenatel = C.znamenatel;

				if (sum1 == 0) noz = 0;

				tir = "";
				tire(C, tir);
				cout << "\n\n" << x - 1 << ") Сумма двух подряд дробей: " << "\n             " << C.chislitel << "\n             " << tir << "\n             " << C.znamenatel;
			}
		}
		tir = "";
		sokr_drob(A);
		tire(A, tir);
		cout << "\n\nСумма последовательности = " << "\n             " << A.chislitel << "\n             " << tir << "\n             " << A.znamenatel << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}

	void ch_p_a(drob A, int n) //числовая последовательность
	{
		long long noz = 0, sum_ch = 0, x = n - n + 1;
		long long a_n = 1, b_n = 1, sum1 = 0, SUM1 = 0;
		long long a = 1;
		string tir = "";
		while (x < n + 1)
		{

			A.chislitel = 1;
			A.znamenatel = x;

			tir = "";
			tire(A, tir);
			cout << "\n\n" << x << "-й элемент: " << "\n             " << A.chislitel << "\n             " << tir << "\n             " << A.znamenatel;
			x++;

		}
	}

};






void in(string num, int& n) // правильный ли номер
{
	int ch;
	do
	{
		ch = 0;
		cin >> num;
		if (!num.empty())
		{
			for (int i = 0; i < num.length(); i++)
			{
				if (num[i] > '9' || num[i] < '0')
				{
					cout << "\nЭто не номер" << "\nВведи любой положительный номер последовательности: ";
					ch++;
				}
			}
			n = atoi(num.c_str());
			if (n < 1)
			{
				cout << "\nНекорректный номер" << "\nВведи любой положительный номер последовательности: ";
			}
			else
			{
				cout << n << "\n\n\n\n";
			}
		}
		else ch++;
	} while (n < 1 || ch != 0);

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
	long long del = nod(a, b);
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
	long long sum = 0, chislo;
	if (a != 0 && b != 0)
	{
		if (a >= b)
		{
			chislo = a;
			while (chislo >= 1)
			{
				chislo /= 10;
				tir.insert(0, "-");
			}
		}
		else if (b >= a)
		{
			chislo = b;
			while (chislo >= 1)
			{
				chislo /= 10;
				tir.insert(0, "-");
			}
		}
	}
	else
	{
		tir.insert(0, "-");
	}

}

void ch_p(int n) //числовая последовательность
{
	long long sum1 = 0, SUM1 = 0, noz = 0, sum_ch = 0, x = n - n + 1;
	long long a, b, signum = 1;
	string tir = "";
	while (x < n + 1)
	{
		if (x % 2 == 0) signum = 1;
		else signum = -1;

		a = (x - 1) * signum;
		b = x * (x + 1);

		if (x % 2 == 1)
		{
			if (x == 1)
			{
				b = 0;
			}
			sum_drob(sum1, SUM1, a, b, noz, sum_ch);
			sokr_drob(sum_ch, noz);
			sum1 = sum_ch;
			SUM1 = noz;

			if (sum1 == 0) noz = 0;

			tir = "";
			tire(sum_ch, noz, tir);
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

			if (sum1 == 0) noz = 0;

			tir = "";
			tire(sum_ch, noz, tir);
			cout << "\n\n" << x - 1 << ") Сумма двух подряд дробей: " << "\n             " << sum_ch << "\n             " << tir << "\n             " << noz;
		}
	}
	tir = "";
	sokr_drob(sum1, SUM1);
	tire(sum1, SUM1, tir);
	cout << "\n\nСумма последовательности = " << "\n             " << sum1 << "\n             " << tir << "\n             " << SUM1 << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void ch_p_a(int n) //числовая последовательность
{
	long long noz = 0, sum_ch = 0, x = n - n + 1;
	long long a_n = 1, b_n = 1, sum1 = 0, SUM1 = 0;
	long long a = 1;
	string tir = "";
	while (x < n + 1)
	{

		a_n = 1;
		b_n = x;

		tir = "";
		tire(a_n, b_n, tir);
		cout << "\n\n" << x << "-й элемент: " << "\n             " << a_n << "\n             " << tir << "\n             " << b_n;
		x++;

	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\nФункции. Передача параметра по ссылке\n\n";

	int n = 0;
	string num;

	while (n != 1488)
	{
		cout << "\nВведи любой положительный номер последовательности: ";
		in(num, n);
		if (n != 1488) ch_p(n);
		else ch_p_a(n);
	}







	drob A, B, C, D;
	n = 0;
	while (n != 1488)
	{
		cout << "\nВведи любой положительный номер последовательности: ";
		in(num, n);
		if (n != 1488)
		{
			D.ch_p(A, B, C, n);
		}
		else D.ch_p_a(A, n);
	}
}