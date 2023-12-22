#ifndef MONEYTEST_H_INCLUDED
#define MONEYTEST_H_INCLUDED

#include "../catch.hpp"
#include "Money.h"

// -- непосредственно тесты -
TEST_CASE("Тесты MoneyTest в Catch","[MoneyTest]")
{
    SECTION("Тест создание и присваивание объектов") // -- создание и присваивание --
    {
        Money a;                     CHECK(a.toString() == "0 руб. 0 коп.");
        Money b(1233);               CHECK(b.getFirst() == 12); 
                                     CHECK(b.getSecond() == 33);
        Money c(433);                CHECK(c.toString() == "4 руб. 33 коп.");
        a = c;                       CHECK(a.toString() == "4 руб. 33 коп.");
        a.setRub(b.getFirst()), 
        a.setKop(b.getSecond());     CHECK(a.toString() == "12 руб. 33 коп.");
        a.setRub(65), a.setKop(113); CHECK(a.toString() == "66 руб. 13 коп.");
    }
    SECTION("Тест арифметики объектов")              // -- тестирование сложения --
    {
        Money a(46534), b(2301);
        a += b; CHECK(a.toString() == "488 руб. 35 коп.");
                CHECK((a + b).toString() == "511 руб. 36 коп.");
        a -= 1; CHECK(a.toString() == "488 руб. 34 коп.");
                CHECK((a - 1000).toString() == "478 руб. 34 коп.");
        a /= 2; CHECK(a.toString() == "244 руб. 17 коп.");
                CHECK((a / 4).toString() == "61 руб. 4 коп.");
    }
    SECTION("Тест создание и присваивание объектов массива") // -- создание и присваивание --
    {
        Money mas[3] { {1233}, {433} };
        CHECK(mas[2].toString() == "0 руб. 0 коп.");
        CHECK(mas[0].getFirst() == 12); 
        CHECK(mas[0].getSecond() == 33);
        CHECK(mas[1].toString() == "4 руб. 33 коп.");
        mas[2] = mas[1];                        CHECK(mas[2].toString() == "4 руб. 33 коп.");
        mas[2].setRub(mas[0].getFirst()),
        mas[2].setKop(mas[0].getSecond());      CHECK(mas[2].toString() == "12 руб. 33 коп.");
        mas[2].setRub(65), mas[2].setKop(113);  CHECK(mas[2].toString() == "66 руб. 13 коп.");
    }
    SECTION("Тест арифметики объектов массива")              // -- тестирование сложения --
    {
        Money mas[2] { {46534}, {2301} };
        mas[0] += mas[1];   CHECK(mas[0].toString() == "488 руб. 35 коп.");
                            CHECK((mas[0] + mas[1]).toString() == "511 руб. 36 коп.");
        mas[0] -= 1;        CHECK(mas[0].toString() == "488 руб. 34 коп.");
                            CHECK((mas[0] - 1000).toString() == "478 руб. 34 коп.");
        mas[0] /= 2;        CHECK(mas[0].toString() == "244 руб. 17 коп.");
                            CHECK((mas[0] / 4).toString() == "61 руб. 4 коп.");
    }
    SECTION("Тест создание и присваивание объектов динамического массива") // -- создание и присваивание --
    {
        Money* dynMas = new Money[3] { {1233}, {433} };
        CHECK(dynMas[2].toString() == "0 руб. 0 коп.");
        CHECK(dynMas[0].getFirst() == 12); 
        CHECK(dynMas[0].getSecond() == 33);
        CHECK(dynMas[1].toString() == "4 руб. 33 коп.");
        dynMas[2] = dynMas[1];                        CHECK(dynMas[2].toString() == "4 руб. 33 коп.");
        dynMas[2].setRub(dynMas[0].getFirst()),
        dynMas[2].setKop(dynMas[0].getSecond());      CHECK(dynMas[2].toString() == "12 руб. 33 коп.");
        dynMas[2].setRub(65), dynMas[2].setKop(113);  CHECK(dynMas[2].toString() == "66 руб. 13 коп.");
        delete[] dynMas;
    }
    SECTION("Тест арифметики объектов динамического массива")              // -- тестирование сложения --
    {
        Money* dynMas = new Money[2] { {46534}, {2301} };
        dynMas[0] += dynMas[1]; CHECK(dynMas[0].toString() == "488 руб. 35 коп.");
                                CHECK((dynMas[0] + dynMas[1]).toString() == "511 руб. 36 коп.");
        dynMas[0] -= 1;         CHECK(dynMas[0].toString() == "488 руб. 34 коп.");
                                CHECK((dynMas[0] - 1000).toString() == "478 руб. 34 коп.");
        dynMas[0] /= 2;         CHECK(dynMas[0].toString() == "244 руб. 17 коп.");
                                CHECK((dynMas[0] / 4).toString() == "61 руб. 4 коп.");
        delete[] dynMas;
    }
}
// -- тестирование исключений --
TEST_CASE("Тест исключений", "[MoneyTest]") {
    CHECK_THROWS( [&] () { Money F(-2); } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Money F;  F.setRub(-2);} () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Money F;  F.setKop(-2);} () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Money F;  F -= 3;} () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Money F;  F /= -3;} () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Money F;  F /= 0;} () ); // -- правильно - генерит исключения --
}
#endif // MONEYTEST_H_INCLUDED
