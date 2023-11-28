#include "Longtype.h"
#include "LongTest.h"

int main() {
    setlocale(LC_ALL, "RUS");
    cout << "Самодуров ДИНРБ-21/2\nВариант 13\n\n\n";
    LongTest test;               // -- объект тестового класса --
    test.run();                     // -- запуск тестовых методов --
    test.report();                  // -- вывод отчета --
    system("pause");

    return 0;
}
