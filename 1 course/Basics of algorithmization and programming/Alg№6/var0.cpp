#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;

void Print(string str)
{
	
	cout << str << " | Количество символов: " << str.size() << endl;
}

string FindExistFile()
{
	string NameFile;
	cout << "Введи название файла: ";
	cin >> NameFile;
	return NameFile + ".txt";
}

string CreateNewFile()
{
	string NameFile;
	cout << "Введи название файла: ";
	cin >> NameFile;
	ofstream File(NameFile + ".txt");
	File.close();
	cout << "Файл " << NameFile + ".txt" << " создан.";
	return NameFile + ".txt";
}

void fill(string Name)
{
	ofstream oFile(Name);
	string words;
	cout << "\nВведи предложение в файл: ";
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
	cout << "\n\nСодержание файла: " << endl;
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
	cout << "Самодуров ДИНРБ-11/2\nВариант 0\n\n";
	string File = FindExistFile();

	out(File);


}