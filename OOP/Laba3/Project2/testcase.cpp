#include "catch_amalgamated.hpp"
#include "Longtype.h"

// -- непосредственно тесты -
TEST_CASE("Тесты LongTest в Catch2","[LongTest]")
{
    Long a = 32313213l; Long b = static_cast<long>(INT32_MAX); Long c;
    Long d(b); Long e(("234234234234234")); Long f(("234234234234230"));
    Long mas[6];
    mas[0] = 32313213l; mas[1] = static_cast<long>(INT32_MAX);
    mas[3] = mas[1]; mas[4] = e; mas[5] = f;
    Long* dynMas = new Long[6];
    dynMas[0] = 32313213l; dynMas[1] = static_cast<long>(INT32_MAX);
    dynMas[3] = dynMas[1]; dynMas[4] = e; dynMas[5] = f;   // -- объекты, нужны всем --
    SECTION("Тест создание и присваивание объектов") // -- создание и присваивание --
    {
        CHECK(a == 32313213l);
        CHECK(b == INT32_MAX);
        CHECK(c == 0);
        c = b;          CHECK(c == a);    // -- ошибка - должно быть b --
        CHECK(d == b);
        CHECK(e == f + 4);
        c = e;          CHECK(c == f + 4);
        c = 0l;   // -- возвращение к начальному значению --
    }
    SECTION("Тест сложения объектов")              // -- тестирование сложения --
    {
        // -- арифметические операции. Слева Long --
        CHECK(e == f + 4);
        CHECK(e - 4 == f);
        CHECK(e * 2 == f * 2 + 8);
        CHECK(e / 2 == f / 2 + 2);
        CHECK((e + 1) % 2 == 1);
        d = 1234;        CHECK(d == 1234);
        // -- арифметические операции. Справа Long --
        CHECK(e == 4 + f);
        CHECK(0 == 32313213 - a);
        CHECK(2 * a == 64626427);       // -- ошибка - должно быть 64626426 --
        CHECK(64626426 / a == 2);
        CHECK(14 % a == 14);
        // -- арифметические операции. Оба Long --
        CHECK(a + a == 64626426);
        CHECK(0 == a - a);
        CHECK(a * c == 0);
        CHECK(a / a == 1);
        CHECK(a % a == 0);
        d = f;        CHECK(d == f);
        // -- арифметические операции. C присваиванием --
        c += f;             CHECK(c == a);      // -- ошибка - должно быть f --
        c += 4;            CHECK(c == e);
        c -= 4;             CHECK(c == f);
        c -= f - 1;        CHECK(c == 1);
        c *= 2;             CHECK(c == 2);
        c *= a;             CHECK(c == 64626426);
        c /= a;             CHECK(c == 2);
        c /= 2;             CHECK(c == 1);
        c %= 6;            CHECK(c == 1);
        c %= a;            CHECK(c == 1);
        ++c;                CHECK(c == 2);
        c++;                CHECK(c == 3);
        --c;                   CHECK(c == 2);
        c--;                   CHECK(c == 1);
        c = 0l;   // -- возвращение к начальному значению --
    }
    SECTION("Тест сравнения объектов")          // -- проверка сравнения --
    {
        CHECK(e > f);
        CHECK(e <= f);       // -- ошибка --
        CHECK(e >= f);
        CHECK(e <= f + 4);
        CHECK(e != f);
        CHECK(c < 1);
        CHECK(c <= 1);
        CHECK(c != 1);
        CHECK(1 > c);
        CHECK(1 >= c);
        CHECK(1 != c);
    }
    SECTION("Тест создание и присваивание объектов массива") // -- создание и присваивание --
    {
        CHECK(mas[0] == 32313213);
        CHECK(mas[1] == INT32_MAX);
        CHECK(mas[2] == 0);
        mas[2] = mas[1];        CHECK(mas[2] == mas[0]);  // -- ошибка - должно быть mas[1] --
        CHECK(mas[3] == mas[1]);
        CHECK(mas[4] == mas[5] + 4);
        mas[2] = mas[4];         CHECK(mas[2] == mas[5] + 4);
        mas[2] = 0l;   // -- возвращение к начальному значению --
    }
    SECTION("Тест сложения объектов массива")              // -- тестирование сложения --
    {
        // -- арифметические операции. Слева Long --
        CHECK(mas[4] == mas[5] + 4);
        CHECK(mas[4] - 4 == mas[5]);
        CHECK(mas[4] * 2 == mas[5] * 2 + 8);
        CHECK(mas[4] / 2 == mas[5] / 2 + 2);
        CHECK((mas[4] + 1) % 2 == 1);
        mas[3] = 1234; CHECK(mas[3]== 1234);
        // -- арифметические операции. Справа Long --
        CHECK(mas[4] == 4 + mas[5]);
        CHECK(0 == 32313213 - mas[0]);
        CHECK(2 * mas[0] == 64626427);       // -- ошибка - должно быть 64626426 --
        CHECK(64626426 / mas[0] == 2);
        CHECK(14 % mas[0] == 14);
        // -- арифметические операции. Оба Long --
        CHECK(mas[0] + mas[0] == 64626426);
        CHECK(0 == mas[0] - mas[0]);
        CHECK(mas[0] * mas[2] == 0);
        CHECK(mas[0] / mas[0] == 1);
        CHECK(mas[0] % mas[0] == 0);
        mas[3] = mas[5]; CHECK(mas[3]== mas[5]);
        // -- арифметические операции. C присваиванием --
        mas[2] += mas[5]; CHECK(mas[2] == mas[0]);      // -- ошибка - должно быть mas[5] --
        mas[2] += 4; CHECK(mas[2] == mas[4]);
        mas[2] -= 4; CHECK(mas[2] == mas[5]);
        mas[2] -= mas[5] - 1; CHECK(mas[2] == 1);
        mas[2] *= 2; CHECK(mas[2] == 2);
        mas[2] *= mas[0]; CHECK(mas[2] == 64626426);
        mas[2] /= mas[0]; CHECK(mas[2] == 2);
        mas[2] /= 2; CHECK(mas[2] == 1);
        mas[2] %= 6; CHECK(mas[2] == 1);
        mas[2] %= mas[0]; CHECK(mas[2] == 1);
        ++mas[2]; CHECK(mas[2] == 2);
        mas[2]++; CHECK(mas[2] == 3);
        --mas[2]; CHECK(mas[2] == 2);
        mas[2]--; CHECK(mas[2] == 1);
        mas[2] = 0l;   // -- возвращение к начальному значению --
    }
    SECTION("Тест сравнения объектов массива")          // -- проверка сравнения --
    {
        CHECK(mas[4] > mas[5]);
        CHECK(mas[4] <= mas[5]);       // -- ошибка --
        CHECK(mas[4] >= mas[5]);
        CHECK(mas[4] <= mas[5] + 4);
        CHECK(mas[4] != mas[5]);
        CHECK(mas[2] < 1);
        CHECK(mas[2] <= 1);
        CHECK(mas[2] != 1);
        CHECK(1 > mas[2]);
        CHECK(1 >= mas[2]);
        CHECK(1 != mas[2]);
    }
    SECTION("Тест создание и присваивание объектов динамического массива") // -- создание и присваивание --
    {
        CHECK(dynMas[0] == 32313213);
        CHECK(dynMas[1] == INT32_MAX);
        CHECK(dynMas[2] == 0);
        dynMas[2] = dynMas[1];        CHECK(dynMas[2] == dynMas[0]);  // -- ошибка - должно быть dynMas[1] --
        CHECK(dynMas[3] == dynMas[1]);
        CHECK(dynMas[4] == dynMas[5] + 4);
        dynMas[2] = dynMas[4];         CHECK(dynMas[2] == dynMas[5] + 4);
        dynMas[2] = 0l;   // -- возвращение к начальному значению --
    }
    SECTION("Тест сложения объектов динамического массива")              // -- тестирование сложения --
    {
        // -- арифметические операции. Слева Long --
        CHECK(dynMas[4] == dynMas[5] + 4);
        CHECK(dynMas[4] - 4 == dynMas[5]);
        CHECK(dynMas[4] * 2 == dynMas[5] * 2 + 8);
        CHECK(dynMas[4] / 2 == dynMas[5] / 2 + 2);
        CHECK((dynMas[4] + 1) % 2 == 1);
        dynMas[3] = 1234; CHECK(dynMas[3]== 1234);
        // -- арифметические операции. Справа Long --
        CHECK(dynMas[4] == 4 + dynMas[5]);
        CHECK(0 == 32313213 - dynMas[0]);
        CHECK(2 * dynMas[0] == 64626427);       // -- ошибка - должно быть 64626426 --
        CHECK(64626426 / dynMas[0] == 2);
        CHECK(14 % dynMas[0] == 14);
        // -- арифметические операции. Оба Long --
        CHECK(dynMas[0] + dynMas[0] == 64626426);
        CHECK(0 == dynMas[0] - dynMas[0]);
        CHECK(dynMas[0] * dynMas[2] == 0);
        CHECK(dynMas[0] / dynMas[0] == 1);
        CHECK(dynMas[0] % dynMas[0] == 0);
        dynMas[3] = dynMas[5]; CHECK(dynMas[3]== dynMas[5]);
        // -- арифметические операции. C присваиванием --
        dynMas[2] += dynMas[5]; CHECK(dynMas[2] == dynMas[0]);      // -- ошибка - должно быть dynMas[5] --
        dynMas[2] += 4; CHECK(dynMas[2] == dynMas[4]);
        dynMas[2] -= 4; CHECK(dynMas[2] == dynMas[5]);
        dynMas[2] -= dynMas[5] - 1; CHECK(dynMas[2] == 1);
        dynMas[2] *= 2; CHECK(dynMas[2] == 2);
        dynMas[2] *= dynMas[0]; CHECK(dynMas[2] == 64626426);
        dynMas[2] /= dynMas[0]; CHECK(dynMas[2] == 2);
        dynMas[2] /= 2; CHECK(dynMas[2] == 1);
        dynMas[2] %= 6; CHECK(dynMas[2] == 1);
        dynMas[2] %= dynMas[0]; CHECK(dynMas[2] == 1);
        ++dynMas[2]; CHECK(dynMas[2] == 2);
        dynMas[2]++; CHECK(dynMas[2] == 3);
        --dynMas[2]; CHECK(dynMas[2] == 2);
        dynMas[2]--; CHECK(dynMas[2] == 1);
        dynMas[2] = 0l;   // -- возвращение к начальному значению --
    }
    SECTION("Тест сравнения объектов динамического массива")          // -- проверка сравнения --
    {
        CHECK(dynMas[4] > dynMas[5]);
        CHECK(dynMas[4] <= dynMas[5]);       // -- ошибка --
        CHECK(dynMas[4] >= dynMas[5]);
        CHECK(dynMas[4] <= dynMas[5] + 4);
        CHECK(dynMas[4] != dynMas[5]);
        CHECK(dynMas[2] < 1);
        CHECK(dynMas[2] <= 1);
        CHECK(dynMas[2] != 1);
        CHECK(1 > dynMas[2]);
        CHECK(1 >= dynMas[2]);
        CHECK(1 != dynMas[2]);
    }
}
// -- тестирование исключений --
TEST_CASE("Тест исключений","[LongTest]")
{
  CHECK_THROWS([&](){Long F('a');}()); // -- правильно - генерит исключения --
  CHECK_THROWS([&](){Long F("123");}());  // -- ошибка - не генерит исключения --
}
