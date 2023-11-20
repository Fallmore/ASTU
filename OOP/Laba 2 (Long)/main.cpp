#include "Longtype.h"

void Tests() {
    try {
        Long a = 32313213;
        assert(a == 32313213);
        Long b = INT32_MAX;
        assert(b == INT32_MAX);
        Long c;
        assert(c == 0);
        Long d(b);
        assert(d == b);
        Long e("234234234234234");
        Long f("234234234234230");
        // Знаки сравнения
        assert(e < f == false);
        assert(e > f == true);
        assert(e <= f == false);
        assert(e >= f == true);
        assert(e <= f + 4 == true);
        assert(e >= f + 4 == true);
        assert(e != f == true);
        assert(c < 1 == true);
        assert(c > 1 == false);
        assert(c >= 1 == false);
        assert(c <= 1 == true);
        assert(c != 1 == true);
        assert(1 < c == false);
        assert(1 > c == true);
        assert(1 >= c == true);
        assert(1 <= c == false);
        assert(1 != c == true);
        // Арифметические операции. Слева Long
        assert(e == f + 4);
        assert(e - 4 == f);
        assert(e * 2 == f * 2 + 8);
        assert(e / 2 == f / 2 + 2);
        assert((e + 1) % 2 == 1);
        d = 1234; assert(d == 1234);
        // Арифметические операции. Справа Long
        assert(e == 4 + f);
        assert(0 == 32313213 - a);
        assert(2 * a == 64626426);
        assert(64626426 / a == 2);
        assert(14 % a == 14);
        // Арифметические операции. Оба Long
        assert(a + a == 64626426);
        assert(0 == a - a);
        assert(a * c == 0);
        assert(a / a == 1);
        assert(a % a == 0);
        d = f; assert(d == f);
        // Арифметические операции. C присваиванием
        c += f; assert(c == f);
        c += 4; assert(c == e);
        c -= 4; assert(c == f);
        c -= f - 1; assert(c == 1);
        c *= 2; assert(c == 2);
        c *= a; assert(c == 64626426);
        c /= a; assert(c == 2);
        c /= 2; assert(c == 1);
        c %= 6; assert(c == 1);
        c %= a; assert(c == 1);
        ++c; assert(c == 2);
        c++; assert(c == 3);
        --c; assert(c == 2);
        c--; assert(c == 1);
        cout << "Тест с переменными пройден!\n";
    } catch (const exception& e) {
        cerr << e.what();
    }
}
void TestsMas() {
    try {
        Long mas[6];
        mas[0] = 32313213;
        assert(mas[0] == 32313213);
        mas[1] = INT32_MAX;
        assert(mas[1] == INT32_MAX);
        assert(mas[2] == 0);
        mas[3] = mas[1];
        assert(mas[3] == mas[1]);
        Long a("234234234234234");
        Long b("234234234234230");
        mas[4] = a;
        mas[5] = b;
        // Знаки сравнения
        assert(mas[4] < mas[5] == false);
        assert(mas[4] > mas[5] == true);
        assert(mas[4] <= mas[5] == false);
        assert(mas[4] >= mas[5] == true);
        assert(mas[4] <= mas[5] + 4 == true);
        assert(mas[4] >= mas[5] + 4 == true);
        assert(mas[4] != mas[5] == true);
        assert(mas[2] < 1 == true);
        assert(mas[2] > 1 == false);
        assert(mas[2] >= 1 == false);
        assert(mas[2] <= 1 == true);
        assert(mas[2] != 1 == true);
        assert(1 < mas[2] == false);
        assert(1 > mas[2] == true);
        assert(1 >= mas[2] == true);
        assert(1 <= mas[2] == false);
        assert(1 != mas[2] == true);
        // Арифметические операции. Слева Long
        assert(mas[4] == mas[5] + 4);
        assert(mas[4] - 4 == mas[5]);
        assert(mas[4] * 2 == mas[5] * 2 + 8);
        assert(mas[4] / 2 == mas[5] / 2 + 2);
        assert((mas[4] + 1) % 2 == 1);
        mas[3] = 1234; assert(mas[3]== 1234);
        // Арифметические операции. Справа Long
        assert(mas[4] == 4 + mas[5]);
        assert(0 == 32313213 - mas[0]);
        assert(2 * mas[0] == 64626426);
        assert(64626426 / mas[0] == 2);
        assert(14 % mas[0] == 14);
        // Арифметические операции. Оба Long
        assert(mas[0] + mas[0] == 64626426);
        assert(0 == mas[0] - mas[0]);
        assert(mas[0] * mas[2] == 0);
        assert(mas[0] / mas[0] == 1);
        assert(mas[0] % mas[0] == 0);
        mas[3] = mas[5]; assert(mas[3]== mas[5]);
        // Арифметические операции. C присваиванием
        mas[2] += mas[5]; assert(mas[2] == mas[5]);
        mas[2] += 4; assert(mas[2] == mas[4]);
        mas[2] -= 4; assert(mas[2] == mas[5]);
        mas[2] -= mas[5] - 1; assert(mas[2] == 1);
        mas[2] *= 2; assert(mas[2] == 2);
        mas[2] *= mas[0]; assert(mas[2] == 64626426);
        mas[2] /= mas[0]; assert(mas[2] == 2);
        mas[2] /= 2; assert(mas[2] == 1);
        mas[2] %= 6; assert(mas[2] == 1);
        mas[2] %= mas[0]; assert(mas[2] == 1);
        ++mas[2]; assert(mas[2] == 2);
        mas[2]++; assert(mas[2] == 3);
        --mas[2]; assert(mas[2] == 2);
        mas[2]--; assert(mas[2] == 1);
        cout << "Тест с массивами пройден!\n";
    } catch (const exception& e) {
        cerr << e.what();
    }
}
void TestsDynMas() {
    try {
        Long* dynMas = new Long[6];
        dynMas[0] = 32313213;
        assert(dynMas[0] == 32313213);
        dynMas[1] = INT32_MAX;
        assert(dynMas[1] == INT32_MAX);
        assert(dynMas[2] == 0);
        dynMas[3] = dynMas[1];
        assert(dynMas[3] == dynMas[1]);
        Long a("234234234234234");
        Long b("234234234234230");
        dynMas[4] = a;
        dynMas[5] = b;
        // Знаки сравнения
        assert(dynMas[4] < dynMas[5] == false);
        assert(dynMas[4] > dynMas[5] == true);
        assert(dynMas[4] <= dynMas[5] == false);
        assert(dynMas[4] >= dynMas[5] == true);
        assert(dynMas[4] <= dynMas[5] + 4 == true);
        assert(dynMas[4] >= dynMas[5] + 4 == true);
        assert(dynMas[4] != dynMas[5] == true);
        assert(dynMas[2] < 1 == true);
        assert(dynMas[2] > 1 == false);
        assert(dynMas[2] >= 1 == false);
        assert(dynMas[2] <= 1 == true);
        assert(dynMas[2] != 1 == true);
        assert(1 < dynMas[2] == false);
        assert(1 > dynMas[2] == true);
        assert(1 >= dynMas[2] == true);
        assert(1 <= dynMas[2] == false);
        assert(1 != dynMas[2] == true);
        // Арифметические операции. Слева Long
        assert(dynMas[4] == dynMas[5] + 4);
        assert(dynMas[4] - 4 == dynMas[5]);
        assert(dynMas[4] * 2 == dynMas[5] * 2 + 8);
        assert(dynMas[4] / 2 == dynMas[5] / 2 + 2);
        assert((dynMas[4] + 1) % 2 == 1);
        dynMas[3] = 1234; assert(dynMas[3]== 1234);
        // Арифметические операции. Справа Long
        assert(dynMas[4] == 4 + dynMas[5]);
        assert(0 == 32313213 - dynMas[0]);
        assert(2 * dynMas[0] == 64626426);
        assert(64626426 / dynMas[0] == 2);
        assert(14 % dynMas[0] == 14);
        // Арифметические операции. Оба Long
        assert(dynMas[0] + dynMas[0] == 64626426);
        assert(0 == dynMas[0] - dynMas[0]);
        assert(dynMas[0] * dynMas[2] == 0);
        assert(dynMas[0] / dynMas[0] == 1);
        assert(dynMas[0] % dynMas[0] == 0);
        dynMas[3] = dynMas[5]; assert(dynMas[3]== dynMas[5]);
        // Арифметические операции. C присваиванием
        dynMas[2] += dynMas[5]; assert(dynMas[2] == dynMas[5]);
        dynMas[2] += 4; assert(dynMas[2] == dynMas[4]);
        dynMas[2] -= 4; assert(dynMas[2] == dynMas[5]);
        dynMas[2] -= dynMas[5] - 1; assert(dynMas[2] == 1);
        dynMas[2] *= 2; assert(dynMas[2] == 2);
        dynMas[2] *= dynMas[0]; assert(dynMas[2] == 64626426);
        dynMas[2] /= dynMas[0]; assert(dynMas[2] == 2);
        dynMas[2] /= 2; assert(dynMas[2] == 1);
        dynMas[2] %= 6; assert(dynMas[2] == 1);
        dynMas[2] %= dynMas[0]; assert(dynMas[2] == 1);
        ++dynMas[2]; assert(dynMas[2] == 2);
        dynMas[2]++; assert(dynMas[2] == 3);
        --dynMas[2]; assert(dynMas[2] == 2);
        dynMas[2]--; assert(dynMas[2] == 1);
        delete[] dynMas;
        cout << "Тест с динамическими массивами пройден!\n";
    } catch (const exception& e) {
        cerr << e.what();
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    cout << "Самодуров ДИНРБ-21/2\nВариант 13\n\n\n";
    Tests();
    TestsMas();
    TestsDynMas();
    return 0;
}
