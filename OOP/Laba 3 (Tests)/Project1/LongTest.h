#ifndef LONGTEST_H_INCLUDED
#define LONGTEST_H_INCLUDED

#include "Longtype.h"
#include "UnitTest.h"

using namespace UnitTest;         // -- чтобы не писать полные имена --
// -- в тестовых методах пишутся вызовы макроса check() --
class LongTest: public Test {
    // -- здесь можно определять объекты тестируемого класса --
    Long a; Long b; Long c;
    Long d; Long e; Long f;    // -- объекты, нужны всем --
    Long mas[6]; Long* dynMas = new Long[6];
  public:
      LongTest() : a(32313213l), b(static_cast<long>(INT32_MAX)), c(0l), d(b), e("234234234234234"), f("234234234234230") {
        mas[0] = 32313213l; mas[1] = static_cast<long>(INT32_MAX);
        mas[3] = mas[1]; mas[4] = e; mas[5] = f;
        dynMas[0] = 32313213l; dynMas[1] = static_cast<long>(INT32_MAX);
        dynMas[3] = dynMas[1]; dynMas[4] = e; dynMas[5] = f;
      } // -- инициализация объектов --
    // -- можно написать конструктор для инициализации обектов-полей --
    // - определение чистой виртуальной функции run() класса Test --
    void run() {                 // -- вызов тестовых методв --
        testCreate();			// -- тест конструкторов и присваивания --
        testArithmetic();	// -- тест арифметики --
        testCompare();		// -- тест сравнения --
        testCreateMas();			// -- тест конструкторов и присваивания --
        testArithmeticMas();	// -- тест арифметики --
        testCompareMas();		// -- тест сравнения --
        testCreateDynMas();			// -- тест конструкторов и присваивания --
        testArithmeticDynMas();	// -- тест арифметики --
        testCompareDynMas();		// -- тест сравнения --
        testExeption();		// -- тест исключений --
    }
    // -- тестовые методы --
    void testCreate() { 		// -- создание и присваивание --
        check(a == 32313213l);
        check(b == INT32_MAX);
        check(c == 0);
        c = b;          check(c == a);    // -- ошибка - должно быть b --
        check(d == b);
        check(e == f + 4);
        c = e;          check(c == f + 4);
        c = 0l;   // -- возвращение к начальному значению --
    }
    void testArithmetic() {     // -- тестирование сложения --
        // -- арифметические операции. Слева Long --
        check(e == f + 4);
        check(e - 4 == f);
        check(e * 2 == f * 2 + 8);
        check(e / 2 == f / 2 + 2);
        check((e + 1) % 2 == 1);
        d = 1234;        check(d == 1234);
        // -- арифметические операции. Справа Long --
        check(e == 4 + f);
        check(0 == 32313213 - a);
        check(2 * a == 64626427);       // -- ошибка - должно быть 64626426 --
        check(64626426 / a == 2);
        check(14 % a == 14);
        // -- арифметические операции. Оба Long --
        check(a + a == 64626426);
        check(0 == a - a);
        check(a * c == 0);
        check(a / a == 1);
        check(a % a == 0);
        d = f;        check(d == f);
        // -- арифметические операции. C присваиванием --
        c += f;             check(c == a);      // -- ошибка - должно быть f --
        c += 4;            check(c == e);
        c -= 4;             check(c == f);
        c -= f - 1;        check(c == 1);
        c *= 2;             check(c == 2);
        c *= a;             check(c == 64626426);
        c /= a;             check(c == 2);
        c /= 2;             check(c == 1);
        c %= 6;            check(c == 1);
        c %= a;            check(c == 1);
        ++c;                check(c == 2);
        c++;                check(c == 3);
        --c;                   check(c == 2);
        c--;                   check(c == 1);
        c = 0l;   // -- возвращение к начальному значению --
    }
    void testCompare() {  		// -- проверка сравнения --
        check(e < f == false);
        check(e > f == true);
        check(e <= f == false);
        check(e >= f == false);     // -- ошибка - должно быть true 0 --
        check(e <= f + 4 == true);
        check(e >= f + 4 == true);
        check(e != f == true);
        check(c < 1 == true);
        check(c > 1 == false);
        check(c >= 1 == false);
        check(c <= 1 == true);
        check(c != 1 == true);
        check(1 < c == false);
        check(1 > c == true);
        check(1 >= c == true);
        check(1 <= c == false);
        check(1 != c == true);
    }
    void testCreateMas() { 		// -- создание и присваивание --
        check(mas[0] == 32313213);
        check(mas[1] == INT32_MAX);
        check(mas[2] == 0);
        mas[2] = mas[1];        check(mas[2] == mas[0]);  // -- ошибка - должно быть mas[1] --
        check(mas[3] == mas[1]);
        check(mas[4] == mas[5] + 4);
        mas[2] = mas[4];         check(mas[2] == mas[5] + 4);
        mas[2] = 0l;   // -- возвращение к начальному значению --
    }
    void testArithmeticMas() {     // -- тестирование сложения --
        // -- арифметические операции. Слева Long --
        check(mas[4] == mas[5] + 4);
        check(mas[4] - 4 == mas[5]);
        check(mas[4] * 2 == mas[5] * 2 + 8);
        check(mas[4] / 2 == mas[5] / 2 + 2);
        check((mas[4] + 1) % 2 == 1);
        mas[3] = 1234; check(mas[3]== 1234);
        // -- арифметические операции. Справа Long --
        check(mas[4] == 4 + mas[5]);
        check(0 == 32313213 - mas[0]);
        check(2 * mas[0] == 64626427);       // -- ошибка - должно быть 64626426 --
        check(64626426 / mas[0] == 2);
        check(14 % mas[0] == 14);
        // -- арифметические операции. Оба Long --
        check(mas[0] + mas[0] == 64626426);
        check(0 == mas[0] - mas[0]);
        check(mas[0] * mas[2] == 0);
        check(mas[0] / mas[0] == 1);
        check(mas[0] % mas[0] == 0);
        mas[3] = mas[5]; check(mas[3]== mas[5]);
        // -- арифметические операции. C присваиванием --
        mas[2] += mas[5]; check(mas[2] == mas[0]);      // -- ошибка - должно быть mas[5] --
        mas[2] += 4; check(mas[2] == mas[4]);
        mas[2] -= 4; check(mas[2] == mas[5]);
        mas[2] -= mas[5] - 1; check(mas[2] == 1);
        mas[2] *= 2; check(mas[2] == 2);
        mas[2] *= mas[0]; check(mas[2] == 64626426);
        mas[2] /= mas[0]; check(mas[2] == 2);
        mas[2] /= 2; check(mas[2] == 1);
        mas[2] %= 6; check(mas[2] == 1);
        mas[2] %= mas[0]; check(mas[2] == 1);
        ++mas[2]; check(mas[2] == 2);
        mas[2]++; check(mas[2] == 3);
        --mas[2]; check(mas[2] == 2);
        mas[2]--; check(mas[2] == 1);
        mas[2] = 0l;   // -- возвращение к начальному значению --
    }
    void testCompareMas() {  		// -- проверка сравнения --
        check(mas[4] < mas[5] == false);
        check(mas[4] > mas[5] == true);
        check(mas[4] <= mas[5] == false);
        check(mas[4] >= mas[5] == true);
        check(mas[4] <= mas[5] + 4 == true);
        check(mas[4] >= mas[5] + 4 == false);
        check(mas[4] != mas[5] == true);
        check(mas[2] < 1 == true);
        check(mas[2] > 1 == false);
        check(mas[2] >= 1 == false);
        check(mas[2] <= 1 == true);
        check(mas[2] != 1 == true);
        check(1 < mas[2] == false);
        check(1 > mas[2] == true);
        check(1 >= mas[2] == true);
        check(1 <= mas[2] == false);
        check(1 != mas[2] == true);
    }
    void testCreateDynMas() { 		// -- создание и присваивание --
        check(dynMas[0] == 32313213);
        check(dynMas[1] == INT32_MAX);
        check(dynMas[2] == 0);
        dynMas[2] = dynMas[1];        check(dynMas[2] == dynMas[0]);  // -- ошибка - должно быть dynMas[1] --
        check(dynMas[3] == dynMas[1]);
        check(dynMas[4] == dynMas[5] + 4);
        dynMas[2] = dynMas[4];         check(dynMas[2] == dynMas[5] + 4);
        dynMas[2] = 0l;   // -- возвращение к начальному значению --
    }
    void testArithmeticDynMas() {     // -- тестирование сложения --
        // -- арифметические операции. Слева Long --
        check(dynMas[4] == dynMas[5] + 4);
        check(dynMas[4] - 4 == dynMas[5]);
        check(dynMas[4] * 2 == dynMas[5] * 2 + 8);
        check(dynMas[4] / 2 == dynMas[5] / 2 + 2);
        check((dynMas[4] + 1) % 2 == 1);
        dynMas[3] = 1234; check(dynMas[3]== 1234);
        // -- арифметические операции. Справа Long --
        check(dynMas[4] == 4 + dynMas[5]);
        check(0 == 32313213 - dynMas[0]);
        check(2 * dynMas[0] == 64626427);       // -- ошибка - должно быть 64626426 --
        check(64626426 / dynMas[0] == 2);
        check(14 % dynMas[0] == 14);
        // -- арифметические операции. Оба Long --
        check(dynMas[0] + dynMas[0] == 64626426);
        check(0 == dynMas[0] - dynMas[0]);
        check(dynMas[0] * dynMas[2] == 0);
        check(dynMas[0] / dynMas[0] == 1);
        check(dynMas[0] % dynMas[0] == 0);
        dynMas[3] = dynMas[5]; check(dynMas[3]== dynMas[5]);
        // -- арифметические операции. C присваиванием --
        dynMas[2] += dynMas[5]; check(dynMas[2] == dynMas[0]);      // -- ошибка - должно быть dynMas[5] --
        dynMas[2] += 4; check(dynMas[2] == dynMas[4]);
        dynMas[2] -= 4; check(dynMas[2] == dynMas[5]);
        dynMas[2] -= dynMas[5] - 1; check(dynMas[2] == 1);
        dynMas[2] *= 2; check(dynMas[2] == 2);
        dynMas[2] *= dynMas[0]; check(dynMas[2] == 64626426);
        dynMas[2] /= dynMas[0]; check(dynMas[2] == 2);
        dynMas[2] /= 2; check(dynMas[2] == 1);
        dynMas[2] %= 6; check(dynMas[2] == 1);
        dynMas[2] %= dynMas[0]; check(dynMas[2] == 1);
        ++dynMas[2]; check(dynMas[2] == 2);
        dynMas[2]++; check(dynMas[2] == 3);
        --dynMas[2]; check(dynMas[2] == 2);
        dynMas[2]--; check(dynMas[2] == 1);
        dynMas[2] = 0l;   // -- возвращение к начальному значению --
    }
    void testCompareDynMas() {  		// -- проверка сравнения --
        check(dynMas[4] < dynMas[5] == false);
        check(dynMas[4] > dynMas[5] == true);
        check(dynMas[4] <= dynMas[5] == false);
        check(dynMas[4] >= dynMas[5] == true);
        check(dynMas[4] <= dynMas[5] + 4 == true);
        check(dynMas[4] >= dynMas[5] + 4 == false);
        check(dynMas[4] != dynMas[5] == true);
        check(dynMas[2] < 1 == true);
        check(dynMas[2] > 1 == false);
        check(dynMas[2] >= 1 == false);
        check(dynMas[2] <= 1 == true);
        check(dynMas[2] != 1 == true);
        check(1 < dynMas[2] == false);
        check(1 > dynMas[2] == true);
        check(1 >= dynMas[2] == true);
        check(1 <= dynMas[2] == false);
        check(1 != dynMas[2] == true);
    }
    void testExeption() {
        try {                     // -- это работает правильно
            Long F('a');     // -- должен генерить исключение --
            fail();                 // -- проваленный тест по исключениям --
            error("Invalid Long undetected");     // -- без препроцессора не обойтись --
        } catch(Long::LongError &) {
            success();            // -- только для этого сделан метод --
        }
        return;
    };
};
#endif // LONGTEST_H_INCLUDED
