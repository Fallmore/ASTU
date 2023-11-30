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
							if (rep < 1) cout << "\nЧисло должно быть положительным" << "\nВвод: ";
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

void in(string num, int& n) // правильный ли номер
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
						cout << "\nЭто не цифра" << "\nВведи любой положительный номер последовательности: ";
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
	void Show(int size);									 //Функция отображения элементов списка
	int Count();											 //Функция возвращающая число элементов в списке
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
	return size; //Возвращаем число элементов списка
}

void List_one_path::Add(int n, int _size)
{
	unsigned short int x = 0;

	switch (n)
	{
	case 1:

		while (size != _size)
		{
			cout << "\nВведи положительное число: ";
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

		cout << "\nВведи диапазон от 0 до 65535 [a;b] - ";
		do
		{
			Enter(a, 0);
			Enter(b, 0);

			if (a >= b) cout << "\nНеверный диапазон\n Введи диапазон - ";

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

	while (temp != 0) //Пока не выполнен признак прохода по всему списку
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

		tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
		temp--; //Один элемент считан, значит осталось на один меньше 
	}

	cout << "\nМаксимальный палиндром = " << maxpal;
	tempHead = Head; temp = size;
	cout << "\n\nДобавить палиндром до простых чисел или после?"
		<< "\n1 - До"
		<< "\n2 - После"
		<< "\nВвод: ";
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
			tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
			temp--; //Один элемент считан, значит осталось на один меньше
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
			tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
			temp--; //Один элемент считан, значит осталось на один меньше
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
		tempHead = Head; //Создаём копию головы для указателя для перебора списка
		Node_one_path* tempTail = new Node_one_path;
		tempTail = Head; //Второй указатель, "хвостик"

		cout << "\nВведи цифру для удаления числа, содержащего эту цифру\n"
			<< "Ввод: ";
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
				Node_one_path* del = new Node_one_path;				//Создаём элемент, который можно будет удалить без осложнений

				sum++;
				tempTail->Next = tempHead->Next;	//Присваиваем указателю "хвостика" следующий за удаляемым элементом адрес, чтобы цепочка списка не распалась
				del = tempHead;						//Удаляемый элемент переносим на только что созданный

				if (size == sum) //Если мы удаляем голову и она одна в списке
				{
					delete del;			//Удаляем
					Head = Tail = NULL; //Обнуляем
				}
				else
				{
					if (Head == tempHead)
					{
						Head = tempHead->Next;			 //Если удаляется голова, то головой становится следующий элемент
						tempTail = tempHead;				 //"хвостик" остаётся "хвостиком"
						tempHead = tempHead->Next;			 //Переходим к следующему элементу
					}
					else if (Tail == tempHead)
					{
						Tail = tempTail;
					}
					else
					{
						tempHead = tempHead->Next;			 //Переходим к следующему элементу
					}

					delete del;							 //И только потом удаляем
				}
			}
			else //Если не нашёл
			{
				tempTail = tempHead;			 //"хвостик" остаётся "хвостиком"
				tempHead = tempHead->Next;		 //Переходим к следующему элементу
			}
			temp--;
		}

		if (sum == 0) cout << "\nЭлемент отсутствует\n\n"; //Если не найдено ни одного элемента
		else
		{
			size -= sum;							 //Получаем итоговый размер
		}
	}
}

void List_one_path::Show(int size)
{
	Node_one_path* tempHead = new Node_one_path; //Создаём...
	tempHead = Head; //...копию головы
	int temp = size; //Временная переменная равная числу элементов в списке

	cout << "\n\nИтоговый список: [ ";
	while (temp != 0) //Пока не выполнен признак прохода по всему списку
	{
		cout << tempHead->data << " "; //Очередной элемент списка на экран 
		tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
		temp--; //Один элемент считан, значит осталось на один меньше 
	}
	cout << "]\n\n";
}

void Menu(List_one_path& node, int rep)
{
	unsigned short int ch, len;
	if (rep == 0)
	{
		cout << "	Меню\n"
			<< "1 - Заполнить односвязный список\n"
			<< "Ввод: ";
		Enter(ch, 1);

		cout << "\nВыбери способ"
			<< "\n1 - С клавиатуры"
			<< "\n2 - Случайные числа\n"
			<< "Ввод: ";
		Enter(ch, 2);

		cout << "\nВыбери количество элементов: ";
		Enter(len, 0);

		node.Add(ch, len);
		node.Show(node.Count());

		Menu(node, 1);
	}
	else if (node.Count() == 0)
	{
		cout << "\nСписок пуст, выход из программы\n";
	}
	else
	{
		cout << "	Меню\n"
			<< "1 - Добавить максимальный палиндром из списка перед/после простыми числами\n"
			<< "2 - Удалить числа, содержащие цифру\n"
			<< "3 - Выход из программы\n"
			<< "Ввод: ";
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
	void Show(int size);									 //Функция отображения элементов списка
	int Count();											 //Функция возвращающая число элементов в списке
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
	return size; //Возвращаем число элементов списка
}

void Helper::Add(int n, int _size)
{
	unsigned short int x = 0;

	switch (n)
	{
	case 1:

		while (size != _size)
		{
			cout << "\nВведи положительное число: ";
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

		cout << "\nВведи диапазон от 0 до 65535 [a;b] - ";
		do
		{
			Enter(a, 0);
			Enter(b, 0);

			if (a >= b) cout << "\nНеверный диапазон\n Введи диапазон - ";

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

	while (temp != 0) //Пока не выполнен признак прохода по всему списку
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

		tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
		temp--; //Один элемент считан, значит осталось на один меньше 
	}

	cout << "\nМаксимальный палиндром = " << maxpal;
	tempHead = Head; temp = size;
	cout << "\n\nДобавить палиндром до простых чисел или после?"
		<< "\n1 - До"
		<< "\n2 - После"
		<< "\nВвод: ";
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
			tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
			temp--; //Один элемент считан, значит осталось на один меньше
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
			tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
			temp--; //Один элемент считан, значит осталось на один меньше
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
		tempHead = Head; //Создаём копию головы для указателя для перебора списка
		Node* tempTail = new Node;
		tempTail = Head; //Второй указатель, "хвостик"

		cout << "\nВведи цифру для удаления числа, содержащего эту цифру\n"
			<< "Ввод: ";
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
				Node* del = new Node;				//Создаём элемент, который можно будет удалить без осложнений

				sum++;
				tempTail->Next = tempHead->Next;	//Присваиваем указателю "хвостика" следующий за удаляемым элементом адрес, чтобы цепочка списка не распалась
				tempHead->Next->Prev = tempTail;

				del = tempHead;						//Удаляемый элемент переносим на только что созданный

				if (size == sum) //Если мы удаляем голову и она одна в списке
				{
					delete del;			//Удаляем
					Head = Tail = NULL; //Обнуляем
				}
				else
				{
					if (Head == tempHead)
					{
						Head = tempHead->Next;			 //Если удаляется голова, то головой становится следующий элемент
						tempHead = tempHead->Next;			 //Переходим к следующему элементу
					}
					else if (Tail == tempHead)
					{
						Tail = tempTail;
					}
					else
					{
						tempHead = tempHead->Next;			 //Переходим к следующему элементу
					}

					delete del;							 //И только потом удаляем
				}
			}
			else //Если не нашёл
			{
				tempTail = tempHead;			 //"хвостик" остаётся "хвостиком"
				tempHead = tempHead->Next;		 //Переходим к следующему элементу
			}
			temp--;
		}

		if (sum == 0) cout << "\nЭлемент отсутствует\n\n"; //Если не найдено ни одного элемента
		else
		{
			size -= sum;							 //Получаем итоговый размер
		}
	}
}

void Helper::Show(int size)
{
	Node* tempHead = new Node; //Создаём...
	tempHead = Head; //...копию головы
	int temp = size; //Временная переменная равная числу элементов в списке

	cout << "\n\nИтоговый список: [ ";
	while (temp != 0) //Пока не выполнен признак прохода по всему списку
	{
		cout << tempHead->data << " "; //Очередной элемент списка на экран 
		tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
		temp--; //Один элемент считан, значит осталось на один меньше 
	}
	cout << "]\n\n";
}

void Menu(Helper& node, int rep)
{
	unsigned short int ch, len;
	if (rep == 0)
	{
		cout << "	Меню\n"
			<< "1 - Заполнить двусвязный список\n"
			<< "Ввод: ";
		Enter(ch, 1);

		cout << "\nВыбери способ"
			<< "\n1 - С клавиатуры"
			<< "\n2 - Случайные числа\n"
			<< "Ввод: ";
		Enter(ch, 2);

		cout << "\nВыбери количество элементов: ";
		Enter(len, 0);

		node.Add(ch, len);
		node.Show(node.Count());

		Menu(node, 1);
	}
	else if (node.Count() == 0)
	{
		cout << "\nСписок пуст, выход из программы\n";
	}
	else
	{
		cout << "	Меню\n"
			<< "1 - Добавить максимальный палиндром из списка перед/после простыми числами\n"
			<< "2 - Удалить числа, содержащие цифру\n"
			<< "3 - Выход из программы\n"
			<< "Ввод: ";
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
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\nСписки\n\n";

	List_one_path Node1; Helper Node2;
	int rep = 0;

	Menu(Node1, rep);

	rep = 0;
	Menu(Node2, rep);

}