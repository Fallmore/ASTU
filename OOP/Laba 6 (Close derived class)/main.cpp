#define CATCH_CONFIG_RUNNER

#include <iostream>
#include "ModuloTest.h"
#include "TimeTest.h"

using namespace std;

int main(int argc, char* argv[] ) {
    setlocale(0, "");
    cout << "Самодуров ДИНРБ-21/2\nЛабораторная №6 Вариант 10\n\n\n";
    int result = Catch::Session().run( argc, argv );	// -- пуск системы Catch --
    system("pause");			// -- для просмотра результатов --
    return result;
}
