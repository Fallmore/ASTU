#ifndef TIMETEST_H_INCLUDED
#define TIMETEST_H_INCLUDED

#include "../catch.hpp"
#include "Time.h"

TEST_CASE("Тесты TimeTest в Catch","[TimeTest]")
{
    SECTION("Тест создание и присваивание объектов") // -- создание и присваивание --
    {
        Time a;     CHECK(a.toString() == "00:00:00");
        Time b(70);     CHECK(b.toString() == "00:01:10");
        Time c(65,30);     CHECK(c.toString() == "01:05:30");
        Time d(31,21,66);     CHECK(d.toString() == "07:22:06");
        Time e(0,0,-23);     CHECK(e.toString()== a.ConvertInTimeFromSeconds(UINT32_MAX-22).toString());
        a = c;     CHECK(a.toString() == "01:05:30");
    }
    SECTION("Тест арифметики объектов")              // -- тестирование арифметики --
    {
        Time a(13,76,222);     // 14:19:42
        CHECK(a.ConvertInSeconds() == 13*3600+76*60+222);
        CHECK(a.ConvertInMinutes() == round(static_cast<float>(13*3600+76*60+222)/60));
        CHECK(a.ConvertInTimeFromSeconds(225).toString() == "00:03:45");
        CHECK(a.ConvertInTimeFromMinutes(225).toString() == "03:45:00");
        CHECK(a.Difference(a.ConvertInTimeFromMinutes(225)) == 10*3600+34*60+42);
        CHECK((a - a.ConvertInTimeFromSeconds(660)).toString() == "14:08:42");
        CHECK((a + a.ConvertInTimeFromSeconds(660)).toString() == "14:30:42");
        CHECK((a - (unsigned int)75).toString() == "14:18:27");
        CHECK((a + (unsigned int)23).toString() == "14:20:05");
    }
    SECTION("Тест сравнения объектов")              // -- тестирование арифметики --
    {
        Time a(13,76,222), b(23,2,2);
        CHECK(a < b); CHECK(b > a); CHECK(a != b); CHECK(a == a);
        CHECK(a <=b); CHECK(b >= a);
    }
    SECTION("Тест создание и присваивание объектов массива") // -- создание и присваивание --
    {
        Time mas[5] { {70}, {65,30}, {31,21,66}, {0,0,-23u} };
        CHECK(mas[4].toString() == "00:00:00");
        CHECK(mas[0].toString() == "00:01:10");
        CHECK(mas[1].toString() == "01:05:30");
        CHECK(mas[2].toString() == "07:22:06");
        CHECK(mas[3].toString()== mas[3].ConvertInTimeFromSeconds(UINT32_MAX-22).toString());
        mas[4] = mas[1];     CHECK(mas[4].toString() == "01:05:30");
    }
    SECTION("Тест арифметики объектов массива")              // -- тестирование арифметики --
    {
        Time mas[1] { {13,76,222} };     // 14:19:42
        CHECK(mas[0].ConvertInSeconds() == 13*3600+76*60+222);
        CHECK(mas[0].ConvertInMinutes() == round(static_cast<float>(13*3600+76*60+222)/60));
        CHECK(mas[0].ConvertInTimeFromSeconds(225).toString() == "00:03:45");
        CHECK(mas[0].ConvertInTimeFromMinutes(225).toString() == "03:45:00");
        CHECK(mas[0].Difference(mas[0].ConvertInTimeFromMinutes(225)) == 10*3600+34*60+42);
        CHECK((mas[0] - mas[0].ConvertInTimeFromSeconds(660)).toString() == "14:08:42");
        CHECK((mas[0] + mas[0].ConvertInTimeFromSeconds(660)).toString() == "14:30:42");
        CHECK((mas[0] - (unsigned int)75).toString() == "14:18:27");
        CHECK((mas[0] + (unsigned int)23).toString() == "14:20:05");
    }
    SECTION("Тест сравнения объектов массива")              // -- тестирование арифметики --
    {
        Time mas[2] { {13,76,222}, {23,2,2} };
        CHECK(mas[0] < mas[1]); CHECK(mas[1] > mas[0]); CHECK(mas[0] != mas[1]); CHECK(mas[0] == mas[0]);
        CHECK(mas[0] <=mas[1]); CHECK(mas[1] >= mas[0]);
    }
    SECTION("Тест создание и присваивание объектов динамического массива") // -- создание и присваивание --
    {
        Time* dynMas = new Time[5] { {70}, {65,30}, {31,21,66}, {0,0,-23u} };
        CHECK(dynMas[4].toString() == "00:00:00");
        CHECK(dynMas[0].toString() == "00:01:10");
        CHECK(dynMas[1].toString() == "01:05:30");
        CHECK(dynMas[2].toString() == "07:22:06");
        CHECK(dynMas[3].toString()== dynMas[3].ConvertInTimeFromSeconds(UINT32_MAX-22).toString());
        dynMas[4] = dynMas[1];     CHECK(dynMas[4].toString() == "01:05:30");
        delete[] dynMas;
    }
    SECTION("Тест арифметики объектов динамического массива")  // -- тестирование арифметики --
    {
        Time* dynMas = new Time[1] { {13,76,222} };     // 14:19:42
        CHECK(dynMas[0].ConvertInSeconds() == 13*3600+76*60+222);
        CHECK(dynMas[0].ConvertInMinutes() == round(static_cast<float>(13*3600+76*60+222)/60));
        CHECK(dynMas[0].ConvertInTimeFromSeconds(225).toString() == "00:03:45");
        CHECK(dynMas[0].ConvertInTimeFromMinutes(225).toString() == "03:45:00");
        CHECK(dynMas[0].Difference(dynMas[0].ConvertInTimeFromMinutes(225)) == 10*3600+34*60+42);
        CHECK((dynMas[0] - dynMas[0].ConvertInTimeFromSeconds(660)).toString() == "14:08:42");
        CHECK((dynMas[0] + dynMas[0].ConvertInTimeFromSeconds(660)).toString() == "14:30:42");
        CHECK((dynMas[0] - (unsigned int)75).toString() == "14:18:27");
        CHECK((dynMas[0] + (unsigned int)23).toString() == "14:20:05");
        delete[] dynMas;
    }
    SECTION("Тест сравнения объектов динамического массива")              // -- тестирование арифметики --
    {
        Time* dynMas = new Time[2] { {13,76,222}, {23,2,2} };
        CHECK(dynMas[0] < dynMas[1]); CHECK(dynMas[1] > dynMas[0]); CHECK(dynMas[0] != dynMas[1]); CHECK(dynMas[0] == dynMas[0]);
        CHECK(dynMas[0] <=dynMas[1]); CHECK(dynMas[1] >= dynMas[0]);
        delete[] dynMas;
    }
}
// -- тестирование исключений --
TEST_CASE("Тест исключений TimeTest", "[TimeTest]") {
    CHECK_THROWS( [&] () { Time F; F = F - (unsigned int)3; } () ); // -- правильно - генерит исключения --
}
#endif // TIMETEST_H_INCLUDED
