#include <iostream>
#define CATCH_CONFIG_RUNNER           // -- main() ��������� ����� --
#include "catch_amalgamated.hpp"

int main(int argc, char* argv[] ) {
    setlocale(LC_ALL, "RUS");
    std::cout << "��������� �����-21/2\n������� 13\n\n\n";
//    (void)&Catch::leakDetector;

    int result = Catch::Session().run( argc, argv );        // -- ���� ������� Catch --
    system("pause");

    return 0;
}
