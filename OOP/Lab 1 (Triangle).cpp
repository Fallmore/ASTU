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

    // ���� ������������
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

    // �������� �� �������������
    bool Exist(const float a, const float b, const float c) {
        if (a + b <= c || a + c <= b || b + c <= a || a == 0 || b == 0 || c == 0)
            return 0;
        return 1;
    }
    bool Exist() {
        float a, b, c;
        Getter(a, b, c);
        return (Exist(a, b, c));
    }

public:
    Triangle() : side1(0), side2(0), side3(0), sideType(None), angleType(None) {};
    Triangle(const float a, const float b, const float c) : side1(a), side2(b), side3(c), sideType(FormSides()), angleType(FormAngles()) {
        if (!Exist(a, b, c)) side1 = 6, side2 = 6, side3 = 6, sideType = None, angleType = None;
    };
    Triangle(const float a) : side1(a), side2(a), side3(a), sideType(FormSides()), angleType(FormAngles()) {};
    Triangle(Triangle& tr) : side1(tr.side1), side2(tr.side2), side3(tr.side3), sideType(tr.FormSides()), angleType(tr.FormAngles()) {};

    void Read();	// ���� � ����������

    void Display();	// ����� �� �����

    // ���������� ������ ������ �����
    string toString() {
        return to_string(side1) + " " + to_string(side2) + " " + to_string(side3);
    }

    // ��������� ����� ������
    void Setter(float a, float b, float c) {
            side1 = a, side2 = b, side3 = c,
            sideType = FormSides(), angleType = FormAngles();


    }
    void Setter(float a) {
        side1 = a, side2 = a, side3 = a;
        sideType = FormSides();
        angleType = FormAngles();
    }
    void Setter(Triangle tr) {
        this->side1 = tr.side1, this->side2 = tr.side2, this->side3 = tr.side3,
            sideType = tr.FormSides(), angleType = tr.FormAngles();
    }

    // ��������� ����� � ����������
    void Getter(float& a, float& b, float& c) {
        a = side1, b = side2, c = side3;
    }
    // ��������� ����� � ������
    void Getter(Triangle tr) {
        Setter(tr);
    }

    // ���������� ���������
    float Perimetr() {
        return side1 + side2 + side3;
    }

    // ���������� �������
    float Square() {
        float p = Perimetr() / 2;
        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }

    // ����������� ���� ������ ������������
    Forms FormSides() {
        float a, b, c;
        Getter(a, b, c);

        if (a == b && b == c) return Common;
        else if (a == b || b == c || a == c) return Isosceles;
        else if (a + b + c == 12) return Egypt;
        else return Versatile;
    }

    // ����������� ���� ����� ������������
    Forms FormAngles() {
        float ang1, ang2, ang3, eps = 0.001;
        Angle(ang1, ang2, ang3);

        // �������� �� �������������� ����� ���������
        auto range = [](float a, float b, float eps) {
            return (a <= b + eps && a >= b - eps);
        };

        if (range(ang1, 90, eps) || range(ang2, 90, eps) || range(ang3, 90,eps))
            return Rectengular;
        else if (ang1 < 90 && ang2 < 90 && ang3 < 90) return Acute;
        else return Obtuse;
    }

    // ���������� ����� � ����������
    void Highs(float& a, float& b, float& c) {
        a = 2 * Square() / side1, b = 2 * Square() / side2, c = 2 * Square() / side3;
    }

    //���������� ����� � ����������
    void Angle(float& num1, float& num2, float& num3) {
        float a, b, c;

        // ���������� ����
        auto degree = [](float a, float b, float c) {
            return acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / M_PI;
        };

        Getter(a, b, c);
        num1 = degree(a, b, c), num2 = degree(b, a, c), num3 = degree(c, a, b);
    }

    // ��������� �������
    int CompareSquares(Triangle tr) {
        int sign = 0;
        if (this->Square() < tr.Square()) --sign;
        else if (this->Square() > tr.Square()) ++sign;
        return sign;
    }

    // ��������� ����������
    int ComparePerimetrs(Triangle tr) {
        int sign = 0;
        if (this->Perimetr() < tr.Perimetr()) --sign;
        else if (this->Perimetr() > tr.Perimetr()) ++sign;
        return sign;
    }

    // ����������� �������
    bool Similarity(Triangle tr) {
        Triangle ltr = *this;
        vector<float>  vc1 = { ltr.side1, ltr.side2, ltr.side3 }, vc2 = { tr.side1, tr.side2, tr.side3 };
        sort(vc1.begin(), vc1.end()), sort(vc2.begin(), vc2.end());
        return (vc1[0] / vc2[0] == vc1[1] / vc2[1] && vc1[1] / vc2[1] == vc1[2] / vc2[2]);
    }

};

void Triangle::Read() {
    cout << "\n������� ������� ������������:\n";
    float a, b, c;
    do {
        a = Check();
        b = Check();
        c = Check();
    } while (!Exist(a,b,c));
    Setter(a, b, c);
}

void Triangle::Display() {
    cout << "\n������ �������: " << this->side1;
    cout << "\n������ �������: " << this->side2;
    cout << "\n������ �������: " << this->side3;

    if (this->sideType == Versatile) cout << "\n�������������� ";
    else if (this->sideType == Isosceles) cout << "\n�������������� ";
    else if (this->sideType == Common) cout << "\n�������������� ";
    else if (this->sideType == Egypt) cout << "\n���������� ";

    if (this->angleType == Rectengular) cout << "������������� ";
    else if (this->angleType == Acute) cout << "������������� ";
    else if (this->angleType == Obtuse) cout << "������������ ";

}

void Tests(Triangle tr, Triangle rtr) {
    float a, b, c;
    Triangle test_tr1(3, 4, 6), test_tr2;

    cout << "\n\n�������\n\n"
        << "----------------������ � ������------------------\n\n"
        << "Display()"; tr.Display();

    cout << "\n\nSetter(13) � Getter(a,b,c)";
    tr.Setter(13); tr.Getter(a, b, c);
    assert(a == 13 && b == 13 && c == 13);

    cout << "\n\nRead() *� ��������� Setter(a,b,c)* � Getter(a,b,c)";
    tr.Read(); tr.Getter(a, b, c);
    assert(a != 13 && b != 13 && c != 13);

    cout << "\nGetter(tr) ��� test_tr2() � Setter(rtr)";
    test_tr2.Getter(tr); assert(test_tr2.Similarity(tr) == 1);
    tr.Setter(rtr); assert(rtr.Similarity(tr) == 1);

    cout << "\n\n----------------��������------------------\n\n"
         << "Perimetr() = " << tr.Perimetr()
   << "\nSquare() = " << tr.Square()
         << "\n\nHighs(): "; tr.Highs(a, b, c);
    cout << a << " " << b << " " << c;

    cout << "\nAngles(): "; tr.Angle(a, b, c);
    cout << a << " " << b << " " << c;

    cout << "\n\n----------------���������------------------\n\n"
        << "tr.toString() (�������): " << tr.toString()
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
    cout << "\n\n������� ��������\n\n"
        << "----------------���������------------------\n\n"
        << "trMas[1].toString() (�������): " << trMas[1].toString()
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
    cout << "\n\n������������ ������� ��������\n\n"
        << "----------------���������------------------\n\n"
        << "trDynMas[1].toString() (�������): " << trDynMas[1].toString()
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
    cout << "��������� �������� �����-21/2\n������� 7\n\n\n";

    /*
        �������� ������ ��� ��������

        ������������ ������:
        2, 2, 8                 //  ����� ���� ������ ������ �������
        0, 0, 0                 //  ���������� ������
        -2, 3, 1                //  ������������� �������

        ���������� ������:
        3, 3, 4                         //  �������������� �������������
        3, 4, 5                         //  ���������� �������������
        1, 1, 1                          //  �������������� �������������
        8, 5, 4                         //   �������������� ������������
        2, 1, 2                         //   �������������� �������������
        11, 4, 8                        //  �������������� ������������
        2, 2, sqrt(2.0f)*2  	//  �������������� �������������

        ������ �������������� � ��������

        1) ������ ������: Triangle tr;
        2) ���������� �������:
            2.1) tr(...) - ����� �����������;
            2.2) tr.Read() - ���� ������ ����� �������;
        3) �������� ���� �������: tr.Setter();
        4) �������� ���� ������: tr.Getter(), tr.Display();
        5) �������� �������� �� ���������: tr.Perimetr(), tr.Square(), tr.Angle(...), tr.Highs(...);
        6) ��������� �������� ����������� ����:
            6.1) tr.ComparePerimetr(...), tr.CompareSquare(...) - ��������� ��������� � �������;
            6.2) tr.Similarity(...) - ����������� ������� �������������;
    */

    Triangle triangle1, triangle2,
    trMas[2], *trDynMas = new Triangle[2];

    // ���������� ��������
    triangle1.Read(); triangle2.Read();
    // ���������� ������� ��������
    trMas[0].Setter(triangle1); trMas[1].Setter(triangle2);
    // ���������� ������������� ������� ��������
    trDynMas[0].Setter(triangle1); trDynMas[1].Setter(triangle2);

    cout << "\n�������\n������� = " << sizeof(triangle1) << endl
            << "������� �������� = " << sizeof(trMas) << endl
            << "������������� ������� �������� = " << sizeof(trDynMas) << endl;

    // ������ � ��������������
    Tests(triangle1, triangle2);
    TestsMas(trMas);
    TestsDynamicMas(trDynMas);

    delete[] trDynMas;
    return 0;
}
