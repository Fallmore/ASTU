#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <windows.h>
#include <wchar.h>
#include <conio.h>

using namespace std;

void Color(int mode) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (mode == 1) SetConsoleTextAttribute(hStdOut, (WORD)((15 << 4) | 0));		// белый фон; черный текст
	if (mode == 0) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 2));		// черный фон; зелёный текст
	if (mode == 2) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 2));		// черный фон; зеленый текст
	if (mode == 3) SetConsoleTextAttribute(hStdOut, (WORD)((15 << 4) | 4));		// черный фон; красный текст
}

// Функция покраски текста
void Paint(const char text[], int mode)
{
	Color(mode);
	wcout << text;
	Color(0);
}

int CheckEnter(int& choice, int NumberOfChoice, int rep)
{
	cin.clear();
	rep = 0;
	do
	{
		if (!(cin >> choice))
		{
			if (rep < 1) cout << "\nЭто не число" << endl << "Введите повторно: ";
			rep = 1;
		}
	} while (getchar() != '\n');
	if (rep != 0) CheckEnter(choice, NumberOfChoice, rep);
	return choice;
}

void EnterLength(int& N, int& M)
{
	cout << "\nВведи размер прямоугольной матрицы.\n";
	do
	{
		cout << "Число строк: ";
		CheckEnter(N, 0, 0);
		cout << "Число столбцов: ";
		CheckEnter(M, 0, 0);
		if (N < 1 || M < 1) cout << "\nРазмер должен быть больше 0\n";
		else if (N > 26 || M > 26) cout << "\nИзвините, но размер слишком большой\n";
		else if (N == M) cout << "\nМатрица должна быть прямоугольной\n";
	} while (N < 1 || N > 26 || M < 1 || M > 26 || N == M);
	cout << "\nСтроки = " << N << "\nСтолбцы = " << M << endl;
}

void EnterLength(int& N)
{
	cout << "\nВведи размер квадратной матрицы: ";
	do
	{
		CheckEnter(N, 0, 0);
		if (N < 1) cout << "\nРазмер должен быть больше 0\n";
		else if (N > 26) cout << "\nИзвините, но размер слишком большой\n";
	} while (N < 1 || N > 26);
}

void EnterKeyboard(int Name[25][25], int N, int M)
{
	cout << "\nЗаполните массив\n";
	int num;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << i + 1 << "-я строка ";
			cout << j + 1 << "-й столбец: ";
			cin >> num;
			Name[i][j] = num;
		}
		cout << endl;
	}

}

void EnterRandom(int Name[25][25], int N)
{
	int a, b, num;
	do
	{
		cout << "\nВведи диапазон [a;b]: ";
		cin >> a >> b;
		if (a > b) cout << "Левая граница не может быть больше правой\n";
		else if (a == b) cout << "Нежелательный диапазон\n";
	} while (a >= b);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			num = a + rand() % (b - a + 1);
			Name[i][j] = num;
		}
	}
}

void EnterFromFile(int Name[25][25], int N, int M, string File)
{
	fstream out(File);
	if (out.is_open())
	{

		int count = 0, temp;
		while (!out.eof())// пробегаем пока не встретим конец файла eof
		{
			out >> temp;//в пустоту считываем из файла числа
			count++;// увеличиваем счетчик числа чисел
		}
		out.clear();
		out.seekg(0, ios::beg);
		int count_space = 0;
		char symbol;
		while (!out.eof())//на всякий случай цикл ограничиваем концом файла
		{
			//теперь нам нужно считывать не числа, а посимвольно считывать данные
			out.get(symbol);//считали текущий символ
			if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
			if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
		}
		int n = count / (count_space + 1);//число строк
		int m = count_space + 1;
		if (n < N || m < M)
		{
			cout << "\nВ файле меньше чисел, чем размер матрицы";
			EnterLength(N, M);
			EnterFromFile(Name, N, M, File);
		}
	}
	out.clear();
	out.seekg(0, ios::beg);
	string waste;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			out >> Name[i][j];
		}
		getline(out, waste);
	}
}

void Output(int Name[25][25], int N, int M)
{
	cout << "\nСодержимое матрицы: \n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << setw(6) << Name[i][j] << " ";
		}
		cout << "\n";
	}
}

void OutputInFile(int Name[25][25], int N, int M)
{
	string file2 = "Output.txt";
	fstream filein(file2);
	filein.seekg(0, ios::end);
	if (filein.is_open())
	{
		cout << "\nЗаполнение файла " << file2 << "...";
		filein << "\nМатрица:\n";
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				filein << setw(6) << Name[i][j] << " ";
			}
			filein << endl;
		}
		cout << "\nФайл заполнен\n";
	}
	else cout << "\nФайл  не заполнен\n";
}

void PositiveLine(int Name[25][25], int N, int M)
{
	int positive = 0, sum_pos = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Name[i][j] > 0)
				positive++;
		}
		if (positive == M)
			sum_pos++;
		positive = 0;
	}
	if (sum_pos == 0)
		cout << "\nПоложительных строк нет\n";
	else cout << "\nПоложительных строк: " << sum_pos << endl;

	string file2 = "Output.txt";
	fstream filein(file2);
	filein.seekg(0, ios::end);
	if (filein.is_open())
	{
		if (sum_pos == 0)
			filein << "\nПоложительных строк нет\n";
		else filein << "\nПоложительных строк: " << sum_pos << endl;
	}
}

void MinMax(int Name[25][25], int N, int M)
{
	int min = 100000000, max = -100000000, mult = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Name[i][j] > max) max = Name[i][j];
			if (Name[i][j] < min) min = Name[i][j];
			mult *= Name[i][j];
		}
	}
	cout << "\nMax = " << max
		<< "\nMin = " << min
		<< "\nПроизведение всех элементов = " << mult;
	if (mult < 0) cout << "\nMax со знаком = " << 0 - max;
	cout << endl;

	string file2 = "Output.txt";
	fstream filein(file2);
	filein.seekg(0, ios::end);
	if (filein.is_open())
	{
		filein << "\nMax = " << max
			<< "\nMin = " << min
			<< "\nПроизведение всех элементов = " << mult;
		if (mult < 0) filein << "\nMax со знаком = " << 0 - max;
		filein << endl;
	}
}

void BlackSegment(int Name[25][25], int N)
{
	int sum = 0;
	cout << "\nМатрица с выделенными элементами:\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i != j && j < N / 2 && j > i)
			{
				sum += Name[i][j];
				string t = to_string(Name[i][j]);
				char const* n_char = t.c_str();
				wcout << setw(6); Paint(n_char, 1); wcout << " ";
			}
			else wcout << setw(6) << Name[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\nСумма выделенных элементов = " << sum << endl;

	string file2 = "Output.txt";
	fstream filein(file2);
	filein.seekg(0, ios::end);
	if (filein.is_open())
	{
		filein << "\nСумма выделенных элементов = " << sum << endl;
	}
}

void AddLineAndColumn(int Name[25][25], int& N, int& M, int matr[26][26], int matr3[26][26])
{
	int A, B, num_str = -1, matr2[26][30];
	cout << "\nВведи любое число, которое есть в матрице, чтобы после строки с этим числом добавить последнюю строку (если введёшь не то, ничего не заработает): ";
	CheckEnter(A, 0, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Name[i][j] == A) num_str = i;
			matr[i][j] = Name[i][j];
			matr2[i][j] = Name[i][j];
		}
	}

	if (num_str != -1)
	{
		for (int i = 0; i < N + 1; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (num_str + i + 2 != N * 2 + 1)
				{
					matr[num_str + i + 2][j] = Name[num_str + i + 1][j];
					matr2[num_str + i + 2][j] = Name[num_str + i + 1][j];
				}
				else throw out_of_range("Вышло за пределы матрицы");
				matr[num_str + 1][j] = Name[N - 1][j];
				matr2[num_str + 1][j] = Name[N - 1][j];
			}
		}
		N++;
	}
	else cout << "\nСтроки с таким числом нет\n";

	string file2 = "Output.txt";
	fstream filein(file2);
	filein.seekg(0, ios::end);

	cout << "\nМатрица с доп строкой: \n";
	if (filein.is_open())
	{
		filein << "\nЧисло А = " << A;
		if (num_str == -1) filein << "\nСтроки с числом" << A << " нет\n";
		else
		{
			filein << "\nМатрица с доп строкой: \n";
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (i == num_str + 1)
					{
						string t = to_string(matr[i][j]);
						char const* n_char = t.c_str();
						wcout << setw(6); Paint(n_char, 1); wcout << " ";
					}
					else wcout << setw(6) << matr[i][j] << " ";
					filein << setw(6) << matr[i][j] << " ";
				}
				cout << "\n";
				filein << "\n";
			}
		}
	}

	cout << "\nВведи любой номер столбца, который есть в матрице, чтоб перед ним добавить нулевой столбец (если введёшь не тот, ничего не заработает): ";
	CheckEnter(B, 0, 0);
	B = B - 1;
	if (B > 0 || B < M + 1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M + 1; j++)
			{

				if (B + j + 1 != 61)
					matr[i][B + j + 1] = matr2[i][B + j];
				else throw out_of_range("Вышло за пределы матрицы");
				matr[i][B] = matr2[i][0];
			}
		}
		M++;
	}
	else cout << "\nТакого столбца не существует\n";


	cout << "\nМатрица с доп строкой и доп столбцами: \n";
	if (filein.is_open())
	{
		filein << "\nНомер столбца B = " << B;
		if (B > 0 || B < M)
		{
			filein << "\nМатрица с доп строкой и доп столбцами: \n";
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (i == num_str + 1)
					{
						string t = to_string(matr[i][j]);
						char const* n_char = t.c_str();
						wcout << setw(6); Paint(n_char, 1); wcout << " ";
					}
					else if (j == B)
					{
						string t = to_string(matr[i][j]);
						char const* n_char = t.c_str();
						wcout << setw(6); Paint(n_char, 3); wcout << " ";
					}
					else wcout << setw(6) << matr[i][j] << " ";
					filein << setw(6) << matr[i][j] << " ";
					matr3[i][j] = matr[i][j];
				}
				cout << "\n";
				filein << "\n";
			}
		}
		else filein << "\nТакого столбца не существует\n";
	}

}

void DeleteLineAndColumn(int Name[26][26], int N, double M, int matr[26][26])
{
	string file2 = "Output.txt";
	fstream filein(file2);
	filein.seekg(0, ios::end);

	int A, sum = 0, sumleft = 0, sumright = 0; double width = (M - 1) / 2;

	cout << "\nВведи любое число, которое есть в матрице, чтобы удалить столбцы с этим числом (если введёшь не то, ничего не заработает): ";
	CheckEnter(A, 0, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Name[i][j] == A)
			{
				sum = 1;
				for (int k = 0; k < N; k++)
				{
					matr[k][j] = 0;
				}
			}
		}
	}

	if (filein.is_open())
	{
		filein << "\nЧисло А = " << A;
		if (sum == 0)
		{
			cout << "\nТаких чисел нет\n";
			filein << "\nТаких чисел нет\n";
		}
		else
		{
			cout << "\nМатрица с удалёнными столбцами:\n";
			filein << "\nМатрица с удалёнными столбцами:\n";
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					cout << setw(6) << matr[i][j] << " ";
					filein << setw(6) << matr[i][j] << " ";
				}
				cout << endl;
				filein << endl;
			}
		}
	}

	sum = 0;
	cout << "\nУдаление строк, сумма элементов первой половины которых больше суммы элементов второй половины.\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (j < width) sumleft += matr[i][j];
			else if (j > width) sumright += matr[i][j];
		}
		if (sumleft > sumright)
		{
			sum = 1;
			for (int k = 0; k < M; k++)
			{
				matr[i][k] = 0;
			}
		}
		sumleft = 0; sumright = 0;
	}

	if (filein.is_open())
	{
		filein << "\nЧисло А = " << A;
		if (sum == 0)
		{
			cout << "\nТаких строк нет\n";
			filein << "\nТаких строк нет\n";
		}
		else
		{
			cout << "\nМатрица с удалёнными строками:\n";
			filein << "\nМатрица с удалёнными строками:\n";
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					cout << setw(6) << matr[i][j] << " ";
					filein << setw(6) << matr[i][j] << " ";
				}
				cout << endl;
				filein << endl;
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\nОбработка матриц\n";
	int rep = 0, matr[25][25], N, M;
	string file = "Input.txt";

	cout << "\n1-2 задание:\n";
	EnterLength(N, M);
	EnterKeyboard(matr, N, M);
	Output(matr, N, M);
	OutputInFile(matr, N, M);
	PositiveLine(matr, N, M);
	MinMax(matr, N, M);
	system("pause");

	cout << "\n3 задание:\n";
	EnterLength(N);
	EnterRandom(matr, N);
	M = N;
	Output(matr, N, M);
	OutputInFile(matr, N, M);
	BlackSegment(matr, N);
	system("pause");

	cout << "\n4-5 задание:\n";
	int matr2[26][26];
	int matr3[26][26];
	EnterLength(N, M);
	EnterFromFile(matr, N, M, file);
	Output(matr, N, M);
	OutputInFile(matr, N, M);
	try
	{
		AddLineAndColumn(matr, N, M, matr2, matr3);
	}
	catch (out_of_range err) { cout << "\nОшибка!\n" << err.what(); }
	DeleteLineAndColumn(matr2, N, M, matr3);
}