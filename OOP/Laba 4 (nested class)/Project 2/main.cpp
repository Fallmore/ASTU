#include <iostream>
#include "ModuloTest.h"
#include "TimeTest.h"

int main()
{
    setlocale(LC_ALL, "RUS");
	cout << "��������� �����-21/2\n������� 10\n\n\n";
	ModuloTest testM;
	testM.run();
    testM.report();
    TimeTest testT;
    testT.run();
    testT.report();
}
