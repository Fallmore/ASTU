#ifndef LONGTEST_H_INCLUDED
#define LONGTEST_H_INCLUDED

#include "Longtype.h"
#include "UnitTest.h"

using namespace UnitTest;         // -- ����� �� ������ ������ ����� --
// -- � �������� ������� ������� ������ ������� check() --
class LongTest: public Test {
    // -- ����� ����� ���������� ������� ������������ ������ --
    Long a; Long b; Long c;
    Long d; Long e; Long f;    // -- �������, ����� ���� --
    Long mas[6]; Long* dynMas = new Long[6];
  public:
      LongTest() : a(32313213l), b(static_cast<long>(INT32_MAX)), c(0l), d(b), e("234234234234234"), f("234234234234230") {
        mas[0] = 32313213l; mas[1] = static_cast<long>(INT32_MAX);
        mas[3] = mas[1]; mas[4] = e; mas[5] = f;
        dynMas[0] = 32313213l; dynMas[1] = static_cast<long>(INT32_MAX);
        dynMas[3] = dynMas[1]; dynMas[4] = e; dynMas[5] = f;
      } // -- ������������� �������� --
    // -- ����� �������� ����������� ��� ������������� �������-����� --
    // - ����������� ������ ����������� ������� run() ������ Test --
    void run() {                 // -- ����� �������� ������ --
        testCreate();			// -- ���� ������������� � ������������ --
        testArithmetic();	// -- ���� ���������� --
        testCompare();		// -- ���� ��������� --
        testCreateMas();			// -- ���� ������������� � ������������ --
        testArithmeticMas();	// -- ���� ���������� --
        testCompareMas();		// -- ���� ��������� --
        testCreateDynMas();			// -- ���� ������������� � ������������ --
        testArithmeticDynMas();	// -- ���� ���������� --
        testCompareDynMas();		// -- ���� ��������� --
        testExeption();		// -- ���� ���������� --
    }
    // -- �������� ������ --
    void testCreate() { 		// -- �������� � ������������ --
        check(a == 32313213l);
        check(b == INT32_MAX);
        check(c == 0);
        c = b;          check(c == a);    // -- ������ - ������ ���� b --
        check(d == b);
        check(e == f + 4);
        c = e;          check(c == f + 4);
        c = 0l;   // -- ����������� � ���������� �������� --
    }
    void testArithmetic() {     // -- ������������ �������� --
        // -- �������������� ��������. ����� Long --
        check(e == f + 4);
        check(e - 4 == f);
        check(e * 2 == f * 2 + 8);
        check(e / 2 == f / 2 + 2);
        check((e + 1) % 2 == 1);
        d = 1234;        check(d == 1234);
        // -- �������������� ��������. ������ Long --
        check(e == 4 + f);
        check(0 == 32313213 - a);
        check(2 * a == 64626427);       // -- ������ - ������ ���� 64626426 --
        check(64626426 / a == 2);
        check(14 % a == 14);
        // -- �������������� ��������. ��� Long --
        check(a + a == 64626426);
        check(0 == a - a);
        check(a * c == 0);
        check(a / a == 1);
        check(a % a == 0);
        d = f;        check(d == f);
        // -- �������������� ��������. C ������������� --
        c += f;             check(c == a);      // -- ������ - ������ ���� f --
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
        c = 0l;   // -- ����������� � ���������� �������� --
    }
    void testCompare() {  		// -- �������� ��������� --
        check(e < f == false);
        check(e > f == true);
        check(e <= f == false);
        check(e >= f == false);     // -- ������ - ������ ���� true 0 --
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
    void testCreateMas() { 		// -- �������� � ������������ --
        check(mas[0] == 32313213);
        check(mas[1] == INT32_MAX);
        check(mas[2] == 0);
        mas[2] = mas[1];        check(mas[2] == mas[0]);  // -- ������ - ������ ���� mas[1] --
        check(mas[3] == mas[1]);
        check(mas[4] == mas[5] + 4);
        mas[2] = mas[4];         check(mas[2] == mas[5] + 4);
        mas[2] = 0l;   // -- ����������� � ���������� �������� --
    }
    void testArithmeticMas() {     // -- ������������ �������� --
        // -- �������������� ��������. ����� Long --
        check(mas[4] == mas[5] + 4);
        check(mas[4] - 4 == mas[5]);
        check(mas[4] * 2 == mas[5] * 2 + 8);
        check(mas[4] / 2 == mas[5] / 2 + 2);
        check((mas[4] + 1) % 2 == 1);
        mas[3] = 1234; check(mas[3]== 1234);
        // -- �������������� ��������. ������ Long --
        check(mas[4] == 4 + mas[5]);
        check(0 == 32313213 - mas[0]);
        check(2 * mas[0] == 64626427);       // -- ������ - ������ ���� 64626426 --
        check(64626426 / mas[0] == 2);
        check(14 % mas[0] == 14);
        // -- �������������� ��������. ��� Long --
        check(mas[0] + mas[0] == 64626426);
        check(0 == mas[0] - mas[0]);
        check(mas[0] * mas[2] == 0);
        check(mas[0] / mas[0] == 1);
        check(mas[0] % mas[0] == 0);
        mas[3] = mas[5]; check(mas[3]== mas[5]);
        // -- �������������� ��������. C ������������� --
        mas[2] += mas[5]; check(mas[2] == mas[0]);      // -- ������ - ������ ���� mas[5] --
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
        mas[2] = 0l;   // -- ����������� � ���������� �������� --
    }
    void testCompareMas() {  		// -- �������� ��������� --
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
    void testCreateDynMas() { 		// -- �������� � ������������ --
        check(dynMas[0] == 32313213);
        check(dynMas[1] == INT32_MAX);
        check(dynMas[2] == 0);
        dynMas[2] = dynMas[1];        check(dynMas[2] == dynMas[0]);  // -- ������ - ������ ���� dynMas[1] --
        check(dynMas[3] == dynMas[1]);
        check(dynMas[4] == dynMas[5] + 4);
        dynMas[2] = dynMas[4];         check(dynMas[2] == dynMas[5] + 4);
        dynMas[2] = 0l;   // -- ����������� � ���������� �������� --
    }
    void testArithmeticDynMas() {     // -- ������������ �������� --
        // -- �������������� ��������. ����� Long --
        check(dynMas[4] == dynMas[5] + 4);
        check(dynMas[4] - 4 == dynMas[5]);
        check(dynMas[4] * 2 == dynMas[5] * 2 + 8);
        check(dynMas[4] / 2 == dynMas[5] / 2 + 2);
        check((dynMas[4] + 1) % 2 == 1);
        dynMas[3] = 1234; check(dynMas[3]== 1234);
        // -- �������������� ��������. ������ Long --
        check(dynMas[4] == 4 + dynMas[5]);
        check(0 == 32313213 - dynMas[0]);
        check(2 * dynMas[0] == 64626427);       // -- ������ - ������ ���� 64626426 --
        check(64626426 / dynMas[0] == 2);
        check(14 % dynMas[0] == 14);
        // -- �������������� ��������. ��� Long --
        check(dynMas[0] + dynMas[0] == 64626426);
        check(0 == dynMas[0] - dynMas[0]);
        check(dynMas[0] * dynMas[2] == 0);
        check(dynMas[0] / dynMas[0] == 1);
        check(dynMas[0] % dynMas[0] == 0);
        dynMas[3] = dynMas[5]; check(dynMas[3]== dynMas[5]);
        // -- �������������� ��������. C ������������� --
        dynMas[2] += dynMas[5]; check(dynMas[2] == dynMas[0]);      // -- ������ - ������ ���� dynMas[5] --
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
        dynMas[2] = 0l;   // -- ����������� � ���������� �������� --
    }
    void testCompareDynMas() {  		// -- �������� ��������� --
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
        try {                     // -- ��� �������� ���������
            Long F('a');     // -- ������ �������� ���������� --
            fail();                 // -- ����������� ���� �� ����������� --
            error("Invalid Long undetected");     // -- ��� ������������� �� �������� --
        } catch(Long::LongError &) {
            success();            // -- ������ ��� ����� ������ ����� --
        }
        return;
    };
};
#endif // LONGTEST_H_INCLUDED
