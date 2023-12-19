#ifndef MODULOTEST_H_INCLUDED
#define MODULOTEST_H_INCLUDED

#include "Time.h"
#include "../Laba3/Project1/UnitTest.h"

using namespace UnitTest;         // -- чтобы не писать полные имена --
// -- в тестовых методах пишутс€ вызовы макроса check() --
class ModuloTest: public Test {
    // -- здесь можно определ€ть объекты тестируемого класса --
  public:
    // -- инициализаци€ объектов --
    // -- можно написать конструктор дл€ инициализации обектов-полей --
    // -- определение чистой виртуальной функции run() класса Test --
    void run() {                 // -- вызов тестовых методв --
        testCreate();			// -- тест конструкторов и присваивани€ --
        testArithmetic();	// -- тест арифметики --
        testCompare();		// -- тест сравнени€ --
        testCreateMas();			// -- тест конструкторов и присваивани€ --
        testArithmeticMas();	// -- тест арифметики --
        testCompareMas();		// -- тест сравнени€ --
        testCreateDynMas();			// -- тест конструкторов и присваивани€ --
        testArithmeticDynMas();	// -- тест арифметики --
        testCompareDynMas();		// -- тест сравнени€ --
    }
    // -- тестовые методы --
    void testCreate() { 		// -- создание и присваивание --
        Time::Modulo a;
        check(a.GetN() == 0);
        check(a.GetNum() == 0);
        Time::Modulo b(4, 5);
        check(b.GetN() == 5);
        check(b.GetNum() == 4);
        Time::Modulo c(4, 2);
        check(c.GetN() == 2);
        check(c.GetNum() == 0);
        a = c;
        check(a.GetN() == 2);
        check(a.GetNum() == 0);
        b = {2,3};
        check(b.GetN() == 3);
        check(b.GetNum() == 2);
    }
    void testArithmetic() {     // -- тестирование сложени€ --
        Time::Modulo a(2,3);
        a += 2;     check(a.GetNum() == 1);
        a++;     check(a.GetNum() == 2);
        ++a;      check(a.GetNum() == 0);
        a--;     check(a.GetNum() == 2);
        --a;     check(a.GetNum() == 1);
        a -= 3;     check(a.GetNum() == 1);
        a %= 6;     check(a.GetNum() == 1);     check(a.GetN() == 6);
        a *= 5;     check(a.GetNum() == 5);
        a /= (-1);     check(a.GetNum() == 1);
        Time::Modulo b(5, 14);
        b += a;     check(b.GetNum() == 6);     check(b.GetN() == 14);
        b += a+2;     check(b.GetNum() == 9);
        b += 2+a;     check(b.GetNum() == 12);
        b -= a-2;     check(b.GetNum() == 7);
        b -= (0-a);     check(b.GetNum() == 2);
        b -= 8-a;     check(b.GetNum() == 1);
        b *= a;     check(b.GetNum() == 1);
        b *= a+2;     check(b.GetNum() == 3);
        b *= 5-a;     check(b.GetNum() == 12);
        b /= a/1*2;     check(b.GetNum() == 6);
        b /=1/a;     check(b.GetNum() == 6);
        b %= (a+2)%4;     check(b.GetNum() == 0);     check(b.GetN() == 3);
        b %= 1%((a+4)%3);     check(b.GetNum() == 0);     check(b.GetN() == 1);
    }
    void testCompare() {  		// -- проверка сравнени€ --
        Time::Modulo a(2,3), b(5,14);
        check(a > 1); check(a < 3); check(a == 2);
        check(a >= -2); check(a <= 5); check( a != 3);
        check(1 < b); check(6 > b); check(5 == b);
        check(-2 <= b); check(8 >= b); check(3 != b);
        check(a < b); check(b > a); check(a != b);
        check(a <= b); check(b >= a);
    }
    void testCreateMas() { 		// -- создание и присваивание --
        Time::Modulo mas[3] { {4,5}, {4,2} };
        check(mas[2].GetN() == 0);
        check(mas[2].GetNum() == 0);
        check(mas[0].GetN() == 5);
        check(mas[0].GetNum() == 4);
        Time::Modulo c(4, 2);
        check(mas[1].GetN() == 2);
        check(mas[1].GetNum() == 0);
        mas[2] = mas[1];
        check(mas[2].GetN() == 2);
        check(mas[2].GetNum() == 0);
        mas[0] = {2,3};
        check(mas[0].GetN() == 3);
        check(mas[0].GetNum() == 2);
    }
    void testArithmeticMas() {     // -- тестирование сложени€ --
        Time::Modulo mas[2] { {2,3}, {5, 14} };
        mas[0] += 2;     check(mas[0].GetNum() == 1);
        mas[0]++;     check(mas[0].GetNum() == 2);
        ++mas[0];      check(mas[0].GetNum() == 0);
        mas[0]--;     check(mas[0].GetNum() == 2);
        --mas[0];     check(mas[0].GetNum() == 1);
        mas[0] -= 3;     check(mas[0].GetNum() == 1);
        mas[0] %= 6;     check(mas[0].GetNum() == 1);     check(mas[0].GetN() == 6);
        mas[0] *= 5;     check(mas[0].GetNum() == 5);
        mas[0] /= (-1);     check(mas[0].GetNum() == 1);
        mas[1] += mas[0];     check(mas[1].GetNum() == 6);     check(mas[1].GetN() == 14);
        mas[1] += mas[0]+2;     check(mas[1].GetNum() == 9);
        mas[1] += 2+mas[0];     check(mas[1].GetNum() == 12);
        mas[1] -= mas[0]-2;     check(mas[1].GetNum() == 7);
        mas[1] -= (0-mas[0]);     check(mas[1].GetNum() == 2);
        mas[1] -= 8-mas[0];     check(mas[1].GetNum() == 1);
        mas[1] *= mas[0];     check(mas[1].GetNum() == 1);
        mas[1] *= mas[0]+2;     check(mas[1].GetNum() == 3);
        mas[1] *= 5-mas[0];     check(mas[1].GetNum() == 12);
        mas[1] /= mas[0]/1*2;     check(mas[1].GetNum() == 6);
        mas[1] /=1/mas[0];     check(mas[1].GetNum() == 6);
        mas[1] %= (mas[0]+2)%4;     check(mas[1].GetNum() == 0);     check(mas[1].GetN() == 3);
        mas[1] %= 1%((mas[0]+4)%3);     check(mas[1].GetNum() == 0);     check(mas[1].GetN() == 1);
    }
    void testCompareMas() {  		// -- проверка сравнени€ --
        Time::Modulo mas[2] { {2,3}, {5, 14} };
        check(mas[0] > 1); check(mas[0] < 3); check(mas[0] == 2);
        check(mas[0] >= -2); check(mas[0] <= 5); check( mas[0] != 3);
        check(1 < mas[1]); check(6 > mas[1]); check(5 == mas[1]);
        check(-2 <= mas[1]); check(8 >= mas[1]); check(3 != mas[1]);
        check(mas[0] < mas[1]); check(mas[1] > mas[0]); check(mas[0] != mas[1]);
        check(mas[0] <= mas[1]); check(mas[1] >= mas[0]);
    }
    void testCreateDynMas() { 		// -- создание и присваивание --
        Time::Modulo* dynMas = new Time::Modulo[3] { {4,5}, {4,2} };
        check(dynMas[2].GetN() == 0);
        check(dynMas[2].GetNum() == 0);
        check(dynMas[0].GetN() == 5);
        check(dynMas[0].GetNum() == 4);
        Time::Modulo c(4, 2);
        check(dynMas[1].GetN() == 2);
        check(dynMas[1].GetNum() == 0);
        dynMas[2] = dynMas[1];
        check(dynMas[2].GetN() == 2);
        check(dynMas[2].GetNum() == 0);
        dynMas[0] = {2,3};
        check(dynMas[0].GetN() == 3);
        check(dynMas[0].GetNum() == 2);
        delete[] dynMas;
    }
    void testArithmeticDynMas() {     // -- тестирование сложени€ --
        Time::Modulo* dynMas = new Time::Modulo[2] { {2,3}, {5, 14} };
        dynMas[0] += 2;     check(dynMas[0].GetNum() == 1);
        dynMas[0]++;     check(dynMas[0].GetNum() == 2);
        ++dynMas[0];      check(dynMas[0].GetNum() == 0);
        dynMas[0]--;     check(dynMas[0].GetNum() == 2);
        --dynMas[0];     check(dynMas[0].GetNum() == 1);
        dynMas[0] -= 3;     check(dynMas[0].GetNum() == 1);
        dynMas[0] %= 6;     check(dynMas[0].GetNum() == 1);     check(dynMas[0].GetN() == 6);
        dynMas[0] *= 5;     check(dynMas[0].GetNum() == 5);
        dynMas[0] /= (-1);     check(dynMas[0].GetNum() == 1);
        dynMas[1] += dynMas[0];     check(dynMas[1].GetNum() == 6);     check(dynMas[1].GetN() == 14);
        dynMas[1] += dynMas[0]+2;     check(dynMas[1].GetNum() == 9);
        dynMas[1] += 2+dynMas[0];     check(dynMas[1].GetNum() == 12);
        dynMas[1] -= dynMas[0]-2;     check(dynMas[1].GetNum() == 7);
        dynMas[1] -= (0-dynMas[0]);     check(dynMas[1].GetNum() == 2);
        dynMas[1] -= 8-dynMas[0];     check(dynMas[1].GetNum() == 1);
        dynMas[1] *= dynMas[0];     check(dynMas[1].GetNum() == 1);
        dynMas[1] *= dynMas[0]+2;     check(dynMas[1].GetNum() == 3);
        dynMas[1] *= 5-dynMas[0];     check(dynMas[1].GetNum() == 12);
        dynMas[1] /= dynMas[0]/1*2;     check(dynMas[1].GetNum() == 6);
        dynMas[1] /=1/dynMas[0];     check(dynMas[1].GetNum() == 6);
        dynMas[1] %= (dynMas[0]+2)%4;     check(dynMas[1].GetNum() == 0);     check(dynMas[1].GetN() == 3);
        dynMas[1] %= 1%((dynMas[0]+4)%3);     check(dynMas[1].GetNum() == 0);     check(dynMas[1].GetN() == 1);
        delete[] dynMas;
    }
    void testCompareDynMas() {  		// -- проверка сравнени€ --
        Time::Modulo* dynMas = new Time::Modulo[2] { {2,3}, {5, 14} };
        check(dynMas[0] > 1); check(dynMas[0] < 3); check(dynMas[0] == 2);
        check(dynMas[0] >= -2); check(dynMas[0] <= 5); check( dynMas[0] != 3);
        check(1 < dynMas[1]); check(6 > dynMas[1]); check(5 == dynMas[1]);
        check(-2 <= dynMas[1]); check(8 >= dynMas[1]); check(3 != dynMas[1]);
        check(dynMas[0] < dynMas[1]); check(dynMas[1] > dynMas[0]); check(dynMas[0] != dynMas[1]);
        check(dynMas[0] <= dynMas[1]); check(dynMas[1] >= dynMas[0]);
        delete[] dynMas;
    }
};

#endif // MODULOTEST_H_INCLUDED
