#include "Longtype.h"
#include "LongTest.h"

int main() {
    setlocale(LC_ALL, "RUS");
    cout << "��������� �����-21/2\n������� 13\n\n\n";
    LongTest test;               // -- ������ ��������� ������ --
    test.run();                     // -- ������ �������� ������� --
    test.report();                  // -- ����� ������ --
    system("pause");

    return 0;
}
