#include <iostream>
#include <math.h>


using namespace std;

double del(long double a, long double sum)
{
	cout << "\n�������� = " << sqrt(a) << "\n����� = " << a  << "\n\n";
	for (long double del = sqrt(a); a > 1; sum += a)
	{
		a /= del;
		cout << "����� = " << a << "\n\n";
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 5\n��������� ����� �� ������������� ����������� ������� ������ ����� ����������� ���-�� ���\n\n";
	long double a;
	long double sum = 0;
	int i = 1;
	do
	{
		cout << "����� ����� ����� = ";
		cin >> a;
		if (a == 1488)
		{
			i = a;
		}
		else
		{
			cout << "����� = " << del(a, sum) << "\n\n";
		}
	} while (i != a);
}