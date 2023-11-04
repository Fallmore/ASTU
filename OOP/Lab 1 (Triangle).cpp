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

class Triangle {
private:
	float side1, side2, side3;

	// Виды треугольника
	enum Sides {
		Scalene, // Разносторонний
		Isosceles, // Равнобедренный
		Common, // Обыкновенный
		Egypt // Египетский
	};
	enum Angles {
		Rectengular, // Прямоугольный
		Obtuse, // Тупоугольный
		Acute // Остроугольный
	};
	Sides sideType;
	Angles angleType;

	string warnings[1]{
		"Нерправильные данные! Повторите ввод: "
	};
	string errors[2]{
		"Неправильная сторона",
		"Стороны не удовлетворяют условию существования треугольника"
	};
	void SetForms() {
		sideType = FormSides();
		angleType = FormAngles();
	}
	//Проверка на неправильную сторону
	void WrongSide(const float a) const {
		if (a <= 0) throw underflow_error(errors[0]);
	}
	// Проверка на существование
	void Exist(const float a, const float b, const float c) const {
		WrongSide(a), WrongSide(b), WrongSide(c);
		if (a + b <= c || a + c <= b || b + c <= a) throw invalid_argument(errors[1]);
	}
	// Проверка ввода
	float Check() const {
		string waste;
		float data;
		while (!(cin >> data)) {
			cin.clear(); getline(cin, waste);
			cout << warnings[0];
		}
		return data;
	}
	// Проверка на принадлежность числа диапазону
	bool range(const float a, const float b, const float eps = 0.001) const noexcept {
		return (a <= b + eps && a >= b - eps);
	}

public:
	Triangle() : side1(1), side2(1), side3(1), sideType(FormSides()), angleType(FormAngles()) {};
	Triangle(const float a, const float b, const float c) {
		Exist(a, b, c);
		side1 = a, side2 = b, side3 = c, sideType = FormSides(), angleType = FormAngles();
	}
	Triangle(const float a) : side1(a), side2(a), side3(a), sideType(FormSides()), angleType(FormAngles()) {};

	void Read();	                                    // Ввод с клавиатуры
	void Display() const noexcept;	// Вывод на экран
	// Возвращает строку данных полей
	string toString() const noexcept {
		return to_string(side1) + " " + to_string(side2) + " " + to_string(side3);
	}
	// Изменение полей класса
	void SetSide1(float a) {
		WrongSide(a);
		side1 = a;
		SetForms();
	}
	void SetSide2(float a) {
		WrongSide(a);
		side2 = a;
		SetForms();
	}
	void SetSide3(float a) {
		WrongSide(a);
		side3 = a;
		SetForms();
	}
	// Получение полей
	float GetSide1() const noexcept {
		return side1;
	}
	float GetSide2()const noexcept {
		return side2;
	}
	float GetSide3() const noexcept {
		return side3;
	}
	// Вычисление периметра
	float Perimetr() const {
		return side1 + side2 + side3;
	}
	// Вычисление площади
	float Square() const {
		float p = Perimetr() / 2;
		return sqrt(p * (p - side1) * (p - side2) * (p - side3));
	}
	// Определение вида сторон треугольника
	Sides FormSides() {
		if (side1 == side2 && side2 == side3) return Common;
		else if (side1 == side2 || side2 == side3 || side1 == side3) return Isosceles;
		else if (side1 + side2 + side3 == 12) return Egypt;
		else return Scalene;
	}
	// Определение вида углов треугольника
	Angles FormAngles() {
		float ang1, ang2, ang3;
		ang1 = AngleSide1(), ang2 = AngleSide2(), ang3 = AngleSide3();

		if (range(ang1, 90) || range(ang2, 90) || range(ang3, 90))
			return Rectengular;
		else if (ang1 < 90 && ang2 < 90 && ang3 < 90) return Acute;
		else return Obtuse;
	}
	// Вычисление высоты на сторону 1
	float HighSide1() const {
		return 2 * Square() / side1;
	}
	float HighSide2() const {
		return 2 * Square() / side2;
	}
	float HighSide3() const {
		return 2 * Square() / side3;
	}
	//Вычисление угла напротив стороны 1
	float AngleSide1() const {
		return acos((side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3)) * 180 / M_PI;
	}
	float AngleSide2() const {
		return acos((side1 * side1 + side3 * side3 - side2 * side2) / (2 * side1 * side3)) * 180 / M_PI;
	}
	float AngleSide3() const {
		return acos((side1 * side1 + side2 * side2 - side3 * side3) / (2 * side2 * side1)) * 180 / M_PI;
	}
	// Сравнение площади
	int CompareSquares(Triangle tr) const {
		if (Square() < tr.Square()) return -1;
		else if (Square() > tr.Square()) return 1;
		return 0;
	}
	// Сравнение периметров
	int ComparePerimetrs(Triangle tr) const {
		if (Perimetr() < tr.Perimetr()) return -1;
		else if (Perimetr() > tr.Perimetr()) return 1;
		return 0;
	}
	// Определение подобия
	bool Similarity(Triangle tr) const {
		vector<float>  vc1 = { side1, side2, side3 }, vc2 = { tr.side1, tr.side2, tr.side3 };
		sort(vc1.begin(), vc1.end()), sort(vc2.begin(), vc2.end());
		return (range(vc1[0] / vc2[0], vc1[1] / vc2[1]) && range(vc1[1] / vc2[1], vc1[2] / vc2[2]));
	}
};

void Triangle::Read() {
	cout << "\nВведите стороны треугольника:\n";
	float a, b, c;
	a = Check();
	b = Check();
	c = Check();
	Exist(a, b, c);
	SetSide1(a), SetSide2(b), SetSide3(c);
}

void Triangle::Display() const noexcept {
	cout << "\nПервая сторона: " << side1;
	cout << "\nВторая сторона: " << side2;
	cout << "\nТретья сторона: " << side3;

	if (sideType == Scalene) cout << "\nРазносторонний ";
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
	a = tr.GetSide1(), b = tr.GetSide2(), c = tr.GetSide3();
	assert(a == 13);
	assert(b == 13);
	assert(c == 13);

	cout << "\n\nRead() *с вложенной SetSide()* и GetSide()";
	tr.Read();
	a = tr.GetSide1(), b = tr.GetSide2(), c = tr.GetSide3();
	assert(a != 13);
	assert(b != 13);
	assert(c != 13);

	cout << "\nSimilarity()";
	test_tr2 = tr;
	assert(test_tr2.Similarity(tr) == 1);
	tr = rtr;
	assert(rtr.Similarity(tr) == 1);

	cout << "\n\n----------------Рассчёты------------------\n\n"
		<< "Perimetr();";
	a = tr.GetSide1(), b = tr.GetSide2(), c = tr.GetSide3();
	assert(tr.Perimetr() == a + b + c);
	cout << "\nSquare();";
	float p = tr.Perimetr() / 2;
	assert(tr.Square() == sqrt(p * (p - a) * (p - b) * (p - c)));
	cout << "\n\nHighSide();";
	assert(tr.HighSide1() == 2 * tr.Square() / a);
	assert(tr.HighSide2() == 2 * tr.Square() / b);
	assert(tr.HighSide3() == 2 * tr.Square() / c);

	cout << "\nAngleSide();";
	assert(tr.AngleSide1() == static_cast<float>(acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / M_PI));
	assert(tr.AngleSide2() == static_cast<float>(acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / M_PI));
	assert(tr.AngleSide3() == static_cast<float>(acos((a * a + b * b - c * c) / (2 * b * a)) * 180 / M_PI));

	cout << "\n\n----------------Сравнение------------------\n\n"
		<< "tr.toString() (стороны): " << tr.toString()
		<< "\n\ntr.ComparePerimetrs(test_tr1(3,4,6));";
	if (tr.Perimetr() < test_tr1.Perimetr()) assert(tr.ComparePerimetrs(test_tr1) == -1);
	else if (tr.Perimetr() > test_tr1.Perimetr()) assert(tr.ComparePerimetrs(test_tr1) == 1);
	else assert(tr.ComparePerimetrs(test_tr1) == 0);

	cout << "\n\nCompareSquares(test_tr1(3,4,6));";
	if (tr.Square() < test_tr1.Square()) assert(tr.CompareSquares(test_tr1) == -1);
	else if (tr.Square() > test_tr1.Square()) assert(tr.CompareSquares(test_tr1) == 1);
	else assert(tr.CompareSquares(test_tr1) == 0);

	cout << "\n\nSimilarity(test_tr1(3,4,6));";
	assert(tr.Similarity(test_tr1) == test_tr1.Similarity(tr));
}

void TestsMas(Triangle* trMas) {
	cout << "\n\nМассивы объектов\n\n"
		<< "----------------Сравнение------------------\n\n"
		<< "trMas[1].toString() (стороны): " << trMas[1].toString()
		<< "\n\ntrMas[1].ComparePerimetrs(trMas[0]);";
	if (trMas[1].Perimetr() < trMas[0].Perimetr()) assert(trMas[1].ComparePerimetrs(trMas[0]) == -1);
	else if (trMas[1].Perimetr() > trMas[0].Perimetr()) assert(trMas[1].ComparePerimetrs(trMas[0]) == 1);
	else assert(trMas[1].ComparePerimetrs(trMas[0]) == 0);

	cout << "\n\nCompareSquares(trMas[0]);";
	if (trMas[1].Square() < trMas[0].Square()) assert(trMas[1].CompareSquares(trMas[0]) == -1);
	else if (trMas[1].Square() > trMas[0].Square()) assert(trMas[1].CompareSquares(trMas[0]) == 1);
	else assert(trMas[1].CompareSquares(trMas[0]) == 0);

	cout << "\n\nSimilarity(trMas[0]);";
	assert(trMas[1].Similarity(trMas[0]) == trMas[0].Similarity(trMas[1]));
}

void TestsDynamicMas(Triangle* trDynMas) {
	cout << "\n\nДинамические массивы объектов\n\n"
		<< "----------------Сравнение------------------\n\n"
		<< "trDynMas[1].toString() (стороны): " << trDynMas[1].toString()
		<< "\n\ntrDynMas[1].ComparePerimetrs(trDynMas[0]);";
	if (trDynMas[1].Perimetr() < trDynMas[0].Perimetr()) assert(trDynMas[1].ComparePerimetrs(trDynMas[0]) == -1);
	else if (trDynMas[1].Perimetr() > trDynMas[0].Perimetr()) assert(trDynMas[1].ComparePerimetrs(trDynMas[0]) == 1);
	else assert(trDynMas[1].ComparePerimetrs(trDynMas[0]) == 0);

	cout << "\n\nCompareSquares(trDynMas[0]);";
	if (trDynMas[1].Square() < trDynMas[0].Square()) assert(trDynMas[1].CompareSquares(trDynMas[0]) == -1);
	else if (trDynMas[1].Square() > trDynMas[0].Square()) assert(trDynMas[1].CompareSquares(trDynMas[0]) == 1);
	else assert(trDynMas[1].CompareSquares(trDynMas[0]) == 0);

	cout << "\n\nSimilarity(trDynMas[0]));\n";
	assert(trDynMas[1].Similarity(trDynMas[0]) == trDynMas[0].Similarity(trDynMas[1]));
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
		trMas[2], * trDynMas = new Triangle[2];

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
