#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");	// установка русского алфавита
	// if (x < -3.2) y = x^4+9
	// else y = 54x^4/(-5x^2+7)

	// -- тестовые значения --
	// для x = -4, ожидается ответ 265
	// для x = 0, ожидается ответ 0
	// для x = 1, ожидается ответ 27

	double x, y; // объявляем переменные
	const double condition = -3.2,
		term1 = 9.0, term2 = 7.0,
		multiplier1 = 54.0, multiplier2 = -5.0; // объявляем и инициализируем константые переменные

	std::cout << "Введите x: ";   std::cin >> x;	//ввод значения x

	__asm
	{
		fld condition		// скопировали condition в st(0)
		fld x				// скопировали x в st(0), а condition провалился в st(1)
		fcomi st, st(1)		// сравниваем x с condition

		jae X_isntLess		// если x >= -3.2, то переходим на метку X_isntLess
		// если x < -3.2, то продолжаем
		fmul x
		fmul x
		fmul x				// st(0) = x^4
		fadd term1			// st(0) = x^4 + 9
		jmp finish			// переходим на метку finish

		X_isntLess :
		fmul x					// st(0) = x^2
			fmul multiplier2	// st(0) = -5x^2
			fadd term2			// st(0) = -5x^2 + 7
			fld x				// st(0) = x, st(1) = -5x^2 + 7
			fmul x
			fmul x
			fmul x				// st(0) = x^4
			fmul multiplier1	// st(0) = 54x^4
			fdivr				// 54x^4/(-5x^2+7)

			finish : fstp y // поместили результат в y
	}

	std::cout << "\nСамодуров Вячеслав. Лабораторная работа № 09-10. Вариант №16.\n\n"
		<< "Результаты вычислений на Assembler: " << y << std::endl;

	// -- здесь вычисление формулы на С++ -- 
	x < -3.2 ? y = x * x * x * x + 9
		: y = (54 * x * x * x * x) / (-5 * x * x + 7);
	std::cout << "Результаты вычислений на C++: " << y << std::endl << std::endl;
	system("pause");
	return 0;
}