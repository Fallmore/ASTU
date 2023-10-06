#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

template<typename T>
struct Node
{
	T term; string explain;
	Node<T>* Prev;
	Node<T>* Next;
	Node(const T& t = T(), const string& e = string(), Node<T>* p = nullptr, Node<T>* n = nullptr) :
		term(t), explain(e), Prev(p), Next(n) {}

};

template<typename T>
class Helper
{
	Node<T>* Head;
	Node<T>* Tail;
	int size;

public:

	Helper() : Head(NULL), Tail(NULL), size(0) {};
	void Add(T wrd, string help);		//Метод добавления термина и его определения
	void Show(int size);				//Метод отображения термина и его определения
	void Show();						//Метод отображения терминов и их определений
	void Terms();						//Метод отображения имеющихся терминов

	int Count()											 //Функция возвращающая число элементов в списке
	{
		return size; //Возвращаем число элементов списка
	}

	~Helper()
	{

		while (size != 0)
		{
			Node<T>* temp = Head->Next;

			delete Head;

			Head = temp;
			--size;
		}
	}

};


template<class T>void Helper<T>::Add(T trm, string expl)
{
	++size;
	Node<T>* temp = new Node<T>;

	temp->term = trm;
	temp->explain = expl;

	if (Head != NULL)
	{
		Tail->Next = temp;
		temp->Prev = Tail;
		Tail = temp;
	}
	else Head = Tail = temp;
}

template<class T>void Helper<T>::Terms()
{
	Node<T>* tempHead = new Node<T>; //Создаём...
	tempHead = Head; //...копию головы
	int temp = Count(); //Временная переменная равная числу элементов в списке

	if (Count() == 0) cout << "\nТермины отсутствуют";

	while (temp != 0) //Пока не выполнен признак прохода по всему списку
	{
		cout << endl << Count() - temp + 1 << ". " << tempHead->term << "\n"; //Очередной элемент списка на экран 
		tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
		--temp; //Один элемент считан, значит осталось на один меньше 
	}
}

template<class T>void Helper<T>::Show(int index)
{
	Node<T>* tempHead = new Node<T>; //Создаём...
	tempHead = Head; //...копию головы
	int temp = 0;
	if (index <= Count() && index >= 0 && Count() != 0)
	{
		temp = index; //Временная переменная равная номеру элемента в списке

		while (temp != 0) //Пока не выполнен признак прохода по всему списку
		{
			tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
			--temp; //Один элемент считан, значит осталось на один меньше 
		}
		cout << endl << tempHead->term << " - " << tempHead->explain << "\n\n"; //Очередной элемент списка на экран 
	}
	else cout << "\nВыход за пределы списка терминов\n\n";
}
template<class T>void Helper<T>::Show()
{
	Node<T>* tempHead = new Node<T>; //Создаём...
	tempHead = Head; //...копию головы
	int temp = Count(); //Временная переменная равная числу элементов в списке

	if (Count() == 0) cout << "\nТермины отсутствуют";

	while (temp != 0) //Пока не выполнен признак прохода по всему списку
	{
		cout << endl << Count() - temp + 1 << ". " << tempHead->term << " - " << tempHead->explain << "\n\n"; //Очередной элемент списка на экран 
		tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
		--temp; //Один элемент считан, значит осталось на один меньше 
	}
}

void Menu(Helper<string>& dict)
{
	int choice = -1, i = 5;
	string term;
	string explain;
	cout << endl << R"(Выбери действие
1. Добавить термин с определением
2. Показать термин с определением
3. Показать все термины
4. Показать все термины с определениями

5. Выход

Ввод: )";
	cin >> choice;

	switch (choice)
	{
	case 1:
		char ch;

		cout << "\n\nВведите термин: ";
		cin >> term;
		cout << "\nВведите определение (Для выхода нажмите \"Ctrl+[\"): ";
		cin.ignore();
		while (i != 0)
		{
			ch = cin.get();
			if (ch == 27) break;
			explain += ch;
			if (ch == '\n') --i;
		}
		dict.Add(term, explain);
		break;
	case 2:
		int index;
		cout << "\nВведи номер термина: ";
		cin >> index;
		if (index > 0) --index;
		dict.Show(index);
		break;
	case 3:
		dict.Terms();
		break;
	case 4:
		dict.Show();
		break;
	case 5:
		exit(0);
		break;
	default:
		break;
	}

	Menu(dict);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	cout << "Самодуров ДИНРБ-21/2\nВариант 6\n\n\n";

	Helper<string> dict;
	Menu(dict);
}

