#include <iostream>
#include <math.h>

using namespace std;

void __main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 9\nНазвание чисел от 0 до 4 на английском и на русском языках\n";
	int a;
	cout << "\nВведи число от 0 до 4 = ";
	cin >> a;
	switch (a)
	{
	case 0: cout << "\n0 - zero, ноль\n";
		break;
	case 1: cout << "\n1 - one, один\n";
		break;
	case 2: cout << "\n2 - two, два\n";
		break;
	case 3: cout << "\n3 - three, три\n";
		break;
	case 4: cout << "\n4 - four, четыре\n";
		break;
	default:
		cout << "\nНе то число\n";
		break;
	}
}