#include <iostream>
#include <math.h>

using namespace std;

void __main()
{
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 9\n�������� ����� �� 0 �� 4 �� ���������� � �� ������� ������\n";
	int a;
	cout << "\n����� ����� �� 0 �� 4 = ";
	cin >> a;
	switch (a)
	{
	case 0: cout << "\n0 - zero, ����\n";
		break;
	case 1: cout << "\n1 - one, ����\n";
		break;
	case 2: cout << "\n2 - two, ���\n";
		break;
	case 3: cout << "\n3 - three, ���\n";
		break;
	case 4: cout << "\n4 - four, ������\n";
		break;
	default:
		cout << "\n�� �� �����\n";
		break;
	}
}