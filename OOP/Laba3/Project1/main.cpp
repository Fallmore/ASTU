#include "Longtype.h"
#include "LongTest.h"

int main() {
    setlocale(LC_ALL, "RUS");
    cout << "Ñàìîäóðîâ ÄÈÍÐÁ-21/2\nÂàðèàíò 13\n\n\n";
    LongTest test;               // -- îáúåêò òåñòîâîãî êëàññà --
    test.run();                     // -- çàïóñê òåñòîâûõ ìåòîäîâ --
    test.report();                  // -- âûâîä îò÷åòà --
    system("pause");

    return 0;
}
