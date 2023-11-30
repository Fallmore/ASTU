#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

void CheckEnter(int& choice, int NumberOfChoice, int rep)
{
	cin.clear();
	rep = 0;
	do
	{
		if (!(cin >> choice))
		{
			if (rep < 1) cout << "\n�������� �����������" << endl << "������� ��������: ";
			rep = 1;
		}
		else if (choice > NumberOfChoice || choice < 0)
		{
			if (rep < 1) cout << "\n�������� �����������" << endl << "������� ��������: ";
			rep = 1;
		}
	} while (getchar() != '\n');
	if (rep != 0) CheckEnter(choice, NumberOfChoice, rep);

}

int EnterLength(int& len)
{
	cout << "\n����� ����� �������\n����: ";
	do
	{
		cin >> len;
		if (len < 1) cout << "\n������ ������ ���� ������ 0\n����: ";
		else if (len > 1000) cout << "\n��������, �� ������ ������� �������\n����: ";
	} while (len < 1 || len > 1000);
	return len;
}

void EnterKeyboard(int Name[], int len)
{
	int num;
	for (int i = 0; i < len; i++)
	{
		cout << i + 1 << "-� �����: ";
		cin >> num;
		Name[i] = num;
		cout << endl;
	}

}

void EnterRandom(int Name[], int len)
{
	int a, b, num;
	do
	{
		cout << "\n����� �������� [a;b]: ";
		cin >> a >> b;
		if (a > b) cout << "����� ������� �� ����� ���� ������ ������\n";
		else if (a == b) cout << "������������� ��������\n";
	} while (a >= b);
	for (int i = 0; i < len; i++)
	{
		num = a + rand() % (b - a + 1);
		Name[i] = num;
	}
}

void EnterFromFile(int Name[], int len, string File)
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
		int n = count_space + 1; //���������� �����
		if (n < len)
		{
			cout << "\n� ����� ������ �����, ��� ������ �������";
			EnterLength(len);
			EnterFromFile(Name, len, File);
		}
	}
	out.clear();
	out.seekg(0, ios::beg);
	for (int i = 0; i < len; i++)
	{
		out >> Name[i];
	}
}

void Output(int Name[], int len)
{
	cout << "\n���������� �������: [ ";
	for (int i = 0; i < len; i++)
	{
		cout << Name[i] << " ";
	}
	cout << "]\n";
}

void OutputInFile(int Name[], int len)
{
	string file2 = "Output.txt";
	fstream filein(file2);
	if (filein.is_open())
	{
		cout << "\n���������� ����� " << file2 << "...";

		for (int i = 0; i < len; i++)
		{
			filein << Name[i] << " ";
		}
		cout << "\n���� ��������\n";
	}
	else cout << "\n����  �� ��������\n";
}

void Choose(int Name[], int len, int& rep)
{
	cin.clear();
	string file = "Input.txt";
	int choice;
	if (rep != 0)
	{
		cout << "\n�������� ����\n\n";
	}
	rep++;
	cout << "\n����� ������ ���������� �����:\n"
		<< "1 - � ����������\n"
		<< "2 - ���������� �������\n"
		<< "3 - �� �����\n"
		<< "����: ";
	cin >> choice;
	switch (choice)
	{
	case 1: EnterKeyboard(Name, len);
		break;
	case 2: EnterRandom(Name, len);
		break;
	case 3: EnterFromFile(Name, len, file);
		break;
	default: Choose(Name, len, rep);
		break;
	}
	Output(Name, len);
}

void DeleteElementsFromRange(int Name[], int len, int mas2[], int& lennew, int& ReturnMenu, int& max, int& min)
{
	int a, b, num;
	lennew = 0;
	cout << "\n\n�������� �� ������� �����, ������������� ������ ���������\n";

	do
	{
		cout << "\n����� �������� [a;b]: ";
		cin >> a >> b;
		if (a > b) cout << "����� ������� �� ����� ���� ������ ������\n";
		else if (a == b) cout << "������������� ��������\n";
	} while (a >= b);

	cout << "\n�������� [" << a << ";" << b << "]\n";
	for (int i = 0; i < len; i++)
	{
		num = Name[i];
		if (num < a || num > b)
		{
			if (num > max) max = num;
			if (num < min) min = num;
			mas2[lennew] = num;
			lennew++;
		}
	}
	cout << "\n������ ������ ������� = " << lennew;
	Output(mas2, lennew);
	ReturnMenu = 1;
}

int FullSquare(int num)
{
	if (num > 0)
	{
		double radical = pow(num, 0.5);
		int radicalInt = pow(num, 0.5);
		if (radical == radicalInt)
		{
			return 1;
		}
		else return 0;
	}
	return 0;
}

void AddDifferenceBetweenMinMaxFromOneMassiveInAnotherMassiveBeforeFullSquare(int Name[], int len, int mas3[], int& len3, int& ReturnMenu, int max, int min)
{
	int num1, mix = min - max;
	cout << "\n�������� ��� ���� = " << mix << endl;
	for (int i = 0; i < len; i++)
	{
		num1 = Name[i];
		if (FullSquare(num1) == 1)
		{
			mas3[len3] = mix;
			len3++;
			mas3[len3] = num1;
			len3++;
		}
		else
		{
			mas3[len3] = num1;
			len3++;
		}
	}
	cout << "������ ������ ������� = " << len3;
	Output(mas3, len3);
	ReturnMenu = 1;
}

void Menu(int Name[], int len, int mas3[], int& len3, int mas2[], int& lennew, int& lenres, int err, int& max, int& min)
{
	int masres[1000];
	if (err == 0)
	{
		cout << "\n�������� �������: "
			<< "\n1 - �������� �� ������� �����, ������������� ������ ���������"
			<< "\n2 - ������� � ������ ������� ����� ������ ������ ��������� �������� ����� ��� � ���� �� ������� ������� �������"
			<< "\n\n0 - ����� �� ���������"
			<< "\n\n����: ";
	}
	int choice, ReturnMenu = 0;
	CheckEnter(choice, 2, 0);
	switch (choice)
	{
	case 1:
		if (lenres == 0) DeleteElementsFromRange(Name, len, mas2, lennew, ReturnMenu, max, min);
		else
		{
			for (int i = 0; i < lennew; i++)
			{
				masres[i] = mas2[i];
			}
			DeleteElementsFromRange(masres, lenres, mas2, lennew, ReturnMenu, max, min);
		}
		lenres = lennew;
		if (lennew == 0)
		{
			cout << "\n\n��� ����� �������. ����� �� ������ �������\n\n";
			ReturnMenu = 0;
		}
		break;
	case 2:
		if (min == 1000000)
		{
			min = 0;
			if (max == -1000000) max = 0;
		}
		AddDifferenceBetweenMinMaxFromOneMassiveInAnotherMassiveBeforeFullSquare(Name, len, mas3, len3, ReturnMenu, max, min);
		break;
	case 0: break;
	}
	if (ReturnMenu != 0)
	{
		cout << "\n\n";
		Menu(Name, len, mas3, len3, mas2, lennew, lenres, err, max, min);
	}
	else OutputInFile(mas3, len3);
}


int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 5\n��������� �������� ������������������� � ������\n";
	int mas[1000], len, rep = 0, mas3[2000], mas2[1000], len3 = 0, max = -1000000, min = 1000000, lenres = 0, lennew = 0;

	EnterLength(len);
	Choose(mas, len, rep);
	Menu(mas, len, mas3, len3, mas2, lennew, lenres, 0, max, min);
}