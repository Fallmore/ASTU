#include <iostream>
#include <cmath>

void FullBranch(double x, double y)
{
	const double ten = 10, sthree = -3, four = 4, six = 6, p_one = 0.1; // объявляем и инициализируем константые переменные

	__asm
	{
		fld sthree			// скопировали -3 в st(0)
		fld x				// скопировали x в st(0), а -3 провалилось в st(1)
		fcomi st, st(1)		// сравниваем x с -3

		jb X_Less_s3		// если x < -3, то переходим на метку X_Less_s3
		jge X_Greater_s3	// если x >= -3, то переходим на метку X_Greater_s3

		X_Less_s3 :
		fcos					// st(0) = cos(x)
			fld x				// st(0) = x, st(1) = cos(x)
			fadd ten			// st(0) = x+10
			fdiv				// st(0) = cos(x)/(x+10)
			jmp finish			// переход к финишу

			X_Greater_s3 :	// x > -3
		fld four			// st(0) = 4, st(1) = x
			fxch			// st(0) = x, st(1) = 4 (st(0) <-> st(1))
			fcomi st, st(1)	// сравниваем x c 4
			jb X_Less_4		// если x < 4, то переходим на метку X_Less_4
			jge X_Greater_4 // если x >= 4, то переходим на метку X_Greater_4

			X_Less_4 :		// x < 4
		fmul p_one			// x * 0.1
			fldl2e			// st(0) = log2(e), st(1) = x * 0.1
			fmul			// st(0) = log2(e) * (x * 0.1)
			fld st			// st(0) = st(1) = log2(e) * (x * 0.1)
			frndint			// округлили st(0)		|	т.к. x * 0.1 в заданном диапазоне не может быть
			fsub st(1), st	// st(1) -= st(0)		|	больше 1 или меньше -1, то эти 3 строчки можно
			fxch			// st(0) <-> st(1)		|	не писать
			f2xm1			// st(0) = 2^st(0) - 1	
			fld1			// st(0) = 1, st(1) = 2^st(1) - 1, st(2) = log2(e) * (x * 0.1)
			fadd			// st(0) = 2^st(0), st(1) = log2(e) * (x * 0.1)
			fscale			// st(0) = 2^st(0) * 2^(log2(e) * (x * 0.1))
			jmp finish		// переход к финишу

			X_Greater_4 :	// x > 4
		fld six				// st(0) = 6, st(1) = x
			fxch			// st(0) <-> st(1)
			fcomi st, st(1)	// сравниваем x c 6
			jae X_Greater_6	// если x >= 6, то переходим на метку X_Greater_6
			// если x < 6, то продолжаем
			fld1				// st(0) = 1, st(1) = x
			fxch			// st(0) <-> st(1)
			fyl2x			// st(1) = st(1) * log2(x) вместе с этим выгрузился st(0) (st(0) <- st(1))
			fldl2t			// st(0) = log2(10)
			fdivp st(1), st	// log2(x)/log2(10) = lg(x)
			jmp finish		// переход к финишу

			X_Greater_6 :	// x > 6
		fsin				// st(0) = sin(x)
			fld x			// st(0) = x, st(1) = sin(x)
			fsin			// st(0) = sin(x)
			fmul			// sin^2(x)

			finish : fstp y // поместили результат в y
	}

	std::cout << "Результаты вычислений на Assembler: " << y << std::endl;

	// -- здесь вычисление формулы на С++ -- 
	if (x < -3) y = cos(x) / (x + 10);
	else if (x >= -3 && x < 4) y = exp(0.1 * x);
	else if (x >= 4 && x < 6) y = log10(x);
	else y = sin(x) * sin(x);
	std::cout << "Результаты вычислений на C++: " << y << std::endl << std::endl;
}

void UnfullBranch(double x, double y)
{
	const double ten = 10, sthree = -3, four = 4, six = 6, p_one = 0.1; // объявляем и инициализируем константые переменные

	__asm
	{
		fld sthree			// скопировали -3 в st(0)
		fld x				// скопировали x в st(0), а -3 провалилось в st(1)
		fcomi st, st(1)		// сравниваем x с -3

		jb X_Less_s3		// если x < -3, то переходим на метку X_Less_s3

		fld four			// st(0) = 4, st(1) = x
		fxch				// st(0) = x, st(1) = 4 (st(0) <-> st(1))
		fcomi st, st(1)		// сравниваем x c 4
		jb X_Less_4			// если x < 4, то переходим на метку X_Less_4

		fld six				// st(0) = 6, st(1) = x
		fxch				// st(0) <-> st(1)
		fcomi st, st(1)		// сравниваем x c 6
		jae X_Greater_6		// если x >= 6, то переходим на метку X_Greater_6
		// если x < 6, то продолжаем
		fld1				// st(0) = 1, st(1) = x
		fxch				// st(0) <-> st(1)
		fyl2x				// st(1) = st(1) * log2(x) вместе с этим выгрузился st(0) (st(0) <- st(1))
		fldl2t				// st(0) = log2(10)
		fdivp st(1), st		// log2(x)/log2(10) = lg(x)
		jmp finish			// переход к финишу

		X_Greater_6 :		// x > 6
		fsin				// st(0) = sin(x)
			fld x			// st(0) = x, st(1) = sin(x)
			fsin			// st(0) = sin(x)
			fmul			// sin^2(x)
			jmp finish		// переход к финишу

			X_Less_4 :		// x < 4 
		fmul p_one			// x * 0.1
			fldl2e			// st(0) = log2(e), st(1) = x * 0.1
			fmul			// st(0) = log2(e) * (x * 0.1)
			fld st			// st(0) = st(1) = log2(e) * (x * 0.1)
			frndint			// округлили st(0)		|	т.к. x * 0.1 в заданном диапазоне не может быть
			fsub st(1), st	// st(1) -= st(0)		|	больше 1 или меньше -1, то эти 3 строчки можно
			fxch			// st(0) <-> st(1)		|	не писать
			f2xm1			// st(0) = 2^st(0) - 1	
			fld1			// st(0) = 1, st(1) = 2^st(1) - 1, st(2) = log2(e) * (x * 0.1)
			fadd			// st(0) = 2^st(0), st(1) = log2(e) * (x * 0.1)
			fscale			// st(0) = 2^st(0) * 2^(log2(e) * (x * 0.1))
			jmp finish		// переход к финишу

			X_Less_s3 :		// x < -3
		fcos				// st(0) = cos(x)
			fld x			// st(0) = x, st(1) = cos(x)
			fadd ten		// st(0) = x+10
			fdiv			// st(0) = cos(x)/(x+10)

			finish : fstp y // поместили результат в y
	}

	std::cout << "Результаты вычислений на Assembler: " << y << std::endl;

	// -- здесь вычисление формулы на С++ -- 
	if (x < -3) y = cos(x) / (x + 10);
	if (x >= -3 && x < 4) y = exp(0.1 * x);
	if (x >= 4 && x < 6) y = log10(x);
	if (x >= 6) y = sin(x) * sin(x);

	std::cout << "Результаты вычислений на C++: " << y << std::endl << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");	// установка русского алфавита
	// если x < -3, то y = cos(x)/(x+10)
	// если -3 <= x < 4, то y = e^(0.1x)
	// если 4 <= x < 6, то y = lg(x)
	// если x >= 6, то y = sin^2(x)

	// -- тестовые значения --
	// для x = -11, ожидается ответ -0.0044257
	// для x = -3, ожидается ответ 0.740818
	// для x = 1, ожидается ответ 1.10517
	// для x = 4, ожидается ответ 0.60206
	// для x = 5, ожидается ответ 0.69897
	// для x = 6, ожидается ответ 0.078073
	// для x = 10, ожидается ответ 0.295959

	int choice; // объявляем переменную выбора решения
	double x = 0, y = 0; // объявляем переменные и инициализируем в ноль

	std::cout << "\nСамодуров Вячеслав. Лабораторная работа № 11-12. Вариант №16(1).\n\n";

	std::cout << "Введите способ решения:\n1.Полное ветвление\n2.Краткая форма ветвления\n\nВвод: "; std::cin >> choice;
	if (std::cin.good())
		std::cout << "Введите x: ";   std::cin >> x;	//ввод значения x

	switch (choice)
	{
	case 1:
		FullBranch(x, y);
		break;
	case 2:
		UnfullBranch(x, y);
		break;
	default:
		break;
	}
	return 0;
}