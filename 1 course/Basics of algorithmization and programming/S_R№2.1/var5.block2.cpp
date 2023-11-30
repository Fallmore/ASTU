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
	if (mode == 1) SetConsoleTextAttribute(hStdOut, (WORD)((15 << 4) | 0));		// ����� ���; ������ �����
	if (mode == 0) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 2));		// ������ ���; ������ �����
	if (mode == 2) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 2));		// ������ ���; ������� �����
	if (mode == 3) SetConsoleTextAttribute(hStdOut, (WORD)((15 << 4) | 4));		// ������ ���; ������� �����
}

// ������� �������� ������
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
			if (rep < 1) cout << "\n��� �� �����" << endl << "������� ��������: ";
			rep = 1;
		}
	} while (getchar() != '\n');
	if (rep != 0) CheckEnter(choice, NumberOfChoice, rep);
	return choice;
}

void EnterLength(int& N, int& M)
{
	cout << "\n����� ������ ������������� �������.\n";
	do
	{
		cout << "����� �����: ";
		CheckEnter(N, 0, 0);
		cout << "����� ��������: ";
		CheckEnter(M, 0, 0);
		if (N < 1 || M < 1) cout << "\n������ ������ ���� ������ 0\n";
		else if (N > 26 || M > 26) cout << "\n��������, �� ������ ������� �������\n";
		else if (N == M) cout << "\n������� ������ ���� �������������\n";
	} while (N < 1 || N > 26 || M < 1 || M > 26 || N == M);
	cout << "\n������ = " << N << "\n������� = " << M << endl;
}

void EnterLength(int& N)
{
	cout << "\n����� ������ ���������� �������: ";
	do
	{
		CheckEnter(N, 0, 0);
		if (N < 1) cout << "\n������ ������ ���� ������ 0\n";
		else if (N > 26) cout << "\n��������, �� ������ ������� �������\n";
	} while (N < 1 || N > 26);
}

void EnterKeyboard(int Name[25][25], int N, int M)
{
	cout << "\n��������� ������\n";
	int num;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << i + 1 << "-� ������ ";
			cout << j + 1 << "-� �������: ";
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
		cout << "\n����� �������� [a;b]: ";
		cin >> a >> b;
		if (a > b) cout << "����� ������� �� ����� ���� ������ ������\n";
		else if (a == b) cout << "������������� ��������\n";
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
		while (!out.eof())// ��������� ���� �� �������� ����� ����� eof
		{
			out >> temp;//� ������� ��������� �� ����� �����
			count++;// ����������� ������� ����� �����
		}
		out.clear();
		out.seekg(0, ios::beg);
		int count_space = 0;
		char symbol;
		while (!out.eof())//�� ������ ������ ���� ������������ ������ �����
		{
			//������ ��� ����� ��������� �� �����, � ����������� ��������� ������
			out.get(symbol);//������� ������� ������
			if (symbol == ' ') count_space++;//���� ��� ������, �� ����� �������� �����������
			if (symbol == '\n') break;//���� ����� �� ����� ������, �� ������� �� �����
		}
		int n = count / (count_space + 1);//����� �����
		int m = count_space + 1;
		if (n < N || m < M)
		{
			cout << "\n� ����� ������ �����, ��� ������ �������";
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
	cout << "\n���������� �������: \n";
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
		cout << "\n���������� ����� " << file2 << "...";
		filein << "\n�������:\n";
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				filein << setw(6) << Name[i][j] << " ";
			}
			filein << endl;
		}
		cout << "\n���� ��������\n";
	}
	else cout << "\n����  �� ��������\n";
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
		cout << "\n������������� ����� ���\n";
	else cout << "\n������������� �����: " << sum_pos << endl;

	string file2 = "Output.txt";
	fstream filein(file2);
	filein.seekg(0, ios::end);
	if (filein.is_open())
	{
		if (sum_pos == 0)
			filein << "\n������������� ����� ���\n";
		else filein << "\n������������� �����: " << sum_pos << endl;
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
		<< "\n������������ ���� ��������� = " << mult;
	if (mult < 0) cout << "\nMax �� ������ = " << 0 - max;
	cout << endl;

	string file2 = "Output.txt";
	fstream filein(file2);
	filein.seekg(0, ios::end);
	if (filein.is_open())
	{
		filein << "\nMax = " << max
			<< "\nMin = " << min
			<< "\n������������ ���� ��������� = " << mult;
		if (mult < 0) filein << "\nMax �� ������ = " << 0 - max;
		filein << endl;
	}
}

void BlackSegment(int Name[25][25], int N)
{
	int sum = 0;
	cout << "\n������� � ����������� ����������:\n";
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
	cout << "\n����� ���������� ��������� = " << sum << endl;

	string file2 = "Output.txt";
	fstream filein(file2);
	filein.seekg(0, ios::end);
	if (filein.is_open())
	{
		filein << "\n����� ���������� ��������� = " << sum << endl;
	}
}

void AddLineAndColumn(int Name[25][25], int& N, int& M, int matr[26][26], int matr3[26][26])
{
	int A, B, num_str = -1, matr2[26][30];
	cout << "\n����� ����� �����, ������� ���� � �������, ����� ����� ������ � ���� ������ �������� ��������� ������ (���� ������ �� ��, ������ �� ����������): ";
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
				else throw out_of_range("����� �� ������� �������");
				matr[num_str + 1][j] = Name[N - 1][j];
				matr2[num_str + 1][j] = Name[N - 1][j];
			}
		}
		N++;
	}
	else cout << "\n������ � ����� ������ ���\n";

	string file2 = "Output.txt";
	fstream filein(file2);
	filein.seekg(0, ios::end);

	cout << "\n������� � ��� �������: \n";
	if (filein.is_open())
	{
		filein << "\n����� � = " << A;
		if (num_str == -1) filein << "\n������ � ������" << A << " ���\n";
		else
		{
			filein << "\n������� � ��� �������: \n";
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

	cout << "\n����� ����� ����� �������, ������� ���� � �������, ���� ����� ��� �������� ������� ������� (���� ������ �� ���, ������ �� ����������): ";
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
				else throw out_of_range("����� �� ������� �������");
				matr[i][B] = matr2[i][0];
			}
		}
		M++;
	}
	else cout << "\n������ ������� �� ����������\n";


	cout << "\n������� � ��� ������� � ��� ���������: \n";
	if (filein.is_open())
	{
		filein << "\n����� ������� B = " << B;
		if (B > 0 || B < M)
		{
			filein << "\n������� � ��� ������� � ��� ���������: \n";
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
		else filein << "\n������ ������� �� ����������\n";
	}

}

void DeleteLineAndColumn(int Name[26][26], int N, double M, int matr[26][26])
{
	string file2 = "Output.txt";
	fstream filein(file2);
	filein.seekg(0, ios::end);

	int A, sum = 0, sumleft = 0, sumright = 0; double width = (M - 1) / 2;

	cout << "\n����� ����� �����, ������� ���� � �������, ����� ������� ������� � ���� ������ (���� ������ �� ��, ������ �� ����������): ";
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
		filein << "\n����� � = " << A;
		if (sum == 0)
		{
			cout << "\n����� ����� ���\n";
			filein << "\n����� ����� ���\n";
		}
		else
		{
			cout << "\n������� � ��������� ���������:\n";
			filein << "\n������� � ��������� ���������:\n";
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
	cout << "\n�������� �����, ����� ��������� ������ �������� ������� ������ ����� ��������� ������ ��������.\n";
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
		filein << "\n����� � = " << A;
		if (sum == 0)
		{
			cout << "\n����� ����� ���\n";
			filein << "\n����� ����� ���\n";
		}
		else
		{
			cout << "\n������� � ��������� ��������:\n";
			filein << "\n������� � ��������� ��������:\n";
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
	cout << "��������� �����-11/2\n������� 5\n��������� ������\n";
	int rep = 0, matr[25][25], N, M;
	string file = "Input.txt";

	cout << "\n1-2 �������:\n";
	EnterLength(N, M);
	EnterKeyboard(matr, N, M);
	Output(matr, N, M);
	OutputInFile(matr, N, M);
	PositiveLine(matr, N, M);
	MinMax(matr, N, M);
	system("pause");

	cout << "\n3 �������:\n";
	EnterLength(N);
	EnterRandom(matr, N);
	M = N;
	Output(matr, N, M);
	OutputInFile(matr, N, M);
	BlackSegment(matr, N);
	system("pause");

	cout << "\n4-5 �������:\n";
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
	catch (out_of_range err) { cout << "\n������!\n" << err.what(); }
	DeleteLineAndColumn(matr2, N, M, matr3);
}