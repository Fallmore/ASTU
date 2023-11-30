#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>

using namespace std;

using row = vector<int>;
using matrix = vector<row>;

void Enter(int& num, int ch)
{
	string choice, waste;
	int rep;
	if (ch > 0)
	{
		do
		{
			rep = 0;
			cin >> choice;
			if (!choice.empty())
			{
				for (int i = 0; i < choice.length(); i++)
				{
					if (choice[i] > '9' || choice[i] < '0')
					{
						if (rep < 1) cout << "\nЭто не число" << "\nВвод: ";
						rep++;
					}
				}
				if (rep == 0)
				{
					num = stoi(choice);
					if (num < 1 || num > ch)
					{
						cout << "\nНекорректный номер" << "\nВвод: ";
					}
				}
				else getline(cin, waste);
			}
			else rep++;
		} while (num < 1 || num > ch || rep != 0);
	}
	else if (ch == -1)
	{
		do
		{
			rep = 0;
			cin >> choice;
			if (!choice.empty())
			{
				for (int i = 0; i < choice.length(); i++)
				{
					if (choice[i] > '9' || choice[i] < '0')
					{
						if (choice[i] != '-')
						{
							if (rep < 1) cout << "\nЭто не число" << "\nВвод: ";
							rep++;
						}
					}
				}
				if (rep == 0)
				{
					num = stoi(choice);
				}
				else getline(cin, waste);
			}
			else rep++;
		} while (rep != 0);
	}
	else
	{
		do
		{
			rep = 0;
			cin >> choice;
			if (!choice.empty())
			{
				for (int i = 0; i < choice.length(); i++)
				{
					if (choice[i] > '9' || choice[i] < '0')
					{
						if (choice[i] == '-')
						{
							if (rep < 1) cout << "\nЧисла должны быть положительными" << "\nВвод: ";
						}
						else
						{
							if (rep < 1) cout << "\nЭто не число" << "\nВвод: ";
						}
						rep++;
					}
				}
				if (rep == 0)
				{
					num = stoi(choice);
				}
				else getline(cin, waste);
			}
			else rep++;
		} while (rep != 0);
	}

}

void Display(const matrix& A)
{
	int m = A.size();
	int n = A[0].size();
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << '\t';
		cout << endl;
	}
}

matrix Make(int m, int n, int ch)
{
	int a, b;
	matrix A;
	row Row(n);
	cout << "\nЗаполнение матрицы\n";
	if (ch == 1)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << i + 1 << "-ая строчка " << j + 1 << "-ый столбец - ";
				cin >> Row[j];
			}
			A.push_back(Row);
		}
	}
	else
	{
		cout << "\nВведи диапазон [a;b] (а должно быть больше b) - ";
		do
		{
			Enter(a, -1);
			Enter(b, -1);
			if (a >= b) cout << "\nНеверный диапазон\n Введи диапазон - ";

		} while (a >= b);

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				Row[j] = a + rand() % (b - a + 1);
			A.push_back(Row);
		}
	}
	return A;
}

void ReplacePalindrom(matrix& A)
{
	int x = 0, maxnum = 0, coin = 1, maxpal = 0, choice = 0, m = A.size(), n = A[0].size();
	string palindrom;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			maxnum = 0;
			for (int k = 0; k < m; k++)
				maxnum = max(maxnum, A[k][j]);

			palindrom = to_string(A[i][j]);
			if (palindrom.length() % 2 == 1)
			{
				coin = 1;
				for (int i = 0; i < palindrom.length() / 2; i++)
				{
					if (palindrom[i] != palindrom[palindrom.length() - 1 - i]) coin = 0;
				}
			}
			else
			{
				coin = 1;
				for (int i = 0; i < (palindrom.length() + 1 / 2) - 1; i++)
				{
					if (palindrom[i] != palindrom[palindrom.length() - 1 - i]) coin = 0;
				}
			}

			if (coin == 1)
				A[i][j] = maxnum;
		}
}

void ReplaceRow(matrix& A)
{
	int x = 0, maxnum = 0, coin = 1, maxpal = 0, choice = 0, m = A.size(), n = A[0].size();
	matrix B = A;

	if (m % 2 == 1)
	{
		for (int i = 0; i < ((m + 1) / 2) - 1; i++)
		{
			B[i] = A[m - 1 - i];
			B[m - 1 - i] = A[i];
		}
	}
	else
	{
		for (int i = 0; i < m / 2; i++)
		{
			B[i] = A[m - 1 - i];
			B[m - 1 - i] = A[i];
		}
	}
	A = B;
}

void EraseColumn(matrix& A, int index)
{
	int num, m = A.size(), n = A[0].size();
	A[1].erase(A[1].begin());
	Enter(num, 0);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{

		}
	}
}

void Menu(matrix& a, int rep)
{
	int ch, m, n;
	if (rep == 0)
	{
		cout << "\n\n	Меню\n"
			<< "1 - Заполнить матрицу векторов\n"
			<< "Ввод: ";
		Enter(ch, 1);

		cout << "\nВыбери способ"
			<< "\n1 - С клавиатуры"
			<< "\n2 - Случайные числа"
			<< "\nВвод: ";
		Enter(ch, 2);

		cout << "\nВыбери размер матрицы [m;n] - ";
		Enter(m, 0);
		Enter(n, 0);

		a = Make(m, n, ch);
		Display(a);

		Menu(a, 1);
	}
	else if (a.size() == 0)
	{
		cout << "\nМатрица пуста, выход из программы\n";
	}
	else
	{
		cout << "\n\n	Меню\n"
			<< "1 - Заменить все элементы-палиндромы на максимальный элемент в столбце.\n"
			<< "2 - Поменять местами первую и последнюю, вторую и предпоследнюю и т.д. строки.\n"
			<< "3 - Вставить перед всеми столбцами, в которых нет отрицательных элементов, последний столбец, а\n"
			<< "    после строк, в которых есть отрицательный элемент, вставить строку, состоящую из случайных чисел.\n"
			<< "4 - Удалить столбцы, в которых есть заданный элемент, а затем строки, сумма элементов первой\n"
			<< "    половины которых больше суммы элементов второй половины.\n"
			<< "5 - Выход из программы\n"
			<< "Ввод: ";
		Enter(ch, 5);
		if (ch != 5)
		{
			if (ch == 1) ReplacePalindrom(a);
			else if (ch == 2) ReplaceRow(a);
			else if (ch == 3) a = a;
			else if (ch == 4)

			Display(a);

			Menu(a, 1);
		}

	}

}


int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\nВекторные и динамические мамтрицы";

	matrix a;
	Menu(a, 0);
	cout << " ERASE ROW INDEX 2 ==========" << endl;
	a.erase(a.begin() + 2);
	Display(a);
	cout << " ERASE COL INDEX 3 ==========" << endl;
	EraseColumn(a, 3);
	Display(a);
	system("pause");
	return 0;
}

