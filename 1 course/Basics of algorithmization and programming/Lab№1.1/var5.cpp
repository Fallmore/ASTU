#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int EnterLength(int& n)
{
	cin >> n;
	if (n < 1)
	{
		cout << "������ ������� �� ������ ���� ������ ��� ����� 0";
		return EnterLength(n);
	}
	else
	{
		return n;
	}
}

void EnterKeyboard(int* Name, int len)
{
	int num;
	for (int i = 0; i < len; i++)
	{
		cout << "����� " << i + 1 << "-� �����: ";
		cin >> num;
		Name[i] = num;
	}
}

void EnterRandom(int* Name, int len)
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

void Output(int* Name, int len)
{
	cout << "\n����� ��������� �������." << "\n�������� �������: ";
	for (int i = 0; i < len; i++)
	{
		cout << Name[i] << " ";
	}
}

void IndexMaxNegative(int* Name, int len)
{
	int maxneg = min(Name[0], Name[len - 1]);
	if (maxneg >= 0)
	{
		cout << "\n\n������������� ����� ���" << endl;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (Name[i] < 0)
			{
				if (Name[i] > maxneg)
				{
					maxneg = Name[i];
				}
			}
		}
		cout << "\n\n������������ ������������� �����: " << maxneg << endl;
	}
}

int SumBeforeLastPositive(int* Name, int len)
{
	int sum = 0, index = 0;
	for (int i = 0; i < len; i++)
	{
		if (Name[i] > 0)
			index = i;
	}
	for (int i = 0; i < index; i++)
	{
		sum += Name[i];
	}
	return sum;
}

void mainArrayS(int* Name, int len, int& rep)
{
	int choice;
	if (rep != 0)
	{
		cout << "\n�������� ������\n";
	}
	rep++;
	cout << "����� ������ ���������� ��������:\n"
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
	default: mainArrayS(Name, len, rep);
		break;
	}
	Output(Name, len);
	IndexMaxNegative(Name, len);
	cout << "����� ����� �� ���������� ��������������: "
		<< SumBeforeLastPositive(Name, len) << endl;
}

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 5\n���������� � ������� ������� ������������� �������������� �����\n� ����� ��������� ������� ����� ��������� ������������� ������\n";
	int len;
	cout << "\n����� ������ �������: ";
	EnterLength(len);
	int* mas = new int[len];
	int repeat = 0;
	mainArrayS(mas, len, repeat);
	delete[] mas;
	return 0;
}