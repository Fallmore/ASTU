#include <iostream>
#define _USE_MATH_DEFINES


//------------------------------------------------№1----------------------------------------------------------

void calculate(float a, float b, float c, float d, float resa, float resc)
{
	__asm
	{
		fld c			// st(0) = c
		fld d			// st(0) = d , st(1) = c
		fmul			// st(0) = c * d

		fld c			// st(0) = c , st(1) = c * d
		fdivr			// st(0) = st(0) / st(1)
		fstp resa		// resa = st(0)
	}

	printf_s("Результаты вычислений на Assembler: %f\n", resa);

	// -- здесь вычисления на С++ -- 
	resc = (a / c) * (b / d) - (a * b - c) / (c * d);

	printf_s("Результаты вычислений на C++: %f\n\n", resc);
}

int main()
{

	setlocale(LC_ALL, "Russian");	// установка русского алфавита

	// Задание №1
	// a/c * b/d - (ab-c)/cd

	// -- тестовые значения --
	// для a = 3, b = 5, c = 2, d = 3 ожидается ответ 0.333...
	// для a = 1, b = -2, c = 6, d = -1 ожидается ответ -1
	// для a = 2, b = 1, c = 4.3, d = 2.7 ожидается ответ 0,370370

	int choice = 0;
	float a, b, c, d, resa = 0, resc = 0;	// объявляем переменные


	std::cout << "Самодуров Вячеслав. Лабораторная работа № 17-18. Вариант №16.\n\n"
		<< R"(
Введите способ передачи данных:
1. Обычно (через С++)
2. В ассемблере

Ввод: )"; std::cin >> choice;
	std::cout << "Введите 4 числа: "; std::cin >> a; std::cin >> b;	//ввод значений a и b
	std::cin >> c; std::cin >> d;	//ввод значений c и d

	if (choice == 1)
		calculate(a, b, c, d, resa, resc);
	else 
		__asm {
		push resc
		push resa
		push d
		push c
		push b
		push a
		call calculate
		add esp, 24
	}
	return 0;
}

//------------------------------------------------№2----------------------------------------------------------

#include <math.h>

//void calculate(float x, float resa, float resc)
//{
//	__asm
//	{
//		fldln2			// st(0) = ln(2)
//		fld1			// st(0) = 1,	st(1) = ln(2)
//		fld x			// st(0) = x,	st(1) = 1,	st(2) = ln(2)
//		fyl2x			// st(0) = log2(x)
//		fmul			// st(0) = log2(x) * ln(2) = log2(x)/log2(e) = ln(x)
//
//		fmul st, st		// st(0) = ln^2(x)
//		fld st			// скопировали st(0) = st(1)
//		fld1			// st(0) = 1,	st(1) = st(2)
//		fadd			// st(0) = ln^2(x)+1,	st(1) = ln^2(x)
//
//		fldln2			// st(0) = ln(2),	st(1) = ln^2(x)+1,	st(2) = ln^2(x)
//		fld1			// st(0) = 1,	st(1) = ln(2),	st(2) = ln^2(x)+1,	st(3) = ln^2(x)
//		fld x			// st(0) = x,	st(1) = 1,	st(2) = ln(2),	st(3) = ln^2(x)+1,	st(4) = ln^2(x)
//		fmul st, st		// st(0) = x^2,		st(1) = 1,	st(2) = ln(2),	st(3) = ln^2(x)+1,	st(4) = ln^2(x)
//		fyl2x			// st(0) = log2(x^2),	st(1) = ln(2),	st(2) = ln^2(x)+1,	st(3) = ln^2(x)
//		fmul			// st(0) = log2(x^2) * ln(2) = log2(x^2)/log2(e) = ln(x^2),	st(1) = ln^2(x)+1,	st(2) = ln^2(x)
//
//		fdivr			// st(0) =  ln(x^2) / (ln^2(x)+1),	st(1) = ln^2(x)
//
//		fxch st(1)		// st(0) <-> st(1)
//		fld x			// st(0) = x,	st(1) = ln^2(x),	st(2) = ln(x^2) / (ln^2(x)+1)
//
//		fdiv			// st(0) = ln^2(x) / x
//
//		fadd			// st(0) = ln^2(x) / x + ln(x^2) / (ln^2(x)+1)
//
//		fstp resa		// resa = st(0)
//	}
//
//	printf_s("Результаты вычислений на Assembler: %f\n", resa);
//
//	// -- здесь вычисления на С++ -- 
//	resc = (log(x) * log(x)) / x + log(x * x) / (1 + log(x) * log(x));
//
//	printf_s("Результаты вычислений на C++: %f\n\n", resc);
//}
//
//int main()
//{
//
//	setlocale(LC_ALL, "Russian");	// установка русского алфавита
//
//	// Задание №2
//	// ln^2(x)/x + ln(x^2)/(1+ln^2(x))
//
//	// -- тестовые значения --
//	// для x = 3 ожидается ответ 1,397910
//	// для x = 5.2 ожидается ответ 1,409541	
//
//	int choice = 0;
//	float x, resa = 0, resc = 0;	// объявляем переменные
//
//
//	std::cout << "Самодуров Вячеслав. Лабораторная работа № 17-18. Вариант №16.\n\n"
//		<< R"(
//Введите способ передачи данных:
//1. Обычно (через С++)
//2. В ассемблере
//
//Ввод: )"; std::cin >> choice;
//	std::cout << "Введите x: "; std::cin >> x;	//ввод значения x
//
//	if (choice == 1)
//		calculate(x, resa, resc);
//	else 
//		__asm {
//		push resc
//		push resa
//		push x
//		call calculate
//		add esp, 12
//	}
//	return 0;
//}

//------------------------------------------------№3----------------------------------------------------------


//void ringSquare(float r, float R, float resa, float resc)
//{
//	__asm
//	{
//		fld r				// st(0) = r
//		fld R				// st(0) = R,	st(1) = r
//
//		fcomi st, st(1)		// сравниваем R c r
//		jb finish			// если R < r, то заканчиваем вычисления
//		js finish			// если < 0, то заканчиваем вычисления
//		jz finish			// если = 0, то заканчиваем вычисления
//
//		fxch
//		fcomi st, st(1)		// сравниваем r c R
//		jae finish			// если r >= R, то заканчиваем вычисления
//		js finish			// если < 0, то заканчиваем вычисления
//		jz finish			// если = 0, то заканчиваем вычисления
//
//		// если r < R, то продолжаем
//		fmul st, st			// st(0) = r^2
//		fxch				// st(0) <-> st(1)
//		fmul st, st			// st(0) - R^2
//
//		fsubr				// st(0) -= st(1)
//		fldpi				// st(0) = PI
//		fmul				// st(0) = PI*(R^2-r^2)
//
//		fstp resa
//		finish :			// конец
//	}
//
//	printf_s("Результаты вычислений на Assembler: %f\n", resa);
//
//	// -- здесь вычисления на С++ -- 
//	if (r < R && r > 0 && R > 0) resc = static_cast<float>(M_PI) * (R * R - r * r);
//
//	printf_s("Результаты вычислений на C++: %f\n\n", resc);
//}
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");	// установка русского алфавита
//
//	// Задание №3
//	// Найти площадь кольца, внутренний радиус которого равен r, 
//	// а внешний - заданному числу R (R>r).
//
//	// -- тестовые значения --
//	// для r = 1, R = 3 ожидается ответ 25,132742
//	// для r = 4, R = 8 ожидается ответ 150,796448
//
//	int choice = 0;
//	float r, R, resa = 0, resc = 0;	// объявляем переменные
//
//	std::cout << "Самодуров Вячеслав. Лабораторная работа № 17-18. Вариант №16.\n\n"
//		<< R"(
//Введите способ передачи данных:
//1. Обычно (через С++)
//2. В ассемблере
//
//Ввод: )"; std::cin >> choice;
//	std::cout << "Введите r и R (r < R): "; std::cin >> r; std::cin >> R;	// ввод значений r и R
//
//	if (choice == 1)
//		ringSquare(r, R, resa, resc);
//	else
//		__asm {
//		push resc
//		push resa
//		push R
//		push r
//		call ringSquare
//		add esp, 16
//	}
//
//	return 0;
//}
