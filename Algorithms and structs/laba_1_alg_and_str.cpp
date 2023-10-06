#include <iostream>
#include <string>

using namespace std;

//------------------------------------------ Список

template<class Type> struct Node
{
	Type data; Node<Type>* Next;
	Node(const Type& d = Type(), Node<Type>* p = nullptr) :data{ d }, Next{ p } {}
};

template<class T> class LinkedList
{
private:
	//void copyList(const LinkedList<T>& otherList); // Функция, создающая копию списка otherList.

	int count;// кол-во элементов списка.
	Node<T>* Head;// Указатель на первый элемент списка. 
	Node<T>* Tail;// Указатель на последний элемент списка.
public:

	LinkedList() : Head(NULL), Tail(NULL), count(0) {}; //Инициализация элементов в ноль с помощью конструктора

	//const LinkedList<T>& operator = (const LinkedList<T>&); // Перегрузка оператора присваивания.

	//LinkedList(const LinkedList<T>& otherList); // Копирующий конструктор
	bool isEmpty() const // Отвечает на вопрос пуст список или нет.
	{
		if (count != 0)
		{
			cout << "\nСписок не пуст\n";
			return false;
		}
		else
		{
			cout << "\nСписок пуст\n";
			return true;
		}
	}

	void print() const // Выводит данные из каждого элемента списка.
	{
		if (!isEmpty())
		{
			cout << "\n\t\tАдрес\t\t\tДанные";

			Node<T>* current = new Node<T>;
			current = Head;
			for (int i = 0; i < count; ++i)
			{
				cout << "\n" << i + 1 << "-й элемент\t" << current << "\t" << current->data;
				current = current->Next;
			}
		}
		else cout << "\nЭлементы отсутствуют";
	}

	template<typename U> void printStruct(U displayFunc)
	{
		if (!isEmpty())
		{
			Node<T>* current = Head;

			cout << "\n\t\tАдрес\t\t\tДанные";

			for (int i = 0; i < count; ++i)
			{
				cout << "\n" << i + 1 << "-й элемент\t" << current << "\t";
				displayFunc(current->data);
				current = current->Next;
			}
		}
		else cout << "\nЭлементы отсутствуют";
	}

	int lengthList() const // Возвращает количество элементов в списке.
	{
		return count;
	}

	void empty() // Удаляет все узлы списка. В результате список пуст
	{
		while (count != 0)                //Пока размерность списка не станет нулевой
		{
			Node<T>* temp = Head->Next; //Создаём временный элемент, который будет хранить ссылку на последующие элементы, пока...
			delete Head;             //... мы освобождаем память от активного элемента
			Head = temp;             //Смена адреса начала на адрес последующего элемента
			--count;                  //Один элемент освобожден. Корректируем число элементов
		}
	}

	template<typename U> void frontStruct(U displayFunc)
	{
		if (!isEmpty())
		{
			cout << "\nИнформация первого элемента: \nАдрес: " << Head << "\nДанные: ";
			displayFunc(Head->data);
		}
		else cout << "\nЭлемент отсутствуют";
	}
	template<typename U> void endStruct(U displayFunc)
	{
		if (!isEmpty())
		{
			cout << "\nИнформация первого элемента: \nАдрес: " << Tail << "\nДанные: ";
			displayFunc(Tail->data);
		}
		else cout << "\nЭлемент отсутствуют";
	}

	void front() const // Возвращает информационную часть первого элемент списка.
	{
		if (!isEmpty())
			cout << "\nИнформация первого элемента: \nАдрес: " << Head << "\nДанные: " << Head->data;
		else cout << "\nЭлемент отсутствуют";
	}
	void end() const // Возвращает информационную часть последнего элемента списка.
	{
		if (!isEmpty())
			cout << "\nИнформация последнего элемента: \nАдрес: " << Tail << "\nДанные: " << Tail->data;
		else cout << "\nЭлемент отсутствуют";
	}

	void addAray(T* newArr, size_t size, bool isFirst)
	{
		if (isFirst)
			for (int i = 0; i < size; insertFirst(newArr[i]), ++i)
				cin >> newArr[i];
		else
			for (int i = 0; i < size; insertLast(newArr[i]), ++i)
				cin >> newArr[i];
	}

	void insertFirstStruct(const T newItem) // Добавляет элемент в начало списка.
	{
		++count;						//При каждом добавлении элемента увеличиваем число элементов в списке
		Node<T>* temp = new Node<T>;    //Выделяем память для нового элемента списка
		temp->data = newItem;           //Записываем в выделенную ячейку памяти значение 

		if (Head != NULL)               //В том случае если список не пустой
		{
			temp->Next = Head;
			Head = temp;
		}
		else
			Head = Tail = temp;  //А если список пуст, то создается первый элемент
	}

	void insertLastStruct(const T* newItem) // Добавляет элемент в конец списка.
	{
		++count;						//При каждом добавлении элемента увеличиваем число элементов в списке
		Node<T>* temp = new Node<T>;    //Выделяем память для нового элемента списка
		temp->Next = Head;              //Замыкаем список. Последний элемент – это 'начало' списка
		temp->data = newItem;           //Записываем в выделенную ячейку памяти значение x


		if (Head != NULL)               //В том случае если список не пустой
		{
			Tail->Next = temp;      //Обновляем указатель хвоста на наш новый элемент
			Tail = temp;            //Теперь хвостом стал новый элемент
		}
		else Head = Tail = temp;        //А если список пуст, то создается первый элемент
	}

	void insertFirst(const T& newItem) // Добавляет элемент в начало списка.
	{
		++count;						//При каждом добавлении элемента увеличиваем число элементов в списке
		Node<T>* temp = new Node<T>;    //Выделяем память для нового элемента списка
		temp->data = newItem;           //Записываем в выделенную ячейку памяти значение 

		if (Head != NULL)               //В том случае если список не пустой
		{
			temp->Next = Head;
			Head = temp;
		}
		else
			Head = Tail = temp;  //А если список пуст, то создается первый элемент
	}

	void insertLast(const T& newItem) // Добавляет элемент в конец списка.
	{
		++count;						//При каждом добавлении элемента увеличиваем число элементов в списке
		Node<T>* temp = new Node<T>;    //Выделяем память для нового элемента списка
		temp->Next = Head;              //Замыкаем список. Последний элемент – это 'начало' списка
		temp->data = newItem;           //Записываем в выделенную ячейку памяти значение x


		if (Head != NULL)               //В том случае если список не пустой
		{
			Tail->Next = temp;      //Обновляем указатель хвоста на наш новый элемент
			Tail = temp;            //Теперь хвостом стал новый элемент
		}
		else Head = Tail = temp;        //А если список пуст, то создается первый элемент
	}

	void findNode(const T& item) // Ищет в списке элемент item и возвращает укзатель на этот элемент.
	{
		Node<T>* current = new Node<T>;
		current = Head;
		bool find = false;

		for (int i = 0; i < count; ++i)
		{
			if (current->data == item)
			{
				find = true;
				cout << "\n" << i + 1 << "-й элемент\t" << current << "\t" << current->data;
			}
			current = current->Next;
		}

		if (!find)
			cout << "\nЭлемент не найден";

	}

	template<typename U> void findNodeOfStruct(U printFunc, T item) // Ищет в списке элемент для структуры item и возвращает укзатель на этот элемент.
	{
		Node<T>* current = new Node<T>;
		current = Head;
		bool find = false;

		for (int i = 0; i < count; ++i)
		{
			if (current->data.Name == item.Name || current->data.Surname == item.Surname || current->data.Birthday == item.Birthday || current->data.Duty == item.Duty)
			{
				if (!find)
					cout << "\n\t\tАдрес\t\t\tДанные";
				find = true;
				cout << "\n" << i + 1 << "-й элемент\t" << current << "\t";
				printFunc(current->data);
			}

			current = current->Next;
		}

		if (!find)
			cout << "\nЭлемент не найден";

	}

	Node<T>* nextNode(Node<T>* curr = nullptr) // Возвращает указатель на следующий элемент списка.
	{
		return curr->Next;
	}

	void deleteNode(const T& item) // Удаляет элемент item из списка.
	{
		Node<T>* tempHead = new Node<T>;
		tempHead = Head; //Создаём копию головы для указателя для перебора списка
		Node<T>* tempTail = new Node<T>;

		int sum = 0;

		for (int i = 0; i < count; ++i)
		{
			if (tempHead->data == item)
			{
				Node<T>* del = new Node<T>;                   //Создаём элемент, который можно будет удалить без осложнений

				++sum;                                  //Создаём счётчик удалённых элементов
				tempTail->Next = tempHead->Next;        //Присваиваем указателю "хвостика" следующий...
				//...за удаляемым элементом адрес, чтобы цепочка списка не распалась
				del = tempHead;                         //Удаляемый элемент переносим на только что созданный

				if (count == sum)                                //Если мы удаляем голову и она одна в списке
				{
					delete del;                             //Удаляем элемент
					Head = Tail = NULL;                     //Обнуляем голову и хвост
				}
				else
				{
					if (Head == tempHead)
						Head = tempHead->Next;          //Если удаляется голова, то головой становится следующий элемент

					tempHead = tempHead->Next;              //Переходим к следующему элементу

					delete del;                             //И только потом удаляем
					cout << "\nЭлемент найден и удалён\n";
				}
			}
			else                                            //Если не нашёл
			{
				tempTail = tempHead;                    //"хвостик" остаётся "хвостиком"
				tempHead = tempHead->Next;              //Переходим к следующему элементу
			}
		}
		count -= sum;
		if (sum == 0)
			cout << "\nЭлемент не найден";
	}

	void deleteNodeOfStruct(T item) // Удаляет элемент item из списка.
	{
		Node<T>* tempHead = new Node<T>;
		tempHead = Head; //Создаём копию головы для указателя для перебора списка
		Node<T>* tempTail = new Node<T>;

		int sum = 0;

		for (int i = 0; i < count; ++i)
		{
			if (tempHead->data.Name == item.Name || tempHead->data.Surname == item.Surname || tempHead->data.Birthday == item.Birthday || tempHead->data.Duty == item.Duty)
			{
				Node<T>* del = new Node<T>;                   //Создаём элемент, который можно будет удалить без осложнений

				++sum;                                  //Создаём счётчик удалённых элементов
				tempTail->Next = tempHead->Next;        //Присваиваем указателю "хвостика" следующий...
				//...за удаляемым элементом адрес, чтобы цепочка списка не распалась
				del = tempHead;                         //Удаляемый элемент переносим на только что созданный

				if (count == sum)                                //Если мы удаляем голову и она одна в списке
				{
					delete del;                             //Удаляем элемент
					Head = Tail = NULL;                     //Обнуляем голову и хвост
					cout << "\nЭлемент найден и удалён\n";
				}
				else
				{
					if (Head == tempHead)
						Head = tempHead->Next;          //Если удаляется голова, то головой становится следующий элемент

					tempHead = tempHead->Next;              //Переходим к следующему элементу

					delete del;                             //И только потом удаляем
					cout << "\nЭлемент найден и удалён\n";
				}
			}
			else                                            //Если не нашёл
			{
				tempTail = tempHead;                    //"хвостик" остаётся "хвостиком"
				tempHead = tempHead->Next;              //Переходим к следующему элементу
			}
		}
		count -= sum;
		if (sum == 0)
			cout << "\nЭлемент не найден";
	}

	~LinkedList() // Деструктор
	{
		while (count != 0)                //Пока размерность списка не станет нулевой
		{
			Node<T>* temp = Head->Next; //Создаём временный элемент, который будет хранить ссылку на последующие элементы, пока...
			delete Head;             //... мы освобождаем память от активного элемента
			Head = temp;             //Смена адреса начала на адрес последующего элемента
			--count;                  //Один элемент освобожден. Корректируем число элементов
		}
	}
};

//------------------------------------------- Структура студента и вывод его элементов в списке

struct Student
{
	string Name = "", Surname = "";
	unsigned short Birthday = NULL, Duty = NULL;
};

void PrintDataStudent(const Student p)
{
	printf_s("%s %s %d %d", p.Name.c_str(), p.Surname.c_str(), p.Birthday, p.Duty);
}

//------------------------------------------- Действия со списком на основе выбранного типа данных

void ActionsOfList(LinkedList<string>& node, int action, bool& rep, bool isMas)
{
	if (isMas)
	{
		string masStr[5], i;

		switch (action)
		{
		case 1:
			node.isEmpty();
			break;
		case 2:
			node.print();
			break;
		case 3:
			printf_s("\nДлина списка: %d\n", node.lengthList());
			break;
		case 4:
			node.empty();
			break;
		case 5:
			node.front();
			break;
		case 6:
			node.end();
			break;
		case 7:
			cout << "Ввод данных: ";
			node.addAray(masStr, size(masStr), 1);
			break;
		case 8:
			cout << "Ввод данных: ";
			node.addAray(masStr, size(masStr), 0);
			break;
		case 9:
			cout << "Ввод данных: ";
			cin >> i;
			node.findNode(i);
			break;
		case 10:
			cout << "Ввод данных: ";
			cin >> i;
			node.deleteNode(i);
			break;
		case 11:
			rep = false;
			node.empty();
			break;
		default:
			break;
		}
	}
	else
	{
		string str;

		switch (action)
		{
		case 1:
			node.isEmpty();
			break;
		case 2:
			node.print();
			break;
		case 3:
			printf_s("\nДлина списка: %d\n", node.lengthList());
			break;
		case 4:
			node.empty();
			break;
		case 5:
			node.front();
			break;
		case 6:
			node.end();
			break;
		case 7:
			cout << "Ввод данных: ";
			cin >> str;
			node.insertFirst(str);
			break;
		case 8:
			cout << "Ввод данных: ";
			cin >> str;
			node.insertLast(str);
			break;
		case 9:
			cout << "Ввод данных: ";
			cin >> str;
			node.findNode(str);
			break;
		case 10:
			cout << "Ввод данных: ";
			cin >> str;
			node.deleteNode(str);
			break;
		case 11:
			rep = false;
			node.empty();
			break;
		default:
			break;
		}
	}
}

void ActionsOfList(LinkedList<float>& node, int action, bool& rep)
{
	float masFl[5];
	float i;

	switch (action)
	{
	case 1:
		node.isEmpty();
		break;
	case 2:
		node.print();
		break;
	case 3:
		printf_s("\nДлина списка: %d\n", node.lengthList());
		break;
	case 4:
		node.empty();
		break;
	case 5:
		node.front();
		break;
	case 6:
		node.end();
		break;
	case 7:
		cout << "Ввод данных: ";
		node.addAray(masFl, size(masFl), 1);
		break;
	case 8:
		cout << "Ввод данных: ";
		node.addAray(masFl, size(masFl), 0);
		break;
	case 9:
		cout << "Ввод данных: ";
		cin >> i;
		node.findNode(i);
		break;
	case 10:
		cout << "Ввод данных: ";
		cin >> i;
		node.deleteNode(i);
		break;
	case 11:
		rep = false;
		node.empty();
		break;
	default:
		break;
	}
}

void ActionsOfList(LinkedList<Student>& node, int action, bool& rep)
{
	Student student = { "","", 0, 0 };
	int i;

	switch (action)
	{
	case 1:
		node.isEmpty();
		break;
	case 2:
		node.printStruct(PrintDataStudent);
		break;
	case 3:
		printf_s("\nДлина списка: %d\n", node.lengthList());
		break;
	case 4:
		node.empty();
		break;
	case 5:
		node.frontStruct(PrintDataStudent);
		break;
	case 6:
		node.endStruct(PrintDataStudent);
		break;
	case 7:
		cout << "Ввод данных структуры (Имя, фамилия, год рождения и сколько долгов по учёбе): ";
		cin >> student.Name >> student.Surname >> student.Birthday >> student.Duty;
		node.insertFirstStruct(student);
		break;
	case 8:
		cout << "Ввод данных структуры (Имя, фамилия, год рождения и сколько долгов по учёбе): ";
		cin >> student.Name >> student.Surname >> student.Birthday >> student.Duty;
		node.insertFirstStruct(student);
		break;
	case 9:
		cout << R"(
Что ищешь?

1. Имя
2. Фамилия
3. Год рождения
4. Количество долгов

Ввод: )";
		cin >> i;

		cout << "\nВведите данные: ";
		if (i == 1)
			cin >> student.Name;
		else if (i == 2)
			cin >> student.Surname;
		else if (i == 3)
			cin >> student.Birthday;
		else if (i == 4)
			cin >> student.Duty;

		node.findNodeOfStruct(PrintDataStudent, student);

		break;
	case 10:
		cout << R"(
По чему удаляем?

1. Имя
2. Фамилия
3. Год рождения
4. Количество долгов

Ввод: )";
		cin >> i;

		cout << "\nВведите данные: ";
		if (i == 1)
			cin >> student.Name;
		else if (i == 2)
			cin >> student.Surname;
		else if (i == 3)
			cin >> student.Birthday;
		else if (i == 4)
			cin >> student.Duty;

		node.deleteNodeOfStruct(student);
		break;
	case 11:
		rep = false;
		node.empty();
		break;
	default:
		break;
	}
}

//------------------------------------------- Меню

void MenuOfActions(bool& isRepeat)
{
	if (!isRepeat)
	{
		cout << R"(
Выбери тип данных нового списка:
1. Строка
2. Массив чисел (5 чисел)
3. Массив строк (5 строк)
4. Структура

5. Выход

Ввод: )";
	}
	else
		cout << R"(

Действия

1. Проверка списка на наличие элементов
2. Вывести все элементы списка
3. Вывести длину списка
4. Очистить список
5. Вывести данные первого элемента
6. Вывести данные последнего элемента
7. Добавить элемент в начало списка
8. Добавить элемент в конец списка
9. Найти данные в списке
10. Удалить элемент по данным
11. Создать другой список (Вернуться в меню)

Ввод: )";

}

void MainMenu()
{
	int choice = -1, action = 0;
	bool isRepeat = false;

	LinkedList<string> nodeStr;
	LinkedList<float> nodeFl;
	LinkedList<Student> nodeStudent;

	while (choice != 0)
	{
		MenuOfActions(isRepeat);

		if (!isRepeat)
		{
			scanf_s("%i", &choice);
			action = 0;
			isRepeat = true;
		}
		else
			scanf_s("%i", &action);

		switch (choice)
		{
		case 1:
			ActionsOfList(nodeStr, action, isRepeat, 0);
			break;
		case 2:
			ActionsOfList(nodeFl, action, isRepeat);
			break;
		case 3:
			ActionsOfList(nodeStr, action, isRepeat, 1);
			break;
		case 4:
			ActionsOfList(nodeStudent, action, isRepeat);
			break;
		case 5:
			exit(0);
			break;
		default:
			MainMenu();
		}
	}

}

//------------------------------------------- main

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-21\nВариант 0\n\n\n";

	MainMenu();

	return 0;
}
