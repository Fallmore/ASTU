#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 5\n\n���������� �������� �������^";
	double a = 1.5;
	cout << "\n\n����������� ���������� = " << a;
	int xn = 1;
	cout << "\n��������� ����� = " << xn;
	double xk = 2.5;
	cout << "\n�������� ����� = " << xk;
	int N = 15;
	cout << "\n���������� ����� ����� ���������� = " << N;
	double h = (xk - xn) / N;
	cout << "\n��� ��������� = " << h;
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