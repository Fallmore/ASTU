#ifndef TIMETEST_H_INCLUDED
#define TIMETEST_H_INCLUDED

#pragma once
#include "Time.h"
#include "../Laba3/Project1/UnitTest.h"

using namespace UnitTest;         // -- чтобы не писать полные имена --
// -- в тестовых методах пишутся вызовы макроса check() --
class TimeTest: public Test {
    // -- здесь можно определять объекты тестируемого класса --
  public:
    // -- инициализация объектов --
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
    }
    // -- тестовые методы --
    void testCreate() { 		// -- создание и присваивание --
        Time a;     check(a.toString() == "\n00:00:00");
        Time b(70);     check(b.toString() == "\n00:01:10");
        Time c(65,30);     check(c.toString() == "\n01:05:30");
        Time d(31,21,66);     check(d.toString() == "\n07:22:06");
        Time e(0,0,-23);     check(e.toString()== a.ConvertInTimeFromSeconds(UINT32_MAX-22).toString());
        a = c;     check(a.toString() == "\n01:05:30");
    }
    void testArithmetic() {     // -- тестирование преобразований --
        Time a(13,76,222);     // 14:19:42
        check(a.ConvertInSeconds() == 13*3600+76*60+222);
        check(a.ConvertInMinutes() == round(static_cast<float>(13*3600+76*60+222)/60));
        check(a.ConvertInTimeFromSeconds(225).toString() == "\n00:03:45");
        check(a.ConvertInTimeFromMinutes(225).toString() == "\n03:45:00");
        check(a.Difference(a.ConvertInTimeFromMinutes(225)) == 10*3600+34*60+42);
        check((a - a.ConvertInTimeFromSeconds(660)).toString() == "\n14:08:42");
        check((a + a.ConvertInTimeFromSeconds(660)).toString() == "\n14:30:42");
        check((a - 75).toString() == "\n14:18:27");
        check((a + 23).toString() == "\n14:20:05");
    }
    void testCompare() {  		// -- проверка сравнения --
        Time a(13,76,222), b(23,2,2);
        check(a < b); check(b > a); check(a != b); check(a == a);
        check(a <=b); check(b >= a);
    }
    void testCreateMas() { 		// -- создание и присваивание --
        Time mas[5] { {70}, {65,30}, {31,21,66}, {0,0,-23u} };
        check(mas[4].toString() == "\n00:00:00");
        check(mas[0].toString() == "\n00:01:10");
        check(mas[1].toString() == "\n01:05:30");
        check(mas[2].toString() == "\n07:22:06");
        check(mas[3].toString()== mas[3].ConvertInTimeFromSeconds(UINT32_MAX-22).toString());
        mas[4] = mas[1];     check(mas[4].toString() == "\n01:05:30");
    }
    void testArithmeticMas() {     // -- тестирование преобразований --
        Time mas[1] { {13,76,222} };     // 14:19:42
        check(mas[0].ConvertInSeconds() == 13*3600+76*60+222);
        check(mas[0].ConvertInMinutes() == round(static_cast<float>(13*3600+76*60+222)/60));
        check(mas[0].ConvertInTimeFromSeconds(225).toString() == "\n00:03:45");
        check(mas[0].ConvertInTimeFromMinutes(225).toString() == "\n03:45:00");
        check(mas[0].Difference(mas[0].ConvertInTimeFromMinutes(225)) == 10*3600+34*60+42);
        check((mas[0] - mas[0].ConvertInTimeFromSeconds(660)).toString() == "\n14:08:42");
        check((mas[0] + mas[0].ConvertInTimeFromSeconds(660)).toString() == "\n14:30:42");
        check((mas[0] - 75).toString() == "\n14:18:27");
        check((mas[0] + 23).toString() == "\n14:20:05");
    }
    void testCompareMas() {  		// -- проверка сравнения --
        Time mas[2] { {13,76,222}, {23,2,2} };
        check(mas[0] < mas[1]); check(mas[1] > mas[0]); check(mas[0] != mas[1]); check(mas[0] == mas[0]);
        check(mas[0] <=mas[1]); check(mas[1] >= mas[0]);
    }
    void testCreateDynMas() { 		// -- создание и присваивание --
        Time* dynMas = new Time[5] { {70}, {65,30}, {31,21,66}, {0,0,-23u} };
        check(dynMas[4].toString() == "\n00:00:00");
        check(dynMas[0].toString() == "\n00:01:10");
        check(dynMas[1].toString() == "\n01:05:30");
        check(dynMas[2].toString() == "\n07:22:06");
        check(dynMas[3].toString()== dynMas[3].ConvertInTimeFromSeconds(UINT32_MAX-22).toString());
        dynMas[4] = dynMas[1];     check(dynMas[4].toString() == "\n01:05:30");
        delete[] dynMas;
    }
    void testArithmeticDynMas() {     // -- тестирование преобразований --
        Time* dynMas = new Time[1] { {13,76,222} };     // 14:19:42
        check(dynMas[0].ConvertInSeconds() == 13*3600+76*60+222);
        check(dynMas[0].ConvertInMinutes() == round(static_cast<float>(13*3600+76*60+222)/60));
        check(dynMas[0].ConvertInTimeFromSeconds(225).toString() == "\n00:03:45");
        check(dynMas[0].ConvertInTimeFromMinutes(225).toString() == "\n03:45:00");
        check(dynMas[0].Difference(dynMas[0].ConvertInTimeFromMinutes(225)) == 10*3600+34*60+42);
        check((dynMas[0] - dynMas[0].ConvertInTimeFromSeconds(660)).toString() == "\n14:08:42");
        check((dynMas[0] + dynMas[0].ConvertInTimeFromSeconds(660)).toString() == "\n14:30:42");
        check((dynMas[0] - 75).toString() == "\n14:18:27");
        check((dynMas[0] + 23).toString() == "\n14:20:05");
        delete[] dynMas;
    }
    void testCompareDynMas() {  		// -- проверка сравнения --
        Time* dynMas = new Time[2] { {13,76,222}, {23,2,2} };
        check(dynMas[0] < dynMas[1]); check(dynMas[1] > dynMas[0]); check(dynMas[0] != dynMas[1]); check(dynMas[0] == dynMas[0]);
        check(dynMas[0] <=dynMas[1]); check(dynMas[1] >= dynMas[0]);
        delete[] dynMas;
    }
};

#endif // TIMETEST_H_INCLUDED
