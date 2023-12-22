#ifndef PAIRTEST_H_INCLUDED
#define PAIRTEST_H_INCLUDED

#include "../catch.hpp"
#include "Pair.h"

// -- непосредственно тесты -
TEST_CASE("Тесты PairTest в Catch","[PairTest]")
{
    SECTION("Тест создание и присваивание объектов") // -- создание и присваивание --
    {
        Pair a;                     CHECK(a.toString() == "0 0");
        Pair b(12, 34);             CHECK(b.getFirst() == 12); CHECK(b.getSecond() == 34);
        a = b;                      CHECK(a.toString() == "12 34");
        Pair c(-2, 123);            CHECK(c.toString() == "-2 123");
        a.setFirst(c.getFirst()), 
        a.setSecond(c.getSecond()); CHECK(a.toString() == "-2 123");
    }
    SECTION("Тест сложения объектов")              // -- тестирование сложения --
    {
        Pair a(3, 213), b(-42, 21);
        b += a; CHECK(b.toString() == "-39 234"); CHECK((a + b).toString() == "-36 447");
    }
    SECTION("Тест создание и присваивание объектов массива") // -- создание и присваивание --
    {
        Pair mas[3] { {12, 34}, {-2, 123}};
        CHECK(mas[2].toString() == "0 0");
        CHECK(mas[0].getFirst() == 12);       CHECK(mas[0].getSecond() == 34);
        mas[2] = mas[0];                      CHECK(mas[2].toString() == "12 34");
        CHECK(mas[1].toString() == "-2 123");
        mas[2].setFirst(mas[1].getFirst()),
        mas[2].setSecond(mas[1].getSecond()); CHECK(mas[2].toString() == "-2 123");
    }
    SECTION("Тест сложения объектов массива")              // -- тестирование сложения --
    {
        Pair mas[2] { {3, 213}, {-42, 21} };
        mas[1] += mas[0]; CHECK(mas[1].toString() == "-39 234"); CHECK((mas[0] + mas[1]).toString() == "-36 447");
    }
    SECTION("Тест создание и присваивание объектов динамического массива") // -- создание и присваивание --
    {
        Pair* dynMas = new Pair[3] { {12, 34}, {-2, 123} };
        CHECK(dynMas[2].toString() == "0 0");
        CHECK(dynMas[0].getFirst() == 12);         CHECK(dynMas[0].getSecond() == 34);
        dynMas[2] = dynMas[0];                     CHECK(dynMas[2].toString() == "12 34");
        CHECK(dynMas[1].toString() == "-2 123");
        dynMas[2].setFirst(dynMas[1].getFirst()),
        dynMas[2].setSecond(dynMas[1].getSecond());CHECK(dynMas[2].toString() == "-2 123");
        delete[] dynMas;
    }
    SECTION("Тест сложения объектов динамического массива")              // -- тестирование сложения --
    {
        Pair* dynMas = new Pair[2] { {3, 213}, {-42, 21} };
        dynMas[1] += dynMas[0]; CHECK(dynMas[1].toString() == "-39 234"); CHECK((dynMas[0] + dynMas[1]).toString() == "-36 447");
        delete[] dynMas;
    }
}

#endif // PAIRTEST_H_INCLUDED
