#include <iostream>
#include <math.h>

using namespace std;

long double f(double x, double eps)
{
	int n = 0; 
	long double sum = eps+1, sum1 = 0, num = 0;

	for (n = 0; fabsl(sum - sum1) > eps; n++)
	{
		sum = sum1;
		num = pow(x, 4 * n + 1) / (4 * n + 1);
		sum1 += num;
		cout << n << ")\n����� = " << sum1 << "\n�������� = " << fabsl(sum - sum1) << "\n\n";
	}
	return sum1;
}

void ___main()
{
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 9\n���������� ������� � �������������� ��� ���������� � ��������� ���\n";
	double eps;
	cout << "\nS = x^(4n+1)/(4n+1)";
	do
	{
		cout << "\n\n����� �������� �� 0 �� 1 = ";
		cin >> eps;
	} while (eps < 0 || eps > 1);
	double x;
	cout << "\n\n����� � = ";
	cin >> x;
	cout << "\n\ny = " << f(x, eps);
}