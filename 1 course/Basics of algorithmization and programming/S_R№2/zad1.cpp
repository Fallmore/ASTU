#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

const int K = 11;
long double Asn[K];
long double Ase[K];
long double As[K];

void ab(double& a, double& b) //Ввод диапазона
{
	cout << "\n\nВведи интервал [a;b] = ";
	cin >> a >> b;
	if (a > b)
	{
		cout << "\n\nа не может быть больше b";
		ab(a, b);
	}

}

void Nin(double& n) //Ввод количества слагаемых
{
	cout << "\n\nВведи количество слагаемых = ";
	cin >> n;
	if (n < 1)
	{
		cout << "\n\nКоличество не может быть таким";
		Nin(n);
	}
}

void EPS(double& eps) //Ввод точности
{
	cout << "\n\nВведи точность, положительную и близкую к нулю = ";
	cin >> eps;
	if (eps <= 0 || eps >= 1)
	{
		cout << "\n\nНеправильная точность";
		EPS(eps);
	}
}

long long fact(long long n) //Факториал
{
	long long a = 1;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i < n + 1; i++)
		{
			a *= i;
		}
		return a;
	}
}

long double fx(double x, long long n) //Формула степенного ряда функции
{
	long double s = cos(x * n) / fact(n);
	return s;
}

long double Sn(double x, double a, double b, double n) //Ф-ция от количества слагаемых
{
	double h = (b - a) / 10; //Шаг разбиения
	long double sum = 0, SUM = 0;
	int k = 0;
	while (x < b)
	{
		for (int i = 0; i < n+1; i++)
		{
			sum += fx(x, i); //Сумма степенного ряда определённого х
		}
		Asn[k] = sum; //Заполнение массива для вывода
		SUM += sum; //Общая сумма
		sum = 0;
		k++;
		x += h;
	}
	return SUM;
}

long double Se(double x, double a, double b, double eps) //Ф-ция от точности
{
	double h = (b - a) / 10; //Шаг разбиения
	long double sum1 = 0, sum = 0, SUM = 0, n = 0;
	int k = 0;
	while (x < b)
	{
		do
		{
			sum = sum1;
			sum1 += fx(x, n); //Сумма степенного ряда определённого х
			n++;
		} while (fabsl(sum - sum1) > eps);
		Ase[k] = sum1; //Заполнение массива для вывода
		SUM += sum1; //Общая сумма
		sum1 = 0;
		n = 0;
		k++;
		x += h;
	}
	return SUM;
}

long double S(double x, double a, double b) //Проверка
{
	double h = (b - a) / 10; //Шаг разбиения
	long double sum = 0, n = 1, s = 0;
	int k = 0;
	while (x < b)
	{
		s = exp(cos(x)) * cos(sin(x)); //Сумма степенного ряда определённого х
		As[k] = s; //Заполнение массива для вывода
		sum += s; //Общая сумма
		k++;
		x += h;
	}
	return sum;
}

void out(double x, double a, double b , long double x1, long double x2, long double x3) //Вывод
{
	double h = (b - a) / 10; //шаг разбиения
	int n = 1, k = 0;
	cout << "| " << setw(6) << "N n/n" << setw(6) << "|" << setw(6) << "x" << setw(5) << "|" << setw(6) << "Sn" << setw(10) << "|" << setw(6) << "Se" << setw(10) << "|" << setw(6) << "S" << setw(7) << "|\n";
	cout << "---------------------------------------------------------------------" << endl;
	while (n != 12)
	{
		cout  << "| " << setw(6) << n << setw(6) << "|" << setw(6) << x << setw(6) <<  "| " << setw(8) << Asn[k] << setw(8) << "| " << setw(8) << Ase[k] << setw(8) << "| " << setw(8)  << As[k] << setw(4) << "|\n";
		cout << "---------------------------------------------------------------------" << endl;
		k++;
		x += h;
		n++;
	}
	cout  << "| " << setw(6) << "Сумма" << setw(6) << "|" << setw(5) << "" << setw(6) << "|" << setw(8) << x1 << setw(8) << "|" << setw(8) << x2 << setw(8) << "|" << setw(8) <<  x3 << setw(5) << "|\n";
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 4\nТабулирование функции\n";
	double a, b;
	ab(a, b);
	double x = a;
	double N;
	Nin(N);
	long double x1, x2, x3;
	x1 = Sn(x, a, b, N);
	double eps;
	EPS(eps);
	x2 = Se(x, a, b, eps);
	x3 = S(x, a, b);
	out(x, a, b, x1, x2, x3);
}