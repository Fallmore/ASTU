#include <iostream>
#include "ModuloTest.h"
#include "TimeTest.h"

int main()
{
    setlocale(LC_ALL, "RUS");
    system("chcp 1251");
	cout << "��������� �����-21/2\n������� 10\n\n\n";
	ModuloTest testM;
	testM.run();
    testM.report();
    TimeTest testT;
    testT.run();
    testT.report();
}
