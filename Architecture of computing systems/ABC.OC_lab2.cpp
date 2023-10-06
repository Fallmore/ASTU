#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");	// установка русского алфавита
	// Вычислить: a/c * b/d - (ab-c)/cd 
	// если упростить, то будет c/cd, но для лучшего освоения деления и умножения будем решать без упрощения
	//-- тестовые значения --
	// для a = 2, b = 1, c = 1, d = 1 ожидается ответ 1
	// для a = 6, b = 5, c = 2, d = 1 ожидается ответ 1

	int a, b, c, d; // инициализация переменных
	int drob1 = 0,  // переменная для хранения дроби a/c
		drob2 = 0,  // переменная для хранения дроби b/d
		drob3 = 0,  // переменная для хранения дроби (ab-c)/cd
		ab, 	    // переменная для хранения a*b
		cd,  	    // переменная для хранения c*d
		resa = 0; 	// результат вычисления выражения на Ассемблере
	int  resc; // результат вычисления выражения на C++

	cout << "Введите a: ";   cin >> a;	//ввод значения a
	cout << "Введите b: ";   cin >> b;	//ввод значения b
	cout << "Введите c: ";   cin >> c;	//ввод значения c
	cout << "Введите d: ";   cin >> d;	//ввод значения d

	__asm
	{
		mov eax, a		// поместили a в регистр eax

		mov ebx, b		// поместили b в регистр ebx
		imul ebx, a		// значение регистра ebx умножили на a 
		mov ab, ebx		// содержимое регистра ebx занесли в ячейку ab

		mov ecx, c		// поместили c в регистр ecx
		imul ecx, d		// значение регистра ecx умножили на d
		mov cd, ecx		// содержимое регистра ecx занесли в ячейку cd 

		cdq				// преобразовали двойное слово в учетверённое
		idiv c			// edx:eax := eax:edx / с с учётом знака
		mov drob1, eax  // содержимое регистра eax занесли в ячейку drob1 

		mov eax, b		// поместили c в регистр eax
		idiv d			// edx:eax := eax:edx / d с учётом знака
		mov drob2, eax	// содержимое регистра eax занесли в ячейку drob2 

		mov eax, ab		// поместили a*b в регистр eax
		sub eax, c		// eax := eax - c
		idiv cd			// eax := eax/(c*d)
		mov drob3, eax  // содержимое регистра eax занесли в ячейку drob3 

		mov eax, drob1  // поместили a/c в регистр eax
		imul eax, drob2 // eax := eax * b/d
		sub eax, drob3  // eax := eax - (ab-c)/cd

		// -- ответ готов --
		mov resa, eax;	// содержимое регистра eax занесли в ячейку resa
	}

	cout << "\nСамодуров Вячеслав. Лабораторная работа № 03-04. Вариант №16.\n\n"
		<< "Результаты вычислений на Assembler: " << endl
		<< "Слагаемое ab = " << ab << endl
		<< "Делитель cd = " << cd << endl
		<< "Первая дробь drob1 = " << drob1 << endl
		<< "Вторая дробь drob2 = " << drob2 << endl
		<< "Третья дробь drob3 = " << drob3 << endl
		<< "Результат resa = " << resa << endl << endl;

	// -- здесь вычисление формулы на С++ -- 
	ab = a * b;
	cd = c * d;
	drob1 = a / c;
	drob2 = b / d;
	drob3 = (ab - c) / cd;
	resc = drob1 * drob2 - drob3;
	cout << "Результаты вычислений на C++: " << endl
		<< "Слагаемое ab = " << ab << endl
		<< "Делитель cd = " << cd << endl
		<< "Первая дробь drob1 = " << drob1 << endl
		<< "Вторая дробь drob2 = " << drob2 << endl
		<< "Третья дробь drob3 = " << drob3 << endl
		<< "Результат resc = " << resc << endl << endl;
	system("pause");
	return 0;
}
