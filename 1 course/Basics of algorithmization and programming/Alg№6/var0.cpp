#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;

void Print(string str)
{
	
	cout << str << " | ���������� ��������: " << str.size() << endl;
}

string FindExistFile()
{
	string NameFile;
	cout << "����� �������� �����: ";
	cin >> NameFile;
	return NameFile + ".txt";
}

string CreateNewFile()
{
	string NameFile;
	cout << "����� �������� �����: ";
	cin >> NameFile;
	ofstream File(NameFile + ".txt");
	File.close();
	cout << "���� " << NameFile + ".txt" << " ������.";
	return NameFile + ".txt";
}

void fill(string Name)
{
	ofstream oFile(Name);
	string words;
	cout << "\n����� ����������� � ����: ";
	cin >> words;
	oFile << words;
	getline(cin, words);
	oFile << words;
	oFile.close();
}

void EditFile(string Name)
{
	ifstream File(Name);
	if (File.is_open())
	{
		while (!File.eof())
		{
			string screen;
			getline(File, screen);
			Print(screen);
		}
	}
}

void out(string Name)
{

	ifstream iFile(Name, ios::in);
	cout << "\n\n���������� �����: " << endl;
	if (iFile.is_open())
	{
		while (!iFile.eof())
		{
			string screen;
			getline(iFile, screen);
			Print(screen);
		}
	}
	else cout << "fuck!!!!!!!!!!!!!!!!!!!";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "��������� �����-11/2\n������� 0\n\n";
	string File = FindExistFile();

	out(File);


}