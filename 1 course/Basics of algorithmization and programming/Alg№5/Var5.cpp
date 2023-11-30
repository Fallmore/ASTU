#include <iostream>
#include <fstream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <list>
#include <set>

using namespace std;

int vvod(int& len) //�������� ������������ �������� �����
{
	cout << "\n����� �������� ����� ������������������: ";
	cin >> len;
	if (len <= 0)
	{
		cout << "\n������: ������ ����� �� ���������\n";
		return vvod(len);
	}
	else return 1;
}

int check(int& min, int& max) //��������
{
	cout << "\n����� �������� �������� ([a;b]): ";
	cin >> min >> max;
	if (min > max)
	{
		cout << "\n������: ����� ������� ������ ������\n";
		return check(min, max);
	}
	else return 1;
}

int GetRandomNumber(int min, int max)
{
	// �������� ��������� ����� - �������
	int num = min + rand() % (max - min + 1);
	return num;
}

bool vvin(const char Name[], int len, int min, int max) //����������
{
	ofstream inn("C:\\Users\\slava\\source\\repos\\Alg�5\\Alg�5");
	inn.open(Name);
	int i;
	if (inn)
	{
		for (i = 0; i < len; i++)
		{
			inn << GetRandomNumber(min, max);
			if (i != len - 1)
			{
				inn << "\n";
			}
		}
		cout << "\n���� " << Name << " ��������\n";
		return 1;
	}
	else
	{
		cout << "\n������: ���� �� ��������\n";
		return 0;
	}
	inn.close();
}

void Print(const char Name[]) //�����
{
	ifstream outt("C:\\Users\\slava\\source\\repos\\Alg�5\\Alg�5");
	outt.open(Name);
	if (outt.is_open())
	{
		if (outt.eof())
		{
			cout << "\n������: ���� ������\n";
		}
		else
		{
			cout << "\n���������� ����� " << Name << ": ";
			while (!outt.eof())
			{
				string str;
				getline(outt, str);
				cout << str << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "\n������: ���� �� ��������\n";
	}
	outt.close();
}

void sort(const char Name[], list <string>& srt) //���������� ��������� �����
{
	ifstream outg("C:\\Users\\slava\\source\\repos\\Alg�5\\Alg�5");
	outg.open(Name);
	list <string> lenlist;
	if (outg.is_open())
	{
		if (outg.eof())
		{
			cout << "\n������: ���� ������\n";
		}
		else
		{
			list <string> unik;
			while (!outg.eof())
			{
				string str;
				getline(outg, str);
				unik.push_back(str);
			}
			lenlist.assign(unik.begin(), unik.end());
			set <string> s;
			unik.remove_if([&](string n) {return (s.find(n) == s.end()) ? (s.insert(n), false) : true;}); //��������
			srt.assign(unik.begin(), unik.end());
			if (lenlist.size() == srt.size())
			{
				cout << "\n������������� ����� ���\n";
			}
			else cout << "\n������������� ����� ���������\n";
		}
	}
	else
	{
		cout << "\n������: ���� �� ��������\n";
	}
	outg.close();
}

void fill(const char Name[], list <string> srt)
{
	ofstream ing("C:\\Users\\slava\\source\\repos\\Alg�5\\Alg�5");
	ing.open(Name);
	int fuck = 0;
	if (ing)
	{
		for (auto i : srt)
		{
			if (fuck != 0)
			{
				ing << "\n";
			}
			fuck = 1;
			ing << i;
		}
		cout << "\n���� " << Name << " ��������\n";
	}
	else
	{
		cout << "\n������: ���� �� ��������\n";
	}
	ing.close();
}

void binin(const char Name1[], const char Name2[])
{
	ifstream from("C:\\Users\\slava\\source\\repos\\Alg�5\\Alg�5");
	ofstream to("C:\\Users\\slava\\source\\repos\\Alg�5\\Alg�5", ios::binary);
	from.open(Name1);
	to.open(Name2);
	string n;
	char c[100];
	int sum = 0;
	while (!from.eof())
	{
		from >> n;
		to.write((char*)&n, sizeof n);
		sum++;
	}
	cout << "\n�������� ���� " << Name2 << " ��������\n";
	cout << "���������� ��������� � �����: " << sum << endl;
	from.close();
	to.close();
}

void PrintBin(const char Name[]) //�����
{
	ifstream outb("C:\\Users\\slava\\source\\repos\\Alg�5\\Alg�5", ios::binary);
	outb.open(Name);
	if (outb.is_open())
	{
		cout << "\n���������� ��������� ����� " << Name << ": ";
		string str;
		while (outb.read(reinterpret_cast<char*>(&str), sizeof(string)))
		{
			cout << str << " ";
		}
		cout << endl;
		outb.close();
	}
	else
	{
		cout << "\n������: �������� ���� �� ��������\n";
	}
}


int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 5\n���������� ����� ������� � ����� ���������� � ������ ����\n";
	// ���������� ��������� ��������� �����
	srand((unsigned)time(NULL));
	int len;
	list <string> srt;
	do
	{
		if (vvod(len) == 1)
		{
			int min;
			int max;
			if (check(min, max) == 1)
			{
				cout << "\n���������� ����� ����������� �����:";
				vvin("f.txt", len, min, max);
				cout << "\n����� ����������� �����:";
				Print("f.txt");
				cout << "\n���������� ������������� ����� �����:";
				sort("f.txt", srt);
				cout << "\n���������� ����� ����������� �������:";
				fill("g.txt", srt);
				cout << "\n����� ����������� �����:";
				Print("g.txt");
				cout << "\n���������� � �������� ����:";
				binin("g.txt", "Output.txt");
				cout << "\n����� ��������� �����:";
				PrintBin("Output.txt");
			}
		}
	} while (len == 0);
}