#define CATCH_CONFIG_RUNNER

#include <iostream>
#include "PairTest.h"
#include "MoneyTest.h"

using namespace std;

int main(int argc, char* argv[] ) {
    setlocale(LC_ALL, "RUS");
    cout << "Самодуров ДИНРБ-21/2\nВариант 10\n\n\n";

    int result = Catch::Session().run( argc, argv );	// -- пуск системы Catch --
    system("pause");			// -- для просмотра результатов --
    return result;

}
