#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cassert>
#define _USE_MATH_DEFINES

#pragma pack(1)

using namespace std;

float Check() {
    float data;

    while ((!(cin >> data)))
        cin.clear(), cin.ignore();
    return data;
}

class Triangle {
  private:
    float side1, side2, side3;

    // Виды треугольника
    enum Forms {
        None,
        Versatile,
        Isosceles,
        Common,
        Egypt,
        Rectengular,
        Obtuse,
        Acute
    };
    Forms sideType, angleType;

    void SetForms() {
        sideType = FormSides();
        angleType = FormAngles();
    }

    //Проверка на неправильные данные
    bool WrongData(const float a)   {
        return a < 1;
    }

    // Проверка на существование
    bool Exist(const float a, const float b, const float c) {
        if (a + b <= c || a + c <= b || b + c <= a || WrongData(a) || WrongData(b) || WrongData(c))
            return false;
        return true;
    }
    bool Exist() {
        return (Exist(side1, side2, side3));
    }

  public:
    Triangle() : side1(0), side2(0), side3(0), sideType(None), angleType(None) {};
    Triangle(const float a, const float b, const float c) : side1(a), side2(b), side3(c), sideType(FormSides()), angleType(FormAngles()) {
        if (!Exist(a, b, c)) side1 = 6, side2 = 6, side3 = 6, sideType = None, angleType = None;
    };
    Triangle(const float a) : side1(a), side2(a), side3(a), sideType(FormSides()), angleType(FormAngles()) {};

    void Read();	// Ввод с клавиатуры
    void Display();	// Вывод на экран
    // Возвращает строку данных полей
    string toString() noexcept {
        return to_string(side1) + " " + to_string(side2) + " " + to_string(side3);
    }
    // Изменение полей класса
    void SetSide1(float a) {
        side1 = a;
        SetForms();
    }
    void SetSide2(float a) {
        side2 = a;
        SetForms();
    }
    void SetSide3(float a) {
        side3 = a;
        SetForms();
    }
    void SetTriangle(Triangle tr) noexcept {
        *this = tr;
    }
    // Получение полей
    float GetSide1() noexcept {
        return side1;
    }
    float GetSide2() noexcept {
        return side2;
    }
    float GetSide3() noexcept {
        return side3;
    }
    // Вычисление периметра
    float Perimetr() {
        return side1 + side2 + side3;
    }
    // Вычисление площади
    float Square() {
        float p = Perimetr() / 2;
        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }
    // Определение вида сторон треугольника
    Forms FormSides() {
        if (side1 == side2 && side2 == side3) return Common;
        else if (side1 == side2 || side2 == side3 || side1 == side3) return Isosceles;
        else if (side1 + side2 + side3 == 12) return Egypt;
        else return Versatile;
    }
    // Определение вида углов треугольника
    Forms FormAngles() {
        // Переменная погрешности "eps", используется только для "range"
        float ang1, ang2, ang3, eps = 0.001;
        ang1 = AngleSide1(), ang2 = AngleSide2(), ang3 = AngleSide3();

        // Проверка на принадлежность числа диапазону
        auto range = [](float a, float b, float eps) {
            return (a <= b + eps && a >= b - eps);
        };

        if (range(ang1, 90, eps) || range(ang2, 90, eps) || range(ang3, 90,eps))
            return Rectengular;
        else if (ang1 < 90 && ang2 < 90 && ang3 < 90) return Acute;
        else return Obtuse;
    }
    // Вычисление высоты
    float HighSide1() {
        return 2 * Square() / side1;
    }
    float HighSide2() {
        return 2 * Square() / side2;
    }
    float HighSide3() {
        return 2 * Square() / side3;
    }
    //Вычисление угла
    float AngleSide1() {
        return acos((side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3)) * 180 / M_PI;
    }
    float AngleSide2() {
        return acos((side1 * side1 + side3 * side3 - side2 * side2) / (2 * side1 * side3)) * 180 / M_PI;
    }
    float AngleSide3() {
        return acos((side2 * side2 + side2 * side2 - side3 * side3) / (2 * side2 * side1)) * 180 / M_PI;
    }
    // Сравнение площади
    int CompareSquares(Triangle tr) {
        if (Square() < tr.Square()) return -1;
        else if (Square() > tr.Square()) return 1;
        return 0;
    }
    // Сравнение периметров
    int ComparePerimetrs(Triangle tr) {
        if (Perimetr() < tr.Perimetr()) return -1;
        else if (Perimetr() > tr.Perimetr()) return 1;
        return 0;
    }
    // Определение подобия
    bool Similarity(Triangle tr) {
        Triangle ltr = *this;
        vector<float>  vc1 = { ltr.side1, ltr.side2, ltr.side3 }, vc2 = { tr.side1, tr.side2, tr.side3 };
        sort(vc1.begin(), vc1.end()), sort(vc2.begin(), vc2.end());
        return (vc1[0] / vc2[0] == vc1[1] / vc2[1] && vc1[1] / vc2[1] == vc1[2] / vc2[2]);
    }
};

void Triangle::Read() {
    cout << "\nВведите стороны треугольника:\n";
    float a, b, c;
    do {
        a = Check();
        b = Check();
        c = Check();
    } while (!Exist(a,b,c));
    SetSide1(a), SetSide2(b), SetSide3(c);
}

void Triangle::Display() {
    cout << "\nПервая сторона: " << side1;
    cout << "\nВторая сторона: " << side2;
    cout << "\nТретья сторона: " << side3;

    if (sideType == Versatile) cout << "\nРазносторонний ";
    else if (sideType == Isosceles) cout << "\nРавнобедренный ";
    else if (sideType == Common) cout << "\nРавносторонний ";
    else if (sideType == Egypt) cout << "\nЕгипетский ";

    if (angleType == Rectengular) cout << "прямоугольный ";
    else if (angleType == Acute) cout << "остроугольный ";
    else if (angleType == Obtuse) cout << "тупоугольный ";

}

void Tests(Triangle tr, Triangle rtr) {
    float a, b, c;
    Triangle test_tr1(3, 4, 6), test_tr2;

    cout << "\n\nОбъекты\n\n"
         << "----------------Работа с полями------------------\n\n"
         << "Display()";
    tr.Display();

    cout << "\n\nSetSide(13) и GetSide()";
    tr.SetSide1(13), tr.SetSide2(13), tr.SetSide3(13);
    a = tr.GetSide1(), b = tr.GetSide2(), c =  tr.GetSide3();
    assert(a == 13); assert(b == 13); assert(c == 13);

    cout << "\n\nRead() *с вложенной SetSide()* и GetSide()";
    tr.Read();
    a = tr.GetSide1(), b = tr.GetSide2(),c =  tr.GetSide3();
    assert(a != 13); assert(b != 13); assert(c != 13);

    cout << "\nSimilarity()";
    test_tr2 = tr;
    assert(test_tr2.Similarity(tr) == 1);
    tr = rtr;
    assert(rtr.Similarity(tr) == 1);

    cout << "\n\n----------------Рассчёты------------------\n\n"
         << "Perimetr() = " << tr.Perimetr()
         << "\nSquare() = " << tr.Square()
         << "\n\nHighSide(): ";
    cout << tr.HighSide1() << " " << tr.HighSide2() << " " << tr.HighSide3();

    cout << "\nAngleSide(): ";
    cout << tr.AngleSide1() << " " << tr.AngleSide2() << " " << tr.AngleSide3();

    cout << "\n\n----------------Сравнение------------------\n\n"
         << "tr.toString() (стороны): " << tr.toString()
         << "\n\ntr.ComparePerimetrs(test_tr1(3,4,6))\ntest_tr1.Perimetr() = "
         << test_tr1.Perimetr()
         << "\ntr.Perimetr() = " << tr.Perimetr() << "\nresult = "
         << tr.ComparePerimetrs(test_tr1);

    cout << "\n\nCompareSquares(test_tr1(3,4,6))\ntest_tr1.Square() = "
         << test_tr1.Square()
         << "\ntr.Square() = " << tr.Square() << "\nresult = "
         << tr.CompareSquares(test_tr1);

    cout << "\n\nSimilarity(test_tr1(3,4,6))\nresult = " << tr.Similarity(test_tr1)
         << endl;
}

void TestsMas(Triangle* trMas) {
    cout << "\n\nМассивы объектов\n\n"
         << "----------------Сравнение------------------\n\n"
         << "trMas[1].toString() (стороны): " << trMas[1].toString()
         << "\n\ntrMas[1].ComparePerimetrs(trMas[0])\ntrMas[0].Perimetr() = "
         << trMas[0].Perimetr()
         << "\ntrMas[1].Perimetr() = " << trMas[1].Perimetr() << "\nresult = "
         << trMas[1].ComparePerimetrs(trMas[0]);

    cout << "\n\nCompareSquares(trMas[0])\ntrMas[0].Square() = " << trMas[0].Square()
         << "\ntrMas[1].Square() = " << trMas[1].Square() << "\nresult = "
         << trMas[1].CompareSquares(trMas[0]);

    cout << "\n\nSimilarity(trMas[0]))\nresult = " << trMas[1].Similarity(trMas[0])
         << endl;
}

void TestsDynamicMas(Triangle* trDynMas) {
    cout << "\n\nДинамические массивы объектов\n\n"
         << "----------------Сравнение------------------\n\n"
         << "trDynMas[1].toString() (стороны): " << trDynMas[1].toString()
         << "\n\ntrDynMas[1].ComparePerimetrs(trDynMas[0])\ntrDynMas[0].Perimetr() = "
         << trDynMas[0].Perimetr()
         << "\ntrDynMas[1].Perimetr() = " << trDynMas[1].Perimetr() << "\nresult = "
         << trDynMas[1].ComparePerimetrs(trDynMas[0]);

    cout << "\n\nCompareSquares(trDynMas[0])\ntrDynMas[0].Square() = "
         << trDynMas[0].Square()
         << "\ntrDynMas[1].Square() = " << trDynMas[1].Square() << "\nresult = "
         << trDynMas[1].CompareSquares(trDynMas[0]);

    cout << "\n\nSimilarity(trDynMas[0]))\nresult = "
         << trDynMas[1].Similarity(trDynMas[0]) << endl;
}

int main() {
    setlocale(0, "");
    cout << "Самодуров Вячеслав ДИНРБ-21/2\nВариант 7\n\n\n";

    /*
        Тестовые данные для проверки

        Неправильные данные:
        2, 2, 8                 //  Сумма двух сторон меньше третьей
        0, 0, 0                 //  Отсутствие сторон
        -2, 3, 1                //  Отрицательная сторона

        Правильные данные:
        3, 3, 4                         //  Равнобедренный остроугольный
        3, 4, 5                         //  Египетский прямоугольный
        1, 1, 1                          //  Равносторонний остроугольный
        8, 5, 4                         //   Разносторонний тупоугольный
        2, 1, 2                         //   Равнобедренный остроугольный
        11, 4, 8                        //  Разносторонний тупоугольный
        2, 2, sqrt(2.0f)*2  	//  Равнобедренный прямоугольный

        Пример взаимодействия с объектом

        1) Создаём объект: Triangle tr;
        2) Заполнение объекта:
            2.1) tr(...) - Через конструктор;
            2.2) tr.Read() - Ввод данных через консоль;
        3) Изменить поля объекта: tr.Setter();
        4) Получить поля бъекта: tr.Getter(), tr.Display();
        5) Провести рассчёты со сторонами: tr.Perimetr(), tr.Square(), tr.Angle(...), tr.Highs(...);
        6) Сравнение объектов одинакового типа:
            6.1) tr.ComparePerimetr(...), tr.CompareSquare(...) - Сравнение периметра и площади;
            6.2) tr.Similarity(...) - Определение подобия треугольников;
    */

    Triangle triangle1, triangle2,
             trMas[2], *trDynMas = new Triangle[2];

    // Заполнение объектов
    triangle1.Read();
    triangle2.Read();
    // Заполнение массива объектов
    trMas[0] = triangle1;
    trMas[1] = triangle2;
    // Заполнение динамического массива объектов
    trDynMas[0] = triangle1;
    trDynMas[1] = triangle2;

    cout << "\nРазмеры\nОбъекта = " << sizeof(triangle1) << endl
         << "Массива объектов = " << sizeof(trMas) << endl
         << "Динамического массива объектов = " << sizeof(trDynMas) << endl;

    // Работа с треугольниками
    Tests(triangle1, triangle2);
    TestsMas(trMas);
    TestsDynamicMas(trDynMas);

    delete[] trDynMas;
    return 0;
}
