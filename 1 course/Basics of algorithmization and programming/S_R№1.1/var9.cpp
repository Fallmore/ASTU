#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int RandomLength(int& len)
{
	return len = 10 + rand() % (30 - 10 + 1);
}

int EnterN(int& N)
{
	cout << "\n����� �������� ����������� �����: ";
	do
	{
		cin >> N;
		if (N < 1) cout << "\n����� ������ ���� ������ 0\n����: ";
	} while (N < 1);
	return N;
}

void EnterKeyboard(string Name, int len)
{
	fstream file(Name);
	int num;
	for (int i = 0; i < len; i++)
	{
		cin >> num;
		file << num << " ";
	}

}

void EnterRandom(string Name, int len)
{
	fstream file(Name);
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
		file << num << " ";
	}
}

void Output(string Name, int len)
{
	cout << "\n���������� �����: ";
	fstream file(Name);
	int num;
	for (int i = 0; i < len; i++)
	{
		if (!file.eof())
		{
			file >> num;
			cout << num << " ";
		}
	}
	cout << endl;
}

void Choose(string Name, int len, int& rep)
{
	cin.clear();
	int choice;
	if (rep != 0)
	{
		cout << "\n�������� ����\n\n";
	}
	rep++;
	cout << "\n����� ������ ���������� �����:\n"
		<< "1 - � ����������\n"
		<< "2 - ���������� �������\n"
		<< "����: ";
	cin >> choice;
	switch (choice)
	{
	case 1: EnterKeyboard(Name, len);
		break;
	case 2: EnterRandom(Name, len);
		break;
	default: Choose(Name, len, rep);
		break;
	}
	Output(Name, len);
}

void MessageAboutThreeInRowRisingNumbers(string Name, int len)
{
	cout << "\n���� �� � ����� ���� �� 3 ������ ������������ �����?\n";
	int row = 0, num1, num2 = 0, max = 0;
	fstream file(Name);

	for (int i = 0; i < len; i++)
	{
		if (!file.eof())
		{
			num1 = num2;
			file >> num2;

			if (num2 <= num1) row = 0;
			else
			{
				if (row != 0)
				{
					if (row == 1) cout << "\n���: " << num1 << " ";
					cout << num2 << " ";
				}
			}

			row++;
			if (row > max) max = row;
		}
	}
	if (max > 3) cout << "\n\n����, �� ���� " << max << "\n\n";
	else if (max == 3) cout << "\n\n����\n\n";
	else cout << "\n\n���\n\n";
	system("pause");
}

void LookingForMaxNumberOnOddPlaces(string In, int lennew)
{
	system("pause");
	cout << "\n����� ����������� ����� �� �������� ������\n";
	fstream file(In);
	int num, index, max = -1000000;
	for (int i = 0; i < lennew; i++)
	{
		file >> num;
		if (i % 2 == 1)
			if (num > max) 
			{
				max = num;
				index = i;
			}
	}
	if (max != -1000000)
	{
		cout << "\n������������ �����: " << max
			<< "\n��� ������: " << index << endl;
	}
	else cout << "\n������������� ����� �� �������� ������ ���\n";
}

void NumbersLessThanN(string Name, string In, int len)
{
	fstream Fileout(Name);
	fstream Filein(In);
	int N, num, lennew = 0;
	cout << "\n������ � ������ ���� �����, �� ����������� ���������� �������� ������ �����.\n";
	EnterN(N);
	for (int i = 0; i < len; i++)
	{
		Fileout >> num;
		if (abs(num) < N)
		{
			Filein << num << " ";
			lennew++;
		}
	}
	Filein.close();
	if (lennew == 0)
	{
		cout << "\n��� �����, �� ����������� ���������� �������� ������ �����\n";
	}
	else 
	{
		cout << "\n����� ���� � ��������� � ����\n";
		Output(In, lennew);
	}
	LookingForMaxNumberOnOddPlaces(In, lennew);
}

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 9\n�������� ������\n\n";
	int len, rep = 0;
	string file1 = "Input.txt";
	string file2 = "Output.txt";
	RandomLength(len);
	cout << "����� ������������������ (���������� �����) ����� " << len << "\n\n";
	system("pause");
	Choose(file1, len, rep);
	MessageAboutThreeInRowRisingNumbers(file1, len);
	NumbersLessThanN(file1, file2, len);
	return 1;
}