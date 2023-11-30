#include <iostream>
#include <math.h>

using namespace std;

long double f1(long double x)
{
	return 1 + pow(x, 2);
}

long double f2(long double x)
{
	return 1/x + pow(x, 2);
}

long double f3(long double x)
{
	return sqrt(x) - pow(x, 2);
}

long double f4(long double x)
{
	return 5 * exp(-x);
}

void _main()
{
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 9\n���������� �������� �������������� �������";
	long double x, y = 0;
	int choice;
	cout << "\n\n��� x > 25   � = 1 + �^2\n��� 8 < x <= 25   � = 1/x + �^2\n��� 2 < x <= 8   � = x^(1/2) - �^2\n��� x < 2   � = 5 * e^(-x)\n\n";
	cout << "����� � = ";
	cin >> x;
	cout << "������ ������: \n1.������ ���������\n2.������� ���������\n3.�������� ��������\n";
	cin >> choice;
	while (choice < 1 || choice > 4)
	{
		cout << "������ ������: \n1.������ ���������\n2.������� ���������\n3.�������� ��������\n";
		cin >> choice;
	}
	switch (choice)
	{
	case 1: 
		if (x > 25)
		{
			cout << "\ny = " << f1(x);
		}
		else if (x > 8 && x <= 25)
		{
			cout << "\ny = " << f2(x);
		}
		else if (x > 2 && x <= 8)
		{
			cout << "\ny = " << f3(x);
		}
		else if (x < 2)
		{
			cout << "\ny = " << f4(x);
		}
		break;
	case 2:
		if (x > 25)
		{
			cout << "\ny = " << f1(x);
		}
		if (x > 8 && x <= 25)
		{
			cout << "\ny = " << f2(x);
		}
		if (x > 2 && x <= 8)
		{
			cout << "\ny = " << f3(x);
		}
		if (x < 2)
		{
			cout << "\ny = " << f4(x);
		}
		break;
	case 3: (x > 25) ? y = f1(x)
		: ((x > 8 && x <= 25) ? y = f2(x)
			: ((x > 2 && x <= 8) ? y = f3(x) : y = f4(x)));
		cout << "\ny = " << y;
		break;
	}
}