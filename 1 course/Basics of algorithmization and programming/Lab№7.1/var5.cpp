#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

//bool CheckEnter(double a, double b)
//{
//	if (a < b)
//	{
//		return 1;
//	}
//	else if (a >= b) cout << "\nЛевая граница должна быть меньше правой\nВведи диапазон [a;b] - ";
//	else
//	{
//		throw exception("\nВведи числа!");
//	}
//	return 0;
//}
//
//void Enter(double& a, double& b)
//{
//	try
//	{
//		do
//		{
//			cin >> a >> b;
//		} while (!CheckEnter(a, b));
//	}
//	catch (exception err) { cout << err.what(); }
//}
//void Enter(int& N)
//{
//	cin >> N;
//	if (N < 1)
//	{
//		cout << "\nШагов должно быть больше 0\nВведи повторно - ";
//		Enter(N);
//	}
//}
//
//int main()
//{
//	setlocale(LC_ALL, "RUS");
//	cout << "Самодуров ДИНРБ-11/2\nВариант 5\n\n\n";
//
//	double a = 0, b = 0, e = 0, h = 0;
//	int N = 0;
//
//	cout << "Введи диапазон [a;b] - ";
//	Enter(a, b);
//	cout << "\n[" << a << ";" << b << "]\n";
//
//	cout << "\nВведи количество шагов N - ";
//	Enter(N);
//
//	h = (b - a) / N;
//	cout << "\nШаг h = " << h;
//
//
//
//}

const int K = 11;
long double Asn[K];
long double Ase[K];
long double As[K];

void ab(double& a, double& b) //Ввод диапазона
{
	cout << "\n\nВведи интервал [a;b] = ";
	cin.clear();
	cin >> a >> b;
	if (a >= b)
	{
		a = 0; b = 0;
		throw exception("\nа должно быть меньше b\n");
	}
	cout << "\n[" << a << ";" << b << "]\n";
}

void Nin(double& n) //Ввод количества слагаемых
{
	cout << "\n\nВведи количество слагаемых = ";
	cin >> n;
	if (n < 1)
	{
		throw exception("\nКоличество не может быть таким\n");
	}
}

void EPS(long double& eps) //Ввод точности
{
	cout << "\n\nВведи точность, положительную и близкую к нулю = ";
	cin >> eps;
	if (eps <= 0 || eps >= 1)
	{
		throw exception("\nНеправильная точность\n");
	}
}

unsigned long long accumulate(int n, unsigned long long& a, unsigned long long& c) //Факториал
{

	for (int i = 1; i < n + 1; i++)
	{
		if (i < (n + 1) / 2) a *= (2 * i - 1);
		else c *= 2 * i - 1;
	}
	cout << "\nn = " << n << "\naccumulate1 =	" << a << "	и	" << c;
	return a;
}
unsigned long long accum(int n, unsigned long long& a, unsigned long long& c) //Факториал
{
	int b = 2 * n + 1;

	for (int i = 1; i < n + 1; i++)
	{
		if (i < (n + 1) / 2) a *= 2 * i;
		else c *= 2 * i;
	}
	a *= b;
	cout << "\naccumulate2 =	" << a << "	и	" << c << "\n\n";
	return a;
}
long double piw(double x, int n)
{
	long double a = x, sign = x, b = 2 * n + 1;

	for (int i = 1; i < b + 1; i++)
	{
		a *= a;
	}
	if (sign < 0) a = -a;
	return a;
}

long double fx(double x) //Формула степенного ряда функции
{
	long double s = (pow(x, 3)) / (2 * 3);

	return s;
}

long double S(double x, double a, double b, double n) //Ф-ция от количества слагаемых
{
	double h = (b - a) / 10; //Шаг разбиения
	long double s, sum = 0, SUM = 0;
	int k = 0;
	while (x < b + h)
	{
		s = fx(x);
		sum += s + x;
		for (int i = 1; i < n; i++)
		{
			s = (s * pow(2 * i - 1, 2) * pow(x, 2)) / ((2 * i) * (2 * i + 1));
			sum += s; //Сумма степенного ряда определённого х
		}
		Asn[k] = sum; //Заполнение массива для вывода
		SUM += sum; //Общая сумма
		sum = 0;
		k++;
		if (k == 5) x = 0;
		else x += h;
	}
	return SUM;
}

long double S(double x, double a, double b, long double eps, int r) //Ф-ция от точности
{
	r = 0;
	double h = (b - a) / 10; //Шаг разбиения
	long double s, sum1 = 0, sum = 0, SUM = 0, n = 1, def = 1;
	int k = 0;
	while (x < b + h)
	{
		s = fx(x);
		sum1 += x + s;
		do
		{
			s = (s * pow(2 * n - 1, 2) * pow(x, 2)) / ((2 * n) * (2 * n + 1));
			cout << "\nn = " << n << "\ns = " << s << "\n\n";
			sum1 += s; //Сумма степенного ряда определённого х
			n++;
		} while (fabsl(s) > eps);
		Ase[k] = sum1; //Заполнение массива для вывода
		SUM += sum1; //Общая сумма
		sum1 = 0;
		n = 1;
		k++;
		if (k == 5) x = 0;
		else x += h;
	}
	if (fabsl(SUM) < 0.0000000001) SUM = 0;
	return SUM;
}

long double S(double x, double a, double b) //Проверка
{
	double h = (b - a) / 10; //Шаг разбиения
	long double sum = 0, n = 1, s = 0;
	int k = 0;
	while (x < b + h)
	{
		s = asin(x); //Сумма степенного ряда определённого х
		As[k] = s; //Заполнение массива для вывода
		sum += s; //Общая сумма
		k++;
		if (k == 5) x = 0;
		else x += h;
	}
	return sum;
}

void out(double x, double a, double b, long double x1, long double x2, long double x3) //Вывод
{
	double h = (b - a) / 10; //шаг разбиения
	int n = 1, k = 0;
	cout << "| " << setw(6) << "N n/n" << setw(6) << "|" << setw(6) << "x" << setw(5) << "|" << setw(6) << "Sn" << setw(10) << "|" << setw(6) << "Se" << setw(10) << "|" << setw(6) << "S" << setw(7) << "|\n";
	cout << "---------------------------------------------------------------------" << endl;
	while (n != 12)
	{
		cout << "| " << setw(6) << n << setw(6) << "|" << setw(6) << x << setw(6) << "| " << setw(8) << Asn[k] << setw(8) << "| " << setw(8) << Ase[k] << setw(8) << "| " << setw(8) << As[k] << setw(4) << "|\n";
		cout << "---------------------------------------------------------------------" << endl;
		k++;
		if (k == 5) x = 0;
		else x += h;
		n++;
	}
	cout << "| " << setw(6) << "Сумма" << setw(6) << "|" << setw(5) << "" << setw(6) << "|" << setw(8) << x1 << setw(8) << "|" << setw(8) << x2 << setw(8) << "|" << setw(8) << x3 << setw(5) << "|\n";
}

void Check(int x, int n)
{
	string num;
	num = to_string(n);
	int ch = 0;
	for (int i = 0; i < num.length(); i++)
	{

		if (num[i] == x + '0')
		{
			ch++;
			if (ch == 1) cout << "\nЦифра присутствует в числе N^2 в следующих позициях: ";
			cout << i + 1 << " ";
		}
	}
	if (ch == 0) cout << "\nЦифра отсутствует\n";
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\nФункции. Передача параметра по значению. Перегрузка\n";
	/*double a, b, N;
	long double x1, x2, x3, eps;

	try
	{
		ab(a, b);
		Nin(N);
		EPS(eps);

		double x = a;
		double h = (b - a) / 10;
		cout << "\nШаг h = " << h << endl;

		x1 = S(x, a, b, N);
		x2 = S(x, a, b, eps, r);
		x3 = S(x, a, b);

		out(x, a, b, x1, x2, x3);
	}
	catch (exception err)
	{
		cout << err.what();
	}
	system("pause");*/

	unsigned int N = 0;
	int X = 0, sum = 0;
	string num;

	cout << "\nВведи число N от 0 до 65535  - ";
	do
	{
		cin >> num;
		if (!num.empty())
		{
			for (int i = 0; i < num.length(); i++)
			{
				if (num[i] > '9' || num[i] < '0')
				{
					cout << "\nВведи число! - ";
				}
			}
			N = atoi(num.c_str());
		}
		else cout << "\nНу введи число блин - ";
		if (N < 1 || N > 65535) cout << "\nВведи число N от 0 до 65535!!!  - ";

	} while (N < 1 || N > 65535);

	N *= N;
	cout << "\nN^2 = " << N << "\n\nВведи цифру, чтобы выяснить, есть ли она в числе N^2 - ";

	do
	{
		cin >> num;
		if (!num.empty())
		{
			if (num[0] > '9' || num[0] < '0')
			{
				cout << "\nВведи цифру! - ";
			}
			X = atoi(num.c_str());
		}
		else cout << "\nНу введи цифру блин - ";
		if (num.length() > 1 || num.length() < 1) cout << "\nВведи цифру, а не число!  - ";

	} while (num.length() > 1 || num.length() < 1 || num[0] > '9' || num[0] < '0');

	Check(X, N);
}