#include <iostream>
#include <string>
#include <cstdlib>
#include <numeric>

using namespace std;

void Enter(unsigned short int& num, int ch)
{
	string choice;
	int rep;
	if (ch != 0)
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
						if (rep < 1) cout << "\n��� �� �����" << "\n����: ";
						rep++;
					}
				}
				if (rep == 0)
				{
					num = stoi(choice);
					if (num < 1 || num > ch)
					{
						cout << "\n������������ �����" << "\n����: ";
					}
				}
			}
			else rep++;
		} while (num < 1 || num > ch || rep != 0);
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
							if (rep < 1) cout << "\n����� ������ ���� �������������" << "\n����: ";
						}
						else
						{
							if (rep < 1) cout << "\n��� �� �����" << "\n����: ";
						}
						rep++;
					}
				}
				if (rep == 0)
				{
					num = stoi(choice);
				}
			}
			else rep++;
		} while (rep != 0);
	}
}

bool SimpleNum(unsigned short int num)
{
	unsigned short int del = 1, sumdel = 0;
	if (num > 1)
	{
		while (del != num + 1)
		{
			if (num % del == 0) sumdel++;
			del++;
		}
		if (sumdel == 2) return true;
		else return false;
	}
	else return false;
}

void in(string num, int& n) // ���������� �� �����
{
	int ch;
	do
	{
		ch = 0;
		cin >> num;
		if (!num.empty())
		{
			if (num.length() == 1)
			{
				for (int i = 0; i < num.length(); i++)
				{
					if (num[i] > '9' || num[i] < '0')
					{
						cout << "\n��� �� �����" << "\n����� ����� ������������� ����� ������������������: ";
						ch++;
					}
				}
				n = stoi(num);
			}
			else ch++;
		}
		else ch++;
	} while (n < 0 || ch != 0);
}




struct Node_one_path
{
	unsigned short int data;
	Node_one_path* Next;
};

class List_one_path
{
	Node_one_path* Head;
	Node_one_path* Tail;
	int size;

public:

	List_one_path() : Head(NULL), Tail(NULL), size(0) {};
	void Add(int n, int _size);
	void AddElement();
	void Show(int size);									 //������� ����������� ��������� ������
	int Count();											 //������� ������������ ����� ��������� � ������
	void DelEl();
	~List_one_path();

};

List_one_path::~List_one_path()
{

	while (size != 0)
	{
		Node_one_path* temp = Head->Next;

		delete Head;

		Head = temp;
		size--;
	}
}

int List_one_path::Count()
{
	return size; //���������� ����� ��������� ������
}

void List_one_path::Add(int n, int _size)
{
	unsigned short int x = 0;

	switch (n)
	{
	case 1:

		while (size != _size)
		{
			cout << "\n����� ������������� �����: ";
			Enter(x, 0);

			size++;
			Node_one_path* temp = new Node_one_path;


			temp->data = x;

			if (Head != NULL)
			{
				Tail->Next = temp;
				Tail = temp;
			}
			else Head = Tail = temp;
		}

		break;

	case 2:

		unsigned short int a, b;

		cout << "\n����� �������� �� 0 �� 65535 [a;b] - ";
		do
		{
			Enter(a, 0);
			Enter(b, 0);

			if (a >= b) cout << "\n�������� ��������\n ����� �������� - ";

		} while (a >= b);

		while (size != _size)
		{
			x = a + rand() % (b - a + 1);

			size++;
			Node_one_path* temp = new Node_one_path;

			temp->data = x;

			if (Head != NULL)
			{
				Tail->Next = temp;
				Tail = temp;
			}
			else Head = Tail = temp;
		}

		break;
	default:
		break;
	}
}

void List_one_path::AddElement()
{
	unsigned short int x = 0, maxnum = 0, coin = 1, maxpal = 0, choice = 0;
	string palindrom;

	Node_one_path* tempHead = new Node_one_path;
	Node_one_path* tempTail = new Node_one_path;
	tempHead = Head; tempTail = Head;
	int temp = size;

	while (temp != 0) //���� �� �������� ������� ������� �� ����� ������
	{

		palindrom = to_string(tempHead->data);
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
			if (maxpal < stoi(palindrom))
				maxpal = stoi(palindrom);

		tempHead = tempHead->Next; //���������, ��� ����� ��������� �������
		temp--; //���� ������� ������, ������ �������� �� ���� ������ 
	}

	cout << "\n������������ ��������� = " << maxpal;
	tempHead = Head; temp = size;
	cout << "\n\n�������� ��������� �� ������� ����� ��� �����?"
		<< "\n1 - ��"
		<< "\n2 - �����"
		<< "\n����: ";
	Enter(choice, 2);
	if (choice == 1)
	{
		while (temp != 0)
		{
			if (SimpleNum(tempHead->data))
			{
				size++;
				Node_one_path* temp = new Node_one_path;

				temp->data = maxpal;
				if (tempHead == Head)
				{
					temp->Next = Head;
					Head = temp;
				}
				else
				{
					tempTail->Next = temp;
					temp->Next = tempHead;
				}
			}
			tempTail = tempHead;
			tempHead = tempHead->Next; //���������, ��� ����� ��������� �������
			temp--; //���� ������� ������, ������ �������� �� ���� ������
		}
	}
	else
	{
		while (temp != 0)
		{
			if (SimpleNum(tempHead->data))
			{
				size++;
				Node_one_path* temp = new Node_one_path;

				temp->data = maxpal;
				if (tempHead == Tail)
				{
					Tail->Next = temp;
					Tail = temp;
				}
				else
				{
					temp->Next = tempHead->Next;
					tempHead->Next = temp;
				}
			}
			tempHead = tempHead->Next; //���������, ��� ����� ��������� �������
			temp--; //���� ������� ������, ������ �������� �� ���� ������
		}
	}

}

void List_one_path::DelEl()
{
	int num, sum = 0, coin = 0;
	string NUM, elementData;
	int temp = size;

	if (Head != NULL)
	{
		Node_one_path* tempHead = new Node_one_path;
		tempHead = Head; //������ ����� ������ ��� ��������� ��� �������� ������
		Node_one_path* tempTail = new Node_one_path;
		tempTail = Head; //������ ���������, "�������"

		cout << "\n����� ����� ��� �������� �����, ����������� ��� �����\n"
			<< "����: ";
		in(NUM, num);
		NUM = to_string(num);

		while (temp != 0)
		{
			coin = 0;

			elementData = to_string(tempHead->data);
			for (int i = 0; i < elementData.length(); i++)
			{
				if (elementData[i] == NUM[0]) coin = 1;
			}

			if (coin == 1)
			{
				Node_one_path* del = new Node_one_path;				//������ �������, ������� ����� ����� ������� ��� ����������

				sum++;
				tempTail->Next = tempHead->Next;	//����������� ��������� "��������" ��������� �� ��������� ��������� �����, ����� ������� ������ �� ���������
				del = tempHead;						//��������� ������� ��������� �� ������ ��� ���������

				if (size == sum) //���� �� ������� ������ � ��� ���� � ������
				{
					delete del;			//�������
					Head = Tail = NULL; //��������
				}
				else
				{
					if (Head == tempHead)
					{
						Head = tempHead->Next;			 //���� ��������� ������, �� ������� ���������� ��������� �������
						tempTail = tempHead;				 //"�������" ������� "���������"
						tempHead = tempHead->Next;			 //��������� � ���������� ��������
					}
					else if (Tail == tempHead)
					{
						Tail = tempTail;
					}
					else
					{
						tempHead = tempHead->Next;			 //��������� � ���������� ��������
					}

					delete del;							 //� ������ ����� �������
				}
			}
			else //���� �� �����
			{
				tempTail = tempHead;			 //"�������" ������� "���������"
				tempHead = tempHead->Next;		 //��������� � ���������� ��������
			}
			temp--;
		}

		if (sum == 0) cout << "\n������� �����������\n\n"; //���� �� ������� �� ������ ��������
		else
		{
			size -= sum;							 //�������� �������� ������
		}
	}
}

void List_one_path::Show(int size)
{
	Node_one_path* tempHead = new Node_one_path; //������...
	tempHead = Head; //...����� ������
	int temp = size; //��������� ���������� ������ ����� ��������� � ������

	cout << "\n\n�������� ������: [ ";
	while (temp != 0) //���� �� �������� ������� ������� �� ����� ������
	{
		cout << tempHead->data << " "; //��������� ������� ������ �� ����� 
		tempHead = tempHead->Next; //���������, ��� ����� ��������� �������
		temp--; //���� ������� ������, ������ �������� �� ���� ������ 
	}
	cout << "]\n\n";
}

void Menu(List_one_path& node, int rep)
{
	unsigned short int ch, len;
	if (rep == 0)
	{
		cout << "	����\n"
			<< "1 - ��������� ����������� ������\n"
			<< "����: ";
		Enter(ch, 1);

		cout << "\n������ ������"
			<< "\n1 - � ����������"
			<< "\n2 - ��������� �����\n"
			<< "����: ";
		Enter(ch, 2);

		cout << "\n������ ���������� ���������: ";
		Enter(len, 0);

		node.Add(ch, len);
		node.Show(node.Count());

		Menu(node, 1);
	}
	else if (node.Count() == 0)
	{
		cout << "\n������ ����, ����� �� ���������\n";
	}
	else
	{
		cout << "	����\n"
			<< "1 - �������� ������������ ��������� �� ������ �����/����� �������� �������\n"
			<< "2 - ������� �����, ���������� �����\n"
			<< "3 - ����� �� ���������\n"
			<< "����: ";
		Enter(ch, 3);
		if (ch != 3)
		{
			if (ch == 1) node.AddElement();
			else if (ch == 2)
			{
				node.DelEl();
			}
			node.Show(node.Count());
			Menu(node, 1);
		}

	}

}






struct Node
{
	unsigned short int data;
	Node* Prev;
	Node* Next;
};

class Helper
{
	Node* Head;
	Node* Tail;
	int size;

public:

	Helper() : Head(NULL), Tail(NULL), size(0) {};
	void Add(int n, int _size);
	void AddElement();
	void Show(int size);									 //������� ����������� ��������� ������
	int Count();											 //������� ������������ ����� ��������� � ������
	void DelEl();
	~Helper();

};

Helper::~Helper()
{

	while (size != 0)
	{
		Node* temp = Head->Next;

		delete Head;

		Head = temp;
		size--;
	}
}

int Helper::Count()
{
	return size; //���������� ����� ��������� ������
}

void Helper::Add(int n, int _size)
{
	unsigned short int x = 0;

	switch (n)
	{
	case 1:

		while (size != _size)
		{
			cout << "\n����� ������������� �����: ";
			Enter(x, 0);

			size++;
			Node* temp = new Node;


			temp->data = x;

			if (Head != NULL)
			{
				Tail->Next = temp;
				temp->Prev = Tail;
				Tail = temp;
			}
			else Head = Tail = temp;
		}

		break;

	case 2:

		unsigned short int a, b;

		cout << "\n����� �������� �� 0 �� 65535 [a;b] - ";
		do
		{
			Enter(a, 0);
			Enter(b, 0);

			if (a >= b) cout << "\n�������� ��������\n ����� �������� - ";

		} while (a >= b);

		while (size != _size)
		{
			x = a + rand() % (b - a + 1);

			size++;
			Node* temp = new Node;

			temp->data = x;

			if (Head != NULL)
			{
				Tail->Next = temp;
				temp->Prev = Tail;
				Tail = temp;
			}
			else Head = Tail = temp;
		}

		break;
	default:
		break;
	}
}

void Helper::AddElement()
{
	unsigned short int x = 0, maxnum = 0, coin = 1, maxpal = 0, choice = 0;
	string palindrom;

	Node* tempHead = new Node;
	Node* tempTail = new Node;
	tempHead = Head; tempTail = Head;
	int temp = size;

	while (temp != 0) //���� �� �������� ������� ������� �� ����� ������
	{

		palindrom = to_string(tempHead->data);
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
			if (maxpal < stoi(palindrom))
				maxpal = stoi(palindrom);

		tempHead = tempHead->Next; //���������, ��� ����� ��������� �������
		temp--; //���� ������� ������, ������ �������� �� ���� ������ 
	}

	cout << "\n������������ ��������� = " << maxpal;
	tempHead = Head; temp = size;
	cout << "\n\n�������� ��������� �� ������� ����� ��� �����?"
		<< "\n1 - ��"
		<< "\n2 - �����"
		<< "\n����: ";
	Enter(choice, 2);
	if (choice == 1)
	{
		while (temp != 0)
		{
			if (SimpleNum(tempHead->data))
			{
				size++;
				Node* temp = new Node;

				temp->data = maxpal;
				if (tempHead == Head)
				{
					temp->Next = Head;
					Head->Prev = temp;
					Head = temp;
				}
				else
				{
					tempTail->Next = temp;
					temp->Prev = tempTail;

					temp->Next = tempHead;
					tempHead->Prev = temp;

				}
			}
			tempTail = tempHead;
			tempHead = tempHead->Next; //���������, ��� ����� ��������� �������
			temp--; //���� ������� ������, ������ �������� �� ���� ������
		}
	}
	else
	{
		while (temp != 0)
		{
			if (SimpleNum(tempHead->data))
			{
				size++;
				Node* temp = new Node;

				temp->data = maxpal;
				if (tempHead == Tail)
				{
					Tail->Next = temp;
					temp->Prev = Tail;
					Tail = temp;
				}
				else
				{
					temp->Next = tempHead->Next;
					tempHead->Next->Prev = temp;

					tempHead->Next = temp;
					temp->Prev = tempHead;
				}
			}
			tempHead = tempHead->Next; //���������, ��� ����� ��������� �������
			temp--; //���� ������� ������, ������ �������� �� ���� ������
		}
	}

}

void Helper::DelEl()
{
	int num, sum = 0, coin = 0;
	string NUM, elementData;
	int temp = size;

	if (Head != NULL)
	{
		Node* tempHead = new Node;
		tempHead = Head; //������ ����� ������ ��� ��������� ��� �������� ������
		Node* tempTail = new Node;
		tempTail = Head; //������ ���������, "�������"

		cout << "\n����� ����� ��� �������� �����, ����������� ��� �����\n"
			<< "����: ";
		in(NUM, num);
		NUM = to_string(num);

		while (temp != 0)
		{
			coin = 0;

			elementData = to_string(tempHead->data);
			for (int i = 0; i < elementData.length(); i++)
			{
				if (elementData[i] == NUM[0]) coin = 1;
			}

			if (coin == 1)
			{
				Node* del = new Node;				//������ �������, ������� ����� ����� ������� ��� ����������

				sum++;
				tempTail->Next = tempHead->Next;	//����������� ��������� "��������" ��������� �� ��������� ��������� �����, ����� ������� ������ �� ���������
				tempHead->Next->Prev = tempTail;

				del = tempHead;						//��������� ������� ��������� �� ������ ��� ���������

				if (size == sum) //���� �� ������� ������ � ��� ���� � ������
				{
					delete del;			//�������
					Head = Tail = NULL; //��������
				}
				else
				{
					if (Head == tempHead)
					{
						Head = tempHead->Next;			 //���� ��������� ������, �� ������� ���������� ��������� �������
						tempHead = tempHead->Next;			 //��������� � ���������� ��������
					}
					else if (Tail == tempHead)
					{
						Tail = tempTail;
					}
					else
					{
						tempHead = tempHead->Next;			 //��������� � ���������� ��������
					}

					delete del;							 //� ������ ����� �������
				}
			}
			else //���� �� �����
			{
				tempTail = tempHead;			 //"�������" ������� "���������"
				tempHead = tempHead->Next;		 //��������� � ���������� ��������
			}
			temp--;
		}

		if (sum == 0) cout << "\n������� �����������\n\n"; //���� �� ������� �� ������ ��������
		else
		{
			size -= sum;							 //�������� �������� ������
		}
	}
}

void Helper::Show(int size)
{
	Node* tempHead = new Node; //������...
	tempHead = Head; //...����� ������
	int temp = size; //��������� ���������� ������ ����� ��������� � ������

	cout << "\n\n�������� ������: [ ";
	while (temp != 0) //���� �� �������� ������� ������� �� ����� ������
	{
		cout << tempHead->data << " "; //��������� ������� ������ �� ����� 
		tempHead = tempHead->Next; //���������, ��� ����� ��������� �������
		temp--; //���� ������� ������, ������ �������� �� ���� ������ 
	}
	cout << "]\n\n";
}

void Menu(Helper& node, int rep)
{
	unsigned short int ch, len;
	if (rep == 0)
	{
		cout << "	����\n"
			<< "1 - ��������� ���������� ������\n"
			<< "����: ";
		Enter(ch, 1);

		cout << "\n������ ������"
			<< "\n1 - � ����������"
			<< "\n2 - ��������� �����\n"
			<< "����: ";
		Enter(ch, 2);

		cout << "\n������ ���������� ���������: ";
		Enter(len, 0);

		node.Add(ch, len);
		node.Show(node.Count());

		Menu(node, 1);
	}
	else if (node.Count() == 0)
	{
		cout << "\n������ ����, ����� �� ���������\n";
	}
	else
	{
		cout << "	����\n"
			<< "1 - �������� ������������ ��������� �� ������ �����/����� �������� �������\n"
			<< "2 - ������� �����, ���������� �����\n"
			<< "3 - ����� �� ���������\n"
			<< "����: ";
		Enter(ch, 3);
		if (ch != 3)
		{
			if (ch == 1) node.AddElement();
			else if (ch == 2)
			{
				node.DelEl();
			}
			node.Show(node.Count());
			Menu(node, 1);
		}

	}

}




int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 5\n������\n\n";

	List_one_path Node1; Helper Node2;
	int rep = 0;

	Menu(Node1, rep);

	rep = 0;
	Menu(Node2, rep);

}