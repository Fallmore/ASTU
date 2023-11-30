#include <Windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <wchar.h>
#include <conio.h>

#pragma comment(lib, "User32.lib")
#pragma comment(lib, "Gdi32.lib ")
#pragma comment(lib, "Shell32.lib")

#define IDI_ICON2

#define WINVER 0x0501
#define _WIN32_WINNT 0x0501
#define _WIN32_WINDOWS 0x0501
#define _WIN32_IE 0x0600

using namespace std;

// ������� � ��������
void Color(int mode) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (mode == 0) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));		// ������ ���; ����� �����
	if (mode == 1) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 1));		// ������ ���; ����� �����
	if (mode == 2) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 14));		// ������ ���; ����� �����
	if (mode == 3) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));		// ������ ���; ����� �����
	if (mode == 4) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 11));		// ������ ���; ������� �����
	if (mode == 5) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 2));		// ������ ���; ������ �����
	if (mode == 6) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 6));		// ������ ���; ������ ����� �����
	if (mode == 7) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 13));		// ������ ���; ������� �����
	if (mode == 8) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 9));		// ������ ���; ������ ������� �����
}

// ������� �������� ������
void Paint(wstring text, int mode)
{
	Color(mode);
	wcout << text;
	Color(0);
}

void CheckEnter(int& choice, int NumberOfChoice)
{
	cin.clear();
	int rep = 0;
	do
	{
		if (!(cin >> choice))
		{
			if (rep < 1) cout << "\n�������� �����������" << endl << "������� ��������: ";
			rep = 1;
		}
		else if (choice > NumberOfChoice || choice < 1)
		{
			if (rep < 1) cout << "\n�������� �����������" << endl << "������� ��������: ";
			rep = 1;
		}
	} while (getchar() != '\n');
	if (rep != 0) CheckEnter(choice, NumberOfChoice);
}
void CheckEnter(int& choice, int NumberOfChoice, int& check)
{
	cin.clear();
	int rep = 0;
	do
	{
		if (!(cin >> choice))
		{
			if (rep < 1) cout << "\n�������� �����������" << endl << "������� ��������: ";
			rep = 1;

		}
		else if (choice > NumberOfChoice || choice < 1)
		{
			if (choice == 1489)
			{
				check = 9; cout << "\n\n���-��� �����������\n\n";
				cout << "\n�������� ��������: "
					<< "\n1 - � ���������"
					<< "\n2 - ����� ����"
					<< "\n3 - ����"
					<< "\n\n4 - ����� �� ���������"
					<< "\n\n����: ";
			}
			else if (rep < 1) cout << "\n�������� �����������" << endl << "������� ��������: ";
			rep = 1;
		}
	} while (getchar() != '\n');
	if (rep != 0) CheckEnter(choice, NumberOfChoice, check);

}
void CheckEnter(int& num)
{
	cin.clear();
	int rep = 0;
	do
	{
		if (!(cin >> num))
		{
			if (rep < 1) cout << "\n��� �� �����" << endl << "������� ��������: ";
			rep = 1;
		}
	} while (getchar() != '\n');
	if (rep != 0) CheckEnter(num);

}

struct Node
{
	int x;
	Node* Next;
};

class List
{
	Node* Head, * Tail; //��������� ������ ������� � ���, ��� ���������
	int size; //����� ��������� � ������
public:
	List() : Head(NULL), Tail(NULL), size(0) {}; //������������� ��������� � ���� � ������� ������������
	void Add(int n, int count, int BeforeChoice, int Insta); //������� ���������� ��������� � ������
	void Show(int size, List& lst, int Insta);				 //������� ����������� ��������� ������
	int Count();											 //������� ������������ ����� ��������� � ������
	void Find();											 //������� ������ ��������
	void DelEl();											 //������� �������� ��������
	~List();												 //���������� ��� ������������ ������
};

List::~List()
{

	cout << "\n\n������ �����������\n\n";
	int tempsize = size;
	if (size == 0) cout << "\nsize = 0 - � ������ ��� ���������, ������� ������ ����������� ���������� �� ������� ������ ����������� ;)\n";
	while (size != 0) //���� ����������� ������ �� ������ ������� 
	{
		Node* temp = Head->Next;
		if (size > tempsize - 2)
		{
			cout << "\n" << tempsize - size + 1 << "-� ��������\n";
			Paint(L"\nNode", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = Head"; Paint(L"->", 3); wcout << "Next;\n";
			wcout << "\nHead"; Paint(L"->", 3); wcout << "Next = " << Head->Next << L" - ������ ������ �� ��������� �������\n";
			Paint(L"temp", 8); wcout << " = " << temp << L" - �� ��� ������ ��������� ���������� �������� ���������, ���������, ������� �� ������,\n"
				<< L"			  ����� �� �������� ����� � ���������� ����������";
		}

		delete Head; //����������� ������ �� ��������� ��������
		if (size > tempsize - 2)
		{
			Paint(L"\ndelete", 1); wcout << " Head;\n"
				<< "Head"; Paint(L"->", 3); Paint(L"x", 8); wcout << " = " << Head->x << "	             \\\n"
				<< "Head"; Paint(L"->", 3); wcout << "Next = " << Head->Next << L" - ������� ������\n";
		}

		Head = temp; //����� ������ ������ �� ����� ���������� ��������
		size--; //���� ������� ����������. ������������ ����� ���������
		if (size > tempsize - 2)
		{
			cout << "\nHead = "; Paint(L"temp", 8); wcout << ";";
			wcout << "\nHead"; Paint(L"->", 3); Paint(L"x", 8); wcout << " = " << Head->x << "	             \\\n"
				<< "Head"; Paint(L"->", 3); wcout << "Next = " << Head->Next << L" - � ����� �������� �������, ��� ������� ������ ����� \"���������\" �������, �.�. �� ���� ���������\n";
			wcout << "\nsize"; Paint(L"--", 3); wcout << " = " << size << L" - �� � ��������� ������ �� ����\n\n";
			system("pause");
		}

		if (size == tempsize - 2)
			cout << "\n\n� ��� �����...\n\n";
	}
	Head = NULL; //��� ���������� ������������� ������ ����� �����������,
	Tail = NULL; //���� ������������ ���-�� �� ����� � ����� ��� ���-�� ����� (+2 ��(��)�� � ������ ������ �� �������))))
}

int List::Count()
{
	return size; //���������� ����� ��������� ������
}

void List::Add(int n, int count, int BeforeChoice, int Insta)
{
	int tempsize = 0;
	switch (n) // �������� ��� �����
	{
	case 1: //������� �������� � ����� ������
		cin.clear(); //������� ���� �� ������, ������� ����� ��������, ���� ����� ��������� � �������
		int x;

		cout << "\n������� ����� ����� (x) ����� ���������� ���, ������ ��� �������� ������������ ������ ����� (����� ��������� ���� ������� Enter)\n����: ";
		do
		{
			if (!(cin >> x)) //���� ���� ����� �������� �������, ��������, ������ �����... 
			{
				if (count < 1) //������ �������, ��� ��� ��� ���� � ������ ���� ��������� ��������� 2 ����
				{
					cout << "\n������������ ��������\n"; //...�� ������� ��������� �� ������
					if (Insta == 0) cout << "�� ����� �����\n"; Paint(L"count", 3); wcout << L" = 1 - ������ ���������, ������\n\n";
					system("Pause");
				}
				count = 1;
			}
			else
			{
				if (tempsize == 0 && Insta == 0)
				{
					cout << "\n�� ����� �����, �������, ������� ����������, ��� ����������\n\n";
					system("Pause");
				}
				else if (tempsize == 1 && Insta == 0)
				{
					system("Pause");
					cout << "\n������ ������� �� �� ����� � " << size + 1 << "-� ������\n";
				}

				size++; //��� ������ ���������� �������� ����������� ����� ��������� � ������
				tempsize++;
				if (Insta == 0 && tempsize < 3)
				{
					Paint(L"\nx", 8); wcout << " ("; cout << "�������) = " << x;
					cout << "\nsize (������) = " << tempsize;
				}
				Node* temp = new Node; //��������� ������ ��� ������ �������� ������

				if (tempsize == 1 && Insta == 0)
				{
					cout << "\n\n� ������ ��������� � ����������\n";
					Paint(L"Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - �������� ������ ��� ������ �������� ������\n";
					Paint(L"Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; cout << temp << " - � ��� � ����� ������ �������� ������\n\n";
					system("Pause");
					cout << "\n������ ������� ��������� ���� �� ����� � ���������� �������� ������ (������)\n";
					cout << "\n����� ������ = " << Head << " - ��� �����, ��� ���\n\n";
					system("Pause");
				}
				else if (size == 2 && Insta == 0)
				{
					Paint(L"\n\nNode", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - ����� �������� ������ ��� ������ �������� ������\n";
					Paint(L"Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; cout << temp << " - ����� ������ �������� ������\n";
					if (size == 2) cout << "\n� ������� ����� � ������\n\n����� ������ = " << Head << " - � �����, ��� �� ��������� � ������� ��������, ������� �� ������ ��� ��������\n\n";
					else cout << "(������ �� ����� ������ ��� ������ ��������, ��� ��� �� ����� ����� ����������)\n\n";
					system("Pause");
				}

				temp->Next = Head; //��������� �������. ��������� ������� � ��� ������ ������
				temp->x = x; //���������� � ���������� ������ ������ �������� x 

				if (tempsize == 1 && Insta == 0)
				{
					cout << "\n����� ��������� ��� �������: ��� ��� ����� �� ��������� ������� � ��� �����\n\n";
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = Head;"; cout << " - ��� ��� ������ ��� ������� �������� ���������, ����������� ��������� ������ �� ������ (���� ���� � ���)\n";
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = "; cout << temp->Next << endl;
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "x = "; Paint(L"x", 8); wcout << ";"; cout << " - � ����������� ��������� ���� �������\n";
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "x = "; cout << temp->x << "\n\n";
					system("Pause");
					cout << "\n������ ������� � ������� � ���������, ���� �� � ��� ������";
				}
				else if (tempsize == 2 && Insta == 0)
				{
					cout << "\n����� ����� ��������� ��� �������: ����� ��� ��� ����� �� ��������� ������� � ��� �����\n\n";
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = Head;"; cout << " - ��� ��� ������ ��� ������� �������� ���������, ����������� ��������� ������ �� ������\n";
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = "; cout << temp->Next << endl;
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "x = "; Paint(L"x", 8); wcout << ";"; cout << " - � ����������� ��������� ���� �������\n";
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "x = "; cout << temp->x << "\n\n";
					system("Pause");
					cout << "\n������ ������� � ������� � ���������, ���� �� � ��� ������";
				}

				if (Head != NULL) //� ��� ������ ���� ������ �� ������
				{
					Tail->Next = temp; //��������� ��������� ������ �� ��� ����� �������
					Tail = temp; //������ ������� ���� ����� �������
					if (Insta == 0 && tempsize == 2)
					{
						cout << "\n\nHead = " << Head << " - ��� �����, ��� �� �����\n";
						Paint(L"\ntemp", 8); wcout << " = "; cout << temp << "       \\";
						wcout << "\nTail"; Paint(L"->", 3); wcout << "Next = "; cout << Tail->Next << "  - ��� �����, ������������ ���������";
						cout << "\nTail = " << Tail << "       /\n\n� ��� �����...\n\n";
					}
				}
				else
				{
					if (Insta == 0) cout << " (����)\n\nHead = " << Head << " - ��� �����, ���� ��� (���� �2)";
					Head = Tail = temp; //���� ������ ����, �� ��������� ������ �������.
					if (Insta == 0)
					{
						cout << "\n\n������� ����������� �������������� ������ � ������ ��� ������� ������, �� ���� ��� ������ ������� ������ � �������, � �������\n";
						Paint(L"\ntemp", 8); wcout << " = "; cout << temp << "  \\"
							<< "\nHead = " << Head << "   - ��� �����, ������������ ���������"
							<< "\nTail = " << Tail << "  /\n\n";
					}
				}
			}
		} while (getchar() != '\n');
		if (count == 1) //���� ���� ��� � �������
		{
			cout << "\n����� ����� ����� ������� �� "; Paint(L"do", 7); wcout << "..."; Paint(L"while", 7); wcout << L" � "; Paint(L"\nif", 7); wcout << " ("; Paint(L"count", 3); wcout << " != 0)\n";
			count = 0; //�������� ������� ���...
			cout << "\n������� ���������� - "; Paint(L"count", 3); wcout << " = "; cout << count << " - � �� ������������ � ������ �������.\n\n";
			system("Pause");
			Add(n, count, BeforeChoice, Insta); //...��������
		}

		if (BeforeChoice == 1)
		{
			Add(2, 0, 0, 0);
		}
		break;

	case 2: //������� �������� � ����� ������� ����� ������� � �������
		if (size > 1)
		{

			int pos;
			int a;
			cout << "\nsize = " << size << endl;
			cout << "������� �������: ";
			CheckEnter(pos);
			if (pos <= size && pos > 1) //���� ������� �� ������ ������� ������, ������������� ����� � �� ��������� �� ������
			{
				cout << "������� a: ";
				CheckEnter(a);
				Node* temp = new Node; //�������� ������ ��� ������ �������� ������
				temp->x = a; //���������� � ���������� ������ ������ �������� �
				Paint(L"\nNode", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - �������� ������ ��� ������ �������� ������\n";
				Paint(L"Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; cout << temp << " - ����� ������ ������ �������� ������\n\n";
				Paint(L"temp", 8); Paint(L"->", 3); wcout << "x = "; Paint(L"a", 8); wcout << ";"; cout << " - � ����������� ��������� ���� �������\n";
				Paint(L"temp", 8); Paint(L"->", 3); wcout << "x = "; cout << temp->x << "\n\n";

				Node* tempHead = new Node;
				tempHead = Head; //������ ����� ������
				Paint(L"Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - �������� ������ ��� ����� ������\n";
				Paint(L"Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; cout << tempHead << " - ��� �����\n\n";
				system("pause");

				cout << "\n���������� � ����������:\n";
				if (Head != NULL) //���� ������ �� ������
				{
					if (pos == size) //��� ���� ������� ����� �������
					{
						cout << "\n���-�, ������� ����� �������, ������ ��� ������� ����� ����� �������\n";

						temp->Next = Tail; //����������� ����� ������
						cout << "\nTail = " << Tail << " - ����� ������\n";
						Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = Tail;\n";
						Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = " << temp->Next << L" - ��������� ��������� ����� �� �����\n\n";
						system("pause");

						wcout << L"\n������ ���� ����� ��������, ������� �������� �� �����, �� ���� ������� ����� ������ ����� ���������:\n\n";
						for (int i = 1; i != pos - 1; i++)
						{
							tempHead = tempHead->Next; //� ���� ������ �����, ������� �������� �� �����, �.�. ����������

							if (i == 1)
							{
								Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;";
							}
							Paint(L"\ni", 8); wcout << " = " << i << "  ";
							Paint(L"tempHead", 8); wcout << " = " << tempHead;
							if (i == pos - 2) cout << " - �����\n\n";
						}
						tempHead->Next = temp; //����������� ����� ������ ����� ������ ��������

						Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"temp", 8); wcout << L"; - �� � ����������� ��������� � ����� �������� ��� �������\n";
						Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next = " << tempHead->Next << "\n\n";
						system("pause");
					}
					else //��� ���� ����� ������ �������
					{
						cout << "\n������, ������� �� ����� �������, ����� ��������� � ����������\n\n";
						for (int i = 1; i != pos; i++)
						{
							tempHead = tempHead->Next; //���� ����� ��������, ��� ����� �� �����, ������� ������

							if (i == 1)
							{
								Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;";
							}
							Paint(L"\ni", 8); wcout << " = " << i << "  ";
							Paint(L"tempHead", 8); wcout << " = " << tempHead;
							if (i == pos - 1) //� �� ��������� �����
							{
								temp->Next = tempHead; //����������� ��������� ����� ������ ��������

								cout << " - �������, ������� �� �������\n\n";
								Paint(L"\ntemp", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"tempHead", 8); wcout << L"; - ����������� ��������� ������ �������� ����� ����������\n";
								Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = " << temp->Next << "\n\n";

								tempHead = Head; //���������� ��������, ����� ����� ���������� �����

								system("pause");
								Paint(L"\ntempHead", 8); wcout << L" = Head; - ���������� ��������\n";
								Paint(L"tempHead", 8); wcout << " = " << Head;
								wcout << L"\n\n������ ���� ����� ��������, ������� �������� �� ���������, �� ���� ������� ����� ������ ����� ����� ����� ���������:\n\n";
								for (int i = 1; i != pos - 1; i++)
								{
									tempHead = tempHead->Next; //� ���� ������ ����� ����� ��������

									if (i == 1) Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;";
									Paint(L"\ni", 8); wcout << " = " << i << "  ";
									Paint(L"tempHead", 8); wcout << " = " << tempHead;
									if (i == pos - 2) cout << " - �����\n\n";
								}
								tempHead->Next = temp; //����������� ��� ����� ������ ��������

								Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"temp", 8); wcout << L"; - �� � ����������� ��������� � ����� �������� ��� �������\n";
								Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next = " << tempHead->Next << "\n\n";
								system("pause");
							}
						}
					}
				}
				size++;
				//����� ����������� ������
				tempHead = Head; //��������
				int c = size; //��������� ���������� ������ ����� ��������� � ������
				cout << "\n���������� ������ = ( ";
				while (c != 0) //���� �� �������� ������� ������� �� ����� ������
				{
					cout << tempHead->x << " "; //��������� ������� ������ �� ����� 
					tempHead = tempHead->Next; //���������, ��� ����� ��������� �������
					c--; //���� ������� ������, ������ �������� �� ���� ������ 
				}
				cout << ")\n\nsize = " << size << endl;
				cout << "\n������� ���������� ��������� (����������� ��������)?\n"
					<< "1 - ��\n"
					<< "2 - ���\n"
					<< "����: ";
				int choice;
				CheckEnter(choice, 2);

				switch (choice)
				{
				case 1:
					Add(2, 0, 0, Insta); //�������� ��� ���������
					break;
				case 2:
					break;
				}
			}
			else //���� ������� ������ ������� ������, ������������� ����� ��� ��������� �� ������
			{
				cout << "\n������������ �������\n";
				Add(2, 0, 0, Insta); //�������� ��� ���������
			}

		}
		else
		{
			if (count == 0)
			{
				cout << "\n���������� ��������� � ������ ������ ����. \n���������� ��������� = " << size << "\n���������� � ������� ����������\n";
				cout << "\n������� ������ ��������� ������ ����������?\n"
					<< "1 - ��\n"
					<< "2 - ��� (� ���������)\n"
					<< "3 - ����� ��� (���������)\n"
					<< "����: ";
			}
			int choice;
			CheckEnter(choice, 3);

			switch (choice)
			{
			case 1: Add(1, 0, 1, 1); //�������� � ����������� ������� ��� �����������
				break;
			case 2: Add(1, 0, 1, 0); //�������� � ����������� ������� ��� �����������
				break;
			case 3:
				break;
			}
		} break;
	default: cout << "\n�������� �����������" << endl << "������� ��������: "; cin >> n; Add(n, 0, 0, Insta);
		break;
	}
}

void List::Show(int size, List& lst, int Insta)
{
	Node* tempHead = new Node; //������...
	tempHead = Head; //...����� ������
	int temp = size; //��������� ���������� ������ ����� ��������� � ������

	if (Insta == 0)
	{
		cout << "\n   ����� ������\n\n";
		Paint(L"Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";\n";
		Paint(L"tempHead", 8); wcout << " = Head;\n";
		cout << "Head = " << Head << " - ������������ ������\n";
		Paint(L"tempHead", 8); wcout << " = " << tempHead << L" - ����� ������\n\n";
		system("pause");
		Paint(L"\nint", 1); Paint(L" temp", 8); wcout << " = "; Paint(L"size", 3); wcout << ";\n";
		Paint(L"temp", 8); wcout << " = " << temp << ";";

		if (size == 0)
		{
			cout << "\n\n�������� ������: "
				<< "[ ] - ��� �����, ������ ����, ��� ��� ������ ����� ���� � �� ��� �� ��������� � ������� �����\n"
				<< "\n������ ������� ����� � ����������? (����� ���������� � �����)"
				<< "\n1 - ��"
				<< "\n2 - ��� (���������� � ���������)"
				<< "\n3 - ����� ��� (���������)"
				<< "\n����: ";
			int choice;
			CheckEnter(choice, 3);
			switch (choice)
			{
			case 1:
				lst.Add(1, 0, 0, 1);
				lst.Show(lst.Count(), lst, 0);
				break;
			case 2:
				lst.Add(1, 0, 0, 0);
				lst.Show(lst.Count(), lst, 0);
				break;
			case 3: cout << endl;
				break;
			}
		}
		else
		{
			Paint(L"\nwhile", 7); wcout << " ("; Paint(L"temp", 8); wcout << " != 0)\n";
			wcout << "{\n"
				<< "	cout <<"; Paint(L" tempHead", 8); Paint(L"->", 3); wcout << "x << \" \";\n";
			Paint(L"	tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;\n";
			Paint(L"	temp", 8); Paint(L"--", 3); wcout << ";\n";
			wcout << "}";
			cout << "\n\n� ���� ������ �� ����� ����, �� ������� ������� ����� ������,"
				<< "\n� ����� ��������� ����� ���������� ��������, ����� ���� ��������� ������ �� 1,\n"
				<< "\n������� ������� ���� �����, ��������� ����� ����� � ��� �����"
				<< "\n\n�������� ������: [ ";
			while (temp != 0) //���� �� �������� ������� ������� �� ����� ������
			{
				cout << tempHead->x << " "; //��������� ������� ������ �� ����� 
				tempHead = tempHead->Next; //���������, ��� ����� ��������� �������
				temp--; //���� ������� ������, ������ �������� �� ���� ������ 
			}
			cout << "]\n\n";
		}
	}
	else
	{
		cout << "\n\n�������� ������: [ ";
		while (temp != 0) //���� �� �������� ������� ������� �� ����� ������
		{
			cout << tempHead->x << " "; //��������� ������� ������ �� ����� 
			tempHead = tempHead->Next; //���������, ��� ����� ��������� �������
			temp--; //���� ������� ������, ������ �������� �� ���� ������ 
		}
		cout << "]\n\n";
	}
}

void List::Find()
{
	int choice, ch, have = 0, pos, a;
	if (Head != NULL)
	{

		cout << "\n������� ����� ������� �� ������������ ��� �� ������� ������-������ ����� � ��?\n"
			<< "1 - �� ������������\n"
			<< "2 - �� ������� �����\n"
			<< "����: ";
		CheckEnter(choice, 2);

		Node* tempHead = new Node;
		tempHead = Head; //������ ����� ������ ��� ��������� ��� �������� ������
		Paint(L"\nNode", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - ������ ������ ���� ���������\n";
		Paint(L"Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = " << tempHead << L" - ���������\n\n";
		system("Pause");

		switch (choice)
		{
		case 1: //����� �������� �� ������������
			cout << "\nsize = " << size;
			cout << "\n������� ������� ��������\n"
				<< "����: ";
			CheckEnter(pos);

			if (pos < 1 || pos > size)
			{
				cout << "\n��\n";
				Paint(L"pos", 8); wcout << " = " << pos
					<< "\nsize = " << size << L" - �� ���� ������� �����, ���...\n";

				cout << "\n������� �����������\n\n";
			}
			else
			{
				for (int i = 1; i != pos; i++)
				{
					if (i == 1)
					{
						cout << "\n�������� ��������:\n\n";
						Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;";
					}
					Paint(L"\ni", 8); wcout << " = " << i << "  ";
					Paint(L"tempHead", 8); wcout << " = " << tempHead;
					tempHead = tempHead->Next; //������� ������ �������� �� ������� ���������

				}
				Paint(L"\ni", 8); wcout << " = " << pos << "  ";
				Paint(L"tempHead", 8); wcout << " = " << tempHead;
				cout << " - �����\n";

				if (pos == 1) cout << "\n�� ��� ��� ������� ����� 1, �� �������� � ���� ��� ������\n";
				cout << "\n������� ������\n�����: " << tempHead
					<< "\n����������: " << tempHead->x << "\n\n";
			}
			break;

		case 2: //����� �������� �� �����
			cout << "\n������� �����\n"
				<< "����: ";
			CheckEnter(a);

			cout << "\n������� � ����:\n\n";

			for (int i = 1; i != size + 1; i++)
			{
				if (i == 1)
				{
					Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "x == "; Paint(L"a\n", 8);
					Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << L"Next - ������� �������� �����, �� � ����������\n\n";
				}
				Paint(L"i", 8); wcout << " = " << i << "  ";
				Paint(L"tempHead", 8); wcout << " = " << tempHead;
				Paint(L" tempHead", 8); Paint(L"->", 3); wcout << "x = " << tempHead->x << endl;
				if (tempHead->x == a)									//���� ������� ����� ������ ��������...
				{
					have = 1;
					cout << "\n������� ������\n�����: " << tempHead	//...������� ���
						<< "\n����������: " << tempHead->x << "\n";
					if (i != size) cout << endl;
				}
				tempHead = tempHead->Next;								//������� ������ �������� ���������
			}
			cout << endl;
			if (have == 0)
			{
				cout << "\n\n�� ������ �������� ������ �� �����, ������";
				cout << "\n������� �����������\n\n"; //���� �� ������� �� ������ ��������
			}
			break;
		}
	}
	else
	{
		cout << "\n\n������ ����";
		cout << "\n������� ������ ��������� ������ ����������?\n"
			<< "1 - ��\n"
			<< "2 - ��� (� ���������)\n"
			<< "3 - ����� ��� (���������)\n"
			<< "����: ";

		CheckEnter(ch, 3);
		switch (ch)
		{
		case 1: Add(1, 0, 0, 1); //�������� � ����������� ������� ��� �����������
			Find();
			break;
		case 2: Add(1, 0, 0, 0); //�������� � ����������� ������� ��� �����������
			Find();
			break;
		case 3: cout << endl;
			break;
		}
	}
}

void List::DelEl()
{
	int choice, ch, sum = 0, pos, a, rep = 1;
	if (Head != NULL)
	{
		Node* tempHead = new Node;
		tempHead = Head; //������ ����� ������ ��� ��������� ��� �������� ������
		Node* tempTail = new Node;
		tempTail = Tail; //������ ���������, "�������"
		Paint(L"\nNode", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - ������ ������ ���� ���������\n";
		Paint(L"tempHead", 8); wcout << L" = Head; - ����� �������� � ������\n";
		Paint(L"tempHead", 8); wcout << " = " << tempHead << L" - ���������\n\n";
		Paint(L"Node", 4); Paint(L"*", 3); Paint(L" tempTail", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - ���� ������ ������ ���� ���������\n";
		Paint(L"tempTail", 8); wcout << L" = Tail; - � \"�������\" �� ���\n";
		Paint(L"tempTail", 8); wcout << " = " << tempTail << L" - ���������\n\n";
		system("Pause");

		cout << "\n������� ������� ������� �� ������������ ��� �� ������� ������-������ ����� � ��?\n"
			<< "1 - �� ������������\n"
			<< "2 - �� ������� �����\n"
			<< "����: ";
		CheckEnter(choice, 2);
		switch (choice)
		{
		case 1: //�������� �������� �� ������������
			cout << "\n\n������� ������� ��������\n"
				<< "����: ";
			CheckEnter(pos);

			if (pos < 1 || pos > size)
			{
				cout << "\n��\n";
				Paint(L"pos", 8); wcout << " = " << pos
					<< "\nsize = " << size << L" - �� ���� ������� �����, ���...\n";

				cout << "\n������� �����������\n";
			}
			else
			{

				if (pos == 1)
				{
					Head = tempHead->Next;			//���� ��������� ������, �� ������� ���������� ��������� �������

					cout << "\n���� � ��� ������� ����� 1, �� ������� ���������� ��������� �� ��� �������\n\n"
						<< "Head = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;\n"
						<< "Head = " << Head << "\n\n";
				}
				else
				{
					for (int i = 1; i != pos; i++)
					{
						if (i == 1)
						{
							cout << "\n���� ������� �� ����� 1, �� ������� � ���� ��������\n\n";
							Paint(L"tempTail", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << L"; - \"��������\" ����������� ������� ������� ���������\n";
							Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << L"Next; - ����� ���� ������� ��������� ��� ��������� �������, ���� �� ����� �� �������\n";
							Paint(L"tempTail", 8); wcout << " = " << tempTail << endl;
							Paint(L"tempHead", 8); wcout << " = " << tempHead << "\n\n";
						}

						Paint(L"i", 8); wcout << " = " << i << "   ";
						Paint(L"tempTail", 8); wcout << " = " << tempTail;
						Paint(L"  tempHead", 8); wcout << " = " << tempHead << endl;

						tempTail = tempHead;			//"�������" ������� "���������"
						tempHead = tempHead->Next;		//� ��� ���� ����� ������� ��������

					}

					Paint(L"i", 8); wcout << " = " << pos << "   ";
					Paint(L"tempTail", 8); wcout << " = " << tempTail;
					Paint(L"  tempHead", 8); wcout << " = " << tempHead;
					cout << " - �����\n\n";
				}
				system("pause");

				tempTail->Next = tempHead->Next;	//����������� ��������� "��������" ��������� �� ��������� ��������� �����, ����� ������� ������ �� ���������
				Paint(L"\ntempTail", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << L"Next; - ����� ��������� ������ ����������� ��������� \"��������\" ����� �� �������, ������� ����� ����������\n";
				Paint(L"tempTail", 8); Paint(L"->", 3); wcout << "Next = " << tempTail->Next;

				delete tempHead;					//����� ���� �������� ������� ��� �������
				size--;								//�� �������� ��������� ������
				Paint(L"\n\ndelete", 1); Paint(L" tempHead", 8); wcout << L"; - � ������� ������� �� �������\n"
					<< L"size--; - ��������� ������\n";
				Paint(L"tempHead", 8); wcout << " = " << tempHead << L" - ��� �����, �� �� ������ ������, �� �� ��-���� ����� �� ������";
				wcout << "\nsize = " << size;

				cout << "\n\n������� ������ � �����\n\n";
			}
			break;

		case 2: //�������� �������� �� �����
			cout << "\n\n������� �����\n"
				<< "����: ";
			CheckEnter(a);

			cout << "\n������� � ����:\n\n";

			for (int i = 1; i != size + 1; i++)
			{
				if (tempHead->x == a)
				{
					Node* del = new Node;				//������ �������, ������� ����� ����� ������� ��� ����������

					if (i <= 2)
					{
						Paint(L"i", 8); wcout << " = " << i << "   ";
						Paint(L"tempTail", 8); wcout << " = " << tempTail;
						Paint(L"  tempHead", 8); wcout << " = " << tempHead << L" - ������ ������� � ������\n\n";
						system("pause");
					}

					sum++;								//������ ������� �������� ���������
					tempTail->Next = tempHead->Next;	//����������� ��������� "��������" ��������� �� ��������� ��������� �����, ����� ������� ������ �� ���������
					del = tempHead;						//��������� ������� ��������� �� ������ ��� ���������

					if (i <= 2)
					{
						Paint(L"\nNode", 4); Paint(L"*", 3); Paint(L" del", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << L"; - ������ 3-� �������, ����� ���������� �������� ��� �������\n";
						Paint(L"sum", 8); wcout << L"++; - ���������, ��� �� ����� �������\n";
						Paint(L"tempTail", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << L"Next; - ������� ��������� \"��������\" ����������� ����� �������� �� ���������\n";
						Paint(L"del", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << L"; - ��������� ��������� ������� �� ������ ��� ���������\n\n";
						Paint(L"sum", 8); wcout << " = " << sum << endl;
						Paint(L"tempTail", 8); Paint(L"->", 3); wcout << "Next = " << tempTail->Next << endl;
						Paint(L"del", 8); wcout << " = " << del << "\n\n";
						system("pause");
					}

					if (size == sum) //���� �� ������� ������ � ��� ���� � ������
					{
						delete del;			//�������
						Head = Tail = NULL; //��������

						cout << "\n� ������ 1 �������, ������ ��� ������ � �����\n";
						Paint(L"delete", 1); Paint(L" del", 8); wcout << L"; - ������� ���\n";
						wcout << "Head = Tail = "; Paint(L"NULL", 8); wcout << L"; - � ��� ������������ �������� ������ � �����\n";

						cout << "\n������� ������ � �����\n\n";
					}
					else
					{
						if (Head == tempHead)
						{
							Head = tempHead->Next;			 //���� ��������� ������, �� ������� ���������� ��������� �������

							if (i <= 2)
							{
								cout << "\n���� ��������� ������� ������, �� ���� ������, �� ������ ������� ��������� �������\n";
								wcout << "Head = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;\n"
									<< "Head = " << Head << endl;
							}
						}

						tempTail = tempHead;				 //"�������" ������� "���������"
						tempHead = tempHead->Next;			 //��������� � ���������� ��������

						delete del;							 //� ������ ����� �������

						if (i <= 2)
						{
							cout << "\n������������ ���������:\n";
							Paint(L"tempTail", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << ";\n";
							Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;\n";
							Paint(L"tempTail", 8); wcout << " = " << tempTail;
							Paint(L"  tempHead", 8); wcout << " = " << tempHead << endl;

							Paint(L"\ndelete", 1); Paint(L" del", 8); wcout << L"; - � ������� �������\n";
							Paint(L"del", 8); wcout << " = " << del << endl;
						}

						cout << "\n������� ������ � �����\n\n";
					}

				}
				else //���� �� �����
				{

					tempTail = tempHead;			 //"�������" ������� "���������"
					tempHead = tempHead->Next;		 //��������� � ���������� ��������

					if (rep <= 2)
					{
						rep++;
						Paint(L"i", 8); wcout << " = " << i << "   ";
						Paint(L"tempTail", 8); wcout << " = " << tempTail;
						Paint(L"  tempHead", 8); wcout << " = " << tempHead << L" - ������ �� ������� � ������, ��� ������\n";
					}
				}
			}
			cout << "� ��� �����, ����� ���� ������� �� �����";

			if (sum == 0)
			{
				cout << "\n\n������ �� ������ �������� ������ �� �����, ������";
				cout << "\n������� �����������\n\n"; //���� �� ������� �� ������ ��������
			}
			else
			{
				size -= sum;							 //�������� �������� ������
				wcout << L"\n\nsize -="; Paint(L" sum", 8); wcout << L"; - ��������� ������ � �������\n"
					<< "size = " << size << "\n\n";
			}
			break;
		}
	}
	else
	{
		cout << "\n\n������ ����";
		cout << "\n������� ������ ��������� ������ ����������?\n"
			<< "1 - ��\n"
			<< "2 - ��� (� ���������)\n"
			<< "3 - ����� ��� (���������)\n"
			<< "����: ";

		CheckEnter(ch, 3);
		switch (ch)
		{
		case 1: Add(1, 0, 0, 1); //�������� � ����������� ������� ��� �����������
			DelEl();
			break;
		case 2: Add(1, 0, 0, 0); //�������� � ����������� ������� ��� �����������
			DelEl();
			break;
		case 3: cout << endl;
			break;
		}
	}
}

void Introduction()
{
	cout << "    � ���������:\n\n"
		<< "������ ��������� ������������� ��� ������������ � ������������ ������������ �������� � �������� �� �������� ��������� �� ����� C++, "
		<< "\n����� ����� �������� ��� �� �������� ����� ��������� ���������� � ����, �� ����� ���������� � ��������� ��� �� ����� "
		<< "������������\n� ������ �������� ���������� � �������� � ���������� ������� � ����. ��������� ���������� ������ �� ������� ����"; Paint(L" int ", 1);
	wcout << L"\n� �� ���������� �� ���������������� ������������� ��� �������� ���� � �� ��� ��������� ������������.\n\n";

	cout << "\n1 - ������� � ����\n"
		<< "����: ";
}

void AboutList()
{
	cout << "    ����: �� ����������� ����������� ������\n\n"
		<< "�� ��������� ��������, ��� ���������� ������� �� ����������� ����������� ������� ��������� ���������� �����\n"
		<< "� ���������� ������� ����� �� ��������� ����� ���� �������������� �������. ����� � ���, ��� � ����� ������� ��� ������ � ��� �����.\n"
		<< "�� ���� ����� ������ (�����) ��������� �� ������ (������) � ����� ������� ���������� ��������� ����.\n\n";
}

void StructureOfList()
{
	cout << "    ����: �������� ��������� ������\n\n"
		<< "������ ��� ������ ������ �� �������, ����� ������� ��������� (����� ���), ������� ����� ������� � ���� ������� ������.\n"
		<< "��� ���������� ������ ��������� � ���������� ������ � ���������:\n\n";
	Paint(L"struct ", 1); Paint(L"Node\n", 4);
	wcout << "{\n";
	Paint(L"	int", 1); wcout << " x;          "; Paint(L"//���� ������\n", 5);
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Next;     "; Paint(L"//��������� (*) �� ��������� �������\n", 5);
	wcout << "}\n\n";

}

void ClassOfList()
{
	cout << "    ����: �������� ������ ������\n\n"
		<< "����� �� �������� ����� ���� �������� � ����������, ������ ����� ����� (����� ���) c ����������� ������ � ����� ��������� � ��.\n"
		<< "� ����� ����������������� ��������� �������� ������ � public � ������� ������������:\n\n";
	Paint(L"class ", 1); Paint(L"List\n", 4);
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Head, "; Paint(L"*", 3); wcout << " Tail;"; Paint(L"   //��������� ������ ������� (������) � ���, ��� ��������� (�����)\n", 5);
	Paint(L"	int ", 1); wcout << "size"; Paint(L"              //����� ��������� � ������\n", 5);
	Paint(L"public:\n", 1);
	Paint(L"	List", 2); wcout << "() : Head("; Paint(L"NULL", 8); wcout << "), Tail("; Paint(L"NULL", 8); wcout << "), size(0) {};"; Paint(L" //������������� ��������� � ���� � ������� ������������\n", 5);
	wcout << "}\n\n";
}

void AddElementToEnd(List& lst)
{
	cout << "    ����: ���������� ��������� � ����� ������\n\n"
		<< "����� ������ ��� �������, �������, ��� ����� ��� ���������, � ������ ������ �� ����� ���, � ����� �����, � ����� ������ ��� ���\n"
		<< "������� �����, ������� ��� ������ ������� � "; Paint(L"public", 1); wcout << L" ������ �� ������������ ������� ���������� ��������� � ������:\n\n";
	Paint(L"class ", 1); Paint(L"List\n", 4);
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Head, "; Paint(L"*", 3); wcout << " Tail;"; Paint(L"   //��������� ������ ������� (������) � ���, ��� ��������� (�����)\n", 5);
	Paint(L"	int ", 1); wcout << "size"; wcout << ";"; Paint(L"             //����� ��������� � ������\n", 5);
	Paint(L"public:\n", 1);
	Paint(L"	List", 2); wcout << "() : Head("; Paint(L"NULL", 8); wcout << "), Tail("; Paint(L"NULL", 8); wcout << "), size(0) {};"; Paint(L"	//������������� ��������� � ���� � ������� ������������\n", 5);
	wcout << "	+ "; Paint(L"void", 1); Paint(L" Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");"; Paint(L"	//������� ���������� ��������� � ������\n", 5);
	wcout << "}\n"
		<< L"\n��� "; Paint(L"n", 3); wcout << L" - ����� ������� ���������� (���� � ��� ��� ����);";
	Paint(L"\ncount", 3); wcout << L" - ������� ������ ��� ����� (�������������);";
	Paint(L"\nBeforeChoice", 3); wcout << L" - ������� ������� ��� ������ ������� ���������� (����� � ��� �����)\n\n";
	system("Pause");

	cout << "\n������ �������� ���� �������:\n"
		<< "\n���������� ����� ��������: \""; Paint(L"->", 3); cout << "\" - ������ � �������� �� ���������, �� ���� ������ � ����, �� ��� ���������\n";
	Paint(L"\nvoid ", 1); Paint(L"List", 4); wcout << "::"; Paint(L"Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");\n";
	wcout << "{\n";
	Paint(L"	switch", 7); wcout << " ("; Paint(L"n", 3); wcout << ")\n"
		<< "	{\n";
	Paint(L"	case", 7); wcout << " 1: "; Paint(L"//������� �������� � ����� ������\n", 5);
	wcout << "		cin."; Paint(L"clear", 2); wcout << "();"; Paint(L" //������� ���� �� ������, ������� ����� ��������, ���� ����� ��������� � �������\n", 5);
	Paint(L"		int ", 1); Paint(L"x", 8); wcout << ";\n"
		<< "		cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"������� ����� �����(x) ����� ���������� ��� (����� ��������� ���� ������� Enter)", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";\n";
	Paint(L"		do\n", 7);
	wcout << "		{\n";
	Paint(L"			if", 7); wcout << " (!(cin >> "; Paint(L"x", 8); wcout << "))"; Paint(L" //���� ���� ����� �������� �������, ��������, ������ �����...\n", 5);
	wcout << "			{\n";
	Paint(L"				if", 7); wcout << " ("; Paint(L"count", 3); wcout << " < 1)"; Paint(L" //������ �������, ��� ��� ��� ���� � ������ ���� ��������� ��������� 2 ����\n", 5);
	wcout << "				{\n";
	wcout << "					cout << "; Paint(L"\"������������ ��������", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << "; "; Paint(L"//...�� ������� ��������� �� ������\n", 5);
	wcout << "				}\n";
	Paint(L"				count ", 3); wcout << "= 1;\n";
	wcout << "			}\n";
	Paint(L"			else", 7); Paint(L" //� ���� ���� ��� ������\n", 5);
	wcout << "			{\n"
		<< "				size"; Paint(L"++", 3); wcout << ";"; Paint(L"				//��� ������ ���������� �������� ����������� ����� ��������� � ������\n", 5);
	Paint(L"				Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; Paint(L"		//�������� ������ ��� ������ �������� ������\n", 5);
	Paint(L"				temp", 8); Paint(L"->", 3); wcout << "Next = Head;"; Paint(L"		//�������� ������. ��������� ������� � ��� '������' ������\n", 5);
	Paint(L"				temp", 8); Paint(L"->", 3); wcout << "x = "; Paint(L"x", 8); wcout << ";"; Paint(L"			//���������� � ���������� ������ ������ �������� x\n", 5);
	Paint(L"\n				if", 7); wcout << " (Head != "; Paint(L"NULL", 8); wcout << ")"; Paint(L"		//� ��� ������ ���� ������ �� ������\n", 5);
	wcout << "				{\n";
	wcout << "					Tail"; Paint(L"->", 3); wcout << "Next = "; Paint(L"temp", 8); wcout << ";"; Paint(L"	//��������� ��������� ������ �� ��� ����� �������\n", 5);
	wcout << "					Tail = "; Paint(L"temp", 8); wcout << ";"; Paint(L"		//������ ������� ���� ����� �������\n", 5);
	wcout << "				}\n";
	Paint(L"				else", 7); wcout << " Head = Tail = "; Paint(L"temp", 8); wcout << ";"; Paint(L"	//� ���� ������ ����, �� ��������� ������ �������\n", 5);
	wcout << "			}\n"
		<< "		} "; Paint(L"while", 7); wcout << " ("; Paint(L"getchar", 2); wcout << "() != '"; Paint(L"\\n", 2); wcout << "');"; Paint(L" //���� � ����� �� ������ Enter\n", 5);
	Paint(L"\n		if", 7); wcout << " ("; Paint(L"count", 3); wcout << " != 0)"; Paint(L" //���� ���� ��� � �������\n", 5);
	wcout << "		{\n";
	Paint(L"			count", 3); wcout << " = 0;"; Paint(L"			//�������� ������� ���...\n", 5);
	Paint(L"			Add", 2); wcout << "("; Paint(L"n", 3); wcout << ","; Paint(L" count", 3); wcout << ","; Paint(L" BeforeChoice", 3); wcout << ");"; Paint(L"	//...��������\n", 5);
	wcout << "		}\n";
	Paint(L"		break", 7); wcout << ";\n";
	Paint(L"	case", 7); wcout << " 2: ... break; "; Paint(L" //������� �������� � ����� ������� ����� ������� � �������, ���� �� �����\n", 5);
	wcout << "}\n\n";
	system("Pause");

	cout << "\n������ ������� ��������� �� ��������:\n\n";
	system("Pause");
	cout << "\n�������� ���������� ����, ������� �� �������:\n\n";
	Paint(L"List", 4); Paint(L" lst", 8); wcout << ";\n\n";
	system("Pause");
	cout << "\n� ������� ������� ���������� ���������:\n\n";
	Paint(L"List", 4); Paint(L" lst", 8); wcout << ";\n";
	Paint(L"lst", 8); wcout << "."; Paint(L"Add", 2); wcout << "(1, 0, 0);"; Paint(L" //��� 1 - ��������������� ������\n", 5);
	lst.Add(1, 0, 0, 0);
}

void AddElementBetweenNum(List& lst)
{
	cout << "    ����: ���������� ��������� ����� ������� ���������� ������\n\n"
		<< "������ ����� � ������� ������ �������� ������� �� �����-������ ���������� �����, ��� ����� ����� ����� ������ ������ � ���������� ���� �������.\n"
		<< "��� ��� ��� ������� ������� � ����������� ��������, �� ��� ����� � "; Paint(L"Add", 2); wcout << "(...)\n";
	Paint(L"\nvoid ", 1); Paint(L"List", 4); wcout << "::"; Paint(L"Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");\n";
	wcout << "{\n";
	Paint(L"	switch", 7); wcout << " ("; Paint(L"n", 3); wcout << ")\n"
		<< "	{\n";
	Paint(L"	case", 7); wcout << " 1: ..."; Paint(L" break;", 7); Paint(L" //������� �������� � ����� ������\n\n", 5);
	Paint(L"	case", 7); wcout << " 2:"; Paint(L" //������� �������� � ����� ������� ����� ������� � �������\n", 5);
	Paint(L"		if", 7); wcout << " (size > 1)\n"
		<< "		{\n";
	Paint(L"			int", 1); Paint(L" pos", 8); Paint(L"	//�������\n", 5);
	Paint(L"			int", 1); Paint(L" a", 8); Paint(L"	//�������� ������������� �����\n", 5);
	wcout << "			cout << "; Paint(L"\"size = \"", 6); wcout << " << size << "; Paint(L"endl", 2); wcout << ";\n";
	wcout << "			cout << "; Paint(L"\"������� �������", 6); wcout << ":"; Paint(L"\"", 6); wcout << ";\n";
	Paint(L"			if", 7); wcout << " (cin >> "; Paint(L"pos", 8); wcout << ")\n";
	wcout << "			{\n";
	Paint(L"				if", 7); wcout << " ("; Paint(L"pos", 8); wcout << " <= size "; Paint(L"&&", 3); Paint(L" pos", 8); wcout << " > 1)"; Paint(L" //���� ������� �� ������ ������� ������, ������������� ����� � �� ��������� �� ������\n", 5);
	wcout << "				{\n";
	wcout << "					cout << "; Paint(L"\"������� a: \"", 6); wcout << ";\n";
	wcout << "					cin >> "; Paint(L"a", 8); wcout << ";\n";
	Paint(L"					Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; Paint(L"	//�������� ������ ��� ������ �������� ������\n", 5);
	Paint(L"					temp", 8); Paint(L"->", 3); wcout << "x = "; Paint(L"a", 8); wcout << ";"; Paint(L"		//���������� � ���������� ������ ������ �������� �\n", 5);
	Paint(L"					Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";\n";
	Paint(L"					tempHead", 8); wcout << " = Head;"; Paint(L"	//������ ����� ������\n", 5);
	Paint(L"					if", 7); wcout << " (Head != "; Paint(L"NULL", 8); wcout << ")"; Paint(L" //���� ������ �� ������\n", 5);
	wcout << "					{\n";
	Paint(L"						if", 7); wcout << " ("; Paint(L"pos", 8); wcout << " == size)"; Paint(L" //��� ���� ������� ����� �������\n", 5);
	wcout << "						{\n";
	Paint(L"							temp", 8); Paint(L"->", 3); wcout << "Next = Tail;"; Paint(L" //����������� ����� ������\n", 5);
	Paint(L"							for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " != "; Paint(L"pos", 8); wcout << " - 1;"; Paint(L" i", 8); Paint(L"++", 3); wcout << ")\n";
	wcout << "							{\n";
	Paint(L"								tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L" //� ���� ������ �����, ������� �������� �� �����, �.�. ����������\n", 5);
	wcout << "							}\n";
	Paint(L"							tempHead", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"temp", 8); wcout << ";"; Paint(L" //����������� ����� ������ ����� ������ ��������\n", 5);
	wcout << "						}\n";
	Paint(L"						else", 7); Paint(L" //��� ���� ����� ������ �������\n", 5);
	wcout << "						{\n";
	Paint(L"							for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " != "; Paint(L"pos", 8); wcout << ";"; Paint(L" i", 8); Paint(L"++", 3); wcout << ")\n";
	wcout << "							{\n";
	Paint(L"								tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"	//���� ����� ��������, ��� ����� �� �����, ������� ������\n", 5);
	Paint(L"								if", 7); wcout << " ("; Paint(L"i", 8); wcout << " == "; Paint(L"pos", 8); wcout << " - 1)"; Paint(L"				//�� ��������� ����� \"����\"\n", 5);
	wcout << "								{\n";
	Paint(L"									temp", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"tempHead", 8); wcout << ";"; Paint(L"			//����������� ��������� ����� ������ ��������\n", 5);
	Paint(L"									tempHead", 8); wcout << " = Head;"; Paint(L"			//���������� ��������, ����� ����� ���������� �����\n", 5);
	Paint(L"									for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " != "; Paint(L"pos", 8); wcout << " - 1;"; Paint(L" i", 8); Paint(L"++", 3); wcout << ")\n";
	wcout << "									{\n";
	Paint(L"										tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"	//� ���� ������ ����� ����� ��������\n", 5);
	wcout << "									}\n";
	Paint(L"									tempHead", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"temp", 8); wcout << ";"; Paint(L"	//����������� ��� ����� ������ ��������\n", 5);
	wcout << "								}\n"
		<< "							}\n"
		<< "						}\n"
		<< "					}\n";
	wcout << "					size"; Paint(L"++", 3); wcout << ";\n\n";
	Paint(L"					//����� ����������� ������\n", 5);
	Paint(L"					//����� ��������� ��� ������� Show()\n", 5);
	wcout << "					cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"���������� ������ = (\"", 6); wcout << ";\n";
	Paint(L"					//���� �� �������\n", 5);
	wcout << "					cout << "; Paint(L"\")", 6); Paint(L"\\n", 2); Paint(L"size = \"", 6); wcout << " << size << "; Paint(L"endl", 2); wcout << ";\n"
		<< "				}\n";
	Paint(L"				else", 7); Paint(L" //���� ������� ������ ������� ������, ������������� ����� ��� ��������� �� ������\n", 5);
	wcout << "				{\n";
	wcout << "					cout << "; Paint(L"\"������������ �������", 6); Paint(L"\\n", 2); wcout << ";\n";
	Paint(L"					Add", 2); wcout << "(2, 0, 0);"; Paint(L" //�������� ��� ���������\n", 5);
	wcout << "				}\n"
		<< "			}\n"
		<< "		}\n";
	Paint(L"		else", 7); wcout << "{...}"; Paint(L"	//���� ������ ������ ����� ����, �� ���������� ������� �������� �������� ����� �����,\n", 5);
	Paint(L"		break", 7); wcout << ";"; Paint(L"		//����� �������� ������ �������� case 2 (BeforeChoice = 1), ������ ���� ������� ��� �� �����\n", 5);
	Paint(L"	default", 7); wcout << ": cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"�������� �����������\"", 6); wcout << " << "; Paint(L"endl", 2); wcout << " << "; Paint(L"\"������� ��������: \"", 6); wcout << "; cin >> "; Paint(L"n", 3); wcout << ";"; Paint(L" Add", 2); wcout << "("; Paint(L"n", 3); wcout << ", 0, 0);\n";
	Paint(L"		break", 7); wcout << ";\n"
		<< "	}\n"
		<< "}\n";
	cout << "\n�������� ���������, ������ ���� ������ ���������� ��������� � "; Paint(L"if", 7); wcout << " (Head != "; Paint(L"NULL", 8); wcout << ") {...}\n";
	cout << "� �������� �������� ���������, �������� �� �������, ����� ������� �� ����� ������� ������.\n"
		<< "�� ���� ��������� �� ���������� � ����������� ���������� ������, �� �� ���������� �������, ��� � �� ������ ������ ����� � �����.\n\n";
	system("pause");

	cout << "\n����� ������ ��������� � ������������ ����� ������:\n\n";
	Paint(L"List", 4); Paint(L" lst", 8); wcout << ";\n";
	Paint(L"lst", 8); wcout << "."; Paint(L"Add", 2); wcout << "(2, 0, 0);"; Paint(L" //��� 2 - ��������������� ������\n", 5);
	lst.Add(2, 0, 0, 0);

	cout << "\n��� � �� ����������\n\n";
}

void OutputList(List& lst)
{
	cout << "    ����: ����� ��������� ������\n\n"
		<< "������ ����, �� ��������, � ������ ����� ������, ��� � �� ����, � ���� ���.\n"
		<< "����� ���� ������� � "; Paint(L"public", 1); wcout << L" ��� ������� ������ ������ �, ��������, �������, ������������ ������ ������:\n\n";
	Paint(L"class ", 1); Paint(L"List\n", 4);
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Head, "; Paint(L"*", 3); wcout << " Tail;"; Paint(L"   //��������� ������ ������� (������) � ���, ��� ��������� (�����)\n", 5);
	Paint(L"	int ", 1); wcout << "size"; wcout << ";"; Paint(L"             //����� ��������� � ������\n", 5);
	Paint(L"public:\n", 1);
	Paint(L"	List", 2); wcout << "() : Head("; Paint(L"NULL", 8); wcout << "), Tail("; Paint(L"NULL", 8); wcout << "), size(0) {};"; Paint(L"	//������������� ��������� � ���� � ������� ������������\n", 5);
	Paint(L"	void", 1); Paint(L" Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");"; Paint(L"	//������� ���������� ��������� � ������\n", 5);
	wcout << "	+ "; Paint(L"void", 1); Paint(L" Show", 2); wcout << "("; Paint(L"int", 1); Paint(L" size", 3); wcout << ");"; Paint(L"				//������� ����������� ��������� ������\n", 5);
	wcout << "	+ "; Paint(L"int", 1); Paint(L" Count", 2); wcout << "();"; Paint(L"					//�������, ������������ ����� ��������� � ������\n", 5);
	wcout << "}\n\n";
	cout << "���� ����� ������,"; Paint(L" Show", 2); wcout << "("; Paint(L"int", 1); Paint(L" size", 3); wcout << L"), ������� ��� ���� �����, �� ����������� ������� ������, "; Paint(L"Count", 2); wcout << L"(), �� ������.\n"
		<< L"��� �� ������, ��� ��� �� ���� ������� ������� �������� ������ ������ � � ���������� ���� "; Paint(L"private", 1); wcout << L"\n(������� ����� �� ��������� �� "; Paint(L"public", 1); wcout << L"). "
		<< L"������ � ����� �������� �������� ������ ������� ������, � ��� ������ ������ ������.\n"
		<< L"����� ���� ������� �� ��� ����������, ����� ������� ����� ������� ������, "; Paint(L"int", 1); Paint(L" Count", 2); wcout << L"(), ������� � ����� ���������� ���� �������:\n\n";
	Paint(L"int", 1); Paint(L" List", 4); wcout << "::"; Paint(L"Count", 2); wcout << "()\n"
		<< "{\n"
		<< "	"; Paint(L"return", 7); wcout << " size;"; Paint(L" //���������� ����� ��������� ������\n", 5);
	wcout << "}\n"
		<< L"\n��� ��� �� ������\n\n";
	system("Pause");

	cout << "\n������ ������� ��������� � ������ ������ ������\n\n";
	Paint(L"void", 1); Paint(L" List", 4); wcout << "::"; Paint(L"Show", 2); wcout << "("; Paint(L"int", 1); Paint(L" size", 3); wcout << ")\n";
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; Paint(L"	//������...\n", 5);
	Paint(L"	tempHead", 8); wcout << " = Head;"; Paint(L"		//...����� ������\n", 5);
	Paint(L"	int", 1); Paint(L" temp", 8); wcout << " = "; Paint(L"size", 3); wcout << ";"; Paint(L"		//������ ��������� ���������� � ����������� � ����� ��������� � ������ (������)\n", 5);
	wcout << L"	cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"�������� ������: ", 6); Paint(L"\"", 6); wcout << ";\n";
	Paint(L"	while", 7); wcout << " ("; Paint(L"temp", 8); wcout << " != 0)"; Paint(L"			//���� �� �������� ������� ������� �� ����� ������\n", 5);
	wcout << "	{\n"
		<< "		cout <<"; Paint(L" tempHead", 8); Paint(L"->", 3); wcout << "x << \" \";"; Paint(L"	//������� ��������� �������� ������ �� �����\n", 5);
	Paint(L"		tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"	//� ����� ���������, ��� ����� ��������� �������\n", 5);
	Paint(L"		temp", 8); Paint(L"--", 3); wcout << ";";  Paint(L"				//���� ������� ������, ������ ��������� ������ ��������� ���������� �� ����\n", 5);
	wcout << "	}\n"
		<< "}\n\n";
	system("Pause");

	cout << "\n�� � ������� ������� ������ �� ���������, ������� �� ������� � 3-� � 4-� ����\n\n";
	Paint(L"lst", 8); wcout << "."; Paint(L"Show", 2); wcout << "("; Paint(L"lst", 8); wcout << "."; Paint(L"Count", 2); wcout << "());\n\n";
	lst.Show(lst.Count(), lst, 0);
}

void LookingForElement(List& lst)
{
	cout << "    ����: ����� �������� �� �������\n\n"
		<< "����� �������� ������������� ����� ��� �� ������� � ������ ��� �� ������� � �� ����, ��� �� �����:\n"
		<< "- ��� ������ �� ������� ����� 1 ���������, ����� ���� ������ ���� ���������� ������, ����� � ������;\n"
		<< "- ��� ������ �� ������� ����� ��������� ���� ������ � ��� �� �������� ����� ����.\n\n"
		<< "������� � "; Paint(L"public", 1); wcout << L" ������ �� ������������ ������� ������ �������� � ������:\n\n";

	Paint(L"class ", 1); Paint(L"List\n", 4);
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Head, "; Paint(L"*", 3); wcout << " Tail;"; Paint(L"   //��������� ������ ������� (������) � ���, ��� ��������� (�����)\n", 5);
	Paint(L"	int ", 1); wcout << "size"; wcout << ";"; Paint(L"             //����� ��������� � ������\n", 5);
	Paint(L"public:\n", 1);
	Paint(L"	List", 2); wcout << "() : Head("; Paint(L"NULL", 8); wcout << "), Tail("; Paint(L"NULL", 8); wcout << "), size(0) {};"; Paint(L"	//������������� ��������� � ���� � ������� ������������\n", 5);
	Paint(L"	void", 1); Paint(L" Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");"; Paint(L"	//������� ���������� ��������� � ������\n", 5);
	Paint(L"	void", 1); Paint(L" Show", 2); wcout << "("; Paint(L"int", 1); Paint(L" size", 3); wcout << ");"; Paint(L"				//������� ����������� ��������� ������\n", 5);
	Paint(L"	int", 1); Paint(L" Count", 2); wcout << "();"; Paint(L"					//�������, ������������ ����� ��������� � ������\n", 5);
	wcout << "	+ "; Paint(L"void", 1); Paint(L" Find", 2); wcout << "();"; Paint(L"					//������� ������ ��������\n", 5);
	wcout << "}\n\n";
	system("Pause");

	cout << "\n���������� ���:\n\n";
	Paint(L"void", 1); Paint(L" List", 4); wcout << "::"; Paint(L"Find", 2); wcout << "()\n";
	wcout << "{\n";
	Paint(L"	int", 1); Paint(L" choice", 8); wcout << ","; Paint(L" ch", 8); wcout << ","; Paint(L" have", 8); wcout << " = 0,"; Paint(L" pos", 8); wcout << ","; Paint(L" a", 8); wcout << ";\n";
	Paint(L"	if", 7); wcout << " (Head != "; Paint(L"NULL", 8); wcout << ")\n"
		<< "	{\n";
	Paint(L"		Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";\n";
	Paint(L"		tempHead", 8); wcout << " = Head;"; Paint(L" //������ ����� ������ ��� ��������� ��� �������� ������\n\n", 5);
	wcout << "		cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"������� ����� ������� �� ������������ ��� �� ������� ������-������ ����� � ��?", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";\n";
	wcout << "			<< "; Paint(L"\"1 - �� ������������", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "			<< "; Paint(L"\"2 - �� ������� �����", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "			<< "; Paint(L"\"����: \"", 6); wcout << ";\n"
		<< "		cin >>"; Paint(L" choice", 8); wcout << ";\n";
	Paint(L"		switch", 7); wcout << " ("; Paint(L"choice", 8); wcout << ")\n"
		<< "		{\n";
	Paint(L"		case", 7); wcout << " 1:"; Paint(L"	//����� �������� �� ������������\n", 5);
	wcout << "			cout << "; Paint(L"\"", 6); Paint(L"\\n\\n", 2); Paint(L"������� ������� ��������", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "				<< "; Paint(L"\"����: \"", 6); wcout << ";\n"
		<< "			cin >>"; Paint(L" pos", 8); wcout << ";\n\n";
	Paint(L"			if", 7); wcout << " ("; Paint(L"pos", 8); wcout << " < 1 || "; Paint(L"pos", 8); wcout << " > size)\n"
		<< "			{\n"
		<< "				cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"������� �����������", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";\n";
	Paint(L"				Find", 2); wcout << "();\n"
		<< "			}\n";
	Paint(L"			else\n", 7);
	wcout << "			{\n";
	Paint(L"				for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " !="; Paint(L" pos", 8); wcout << ";"; Paint(L" i", 8); wcout << "++)\n"
		<< "				{\n";
	Paint(L"					tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L" //������� ������ �������� �� ������� ���������\n", 5);
	wcout << "				}\n";
	wcout << "					cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"������� ������", 6); Paint(L"\\n", 2); Paint(L"�����: \"", 6); wcout << " << "; Paint(L"tempHead\n", 8);
	wcout << "						<< "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"����������: \"", 6); wcout << " << "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "x"; wcout << " << "; Paint(L"endl", 2); wcout << ";\n";
	wcout << "			}\n";
	Paint(L"			break", 7); wcout << ";\n\n";
	Paint(L"		case", 7); wcout << " 2:"; Paint(L"	//����� �������� �� �����\n", 5);
	wcout << "			cout << "; Paint(L"\"", 6); Paint(L"\\n\\n", 2); Paint(L"������� �����", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "				<< "; Paint(L"\"����: \"", 6); wcout << ";\n"
		<< "			cin >>"; Paint(L" a", 8); wcout << ";\n\n";
	Paint(L"			for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " != size;"; Paint(L" i", 8); wcout << "++)\n"
		<< "			{\n";
	Paint(L"				if", 7); wcout << " ("; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "x == "; Paint(L"a", 8); wcout << ")"; Paint(L"						//���� ������� ����� ������ ��������...\n", 5);
	wcout << "				{\n";
	Paint(L"					have", 8); wcout << " = 1;\n";
	wcout << "					cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"������� ������", 6); Paint(L"\\n", 2); Paint(L"�����: \"", 6); wcout << " << "; Paint(L"tempHead", 8); Paint(L"		//...������� ���\n", 5);
	wcout << "						<< "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"����������: \"", 6); wcout << " << "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "x"; wcout << " << "; Paint(L"endl\n", 2);
	wcout << "				}\n";
	Paint(L"				tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"					//������� ������ �������� ���������\n", 5);
	wcout << "			}\n";
	Paint(L"			if", 7); wcout << " ("; Paint(L"have", 8); wcout << " == 0)"; wcout << " cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"������� �����������", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";"; Paint(L" //���� �� ������� �� ������ ��������\n", 5);
	Paint(L"			break", 7); wcout << ";\n"
		<< "		}\n"
		<< "	}\n"
		<< "}\n\n";

	cout << "���������, ������ ��������, ���� ��� ������ ����������� � ���������� �������� ������� ����� "; Paint(L"for", 7); wcout << ".\n\n";
	system("pause");

	cout << "\n������� ������, �� ��������, ����������� � �����:\n\n";
	Paint(L"List", 4); Paint(L" lst", 8); wcout << ";\n";
	Paint(L"lst", 8); wcout << "."; Paint(L"Find", 2); wcout << "();\n";

	int ch = 1;
	do
	{
		lst.Find();

		system("pause");
		cout << "\n������� ��������� �����?\n"
			<< "1 - ��\n"
			<< "2 - ���\n"
			<< "����: ";
		CheckEnter(ch, 2);
	} while (ch == 1);

	cout << "\n��������, ��� ������ ��������? ���� ���, �������� ������)\n\n";
}

void DeleteElement(List& lst)
{
	cout << "    ����: �������� �������� �� ������\n\n"
		<< "��������������, ���� ��� �����-�� ������� �� ����������, �� ��� ����� �������.\n"
		<< "������� ��� ����� ����� �� ������� ��� �� ������� ������:\n"
		<< "- ��� �������� �� ������� ����� 2 ���������, ����� ���� ������ ���� ���������� ������, ����� � ������, ����� � �������;\n"
		<< "- ��� ������ �� ������� ����� ���� 2 ���������, ��������� ���� ������, ��� �� �������� ����� ���� � ����� ������� ��������� �������.\n\n"
		<< "������� � "; Paint(L"public", 1); wcout << L" ������ �� ������������ ������� �������� �������� � ������:\n\n";

	Paint(L"class ", 1); Paint(L"List\n", 4);
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Head, "; Paint(L"*", 3); wcout << " Tail;"; Paint(L"   //��������� ������ ������� (������) � ���, ��� ��������� (�����)\n", 5);
	Paint(L"	int ", 1); wcout << "size"; wcout << ";"; Paint(L"             //����� ��������� � ������\n", 5);
	Paint(L"public:\n", 1);
	Paint(L"	List", 2); wcout << "() : Head("; Paint(L"NULL", 8); wcout << "), Tail("; Paint(L"NULL", 8); wcout << "), size(0) {};"; Paint(L"	//������������� ��������� � ���� � ������� ������������\n", 5);
	Paint(L"	void", 1); Paint(L" Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");"; Paint(L"	//������� ���������� ��������� � ������\n", 5);
	Paint(L"	void", 1); Paint(L" Show", 2); wcout << "("; Paint(L"int", 1); Paint(L" size", 3); wcout << ");"; Paint(L"				//������� ����������� ��������� ������\n", 5);
	Paint(L"	int", 1); Paint(L" Count", 2); wcout << "();"; Paint(L"					//�������, ������������ ����� ��������� � ������\n", 5);
	Paint(L"	void", 1); Paint(L" Find", 2); wcout << "();"; Paint(L"					//������� ������ ��������\n", 5);
	wcout << "	+ "; Paint(L"void", 1); Paint(L" DelEl", 2); wcout << "();"; Paint(L"					//������� �������� ��������\n", 5);
	wcout << "}\n\n";
	system("Pause");

	cout << "\n���������� ���:\n\n";
	Paint(L"void", 1); Paint(L" List", 4); wcout << "::"; Paint(L"DelEl", 2); wcout << "()\n";
	wcout << "{\n";
	Paint(L"	int", 1); Paint(L" choice", 8); wcout << ","; Paint(L" ch", 8); wcout << ","; Paint(L" sum", 8); wcout << " = 0,"; Paint(L" pos", 8); wcout << ","; Paint(L" a", 8); wcout << ";\n";
	Paint(L"	if", 7); wcout << " (Head != "; Paint(L"NULL", 8); wcout << ")\n"
		<< "	{\n";
	Paint(L"		Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";\n";
	Paint(L"		tempHead", 8); wcout << " = Head;"; Paint(L" //������ ����� ������ ��� ��������� ��� �������� ������\n", 5);
	Paint(L"		Node", 4); Paint(L"*", 3); Paint(L" tempTail", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";\n";
	Paint(L"		tempHead", 8); wcout << " = Tail;"; Paint(L" //������ ���������, \"�������\"\n\n", 5);
	wcout << "		cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"������� ������� ������� �� ������������ ��� �� ������� ������-������ ����� � ��?", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";\n";
	wcout << "			<< "; Paint(L"\"1 - �� ������������", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "			<< "; Paint(L"\"2 - �� ������� �����", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "			<< "; Paint(L"\"����: \"", 6); wcout << ";\n"
		<< "		cin >>"; Paint(L" choice", 8); wcout << ";\n";

	Paint(L"		switch", 7); wcout << " ("; Paint(L"choice", 8); wcout << ")\n"
		<< "		{\n";
	Paint(L"		case", 7); wcout << " 1:"; Paint(L"	//�������� �������� �� ������������\n", 5);
	wcout << "			cout << "; Paint(L"\"", 6); Paint(L"\\n\\n", 2); Paint(L"������� ������� ��������", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "				<< "; Paint(L"\"����: \"", 6); wcout << ";\n"
		<< "			cin >>"; Paint(L" pos", 8); wcout << ";\n\n";
	Paint(L"			if", 7); wcout << " ("; Paint(L"pos", 8); wcout << " < 1 || "; Paint(L"pos", 8); wcout << " > size)\n"
		<< "			{\n"
		<< "				cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"������� �����������", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";\n";
	Paint(L"				DelEl", 2); wcout << "();\n"
		<< "			}\n";
	Paint(L"			else\n", 7);
	wcout << "			{\n";
	Paint(L"				for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " !="; Paint(L" pos", 8); wcout << ";"; Paint(L" i", 8); wcout << "++)\n"
		<< "				{\n";
	Paint(L"					tempTail", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << ";"; Paint(L"		//\"�������\" ������� \"���������\"\n", 5);
	Paint(L"					tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"	//� ��� ���� ����� ������� ��������\n", 5);
	wcout << "				}\n\n";
	Paint(L"				if", 7); wcout << " ("; Paint(L"pos", 8); wcout << " == 1)\n"
		<< "				{\n";
	wcout << "					Head = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"		//���� ��������� ������, �� ������� ���������� ��������� �������\n", 5);
	wcout << "				}\n\n";
	Paint(L"				tempTail", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"	//����������� ��������� \"��������\" ���������...\n", 5);
	Paint(L"									//...�� ��������� ��������� �����, ����� ������� ������ �� ���������\n", 5);
	Paint(L"				delete", 1); Paint(L" tempHead", 8); wcout << ";"; Paint(L"			//����� ���� �������� ������� ��� �������\n", 5);
	wcout << "				size--;"; Paint(L"					//�� �������� ��������� ������\n", 5);
	wcout << "				cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"������� ������ � �����", 6); Paint(L"\\n\\n", 2); Paint(L"\"\n", 6);
	wcout << "			}\n";
	Paint(L"			break", 7); wcout << ";\n\n";

	Paint(L"		case", 7); wcout << " 2:"; Paint(L"	//����� �������� �� �����\n", 5);
	wcout << "			cout << "; Paint(L"\"", 6); Paint(L"\\n\\n", 2); Paint(L"������� �����", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "				<< "; Paint(L"\"����: \"", 6); wcout << ";\n"
		<< "			cin >>"; Paint(L" a", 8); wcout << ";\n\n";
	Paint(L"			for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " != size;"; Paint(L" i", 8); wcout << "++)\n"
		<< "			{\n";
	Paint(L"				if", 7); wcout << " ("; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "x == "; Paint(L"a", 8); wcout << ")"; Paint(L"				//���� ������� ����� ������ ��������\n", 5);
	wcout << "				{\n";
	Paint(L"					Node", 4); Paint(L"*", 3); Paint(L" del", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; Paint(L"			//������ �������, ������� ����� ����� ������� ��� ����������\n\n", 5);
	Paint(L"					sum", 8); wcout << "++;"; Paint(L"					//������ ������� �������� ���������\n", 5);
	Paint(L"					tempTail", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"	//����������� ��������� \"��������\" ���������...\n", 5);
	Paint(L"										//...�� ��������� ��������� �����, ����� ������� ������ �� ���������\n", 5);
	Paint(L"					del", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << ";"; Paint(L"				//��������� ������� ��������� �� ������ ��� ���������\n\n", 5);
	Paint(L"					if", 7);  wcout << " (size == "; Paint(L"sum", 8); wcout << ")"; Paint(L"				//���� �� ������� ������ � ��� ���� � ������\n", 5);
	wcout << "					{\n";
	Paint(L"						delete", 1); Paint(L" del", 8); wcout << ";"; Paint(L"				//������� �������\n", 5);
	wcout << "						Head = Tail = "; Paint(L"NULL", 8); wcout << ";"; Paint(L"			//�������� ������ � �����\n", 5);
	wcout << "					}\n";
	Paint(L"					else\n", 7);
	wcout << "					{\n";
	Paint(L"						if", 7); wcout << " (Head == "; Paint(L"tempHead", 8); wcout << ")\n"
		<< "						{\n";
	wcout << "							Head = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"		//���� ��������� ������, �� ������� ���������� ��������� �������\n", 5);
	wcout << "						}\n\n";
	Paint(L"						tempTail", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << ";"; Paint(L"			//\"�������\" ������� \"���������\"\n", 5);
	Paint(L"						tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"		//��������� � ���������� ��������\n\n", 5);
	Paint(L"						delete", 1); Paint(L" del", 8); wcout << ";"; Paint(L"				//� ������ ����� �������\n", 5);
	wcout << "						cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"������� ������ � �����", 6); Paint(L"\\n\\n", 2); Paint(L"\"\n", 6);
	wcout << "					}\n";
	wcout << "				}\n";
	Paint(L"				else", 7); Paint(L"						//���� �� �����\n", 5);
	wcout << "				{\n";
	Paint(L"					tempTail", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << ";"; Paint(L"			//\"�������\" ������� \"���������\"\n", 5);
	Paint(L"					tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"		//��������� � ���������� ��������\n", 5);
	wcout << "				}\n";
	wcout << "			}\n";
	wcout << "			size -= "; Paint(L"sum", 8); wcout << ";"; Paint(L"	//�������� �������� ������\n", 5);
	Paint(L"			if", 7); wcout << " ("; Paint(L"sum", 8); wcout << " == 0)"; wcout << " cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"������� �����������", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";"; Paint(L" //���� �� ������� �� ������ ��������\n", 5);
	Paint(L"			break", 7); wcout << ";\n"
		<< "		}\n"
		<< "	}\n"
		<< "}\n\n";

	cout << "����� ��������, ��� ������ ������� ������, ����������� ���� ���� ������� � ��������.\n\n";
	system("pause");

	cout << "\n��������� � ����������:\n\n";
	Paint(L"List", 4); Paint(L" lst", 8); wcout << ";\n";
	Paint(L"lst", 8); wcout << "."; Paint(L"DelEl", 2); wcout << "();\n";

	int ch = 1;
	do
	{
		lst.DelEl();

		system("pause");
		cout << "\n������� ��������� ��������?\n"
			<< "1 - ��\n"
			<< "2 - ���\n"
			<< "����: ";
		CheckEnter(ch, 2);
	} while (ch == 1);

	cout << endl;

}

void DeleteList(List& lst)
{
	cout << "    ����: �������� ������\n\n"
		<< "��� ������������ ����������������, ���� ���� �������� ������, �� ���������� ������ ���� �����������,\n"
		<< "����� �� ��������� ������ ������. ������������ ������ ������ ������� � ����������� (~\"�������� ������\").\n"
		<< "���������� ����� ����� �� ������� ����������� ������.";
	Paint(L"\n\nclass ", 1); Paint(L"List\n", 4);
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Head, "; Paint(L"*", 3); wcout << " Tail;"; Paint(L"   //��������� ������ ������� (������) � ���, ��� ��������� (�����)\n", 5);
	Paint(L"	int ", 1); wcout << "size"; wcout << ";"; Paint(L"             //����� ��������� � ������\n", 5);
	Paint(L"public:\n", 1);
	Paint(L"	List", 2); wcout << "() : Head("; Paint(L"NULL", 8); wcout << "), Tail("; Paint(L"NULL", 8); wcout << "), size(0) {};"; Paint(L"	//������������� ��������� � ���� � ������� ������������\n", 5);
	Paint(L"	void", 1); Paint(L" Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");"; Paint(L"	//������� ���������� ��������� � ������\n", 5);
	Paint(L"	void", 1); Paint(L" Show", 2); wcout << "("; Paint(L"int", 1); Paint(L" size", 3); wcout << ");"; Paint(L"				//������� ����������� ��������� ������\n", 5);
	Paint(L"	int", 1); Paint(L" Count", 2); wcout << "();"; Paint(L"					//�������, ������������ ����� ��������� � ������\n", 5);
	Paint(L"	void", 1); Paint(L" Find", 2); wcout << "();"; Paint(L"					//������� ������ ��������\n", 5);
	Paint(L"	void", 1); Paint(L" DelEl", 2); wcout << "();"; Paint(L"					//������� �������� ��������\n", 5);
	wcout << "	+ "; Paint(L"~List", 2); wcout << "();"; Paint(L"					//���������� ��� ������������ ������\n", 5);
	wcout << "}\n\n";
	system("pause");

	cout << "\n��� ��� �������� ��� ����������:\n\n";
	Paint(L"List", 4); wcout << "::"; Paint(L"~List", 2); wcout << "()\n"
		<< "{\n";
	Paint(L"	while", 7); wcout << " ("; Paint(L"size", 8); wcout << " != 0)"; Paint(L"		 //���� ����������� ������ �� ������ �������\n", 5);
	wcout << "	{\n";
	Paint(L"		Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = Head"; Paint(L"->", 3); wcout << "Next;"; Paint(L" //������ ��������� �������, ������� ����� ������� ������ �� ����������� ��������, ����...\n", 5);
	Paint(L"		delete", 1); wcout << " Head;"; Paint(L"		 //... �� ����������� ������ �� ��������� ��������\n", 5);
	wcout << "		Head = "; Paint(L"temp", 8); wcout << ";"; Paint(L"		 //����� ������ ������ �� ����� ������������ ��������\n", 5);
	wcout << "		size"; Paint(L"--", 3); wcout << ";"; Paint(L"			 //���� ������� ����������. ������������ ����� ���������\n", 5);
	wcout << "	}\n"
		<< "}\n\n";

	system("pause");

	cout << "\n������� ���������, ��� ��� ��������\n";
	lst.~List();
}

void DeleteListBeforeTheme(List& lst)
{
	cout << "����� ���������� ��������� �� �� ��������� ���� ������� ������, ������� � ��� �������� ������ ������ ����������� ;)\n";
	lst.~List();
}

void ChooseThemes(int ch, int rep, int& ReturnMenu, int& ReturnThemes, List& lst, int& check)
{
	int choice;

	switch (ch)
	{
	case 1: AboutList();
		check++;
		break;
	case 2: StructureOfList();
		check++;
		break;
	case 3: ClassOfList();
		check++;
		break;
	case 4: AddElementToEnd(lst);
		check++;
		break;
	case 5: AddElementBetweenNum(lst);
		check++;
		break;
	case 6: OutputList(lst);
		check++;
		break;
	case 7: LookingForElement(lst);
		check++;
		break;
	case 8: DeleteElement(lst);
		check++;
		break;
	case 9: DeleteList(lst);
		check++;
		break;
	case 10: ReturnMenu = 1;
		break;
	case 11: if (lst.Count() != 0) DeleteListBeforeTheme(lst); exit(0);
		break;
	}

	if (ReturnMenu != 1)
	{
		system("Pause");
		if (check >= 9) cout << "\n---------------------------------------------------------\n�� ������ ��� ����, ������ ��� �������� ���� � ���-��� ��\n��������� ������� � ����� �� ������ ������ �� ���������\n���-��� - 1489\n---------------------------------------------------------\n";
		if (ch == 1)
		{
			wcout << L"\n�������� ��������:\n"
				<< L"1 - ������ ����\n"
				<< L"2 - ��������� ����\n"
				<< L"3 - ������� � �����\n"
				<< L"4 - ������� � ����\n"
				<< L"5 - �������� ������\n\n"
				<< L"6 - ����� �� ���������\n"
				<< L"\n����: ";

			CheckEnter(choice, 6);
			switch (choice)
			{
			case 1: system("cls"); ChooseThemes(ch, rep, ReturnMenu, ReturnThemes, lst, check);
				break;
			case 2: system("cls"); ChooseThemes(ch + 1, rep, ReturnMenu, ReturnThemes, lst, check);
				break;
			case 3: system("cls"); ReturnThemes = 1;
				break;
			case 4: system("cls"); ReturnMenu = 1;
				break;
			case 5: lst.Show(lst.Count(), lst, 1);
				wcout << L"\n�������� ��������:\n"
					<< L"1 - ������ ����\n"
					<< L"2 - ��������� ����\n"
					<< L"3 - ������� � �����\n"
					<< L"4 - ������� � ����\n"
					<< L"5 - ����� �� ���������\n"
					<< L"\n����: ";

				CheckEnter(choice, 5);
				system("cls");
				switch (choice)
				{
				case 1: ChooseThemes(ch, rep, ReturnMenu, ReturnThemes, lst, check);
					break;
				case 2: ChooseThemes(ch + 1, rep, ReturnMenu, ReturnThemes, lst, check);
					break;
				case 3: ReturnThemes = 1;
					break;
				case 4: ReturnMenu = 1;
					break;
				case 5: if (lst.Count() != 0) DeleteListBeforeTheme(lst); exit(0);
					break;
				}
				break;
			case 6: system("cls"); if (lst.Count() != 0) DeleteListBeforeTheme(lst); exit(0);
				break;
			}
		}
		else if (ch == 9)
		{
			cout << "\n�������� ��������:\n"
				<< "1 - ������ ����\n"
				<< "2 - ���������� ����\n"
				<< "3 - ������� � �����\n"
				<< "4 - ������� � ����\n"
				<< "5 - �������� ������\n\n"
				<< "6 - ����� �� ���������\n"
				<< "\n����: ";

			CheckEnter(choice, 6);
			switch (choice)
			{
			case 1: system("cls"); ChooseThemes(ch, rep, ReturnMenu, ReturnThemes, lst, check);
				break;
			case 2: system("cls"); ChooseThemes(ch - 1, rep, ReturnMenu, ReturnThemes, lst, check);
				break;
			case 3: system("cls"); ReturnThemes = 1;
				break;
			case 4: system("cls"); ReturnMenu = 1;
				break;
			case 5: lst.Show(lst.Count(), lst, 1);
				wcout << L"\n�������� ��������:\n"
					<< L"1 - ������ ����\n"
					<< L"2 - ��������� ����\n"
					<< L"3 - ������� � �����\n"
					<< L"4 - ������� � ����\n\n"
					<< L"5 - ����� �� ���������\n"
					<< L"\n����: ";

				CheckEnter(choice, 5);
				system("cls");
				switch (choice)
				{
				case 1: ChooseThemes(ch, rep, ReturnMenu, ReturnThemes, lst, check);
					break;
				case 2: ChooseThemes(ch - 1, rep, ReturnMenu, ReturnThemes, lst, check);
					break;
				case 3: ReturnThemes = 1;
					break;
				case 4: ReturnMenu = 1;
					break;
				case 5: if (lst.Count() != 0) DeleteListBeforeTheme(lst); exit(0);
					break;
				}
				break;
			case 6: system("cls"); if (lst.Count() != 0) DeleteListBeforeTheme(lst); exit(0);
				break;
			}
		}
		else
		{
			cout << "\n�������� ��������:\n"
				<< "1 - ������ ����\n"
				<< "2 - ��������� ����\n"
				<< "3 - ���������� ����\n"
				<< "4 - ������� � �����\n"
				<< "5 - ������� � ����\n"
				<< "6 - �������� ������\n\n"
				<< "7 - ����� �� ���������\n"
				<< "\n����: ";

			CheckEnter(choice, 7);
			switch (choice)
			{
			case 1: system("cls"); ChooseThemes(ch, rep, ReturnMenu, ReturnThemes, lst, check);
				break;
			case 2: system("cls"); ChooseThemes(ch + 1, rep, ReturnMenu, ReturnThemes, lst, check);
				break;
			case 3: system("cls"); ChooseThemes(ch - 1, rep, ReturnMenu, ReturnThemes, lst, check);
				break;
			case 4: system("cls"); ReturnThemes = 1;
				break;
			case 5: system("cls"); ReturnMenu = 1;
				break;
			case 6: lst.Show(lst.Count(), lst, 1);
				wcout << L"\n�������� ��������:\n"
					<< L"1 - ������ ����\n"
					<< L"2 - ��������� ����\n"
					<< L"3 - ���������� ����\n"
					<< L"4 - ������� � �����\n"
					<< L"5 - ������� � ����\n\n"
					<< L"6 - ����� �� ���������\n"
					<< L"\n����: ";

				CheckEnter(choice, 6);
				system("cls");
				switch (choice)
				{
				case 1: ChooseThemes(ch, rep, ReturnMenu, ReturnThemes, lst, check);
					break;
				case 2: ChooseThemes(ch + 1, rep, ReturnMenu, ReturnThemes, lst, check);
					break;
				case 3: ChooseThemes(ch - 1, rep, ReturnMenu, ReturnThemes, lst, check);
					break;
				case 4: ReturnThemes = 1;
					break;
				case 5: ReturnMenu = 1;
					break;
				case 6: if (lst.Count() != 0) DeleteListBeforeTheme(lst); exit(0);
					break;
				}
				break;
			case 7: system("cls"); if (lst.Count() != 0) DeleteListBeforeTheme(lst); exit(0);
				break;
			}
		}

	}
}

void Themes(int& ReturnMenu, int rep, List& lst, int& check)
{
	cout << "    ������ ���:\n\n"
		<< "1 - �� ����������� ����������� ������ (������)\n"
		<< "2 - �������� ��������� ������ (������)\n"
		<< "3 - �������� ������ ������ (������)\n"
		<< "4 - ���������� ��������� � ����� ������ (�����)\n"
		<< "5 - ���������� ��������� ����� ������� ���������� ������ (�����)\n"
		<< "6 - ����� ��������� ������ (������)\n"
		<< "7 - ����� �������� �� ������� (�����)\n"
		<< "8 - �������� �������� �� ������ (�����)\n"
		<< "9 - �������� ������ (������)\n"
		<< "\n10 - ������� � ����\n"
		<< "11 - ����� �� ���������\n"
		<< "\n����: ";

	int choice, ReturnThemes = 0;
	CheckEnter(choice, 11);
	system("cls");
	ChooseThemes(choice, 0, ReturnMenu, ReturnThemes, lst, check);
	if (ReturnThemes != 0)
	{
		Themes(ReturnMenu, 0, lst, check);
	}
}

void Test(int check, int& num, int& score, int wrong[9], int& have)
{
	if (check >= 9)
	{
		int answer = 0;
		cout << "    ��c�\n\n";
		if (num == 1)
		{
			cout << " ����� 1\n";
			cout << "� ������ ����� ���� �������������� ����� ���������, ����� �� ��� �������?\n\n"
				<< "1 - ������\n"
				<< "2 - ������ � �����\n"
				<< "3 - � ���� ���������� ������\n"
				<< "����: ";

			CheckEnter(answer, 3);
			if (answer == 2)
			{
				wrong[0] = 0;
				score++;
				cout << "\n�����\n\n";
			}
			else
			{
				have = 1;
				wrong[0] = 1;
				cout << "\n�������\n\n";
			}
		}
		else if (num == 2)
		{
			cout << " ����� 2\n";
			cout << "�� ����� ���������� ������� ��������� ������?\n\n"
				<< "1 - �� ������\n"
				<< "2 - �� ���������� ����������\n"
				<< "3 - �� ������ � ����������\n"
				<< "����: ";

			CheckEnter(answer, 3);
			if (answer == 3)
			{
				wrong[1] = 0;
				score++;
				cout << "\n�����\n\n";
			}
			else
			{
				have = 1;
				wrong[1] = 1;
				cout << "\n�������\n\n";
			}
		}
		else if (num == 3)
		{
			cout << " ����� 3\n";
			cout << "��� ����� ������� � ���������� ���������� ������ � ������, ����� ������ ������ � ���?\n\n"
				<< "1 - �������\n"
				<< "2 - �������� � ������������������� � ����\n"
				<< "3 - ��������� � ���������\n"
				<< "����: ";

			CheckEnter(answer, 3);
			if (answer == 2)
			{
				wrong[2] = 0;
				score++;
				cout << "\n�����\n\n";
			}
			else
			{
				have = 1;
				wrong[2] = 1;
				cout << "\n�������\n\n";
			}
		}
		else if (num == 4)
		{
			cout << " ����� 4\n";
			cout << "��� ���������� � ������ �������� � �����, ��� �����, ���� ������ ������?\n\n"
				<< "1 - ����� ������� ������ ������� � �������\n"
				<< "2 - ������� �� ���������\n"
				<< "3 - ������� ��������� � �������\n"
				<< "����: ";

			CheckEnter(answer, 3);
			if (answer == 1)
			{
				wrong[3] = 0;
				score++;
				cout << "\n�����\n\n";
			}
			else
			{
				have = 1;
				wrong[3] = 1;
				cout << "\n�������\n\n";
			}
		}
		else if (num == 5)
		{
			cout << " ����� 5\n";
			cout << "��� ���������, ���� ��� ���������� � ������ �������� ����� ������� ���������� ������� ������ �������?\n\n"
				<< "1 - ������ ������� ��������� ������, � ����������� ������ �������\n"
				<< "2 - ��� ����� ��������\n"
				<< "3 - ����������� ������� ���������� ����� ������\n"
				<< "����: ";

			CheckEnter(answer, 3);
			if (answer == 2)
			{
				wrong[4] = 0;
				score++;
				cout << "\n�����\n\n";
			}
			else
			{
				have = 1;
				wrong[4] = 1;
				cout << "\n�������\n\n";
			}
		}
		else if (num == 6)
		{
			cout << " ����� 6\n";
			cout << "����� ������ ����� ����������?\n\n"
				<< "1 - ���, ����� �������� �������, ������������ ������\n"
				<< "2 - ��\n"
				<< "3 - ���, ����� ���������� ����������� ������\n"
				<< "����: ";

			CheckEnter(answer, 3);
			if (answer == 1)
			{
				wrong[5] = 0;
				score++;
				cout << "\n�����\n\n";
			}
			else
			{
				have = 1;
				wrong[5] = 1;
				cout << "\n�������\n\n";
			}
		}
		else if (num == 7)
		{
			cout << " ����� 7\n";
			cout << "��� ���������� ����� ��������?\n\n"
				<< "1 - ��������� ������ � ����� ������� �������, ��� � �������\n"
				<< "2 - ��������� ������ � ����������� ������� ���������, ������� � ������\n"
				<< "3 - ��������� ������ � ����������� ����� ��������\n"
				<< "����: ";

			CheckEnter(answer, 3);
			if (answer == 2)
			{
				wrong[6] = 0;
				score++;
				cout << "\n�����\n\n";
			}
			else
			{
				have = 1;
				wrong[6] = 1;
				cout << "\n�������\n\n";
			}
		}
		else if (num == 8)
		{
			cout << " ����� 8\n";
			cout << "������� ����� ����������, ����� ��������� �������� �������� �� ������ ��� ������?\n\n"
				<< "1 - 3\n"
				<< "2 - 1\n"
				<< "3 - 2\n"
				<< "����: ";

			CheckEnter(answer, 3);
			if (answer == 1)
			{
				wrong[7] = 0;
				score++;
				cout << "\n�����\n\n";
			}
			else
			{
				have = 1;
				wrong[7] = 1;
				cout << "\n�������\n\n";
			}
		}
		else if (num == 9)
		{
			cout << " ����� 9\n";
			cout << "�������� �� �������� ������ ������������� ��������� � ��� ����� ������ � ������������� ��������� ����� ���������� ������ � ����?\n\n"
				<< "1 - ���, ������� ��\n"
				<< "2 - ��, ������ �� ������\n"
				<< "3 - ��, ������� ��\n"
				<< "����: ";

			CheckEnter(answer, 3);
			if (answer == 3)
			{
				wrong[8] = 0;
				score++;
				cout << "\n�����\n\n";
			}
			else
			{
				have = 1;
				wrong[8] = 1;
				cout << "\n�������\n\n";
			}
		}
		else if (num == 10)
		{
			cout << "��� �������� ���� - " << score;
			cout << "\n���� ������ - ";
			if (score >= 8) cout << "5\n�� ������� � ������ ���� ������ ���� � ������ �������� �\n������������ ������������ �������� ��������������\n\n";
			else if (score < 8 && score >= 5) cout << "4\n��� ������� ����������� �������� ������������ ������������ ������,\n�� ��� ������ ����������� �������� ��������������� ������������ ������� ����\n\n";
			else if (score < 5 && score >= 3) cout << "3\n�� ������������ � ����������� ����������� ������ ���� ������������,\n������������� ������ ��������������� ������������ ������� ����\n\n";
			else if (score < 3) cout << "2\n�� �� ������� ��������� ��������, ������������ ������������� ������ ��� ���� ������\n\n";
			if (have == 1)
			{
				cout << "������ �� �������/����:\n";
				for (int i = 0; i <= 8; i++)
				{
					if (wrong[i] == 1)
					{
						cout << "������ ����� " << i + 1 << " - �������\n";
					}
					else cout << "������ ����� " << i + 1 << " - �����\n";
				}
				cout << endl;
			}
		}

		if (num <= 9)
		{
			system("pause");
			system("cls");
			num++;
			Test(check, num, score, wrong, have);
		}
		else if (num == 10) system("pause");
	}
	else
	{
		cout << "\n\n�������� ��� ����, � ����� �� �������� ������ � �����\n\n";
		system("pause");
	}
}

void ChooseMenu(int choice, int rep, int& ReturnMenu, List& lst, int& check)
{
	int scr = 0, num = 1, wrong[9], have = 0;

	switch (choice)
	{
	case 1:
		Introduction();

		int choice2;
		CheckEnter(choice2, 1);
		system("cls");
		if (choice2 == 1) ReturnMenu = 1;
		break;
	case 2: system("cls");
		Themes(ReturnMenu, 0, lst, check);
		break;
	case 3: Test(check, num, scr, wrong, have);
		system("cls");
		ReturnMenu = 1;
		break;
	case 4: if (lst.Count() != 0) DeleteListBeforeTheme(lst); exit(0);
		break;
	}
}

void Menu(int err, List& lst, int& check)
{
	if (err == 0)
	{
		cout << "������-��������������� ��������� \"����������� ����������� ������\"\n"
			<< "�������� ������� ������ ���-11 ��������� �.�.\n\n"
			<< "\n�������� ��������: "
			<< "\n1 - � ���������"
			<< "\n2 - ����� ����"
			<< "\n3 - ����"
			<< "\n\n4 - ����� �� ���������"
			<< "\n\n����: ";
	}
	int choice, ReturnMenu = 0;
	CheckEnter(choice, 4, check);
	system("cls");

	ChooseMenu(choice, 0, ReturnMenu, lst, check);
	if (ReturnMenu != 0)
	{
		Menu(err, lst, check);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	system("title ������-��������������� ��������� \"����������� ����������� ������\"");
	HWND hwnd;
	hwnd = GetConsoleWindow();
	MoveWindow(hwnd, 150, 0, 1350, 850, TRUE); //xnew, ynew, wnew, hnew - ����� ��������� x, y, ������ � ������
	List lst; int check = 0;
	Menu(0, lst, check);
	if (lst.Count() != 0) lst.~List();
	return 0;
}