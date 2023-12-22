#ifndef MODULOTEST_H_INCLUDED
#define MODULOTEST_H_INCLUDED

#include "../catch.hpp"
#include "Modulo.h"

TEST_CASE("Тесты ModuloTest в Catch","[ModuloTest]")
{
    SECTION("Тест создание и присваивание объектов") // -- создание и присваивание --
    {
        Modulo a;
        CHECK(a.GetN() == 0); CHECK(a.GetNum() == 0);
        Modulo b(4, 5);
        CHECK(b.GetN() == 5); CHECK(b.GetNum() == 4);
        Modulo c(4, 2);
        CHECK(c.GetN() == 2); CHECK(c.GetNum() == 0);
        a = c;
        CHECK(a.GetN() == 2); CHECK(a.GetNum() == 0);
        b = {2,3};
        CHECK(b.GetN() == 3); CHECK(b.GetNum() == 2);
    }
    SECTION("Тест арифметики объектов")              // -- тестирование арифметики --
    {
        Modulo a(2,3);
        a += 2;     CHECK(a.GetNum() == 1);
        a++;     CHECK(a.GetNum() == 2);
        ++a;      CHECK(a.GetNum() == 0);
        a--;     CHECK(a.GetNum() == 2);
        --a;     CHECK(a.GetNum() == 1);
        a -= 3;     CHECK(a.GetNum() == 1);
        a %= 6;     CHECK(a.GetNum() == 1);     CHECK(a.GetN() == 6);
        a *= 5;     CHECK(a.GetNum() == 5);
        a /= (-1);     CHECK(a.GetNum() == 1);
        Modulo b(5, 14);
        b += a;     CHECK(b.GetNum() == 6);     CHECK(b.GetN() == 14);
        b += a+2;     CHECK(b.GetNum() == 9);
        b += 2+a;     CHECK(b.GetNum() == 12);
        b -= a-2;     CHECK(b.GetNum() == 7);
        b -= (0-a);     CHECK(b.GetNum() == 2);
        b -= 8-a;     CHECK(b.GetNum() == 1);
        b *= a;     CHECK(b.GetNum() == 1);
        b *= a+2;     CHECK(b.GetNum() == 3);
        b *= 5-a;     CHECK(b.GetNum() == 12);
        b /= a/1*2;     CHECK(b.GetNum() == 6);
        b /=1/a;     CHECK(b.GetNum() == 6);
        b %= (a+2)%4;     CHECK(b.GetNum() == 0);     CHECK(b.GetN() == 3);
        b %= 1%((a+4)%3);     CHECK(b.GetNum() == 0);     CHECK(b.GetN() == 1);
    }
    SECTION("Тест сравнения объектов")              // -- тестирование арифметики --
    {
        Modulo a(2,3), b(5,14);
        CHECK(a > 1); CHECK(a < 3); CHECK(a == 2);
        CHECK(a >= -2); CHECK(a <= 5); CHECK( a != 3);
        CHECK(1 < b); CHECK(6 > b); CHECK(5 == b);
        CHECK(-2 <= b); CHECK(8 >= b); CHECK(3 != b);
        CHECK(a < b); CHECK(b > a); CHECK(a != b);
        CHECK(a <= b); CHECK(b >= a);
    }
    SECTION("Тест создание и присваивание объектов массива") // -- создание и присваивание --
    {
        Modulo mas[3] { {4,5}, {4,2} };
        CHECK(mas[2].GetN() == 0); CHECK(mas[2].GetNum() == 0);
        CHECK(mas[0].GetN() == 5); CHECK(mas[0].GetNum() == 4);
        Modulo c(4, 2);
        CHECK(mas[1].GetN() == 2); CHECK(mas[1].GetNum() == 0);
        mas[2] = mas[1];
        CHECK(mas[2].GetN() == 2); CHECK(mas[2].GetNum() == 0);
        mas[0] = {2,3};
        CHECK(mas[0].GetN() == 3); CHECK(mas[0].GetNum() == 2);
    }
    SECTION("Тест арифметики объектов массива")              // -- тестирование арифметики --
    {
        Modulo mas[2] { {2,3}, {5, 14} };
        mas[0] += 2;     CHECK(mas[0].GetNum() == 1);
        mas[0]++;     CHECK(mas[0].GetNum() == 2);
        ++mas[0];      CHECK(mas[0].GetNum() == 0);
        mas[0]--;     CHECK(mas[0].GetNum() == 2);
        --mas[0];     CHECK(mas[0].GetNum() == 1);
        mas[0] -= 3;     CHECK(mas[0].GetNum() == 1);
        mas[0] %= 6;     CHECK(mas[0].GetNum() == 1);     CHECK(mas[0].GetN() == 6);
        mas[0] *= 5;     CHECK(mas[0].GetNum() == 5);
        mas[0] /= (-1);     CHECK(mas[0].GetNum() == 1);
        mas[1] += mas[0];     CHECK(mas[1].GetNum() == 6);     CHECK(mas[1].GetN() == 14);
        mas[1] += mas[0]+2;     CHECK(mas[1].GetNum() == 9);
        mas[1] += 2+mas[0];     CHECK(mas[1].GetNum() == 12);
        mas[1] -= mas[0]-2;     CHECK(mas[1].GetNum() == 7);
        mas[1] -= (0-mas[0]);     CHECK(mas[1].GetNum() == 2);
        mas[1] -= 8-mas[0];     CHECK(mas[1].GetNum() == 1);
        mas[1] *= mas[0];     CHECK(mas[1].GetNum() == 1);
        mas[1] *= mas[0]+2;     CHECK(mas[1].GetNum() == 3);
        mas[1] *= 5-mas[0];     CHECK(mas[1].GetNum() == 12);
        mas[1] /= mas[0]/1*2;     CHECK(mas[1].GetNum() == 6);
        mas[1] /=1/mas[0];     CHECK(mas[1].GetNum() == 6);
        mas[1] %= (mas[0]+2)%4;     CHECK(mas[1].GetNum() == 0);     CHECK(mas[1].GetN() == 3);
        mas[1] %= 1%((mas[0]+4)%3);     CHECK(mas[1].GetNum() == 0);     CHECK(mas[1].GetN() == 1);
    }
    SECTION("Тест сравнения объектов массива")              // -- тестирование арифметики --
    {
        Modulo mas[2] { {2,3}, {5, 14} };
        CHECK(mas[0] > 1); CHECK(mas[0] < 3); CHECK(mas[0] == 2);
        CHECK(mas[0] >= -2); CHECK(mas[0] <= 5); CHECK( mas[0] != 3);
        CHECK(1 < mas[1]); CHECK(6 > mas[1]); CHECK(5 == mas[1]);
        CHECK(-2 <= mas[1]); CHECK(8 >= mas[1]); CHECK(3 != mas[1]);
        CHECK(mas[0] < mas[1]); CHECK(mas[1] > mas[0]); CHECK(mas[0] != mas[1]);
        CHECK(mas[0] <= mas[1]); CHECK(mas[1] >= mas[0]);
    }
    SECTION("Тест создание и присваивание объектов динамического массива") // -- создание и присваивание --
    {
        Modulo* dynMas = new Modulo[3] { {4,5}, {4,2} };
        CHECK(dynMas[2].GetN() == 0); CHECK(dynMas[2].GetNum() == 0);
        CHECK(dynMas[0].GetN() == 5); CHECK(dynMas[0].GetNum() == 4);
        Modulo c(4, 2);
        CHECK(dynMas[1].GetN() == 2); CHECK(dynMas[1].GetNum() == 0);
        dynMas[2] = dynMas[1];
        CHECK(dynMas[2].GetN() == 2); CHECK(dynMas[2].GetNum() == 0);
        dynMas[0] = {2,3};
        CHECK(dynMas[0].GetN() == 3); CHECK(dynMas[0].GetNum() == 2);
        delete[] dynMas;
    }
    SECTION("Тест арифметики объектов динамического массива")  // -- тестирование арифметики --
    {
        Modulo* dynMas = new Modulo[2] { {2,3}, {5, 14} };
        dynMas[0] += 2;     CHECK(dynMas[0].GetNum() == 1);
        dynMas[0]++;     CHECK(dynMas[0].GetNum() == 2);
        ++dynMas[0];      CHECK(dynMas[0].GetNum() == 0);
        dynMas[0]--;     CHECK(dynMas[0].GetNum() == 2);
        --dynMas[0];     CHECK(dynMas[0].GetNum() == 1);
        dynMas[0] -= 3;     CHECK(dynMas[0].GetNum() == 1);
        dynMas[0] %= 6;     CHECK(dynMas[0].GetNum() == 1);     CHECK(dynMas[0].GetN() == 6);
        dynMas[0] *= 5;     CHECK(dynMas[0].GetNum() == 5);
        dynMas[0] /= (-1);     CHECK(dynMas[0].GetNum() == 1);
        dynMas[1] += dynMas[0];     CHECK(dynMas[1].GetNum() == 6);     CHECK(dynMas[1].GetN() == 14);
        dynMas[1] += dynMas[0]+2;     CHECK(dynMas[1].GetNum() == 9);
        dynMas[1] += 2+dynMas[0];     CHECK(dynMas[1].GetNum() == 12);
        dynMas[1] -= dynMas[0]-2;     CHECK(dynMas[1].GetNum() == 7);
        dynMas[1] -= (0-dynMas[0]);     CHECK(dynMas[1].GetNum() == 2);
        dynMas[1] -= 8-dynMas[0];     CHECK(dynMas[1].GetNum() == 1);
        dynMas[1] *= dynMas[0];     CHECK(dynMas[1].GetNum() == 1);
        dynMas[1] *= dynMas[0]+2;     CHECK(dynMas[1].GetNum() == 3);
        dynMas[1] *= 5-dynMas[0];     CHECK(dynMas[1].GetNum() == 12);
        dynMas[1] /= dynMas[0]/1*2;     CHECK(dynMas[1].GetNum() == 6);
        dynMas[1] /=1/dynMas[0];     CHECK(dynMas[1].GetNum() == 6);
        dynMas[1] %= (dynMas[0]+2)%4;     CHECK(dynMas[1].GetNum() == 0);     CHECK(dynMas[1].GetN() == 3);
        dynMas[1] %= 1%((dynMas[0]+4)%3);     CHECK(dynMas[1].GetNum() == 0);     CHECK(dynMas[1].GetN() == 1);
        delete[] dynMas;
    }
    SECTION("Тест сравнения объектов динамического массива")              // -- тестирование арифметики --
    {
        Modulo* dynMas = new Modulo[2] { {2,3}, {5, 14} };
        CHECK(dynMas[0] > 1); CHECK(dynMas[0] < 3); CHECK(dynMas[0] == 2);
        CHECK(dynMas[0] >= -2); CHECK(dynMas[0] <= 5); CHECK( dynMas[0] != 3);
        CHECK(1 < dynMas[1]); CHECK(6 > dynMas[1]); CHECK(5 == dynMas[1]);
        CHECK(-2 <= dynMas[1]); CHECK(8 >= dynMas[1]); CHECK(3 != dynMas[1]);
        CHECK(dynMas[0] < dynMas[1]); CHECK(dynMas[1] > dynMas[0]); CHECK(dynMas[0] != dynMas[1]);
        CHECK(dynMas[0] <= dynMas[1]); CHECK(dynMas[1] >= dynMas[0]);
        delete[] dynMas;
    }
}
// -- тестирование исключений --
TEST_CASE("Тест исключений ModuloTest", "[ModuloTest]") {
    CHECK_THROWS( [&] () { Modulo F(3, 0); } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4); F /= 0; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4); F = F / 0; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4), D(3, 5); F += D; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4), D(3, 5); F = F + D; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4), D(3, 5); F -= D; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4), D(3, 5); F = F - D; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4), D(3, 5); F *= D; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4), D(3, 5); F = F * D; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4), D(3, 5); F /= D; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4), D(3, 5); F = F / D; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4), D(3, 5); F /= 0; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4), D(3, 5); F = F / 0; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4), D(3, 5); F %= D; } () ); // -- правильно - генерит исключения --
    CHECK_THROWS( [&] () { Modulo F(3, 4), D(3, 5); F = F % D; } () ); // -- правильно - генерит исключения --
}
#endif // MODULOTEST_H_INCLUDED
