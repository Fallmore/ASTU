#include <iostream>
#define CATCH_CONFIG_RUNNER           // -- main() создавать нужно --
#include "catch_amalgamated.hpp"

int main(int argc, char* argv[] ) {
    setlocale(LC_ALL, "RUS");
    std::cout << "Самодуров ДИНРБ-21/2\nВариант 13\n\n\n";
//    (void)&Catch::leakDetector;

    int result = Catch::Session().run( argc, argv );        // -- пуск системы Catch --
    system("pause");

    return 0;
}
