#include <iostream>
#include "ModuloTest.h"
#include "TimeTest.h"

int main()
{
    setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-21/2\nВариант 10\n\n\n";
	ModuloTest testM;
	testM.run();
    testM.report();
    TimeTest testT;
    testT.run();
    testT.report();
}
