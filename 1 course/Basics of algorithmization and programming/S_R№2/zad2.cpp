#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void Eps(double& eps) //���� ��������
{
	cout << "\n\n����� ��������, ������������� � ������� � ���� = ";
	cin >> eps;
	if (eps <= 0 || eps >= 1)
	{
		cout << "\n\n������������ ��������";
		Eps(eps);
	}
}

int Piw(int a, int n) //���� ���������� � �������
{
	for (int i = 0; i <= n; i++) a *= a;
	return a;
}

long double An(int n, double x) //������� ����� ����
{
	long double S = Piw(-1,n)*(n/(n+1));
	return 1;
}

void _main()
{
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 4\n������� ��� ���������� ����������� ����� � �������� ���������\n";
	double x;
	cout << "����� � = ";
	cin >> x;
	double eps;
	Eps(eps);
	int n = 0;

}