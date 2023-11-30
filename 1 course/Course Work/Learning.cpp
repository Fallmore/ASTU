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

// Функция с палитрой
void Color(int mode) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (mode == 0) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));		// черный фон; белый текст
	if (mode == 1) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 1));		// черный фон; синий текст
	if (mode == 2) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 14));		// черный фон; жёлтый текст
	if (mode == 3) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 8));		// черный фон; серый текст
	if (mode == 4) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 11));		// черный фон; голубой текст
	if (mode == 5) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 2));		// черный фон; зелёный текст
	if (mode == 6) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 6));		// черный фон; бледно жёлтый текст
	if (mode == 7) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 13));		// черный фон; розовый текст
	if (mode == 8) SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 9));		// черный фон; бледно голубой текст
}

// Функция покраски текста
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
			if (rep < 1) cout << "\nДействие отсутствует" << endl << "Введите повторно: ";
			rep = 1;
		}
		else if (choice > NumberOfChoice || choice < 1)
		{
			if (rep < 1) cout << "\nДействие отсутствует" << endl << "Введите повторно: ";
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
			if (rep < 1) cout << "\nДействие отсутствует" << endl << "Введите повторно: ";
			rep = 1;

		}
		else if (choice > NumberOfChoice || choice < 1)
		{
			if (choice == 1489)
			{
				check = 9; cout << "\n\nЧит-код активирован\n\n";
				cout << "\nВыберите действие: "
					<< "\n1 - О программе"
					<< "\n2 - Выбор темы"
					<< "\n3 - Тест"
					<< "\n\n4 - Выход из программы"
					<< "\n\nВвод: ";
			}
			else if (rep < 1) cout << "\nДействие отсутствует" << endl << "Введите повторно: ";
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
			if (rep < 1) cout << "\nЭто не число" << endl << "Введите повторно: ";
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
	Node* Head, * Tail; //Объявляем первый элемент и тот, что последний
	int size; //Число элементов в списке
public:
	List() : Head(NULL), Tail(NULL), size(0) {}; //Инициализация элементов в ноль с помощью конструктора
	void Add(int n, int count, int BeforeChoice, int Insta); //Функция добавления элементов в список
	void Show(int size, List& lst, int Insta);				 //Функция отображения элементов списка
	int Count();											 //Функция возвращающая число элементов в списке
	void Find();											 //Функция поиска элемента
	void DelEl();											 //Функция удаления элемента
	~List();												 //Деструктор для освобождения памяти
};

List::~List()
{

	cout << "\n\nРабота деструктора\n\n";
	int tempsize = size;
	if (size == 0) cout << "\nsize = 0 - В списке нет элементов, поэтому работа деструктора невозможна по условию самого деструктора ;)\n";
	while (size != 0) //Пока размерность списка не станет нулевой 
	{
		Node* temp = Head->Next;
		if (size > tempsize - 2)
		{
			cout << "\n" << tempsize - size + 1 << "-е удаление\n";
			Paint(L"\nNode", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = Head"; Paint(L"->", 3); wcout << "Next;\n";
			wcout << "\nHead"; Paint(L"->", 3); wcout << "Next = " << Head->Next << L" - ссылка головы на следующий элемент\n";
			Paint(L"temp", 8); wcout << " = " << temp << L" - из той ссылки присвоили временному элементу настоящий, следующий, элемент из списка,\n"
				<< L"			  чтобы не потерять связь с остальными элементами";
		}

		delete Head; //Освобождаем память от активного элемента
		if (size > tempsize - 2)
		{
			Paint(L"\ndelete", 1); wcout << " Head;\n"
				<< "Head"; Paint(L"->", 3); Paint(L"x", 8); wcout << " = " << Head->x << "	             \\\n"
				<< "Head"; Paint(L"->", 3); wcout << "Next = " << Head->Next << L" - удалили голову\n";
		}

		Head = temp; //Смена адреса начала на адрес следующего элемента
		size--; //Один элемент освобожден. корректируем число элементов
		if (size > tempsize - 2)
		{
			cout << "\nHead = "; Paint(L"temp", 8); wcout << ";";
			wcout << "\nHead"; Paint(L"->", 3); Paint(L"x", 8); wcout << " = " << Head->x << "	             \\\n"
				<< "Head"; Paint(L"->", 3); wcout << "Next = " << Head->Next << L" - и после удаления логично, что головой теперь будет \"настоящий\" элемент, т.к. он стал начальным\n";
			wcout << "\nsize"; Paint(L"--", 3); wcout << " = " << size << L" - ну и уменьшаем размер на один\n\n";
			system("pause");
		}

		if (size == tempsize - 2)
			cout << "\n\nИ так далее...\n\n";
	}
	Head = NULL; //Для следующего использования класса после деструктора,
	Tail = NULL; //если пользователь что-то не понял в темах или что-то хочет (+2 би(ай)та в памяти ничего не сломают))))
}

int List::Count()
{
	return size; //Возвращаем число элементов списка
}

void List::Add(int n, int count, int BeforeChoice, int Insta)
{
	int tempsize = 0;
	switch (n) // изменить для буквы
	{
	case 1: //Вставка элемента в конец списка
		cin.clear(); //Очищаем ввод от ошибок, которые могут остаться, если снова обратимся к функции
		int x;

		cout << "\nВведите любые числа (x) любое количество раз, можете для проверки корректности ввести букву (Чтобы закончить ввод нажмите Enter)\nВвод: ";
		do
		{
			if (!(cin >> x)) //Если ввод числа закончен ошибкой, например, вводом буквы... 
			{
				if (count < 1) //Делаем счётчик, так как без него в данном коде сообщение выводится 2 раза
				{
					cout << "\nНекорректное значение\n"; //...то выводим сообщение об ошибке
					if (Insta == 0) cout << "Вы ввели букву\n"; Paint(L"count", 3); wcout << L" = 1 - Ошибка считалась, хорошо\n\n";
					system("Pause");
				}
				count = 1;
			}
			else
			{
				if (tempsize == 0 && Insta == 0)
				{
					cout << "\nВы ввели числа, отлично, давайте посмоторим, что получилось\n\n";
					system("Pause");
				}
				else if (tempsize == 1 && Insta == 0)
				{
					system("Pause");
					cout << "\nТеперь сделаем то же самое с " << size + 1 << "-м числом\n";
				}

				size++; //При каждом добавлении элемента увеличиваем число элементов в списке
				tempsize++;
				if (Insta == 0 && tempsize < 3)
				{
					Paint(L"\nx", 8); wcout << " ("; cout << "элемент) = " << x;
					cout << "\nsize (размер) = " << tempsize;
				}
				Node* temp = new Node; //Выделение памяти для нового элемента списка

				if (tempsize == 1 && Insta == 0)
				{
					cout << "\n\nИ сейчас переходим к непростому\n";
					Paint(L"Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - Выделяем память для нового элемента списка\n";
					Paint(L"Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; cout << temp << " - А вот и адрес ссылки элемента списка\n\n";
					system("Pause");
					cout << "\nТеперь давайте посмотрим есть ли адрес у начального элемента списка (головы)\n";
					cout << "\nАдрес головы = " << Head << " - Как видим, его нет\n\n";
					system("Pause");
				}
				else if (size == 2 && Insta == 0)
				{
					Paint(L"\n\nNode", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - Снова выделяем память для нового элемента списка\n";
					Paint(L"Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; cout << temp << " - Адрес ссылки элемента списка\n";
					if (size == 2) cout << "\nИ смотрим адрес у головы\n\nАдрес головы = " << Head << " - И видим, что он совпадает с адресом элемента, который мы только что добавили\n\n";
					else cout << "(Теперь на адрес головы нет смысла смотреть, так как он везде будет одинаковым)\n\n";
					system("Pause");
				}

				temp->Next = Head; //Замыкание контура. Последний элемент – это начало списка
				temp->x = x; //Записываем в выделенную ячейку памяти значение x 

				if (tempsize == 1 && Insta == 0)
				{
					cout << "\nДалее заполняем наш элемент: даём ему адрес на следующий элемент и даём число\n\n";
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = Head;"; cout << " - Так как теперь наш элемент является последним, присваиваем указателю ссылку на голову (даже если её нет)\n";
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = "; cout << temp->Next << endl;
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "x = "; Paint(L"x", 8); wcout << ";"; cout << " - И присваиваем вписанный нами элемент\n";
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "x = "; cout << temp->x << "\n\n";
					system("Pause");
					cout << "\nТеперь заходим в условие и проверяем, есть ли у нас голова";
				}
				else if (tempsize == 2 && Insta == 0)
				{
					cout << "\nДалее снова заполняем наш элемент: снова даём ему адрес на следующий элемент и даём число\n\n";
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = Head;"; cout << " - Так как теперь наш элемент является последним, присваиваем указателю ссылку на голову\n";
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = "; cout << temp->Next << endl;
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "x = "; Paint(L"x", 8); wcout << ";"; cout << " - И присваиваем вписанный нами элемент\n";
					Paint(L"temp", 8); Paint(L"->", 3); wcout << "x = "; cout << temp->x << "\n\n";
					system("Pause");
					cout << "\nТеперь заходим в условие и проверяем, есть ли у нас голова";
				}

				if (Head != NULL) //В том случае если список не пустой
				{
					Tail->Next = temp; //Обновляем указатель хвоста на наш новый элемент
					Tail = temp; //Теперь хвостом стал новый элемент
					if (Insta == 0 && tempsize == 2)
					{
						cout << "\n\nHead = " << Head << " - Как видим, она не пуста\n";
						Paint(L"\ntemp", 8); wcout << " = "; cout << temp << "       \\";
						wcout << "\nTail"; Paint(L"->", 3); wcout << "Next = "; cout << Tail->Next << "  - Как видим, присваивание сработало";
						cout << "\nTail = " << Tail << "       /\n\nИ так далее...\n\n";
					}
				}
				else
				{
					if (Insta == 0) cout << " (хаха)\n\nHead = " << Head << " - Как видим, пока нет (хаха х2)";
					Head = Tail = temp; //Если список пуст, то создается первый элемент.
					if (Insta == 0)
					{
						cout << "\n\nПоэтому присваиваем первоначальным голове и хвосту наш элемент списка, то есть наш первый элемент станет и головой, и хвостом\n";
						Paint(L"\ntemp", 8); wcout << " = "; cout << temp << "  \\"
							<< "\nHead = " << Head << "   - Как видим, присваивание сработало"
							<< "\nTail = " << Tail << "  /\n\n";
					}
				}
			}
		} while (getchar() != '\n');
		if (count == 1) //Если ввод был с ошибкой
		{
			cout << "\nПосле этого сразу выходим из "; Paint(L"do", 7); wcout << "..."; Paint(L"while", 7); wcout << L" в "; Paint(L"\nif", 7); wcout << " ("; Paint(L"count", 3); wcout << " != 0)\n";
			count = 0; //Обнуляем счётчик для...
			cout << "\nСчётчик обнуляется - "; Paint(L"count", 3); wcout << " = "; cout << count << " - И мы возвращаемся в начало функции.\n\n";
			system("Pause");
			Add(n, count, BeforeChoice, Insta); //...рекурсии
		}

		if (BeforeChoice == 1)
		{
			Add(2, 0, 0, 0);
		}
		break;

	case 2: //Вставка элемента в любую позицию между головой и хвостом
		if (size > 1)
		{

			int pos;
			int a;
			cout << "\nsize = " << size << endl;
			cout << "Введите позицию: ";
			CheckEnter(pos);
			if (pos <= size && pos > 1) //если позиция не больше размера списка, положительное число и не указывает на голову
			{
				cout << "Введите a: ";
				CheckEnter(a);
				Node* temp = new Node; //Выделяем память для нового элемента списка
				temp->x = a; //Записываем в выделенную ячейку памяти значение а
				Paint(L"\nNode", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - Выделяем память для нового элемента списка\n";
				Paint(L"Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; cout << temp << " - Адрес ссылки нового элемента списка\n\n";
				Paint(L"temp", 8); Paint(L"->", 3); wcout << "x = "; Paint(L"a", 8); wcout << ";"; cout << " - И присваиваем вписанный нами элемент\n";
				Paint(L"temp", 8); Paint(L"->", 3); wcout << "x = "; cout << temp->x << "\n\n";

				Node* tempHead = new Node;
				tempHead = Head; //Создаём копию головы
				Paint(L"Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - Выделяем память для копии головы\n";
				Paint(L"Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; cout << tempHead << " - Его адрес\n\n";
				system("pause");

				cout << "\nПриступаем к добавлению:\n";
				if (Head != NULL) //Если список не пустой
				{
					if (pos == size) //Или если позиция равна размеру
					{
						cout << "\nТак-с, позиция равна размеру, значит наш элемент будет перед хвостом\n";

						temp->Next = Tail; //Присваиваем адрес хвоста
						cout << "\nTail = " << Tail << " - Адрес хвоста\n";
						Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = Tail;\n";
						Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = " << temp->Next << L" - Присвоили указателю адрес на хвост\n\n";
						system("pause");

						wcout << L"\nТеперь ищем адрес элемента, который ссылался на хвост, то есть который будет стоять перед элементом:\n\n";
						for (int i = 1; i != pos - 1; i++)
						{
							tempHead = tempHead->Next; //И ищем нужный адрес, который ссылался на хвост, т.е. предыдущий

							if (i == 1)
							{
								Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;";
							}
							Paint(L"\ni", 8); wcout << " = " << i << "  ";
							Paint(L"tempHead", 8); wcout << " = " << tempHead;
							if (i == pos - 2) cout << " - Нашли\n\n";
						}
						tempHead->Next = temp; //Присваиваем этому адресу адрес нового элемента

						Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"temp", 8); wcout << L"; - Ну и присваиваем указателю у этого элемента наш элемент\n";
						Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next = " << tempHead->Next << "\n\n";
						system("pause");
					}
					else //Или если любая другая позиция
					{
						cout << "\nХорошо, позиция не равна размеру, тогда приступим к махинациям\n\n";
						for (int i = 1; i != pos; i++)
						{
							tempHead = tempHead->Next; //Ищем адрес элемента, чьё место мы займём, сдвинув вправо

							if (i == 1)
							{
								Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;";
							}
							Paint(L"\ni", 8); wcout << " = " << i << "  ";
							Paint(L"tempHead", 8); wcout << " = " << tempHead;
							if (i == pos - 1) //И на последнем цикле
							{
								temp->Next = tempHead; //Присваиваем найденный адрес новому элементу

								cout << " - Элемент, который мы сдвинем\n\n";
								Paint(L"\ntemp", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"tempHead", 8); wcout << L"; - Присваиваем указателю нового элемента адрес найденного\n";
								Paint(L"temp", 8); Paint(L"->", 3); wcout << "Next = " << temp->Next << "\n\n";

								tempHead = Head; //Сбрасываем значение, чтобы найти предыдущий адрес

								system("pause");
								Paint(L"\ntempHead", 8); wcout << L" = Head; - Сбрасываем значение\n";
								Paint(L"tempHead", 8); wcout << " = " << Head;
								wcout << L"\n\nТеперь ищем адрес элемента, который ссылался на заменённый, то есть который будет стоять перед нашим новым элементом:\n\n";
								for (int i = 1; i != pos - 1; i++)
								{
									tempHead = tempHead->Next; //И ищем нужный адрес перед позицией

									if (i == 1) Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;";
									Paint(L"\ni", 8); wcout << " = " << i << "  ";
									Paint(L"tempHead", 8); wcout << " = " << tempHead;
									if (i == pos - 2) cout << " - Нашли\n\n";
								}
								tempHead->Next = temp; //Присваиваем ему адрес нового элемента

								Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"temp", 8); wcout << L"; - Ну и присваиваем указателю у этого элемента наш элемент\n";
								Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next = " << tempHead->Next << "\n\n";
								system("pause");
							}
						}
					}
				}
				size++;
				//Вывод полученного списка
				tempHead = Head; //Обнуляем
				int c = size; //Временная переменная равная числу элементов в списке
				cout << "\nПолученный список = ( ";
				while (c != 0) //Пока не выполнен признак прохода по всему списку
				{
					cout << tempHead->x << " "; //Очередной элемент списка на экран 
					tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
					c--; //Один элемент считан, значит осталось на один меньше 
				}
				cout << ")\n\nsize = " << size << endl;
				cout << "\nЖелаете продолжить добавлять (продолжение обучения)?\n"
					<< "1 - Да\n"
					<< "2 - Нет\n"
					<< "Ввод: ";
				int choice;
				CheckEnter(choice, 2);

				switch (choice)
				{
				case 1:
					Add(2, 0, 0, Insta); //Рекурсия без изменений
					break;
				case 2:
					break;
				}
			}
			else //если позиция больше размера списка, отрицательное число или указывает на голову
			{
				cout << "\nНеправильная позиция\n";
				Add(2, 0, 0, Insta); //Рекурсия без изменений
			}

		}
		else
		{
			if (count == 0)
			{
				cout << "\nКоличество элементов в списке меньше двух. \nКоличество элементов = " << size << "\nЗаполнение в позицию невозможно\n";
				cout << "\nЖелаете быстро заполнить список элементами?\n"
					<< "1 - Да\n"
					<< "2 - Нет (с обучением)\n"
					<< "3 - Точно нет (закончить)\n"
					<< "Ввод: ";
			}
			int choice;
			CheckEnter(choice, 3);

			switch (choice)
			{
			case 1: Add(1, 0, 1, 1); //Рекурсия с добавлением условия для возвращения
				break;
			case 2: Add(1, 0, 1, 0); //Рекурсия с добавлением условия для возвращения
				break;
			case 3:
				break;
			}
		} break;
	default: cout << "\nДействие отсутствует" << endl << "Введите повторно: "; cin >> n; Add(n, 0, 0, Insta);
		break;
	}
}

void List::Show(int size, List& lst, int Insta)
{
	Node* tempHead = new Node; //Создаём...
	tempHead = Head; //...копию головы
	int temp = size; //Временная переменная равная числу элементов в списке

	if (Insta == 0)
	{
		cout << "\n   Вывод списка\n\n";
		Paint(L"Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";\n";
		Paint(L"tempHead", 8); wcout << " = Head;\n";
		cout << "Head = " << Head << " - оригинальная голова\n";
		Paint(L"tempHead", 8); wcout << " = " << tempHead << L" - копия головы\n\n";
		system("pause");
		Paint(L"\nint", 1); Paint(L" temp", 8); wcout << " = "; Paint(L"size", 3); wcout << ";\n";
		Paint(L"temp", 8); wcout << " = " << temp << ";";

		if (size == 0)
		{
			cout << "\n\nИтоговый список: "
				<< "[ ] - Как видим, список пуст, так как размер равен нулю и вы его не заполняли в прошлых темах\n"
				<< "\nХотите перейти сразу к заполнению? (через добавление в конец)"
				<< "\n1 - Да"
				<< "\n2 - Нет (заполнение с обучением)"
				<< "\n3 - Точно нет (закончить)"
				<< "\nВвод: ";
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
			cout << "\n\nИ пока размер не равен нулю, мы выводим элемент копии головы,"
				<< "\nа затем назначаем копию следующего элемента, после чего уменьшаем размер на 1,\n"
				<< "\nвыводим элемент этой копии, назначаем новую копию и так далее"
				<< "\n\nИтоговый список: [ ";
			while (temp != 0) //Пока не выполнен признак прохода по всему списку
			{
				cout << tempHead->x << " "; //Очередной элемент списка на экран 
				tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
				temp--; //Один элемент считан, значит осталось на один меньше 
			}
			cout << "]\n\n";
		}
	}
	else
	{
		cout << "\n\nИтоговый список: [ ";
		while (temp != 0) //Пока не выполнен признак прохода по всему списку
		{
			cout << tempHead->x << " "; //Очередной элемент списка на экран 
			tempHead = tempHead->Next; //Указываем, что нужен следующий элемент
			temp--; //Один элемент считан, значит осталось на один меньше 
		}
		cout << "]\n\n";
	}
}

void List::Find()
{
	int choice, ch, have = 0, pos, a;
	if (Head != NULL)
	{

		cout << "\nЖелаете найти элемент по расположению или по наличию какого-нибудь числа в нём?\n"
			<< "1 - По расположению\n"
			<< "2 - По наличию числа\n"
			<< "Ввод: ";
		CheckEnter(choice, 2);

		Node* tempHead = new Node;
		tempHead = Head; //Создаём копию головы для указателя для перебора списка
		Paint(L"\nNode", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - Создаём только ради указателя\n";
		Paint(L"Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = " << tempHead << L" - Проверяем\n\n";
		system("Pause");

		switch (choice)
		{
		case 1: //Поиск элемента по расположению
			cout << "\nsize = " << size;
			cout << "\nВведите позицию элемента\n"
				<< "Ввод: ";
			CheckEnter(pos);

			if (pos < 1 || pos > size)
			{
				cout << "\nНу\n";
				Paint(L"pos", 8); wcout << " = " << pos
					<< "\nsize = " << size << L" - из чего следует вывод, что...\n";

				cout << "\nЭлемент отсутствует\n\n";
			}
			else
			{
				for (int i = 1; i != pos; i++)
				{
					if (i == 1)
					{
						cout << "\nНачинаем пробежку:\n\n";
						Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;";
					}
					Paint(L"\ni", 8); wcout << " = " << i << "  ";
					Paint(L"tempHead", 8); wcout << " = " << tempHead;
					tempHead = tempHead->Next; //Находим адресс элемента на позиции перебором

				}
				Paint(L"\ni", 8); wcout << " = " << pos << "  ";
				Paint(L"tempHead", 8); wcout << " = " << tempHead;
				cout << " - Нашли\n";

				if (pos == 1) cout << "\nНу так как позиция равна 1, то заходить в цикл нет смысла\n";
				cout << "\nЭлемент найден\nАдрес: " << tempHead
					<< "\nСодержание: " << tempHead->x << "\n\n";
			}
			break;

		case 2: //Поиск элемента по числу
			cout << "\nВведите число\n"
				<< "Ввод: ";
			CheckEnter(a);

			cout << "\nЗаходим в цикл:\n\n";

			for (int i = 1; i != size + 1; i++)
			{
				if (i == 1)
				{
					Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "x == "; Paint(L"a\n", 8);
					Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << L"Next - Главные действия здесь, их и рассмотрим\n\n";
				}
				Paint(L"i", 8); wcout << " = " << i << "  ";
				Paint(L"tempHead", 8); wcout << " = " << tempHead;
				Paint(L" tempHead", 8); Paint(L"->", 3); wcout << "x = " << tempHead->x << endl;
				if (tempHead->x == a)									//Если элемент имеет нужное значение...
				{
					have = 1;
					cout << "\nЭлемент найден\nАдрес: " << tempHead	//...выводим его
						<< "\nСодержание: " << tempHead->x << "\n";
					if (i != size) cout << endl;
				}
				tempHead = tempHead->Next;								//Находим адресс элемента перебором
			}
			cout << endl;
			if (have == 0)
			{
				cout << "\n\nНи одного элемента списка не нашли, значит";
				cout << "\nЭлемент отсутствует\n\n"; //Если не найдено ни одного элемента
			}
			break;
		}
	}
	else
	{
		cout << "\n\nСписок пуст";
		cout << "\nЖелаете быстро заполнить список элементами?\n"
			<< "1 - Да\n"
			<< "2 - Нет (с обучением)\n"
			<< "3 - Точно нет (закончить)\n"
			<< "Ввод: ";

		CheckEnter(ch, 3);
		switch (ch)
		{
		case 1: Add(1, 0, 0, 1); //Рекурсия с добавлением условия для возвращения
			Find();
			break;
		case 2: Add(1, 0, 0, 0); //Рекурсия с добавлением условия для возвращения
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
		tempHead = Head; //Создаём копию головы для указателя для перебора списка
		Node* tempTail = new Node;
		tempTail = Tail; //Второй указатель, "хвостик"
		Paint(L"\nNode", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - Создаём только ради указателя\n";
		Paint(L"tempHead", 8); wcout << L" = Head; - Будем начинать с головы\n";
		Paint(L"tempHead", 8); wcout << " = " << tempHead << L" - Проверяем\n\n";
		Paint(L"Node", 4); Paint(L"*", 3); Paint(L" tempTail", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; cout << " - Тоже создаём только ради указателя\n";
		Paint(L"tempTail", 8); wcout << L" = Tail; - И \"хвостик\" за ним\n";
		Paint(L"tempTail", 8); wcout << " = " << tempTail << L" - Проверяем\n\n";
		system("Pause");

		cout << "\nЖелаете удалить элемент по расположению или по наличию какого-нибудь числа в нём?\n"
			<< "1 - По расположению\n"
			<< "2 - По наличию числа\n"
			<< "Ввод: ";
		CheckEnter(choice, 2);
		switch (choice)
		{
		case 1: //Удаление элемента по расположению
			cout << "\n\nВведите позицию элемента\n"
				<< "Ввод: ";
			CheckEnter(pos);

			if (pos < 1 || pos > size)
			{
				cout << "\nНу\n";
				Paint(L"pos", 8); wcout << " = " << pos
					<< "\nsize = " << size << L" - из чего следует вывод, что...\n";

				cout << "\nЭлемент отсутствует\n";
			}
			else
			{

				if (pos == 1)
				{
					Head = tempHead->Next;			//Если удаляется голова, то головой становится следующий элемент

					cout << "\nЕсли у нас позиция равна 1, то головой становится следующий за ним элемент\n\n"
						<< "Head = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;\n"
						<< "Head = " << Head << "\n\n";
				}
				else
				{
					for (int i = 1; i != pos; i++)
					{
						if (i == 1)
						{
							cout << "\nЕсли позиция не равна 1, то заходим в цикл перебора\n\n";
							Paint(L"tempTail", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << L"; - \"Хвостику\" присваиваем элемент первого указателя\n";
							Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << L"Next; - После чего первому указателю даём следующий элемент, пока не дойдём до позиции\n";
							Paint(L"tempTail", 8); wcout << " = " << tempTail << endl;
							Paint(L"tempHead", 8); wcout << " = " << tempHead << "\n\n";
						}

						Paint(L"i", 8); wcout << " = " << i << "   ";
						Paint(L"tempTail", 8); wcout << " = " << tempTail;
						Paint(L"  tempHead", 8); wcout << " = " << tempHead << endl;

						tempTail = tempHead;			//"хвостик" остаётся "хвостиком"
						tempHead = tempHead->Next;		//А тут ищем адрес нужного элемента

					}

					Paint(L"i", 8); wcout << " = " << pos << "   ";
					Paint(L"tempTail", 8); wcout << " = " << tempTail;
					Paint(L"  tempHead", 8); wcout << " = " << tempHead;
					cout << " - Нашли\n\n";
				}
				system("pause");

				tempTail->Next = tempHead->Next;	//Присваиваем указателю "хвостика" следующий за удаляемым элементом адрес, чтобы цепочка списка не распалась
				Paint(L"\ntempTail", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << L"Next; - После узнавания адреса присваиваем указателю \"хвостика\" адрес на элемент, стоящий после удаляемого\n";
				Paint(L"tempTail", 8); Paint(L"->", 3); wcout << "Next = " << tempTail->Next;

				delete tempHead;					//После чего свободно удаляем наш элемент
				size--;								//Не забываем уменьшить размер
				Paint(L"\n\ndelete", 1); Paint(L" tempHead", 8); wcout << L"; - И удаляем элемент на позиции\n"
					<< L"size--; - Уменьшаем размер\n";
				Paint(L"tempHead", 8); wcout << " = " << tempHead << L" - Как видим, он не совсем пустой, но он всё-таки удалён из списка";
				wcout << "\nsize = " << size;

				cout << "\n\nЭлемент найден и удалён\n\n";
			}
			break;

		case 2: //Удаление элемента по числу
			cout << "\n\nВведите число\n"
				<< "Ввод: ";
			CheckEnter(a);

			cout << "\nЗаходим в цикл:\n\n";

			for (int i = 1; i != size + 1; i++)
			{
				if (tempHead->x == a)
				{
					Node* del = new Node;				//Создаём элемент, который можно будет удалить без осложнений

					if (i <= 2)
					{
						Paint(L"i", 8); wcout << " = " << i << "   ";
						Paint(L"tempTail", 8); wcout << " = " << tempTail;
						Paint(L"  tempHead", 8); wcout << " = " << tempHead << L" - Данные совпали с числом\n\n";
						system("pause");
					}

					sum++;								//Создаём счётчик удалённых элементов
					tempTail->Next = tempHead->Next;	//Присваиваем указателю "хвостика" следующий за удаляемым элементом адрес, чтобы цепочка списка не распалась
					del = tempHead;						//Удаляемый элемент переносим на только что созданный

					if (i <= 2)
					{
						Paint(L"\nNode", 4); Paint(L"*", 3); Paint(L" del", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << L"; - Создаём 3-й элемент, чтобы произвести удаление без проблем\n";
						Paint(L"sum", 8); wcout << L"++; - Учитываем, что мы нашли элемент\n";
						Paint(L"tempTail", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << L"Next; - Заранее указателю \"хвостика\" присваиваем адрес элемента за удаляемым\n";
						Paint(L"del", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << L"; - Переносим удаляемый элемент на только что созданный\n\n";
						Paint(L"sum", 8); wcout << " = " << sum << endl;
						Paint(L"tempTail", 8); Paint(L"->", 3); wcout << "Next = " << tempTail->Next << endl;
						Paint(L"del", 8); wcout << " = " << del << "\n\n";
						system("pause");
					}

					if (size == sum) //Если мы удаляем голову и она одна в списке
					{
						delete del;			//Удаляем
						Head = Tail = NULL; //Обнуляем

						cout << "\nВ списке 1 элемент, значит это голова и хвост\n";
						Paint(L"delete", 1); Paint(L" del", 8); wcout << L"; - Удаляем его\n";
						wcout << "Head = Tail = "; Paint(L"NULL", 8); wcout << L"; - И для корректности обнуляем голову и хвост\n";

						cout << "\nЭлемент найден и удалён\n\n";
					}
					else
					{
						if (Head == tempHead)
						{
							Head = tempHead->Next;			 //Если удаляется голова, то головой становится следующий элемент

							if (i <= 2)
							{
								cout << "\nЕсли удаляемый элемент первый, то есть голова, то делаем головой следующий элемент\n";
								wcout << "Head = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;\n"
									<< "Head = " << Head << endl;
							}
						}

						tempTail = tempHead;				 //"хвостик" остаётся "хвостиком"
						tempHead = tempHead->Next;			 //Переходим к следующему элементу

						delete del;							 //И только потом удаляем

						if (i <= 2)
						{
							cout << "\nПереставляем указатели:\n";
							Paint(L"tempTail", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << ";\n";
							Paint(L"tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;\n";
							Paint(L"tempTail", 8); wcout << " = " << tempTail;
							Paint(L"  tempHead", 8); wcout << " = " << tempHead << endl;

							Paint(L"\ndelete", 1); Paint(L" del", 8); wcout << L"; - И удаляем элемент\n";
							Paint(L"del", 8); wcout << " = " << del << endl;
						}

						cout << "\nЭлемент найден и удалён\n\n";
					}

				}
				else //Если не нашёл
				{

					tempTail = tempHead;			 //"хвостик" остаётся "хвостиком"
					tempHead = tempHead->Next;		 //Переходим к следующему элементу

					if (rep <= 2)
					{
						rep++;
						Paint(L"i", 8); wcout << " = " << i << "   ";
						Paint(L"tempTail", 8); wcout << " = " << tempTail;
						Paint(L"  tempHead", 8); wcout << " = " << tempHead << L" - Данные не совпали с числом, идём дальше\n";
					}
				}
			}
			cout << "И так далее, после чего выходим из цикла";

			if (sum == 0)
			{
				cout << "\n\nОднако ни одного элемента списка не нашли, значит";
				cout << "\nЭлемент отсутствует\n\n"; //Если не найдено ни одного элемента
			}
			else
			{
				size -= sum;							 //Получаем итоговый размер
				wcout << L"\n\nsize -="; Paint(L" sum", 8); wcout << L"; - Уменьшаем размер и выходим\n"
					<< "size = " << size << "\n\n";
			}
			break;
		}
	}
	else
	{
		cout << "\n\nСписок пуст";
		cout << "\nЖелаете быстро заполнить список элементами?\n"
			<< "1 - Да\n"
			<< "2 - Нет (с обучением)\n"
			<< "3 - Точно нет (закончить)\n"
			<< "Ввод: ";

		CheckEnter(ch, 3);
		switch (ch)
		{
		case 1: Add(1, 0, 0, 1); //Рекурсия с добавлением условия для возвращения
			DelEl();
			break;
		case 2: Add(1, 0, 0, 0); //Рекурсия с добавлением условия для возвращения
			DelEl();
			break;
		case 3: cout << endl;
			break;
		}
	}
}

void Introduction()
{
	cout << "    О программе:\n\n"
		<< "Данная программа предназначена для ознакомления с односвязными циклическими списками и обучения их основным операциям на языке C++, "
		<< "\nчтобы любой желающий мог за короткое время научиться обращаться с ними, не тратя физических и моральных сил на поиск "
		<< "разрозненной\nи иногда неточной информации о создании и реализации списков в коде. Программа показывает работу со списком типа"; Paint(L" int ", 1);
	wcout << L"\nи не претендует на исключительность используемого для примеров кода и на его идеальную составляющую.\n\n";

	cout << "\n1 - Обратно в меню\n"
		<< "Ввод: ";
}

void AboutList()
{
	cout << "    Тема: Об односвязном циклическом списке\n\n"
		<< "По некоторым причинам, для начинающих вопросы по односвязным циклическим спискам возникают достаточно часто\n"
		<< "и заставляют тратить время на осознание этого чуда программерской природы. Смысл в том, что у таких списков нет начала и нет конца.\n"
		<< "То есть конец списка (хвост) ссылается на начало (голову) и таким образом образуется замкнутый круг.\n\n";
}

void StructureOfList()
{
	cout << "    Тема: Создание структуры списка\n\n"
		<< "Прежде чем начать работу со списком, нужно создать структуру (любое имя), которая будет хранить в себе элемент списка.\n"
		<< "Она обязтельно должна содержать в параметрах данные и указатель:\n\n";
	Paint(L"struct ", 1); Paint(L"Node\n", 4);
	wcout << "{\n";
	Paint(L"	int", 1); wcout << " x;          "; Paint(L"//Поле данных\n", 5);
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Next;     "; Paint(L"//Указатель (*) на следующий элемент\n", 5);
	wcout << "}\n\n";

}

void ClassOfList()
{
	cout << "    Тема: Создание класса списка\n\n"
		<< "Чтобы со списками можно было работать в дальнейшем, создаём новый класс (любое имя) c объявлением списка и числа элементов в нём.\n"
		<< "И после проинициализируем начальные элементы списка в public с помощью конструктора:\n\n";
	Paint(L"class ", 1); Paint(L"List\n", 4);
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Head, "; Paint(L"*", 3); wcout << " Tail;"; Paint(L"   //Объявляем первый элемент (голову) и тот, что последний (хвост)\n", 5);
	Paint(L"	int ", 1); wcout << "size"; Paint(L"              //Число элементов в списке\n", 5);
	Paint(L"public:\n", 1);
	Paint(L"	List", 2); wcout << "() : Head("; Paint(L"NULL", 8); wcout << "), Tail("; Paint(L"NULL", 8); wcout << "), size(0) {};"; Paint(L" //Инициализация элементов в ноль с помощью конструктора\n", 5);
	wcout << "}\n\n";
}

void AddElementToEnd(List& lst)
{
	cout << "    Тема: Добавление элементов в конец списка\n\n"
		<< "Чтобы список был списком, логично, что нужно его заполнить, в данном случае не важно чем, в какое место, а важно просто как это\n"
		<< "сделать кодом, поэтому для начала добавим в "; Paint(L"public", 1); wcout << L" ничего не возвращающую функцию добавления элементов в список:\n\n";
	Paint(L"class ", 1); Paint(L"List\n", 4);
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Head, "; Paint(L"*", 3); wcout << " Tail;"; Paint(L"   //Объявляем первый элемент (голову) и тот, что последний (хвост)\n", 5);
	Paint(L"	int ", 1); wcout << "size"; wcout << ";"; Paint(L"             //Число элементов в списке\n", 5);
	Paint(L"public:\n", 1);
	Paint(L"	List", 2); wcout << "() : Head("; Paint(L"NULL", 8); wcout << "), Tail("; Paint(L"NULL", 8); wcout << "), size(0) {};"; Paint(L"	//Инициализация элементов в ноль с помощью конструктора\n", 5);
	wcout << "	+ "; Paint(L"void", 1); Paint(L" Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");"; Paint(L"	//Функция добавления элементов в список\n", 5);
	wcout << "}\n"
		<< L"\nГде "; Paint(L"n", 3); wcout << L" - выбор способа заполнения (пока у нас оно одно);";
	Paint(L"\ncount", 3); wcout << L" - счётчик ошибок при вводе (необязательно);";
	Paint(L"\nBeforeChoice", 3); wcout << L" - будущее условие для работы второго заполнения (можно и без этого)\n\n";
	system("Pause");

	cout << "\nТеперь распишем саму функцию:\n"
		<< "\nПримечание перед функцией: \""; Paint(L"->", 3); cout << "\" - доступ к элементу по указателю, то есть доступ к тому, на что указывает\n";
	Paint(L"\nvoid ", 1); Paint(L"List", 4); wcout << "::"; Paint(L"Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");\n";
	wcout << "{\n";
	Paint(L"	switch", 7); wcout << " ("; Paint(L"n", 3); wcout << ")\n"
		<< "	{\n";
	Paint(L"	case", 7); wcout << " 1: "; Paint(L"//Вставка элемента в конец списка\n", 5);
	wcout << "		cin."; Paint(L"clear", 2); wcout << "();"; Paint(L" //Очищаем ввод от ошибок, которые могут остаться, если снова обратимся к функции\n", 5);
	Paint(L"		int ", 1); Paint(L"x", 8); wcout << ";\n"
		<< "		cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Введите любые числа(x) любое количество раз (Чтобы закончить ввод нажмите Enter)", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";\n";
	Paint(L"		do\n", 7);
	wcout << "		{\n";
	Paint(L"			if", 7); wcout << " (!(cin >> "; Paint(L"x", 8); wcout << "))"; Paint(L" //Если ввод числа закончен ошибкой, например, вводом буквы...\n", 5);
	wcout << "			{\n";
	Paint(L"				if", 7); wcout << " ("; Paint(L"count", 3); wcout << " < 1)"; Paint(L" //Делаем счётчик, так как без него в данном коде сообщение выводится 2 раза\n", 5);
	wcout << "				{\n";
	wcout << "					cout << "; Paint(L"\"Некорректное значение", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << "; "; Paint(L"//...то выводим сообщение об ошибке\n", 5);
	wcout << "				}\n";
	Paint(L"				count ", 3); wcout << "= 1;\n";
	wcout << "			}\n";
	Paint(L"			else", 7); Paint(L" //А если ввод без ошибок\n", 5);
	wcout << "			{\n"
		<< "				size"; Paint(L"++", 3); wcout << ";"; Paint(L"				//При каждом добавлении элемента увеличиваем число элементов в списке\n", 5);
	Paint(L"				Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; Paint(L"		//Выделяем память для нового элемента списка\n", 5);
	Paint(L"				temp", 8); Paint(L"->", 3); wcout << "Next = Head;"; Paint(L"		//Замыкаем список. Последний элемент – это 'начало' списка\n", 5);
	Paint(L"				temp", 8); Paint(L"->", 3); wcout << "x = "; Paint(L"x", 8); wcout << ";"; Paint(L"			//Записываем в выделенную ячейку памяти значение x\n", 5);
	Paint(L"\n				if", 7); wcout << " (Head != "; Paint(L"NULL", 8); wcout << ")"; Paint(L"		//В том случае если список не пустой\n", 5);
	wcout << "				{\n";
	wcout << "					Tail"; Paint(L"->", 3); wcout << "Next = "; Paint(L"temp", 8); wcout << ";"; Paint(L"	//Обновляем указатель хвоста на наш новый элемент\n", 5);
	wcout << "					Tail = "; Paint(L"temp", 8); wcout << ";"; Paint(L"		//Теперь хвостом стал новый элемент\n", 5);
	wcout << "				}\n";
	Paint(L"				else", 7); wcout << " Head = Tail = "; Paint(L"temp", 8); wcout << ";"; Paint(L"	//А если список пуст, то создается первый элемент\n", 5);
	wcout << "			}\n"
		<< "		} "; Paint(L"while", 7); wcout << " ("; Paint(L"getchar", 2); wcout << "() != '"; Paint(L"\\n", 2); wcout << "');"; Paint(L" //Пока в вводе не нажмут Enter\n", 5);
	Paint(L"\n		if", 7); wcout << " ("; Paint(L"count", 3); wcout << " != 0)"; Paint(L" //Если ввод был с ошибкой\n", 5);
	wcout << "		{\n";
	Paint(L"			count", 3); wcout << " = 0;"; Paint(L"			//Обнуляем счётчик для...\n", 5);
	Paint(L"			Add", 2); wcout << "("; Paint(L"n", 3); wcout << ","; Paint(L" count", 3); wcout << ","; Paint(L" BeforeChoice", 3); wcout << ");"; Paint(L"	//...рекурсии\n", 5);
	wcout << "		}\n";
	Paint(L"		break", 7); wcout << ";\n";
	Paint(L"	case", 7); wcout << " 2: ... break; "; Paint(L" //Вставка элемента в любую позицию между головой и хвостом, пока не дошли\n", 5);
	wcout << "}\n\n";
	system("Pause");

	cout << "\nТеперь давайте посмотрим на практике:\n\n";
	system("Pause");
	cout << "\nСоздадим переменную типа, который мы создали:\n\n";
	Paint(L"List", 4); Paint(L" lst", 8); wcout << ";\n\n";
	system("Pause");
	cout << "\nИ вызовем функции добавления элементов:\n\n";
	Paint(L"List", 4); Paint(L" lst", 8); wcout << ";\n";
	Paint(L"lst", 8); wcout << "."; Paint(L"Add", 2); wcout << "(1, 0, 0);"; Paint(L" //Где 1 - рассматриваемый способ\n", 5);
	lst.Add(1, 0, 0, 0);
}

void AddElementBetweenNum(List& lst)
{
	cout << "    Тема: Добавление элементов между другими элементами списка\n\n"
		<< "Иногда нужно в готовый список добавить элемент на какое-нибудь конкретное место, для этого нужно знать размер списка и произвести пару фокусов.\n"
		<< "Так как эта функция связана с добавлением элемента, то она будет в "; Paint(L"Add", 2); wcout << "(...)\n";
	Paint(L"\nvoid ", 1); Paint(L"List", 4); wcout << "::"; Paint(L"Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");\n";
	wcout << "{\n";
	Paint(L"	switch", 7); wcout << " ("; Paint(L"n", 3); wcout << ")\n"
		<< "	{\n";
	Paint(L"	case", 7); wcout << " 1: ..."; Paint(L" break;", 7); Paint(L" //Вставка элемента в конец списка\n\n", 5);
	Paint(L"	case", 7); wcout << " 2:"; Paint(L" //Вставка элемента в любую позицию между головой и хвостом\n", 5);
	Paint(L"		if", 7); wcout << " (size > 1)\n"
		<< "		{\n";
	Paint(L"			int", 1); Paint(L" pos", 8); Paint(L"	//Позиция\n", 5);
	Paint(L"			int", 1); Paint(L" a", 8); Paint(L"	//Вводимое пользователем число\n", 5);
	wcout << "			cout << "; Paint(L"\"size = \"", 6); wcout << " << size << "; Paint(L"endl", 2); wcout << ";\n";
	wcout << "			cout << "; Paint(L"\"Введите позицию", 6); wcout << ":"; Paint(L"\"", 6); wcout << ";\n";
	Paint(L"			if", 7); wcout << " (cin >> "; Paint(L"pos", 8); wcout << ")\n";
	wcout << "			{\n";
	Paint(L"				if", 7); wcout << " ("; Paint(L"pos", 8); wcout << " <= size "; Paint(L"&&", 3); Paint(L" pos", 8); wcout << " > 1)"; Paint(L" //Если позиция не больше размера списка, положительное число и не указывает на голову\n", 5);
	wcout << "				{\n";
	wcout << "					cout << "; Paint(L"\"Введите a: \"", 6); wcout << ";\n";
	wcout << "					cin >> "; Paint(L"a", 8); wcout << ";\n";
	Paint(L"					Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; Paint(L"	//Выделяем память для нового элемента списка\n", 5);
	Paint(L"					temp", 8); Paint(L"->", 3); wcout << "x = "; Paint(L"a", 8); wcout << ";"; Paint(L"		//Записываем в выделенную ячейку памяти значение а\n", 5);
	Paint(L"					Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";\n";
	Paint(L"					tempHead", 8); wcout << " = Head;"; Paint(L"	//Создаём копию головы\n", 5);
	Paint(L"					if", 7); wcout << " (Head != "; Paint(L"NULL", 8); wcout << ")"; Paint(L" //Если список не пустой\n", 5);
	wcout << "					{\n";
	Paint(L"						if", 7); wcout << " ("; Paint(L"pos", 8); wcout << " == size)"; Paint(L" //Или если позиция равна размеру\n", 5);
	wcout << "						{\n";
	Paint(L"							temp", 8); Paint(L"->", 3); wcout << "Next = Tail;"; Paint(L" //Присваиваем адрес хвоста\n", 5);
	Paint(L"							for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " != "; Paint(L"pos", 8); wcout << " - 1;"; Paint(L" i", 8); Paint(L"++", 3); wcout << ")\n";
	wcout << "							{\n";
	Paint(L"								tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L" //И ищем нужный адрес, который ссылался на хвост, т.е. предыдущий\n", 5);
	wcout << "							}\n";
	Paint(L"							tempHead", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"temp", 8); wcout << ";"; Paint(L" //Присваиваем этому адресу адрес нового элемента\n", 5);
	wcout << "						}\n";
	Paint(L"						else", 7); Paint(L" //Или если любая другая позиция\n", 5);
	wcout << "						{\n";
	Paint(L"							for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " != "; Paint(L"pos", 8); wcout << ";"; Paint(L" i", 8); Paint(L"++", 3); wcout << ")\n";
	wcout << "							{\n";
	Paint(L"								tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"	//Ищем адрес элемента, чьё место мы займём, сдвинув вправо\n", 5);
	Paint(L"								if", 7); wcout << " ("; Paint(L"i", 8); wcout << " == "; Paint(L"pos", 8); wcout << " - 1)"; Paint(L"				//На последнем цикле \"фора\"\n", 5);
	wcout << "								{\n";
	Paint(L"									temp", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"tempHead", 8); wcout << ";"; Paint(L"			//Присваиваем найденный адрес новому элементу\n", 5);
	Paint(L"									tempHead", 8); wcout << " = Head;"; Paint(L"			//Сбрасываем значение, чтобы найти предыдущий адрес\n", 5);
	Paint(L"									for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " != "; Paint(L"pos", 8); wcout << " - 1;"; Paint(L" i", 8); Paint(L"++", 3); wcout << ")\n";
	wcout << "									{\n";
	Paint(L"										tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"	//И ищем нужный адрес перед позицией\n", 5);
	wcout << "									}\n";
	Paint(L"									tempHead", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"temp", 8); wcout << ";"; Paint(L"	//Присваиваем ему адрес нового элемента\n", 5);
	wcout << "								}\n"
		<< "							}\n"
		<< "						}\n"
		<< "					}\n";
	wcout << "					size"; Paint(L"++", 3); wcout << ";\n\n";
	Paint(L"					//Вывод полученного списка\n", 5);
	Paint(L"					//Почти повторяет код функции Show()\n", 5);
	wcout << "					cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Полученный список = (\"", 6); wcout << ";\n";
	Paint(L"					//Цикл из функции\n", 5);
	wcout << "					cout << "; Paint(L"\")", 6); Paint(L"\\n", 2); Paint(L"size = \"", 6); wcout << " << size << "; Paint(L"endl", 2); wcout << ";\n"
		<< "				}\n";
	Paint(L"				else", 7); Paint(L" //Если позиция больше размера списка, отрицательное число или указывает на голову\n", 5);
	wcout << "				{\n";
	wcout << "					cout << "; Paint(L"\"Неправильная позиция", 6); Paint(L"\\n", 2); wcout << ";\n";
	Paint(L"					Add", 2); wcout << "(2, 0, 0);"; Paint(L" //Рекурсия без изменений\n", 5);
	wcout << "				}\n"
		<< "			}\n"
		<< "		}\n";
	Paint(L"		else", 7); wcout << "{...}"; Paint(L"	//Если размер списка равен нулю, то спрашиваем желание добавить элементы через конец,\n", 5);
	Paint(L"		break", 7); wcout << ";"; Paint(L"		//после которого заново проходим case 2 (BeforeChoice = 1), однако этот сегмент нам не важен\n", 5);
	Paint(L"	default", 7); wcout << ": cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Действие отсутствует\"", 6); wcout << " << "; Paint(L"endl", 2); wcout << " << "; Paint(L"\"Введите повторно: \"", 6); wcout << "; cin >> "; Paint(L"n", 3); wcout << ";"; Paint(L" Add", 2); wcout << "("; Paint(L"n", 3); wcout << ", 0, 0);\n";
	Paint(L"		break", 7); wcout << ";\n"
		<< "	}\n"
		<< "}\n";
	cout << "\nВыглядит громоздко, однако сама работа добавления заключена в "; Paint(L"if", 7); wcout << " (Head != "; Paint(L"NULL", 8); wcout << ") {...}\n";
	cout << "И выглядит довольно непонятно, особенно на моменте, когда позиция не равна размеру списка.\n"
		<< "Но если отвлечься от абстракции и рассмотреть конкретный пример, то всё становится понятно, как и во многих других вещах в жизни.\n\n";
	system("pause");

	cout << "\nДавай теперь приступим к ознакомлению этого метода:\n\n";
	Paint(L"List", 4); Paint(L" lst", 8); wcout << ";\n";
	Paint(L"lst", 8); wcout << "."; Paint(L"Add", 2); wcout << "(2, 0, 0);"; Paint(L" //Где 2 - рассматриваемый способ\n", 5);
	lst.Add(2, 0, 0, 0);

	cout << "\nВот и всё добавление\n\n";
}

void OutputList(List& lst)
{
	cout << "    Тема: Вывод элементов списка\n\n"
		<< "Список есть, он заполнен, и теперь важно узнать, что в нём есть, а чего нет.\n"
		<< "Перед этим добавим в "; Paint(L"public", 1); wcout << L" эту функцию вывода списка и, внимание, функцию, возвращающую размер списка:\n\n";
	Paint(L"class ", 1); Paint(L"List\n", 4);
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Head, "; Paint(L"*", 3); wcout << " Tail;"; Paint(L"   //Объявляем первый элемент (голову) и тот, что последний (хвост)\n", 5);
	Paint(L"	int ", 1); wcout << "size"; wcout << ";"; Paint(L"             //Число элементов в списке\n", 5);
	Paint(L"public:\n", 1);
	Paint(L"	List", 2); wcout << "() : Head("; Paint(L"NULL", 8); wcout << "), Tail("; Paint(L"NULL", 8); wcout << "), size(0) {};"; Paint(L"	//Инициализация элементов в ноль с помощью конструктора\n", 5);
	Paint(L"	void", 1); Paint(L" Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");"; Paint(L"	//Функция добавления элементов в список\n", 5);
	wcout << "	+ "; Paint(L"void", 1); Paint(L" Show", 2); wcout << "("; Paint(L"int", 1); Paint(L" size", 3); wcout << ");"; Paint(L"				//Функция отображения элементов списка\n", 5);
	wcout << "	+ "; Paint(L"int", 1); Paint(L" Count", 2); wcout << "();"; Paint(L"					//Функция, возвращающая число элементов в списке\n", 5);
	wcout << "}\n\n";
	cout << "Если вывод списка,"; Paint(L" Show", 2); wcout << "("; Paint(L"int", 1); Paint(L" size", 3); wcout << L"), понятен для чего нужен, то возвращение размера списка, "; Paint(L"Count", 2); wcout << L"(), не совсем.\n"
		<< L"Это всё потому, что сам по себе счетчик размера объявлен внутри класса и в защищенном поле "; Paint(L"private", 1); wcout << L"\n(Который стоит по умолчанию до "; Paint(L"public", 1); wcout << L"). "
		<< L"Доступ к этому счетчику разрешен только изнутри класса, а вне класса доступ закрыт.\n"
		<< L"Чтобы этот счетчик не был бесполезен, нужно создать новую функцию класса, "; Paint(L"int", 1); Paint(L" Count", 2); wcout << L"(), которая и будет возвращать этот счетчик:\n\n";
	Paint(L"int", 1); Paint(L" List", 4); wcout << "::"; Paint(L"Count", 2); wcout << "()\n"
		<< "{\n"
		<< "	"; Paint(L"return", 7); wcout << " size;"; Paint(L" //Возвращаем число элементов списка\n", 5);
	wcout << "}\n"
		<< L"\nВот так всё просто\n\n";
	system("Pause");

	cout << "\nТеперь давайте приступим к выводу самого списка\n\n";
	Paint(L"void", 1); Paint(L" List", 4); wcout << "::"; Paint(L"Show", 2); wcout << "("; Paint(L"int", 1); Paint(L" size", 3); wcout << ")\n";
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; Paint(L"	//Создаём...\n", 5);
	Paint(L"	tempHead", 8); wcout << " = Head;"; Paint(L"		//...копию головы\n", 5);
	Paint(L"	int", 1); Paint(L" temp", 8); wcout << " = "; Paint(L"size", 3); wcout << ";"; Paint(L"		//Создаём временную переменную и присваиваем её число элементов в списке (размер)\n", 5);
	wcout << L"	cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Итоговый список: ", 6); Paint(L"\"", 6); wcout << ";\n";
	Paint(L"	while", 7); wcout << " ("; Paint(L"temp", 8); wcout << " != 0)"; Paint(L"			//Пока не выполнен признак прохода по всему списку\n", 5);
	wcout << "	{\n"
		<< "		cout <<"; Paint(L" tempHead", 8); Paint(L"->", 3); wcout << "x << \" \";"; Paint(L"	//Выводим очередной элемента списка на экран\n", 5);
	Paint(L"		tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"	//И потом указываем, что нужен следующий элемент\n", 5);
	Paint(L"		temp", 8); Paint(L"--", 3); wcout << ";";  Paint(L"				//Один элемент считан, значит уменьшаем размер временной переменной на один\n", 5);
	wcout << "	}\n"
		<< "}\n\n";
	system("Pause");

	cout << "\nНу и давайте выведем список из элементов, которые вы вводили в 3-й и 4-й теме\n\n";
	Paint(L"lst", 8); wcout << "."; Paint(L"Show", 2); wcout << "("; Paint(L"lst", 8); wcout << "."; Paint(L"Count", 2); wcout << "());\n\n";
	lst.Show(lst.Count(), lst, 0);
}

void LookingForElement(List& lst)
{
	cout << "    Тема: Поиск элемента по условию\n\n"
		<< "Поиск элемента подразумевает поиск его по позиции в списке или по наличию в нём того, что вы ищете:\n"
		<< "- для поиска по позиции нужен 1 указатель, после чего задать цикл нахождения адреса, начав с головы;\n"
		<< "- для поиска по наличию нужно проверять поле данных и так же прогнать через цикл.\n\n"
		<< "Добавим в "; Paint(L"public", 1); wcout << L" ничего не возвращающую функцию поиска элемента в списке:\n\n";

	Paint(L"class ", 1); Paint(L"List\n", 4);
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Head, "; Paint(L"*", 3); wcout << " Tail;"; Paint(L"   //Объявляем первый элемент (голову) и тот, что последний (хвост)\n", 5);
	Paint(L"	int ", 1); wcout << "size"; wcout << ";"; Paint(L"             //Число элементов в списке\n", 5);
	Paint(L"public:\n", 1);
	Paint(L"	List", 2); wcout << "() : Head("; Paint(L"NULL", 8); wcout << "), Tail("; Paint(L"NULL", 8); wcout << "), size(0) {};"; Paint(L"	//Инициализация элементов в ноль с помощью конструктора\n", 5);
	Paint(L"	void", 1); Paint(L" Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");"; Paint(L"	//Функция добавления элементов в список\n", 5);
	Paint(L"	void", 1); Paint(L" Show", 2); wcout << "("; Paint(L"int", 1); Paint(L" size", 3); wcout << ");"; Paint(L"				//Функция отображения элементов списка\n", 5);
	Paint(L"	int", 1); Paint(L" Count", 2); wcout << "();"; Paint(L"					//Функция, возвращающая число элементов в списке\n", 5);
	wcout << "	+ "; Paint(L"void", 1); Paint(L" Find", 2); wcout << "();"; Paint(L"					//Функция поиска элемента\n", 5);
	wcout << "}\n\n";
	system("Pause");

	cout << "\nРассмотрим код:\n\n";
	Paint(L"void", 1); Paint(L" List", 4); wcout << "::"; Paint(L"Find", 2); wcout << "()\n";
	wcout << "{\n";
	Paint(L"	int", 1); Paint(L" choice", 8); wcout << ","; Paint(L" ch", 8); wcout << ","; Paint(L" have", 8); wcout << " = 0,"; Paint(L" pos", 8); wcout << ","; Paint(L" a", 8); wcout << ";\n";
	Paint(L"	if", 7); wcout << " (Head != "; Paint(L"NULL", 8); wcout << ")\n"
		<< "	{\n";
	Paint(L"		Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";\n";
	Paint(L"		tempHead", 8); wcout << " = Head;"; Paint(L" //Создаём копию головы для указателя для перебора списка\n\n", 5);
	wcout << "		cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Желаете найти элемент по расположению или по наличию какого-нибудь числа в нём?", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";\n";
	wcout << "			<< "; Paint(L"\"1 - По расположению", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "			<< "; Paint(L"\"2 - По наличию числа", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "			<< "; Paint(L"\"Ввод: \"", 6); wcout << ";\n"
		<< "		cin >>"; Paint(L" choice", 8); wcout << ";\n";
	Paint(L"		switch", 7); wcout << " ("; Paint(L"choice", 8); wcout << ")\n"
		<< "		{\n";
	Paint(L"		case", 7); wcout << " 1:"; Paint(L"	//Поиск элемента по расположению\n", 5);
	wcout << "			cout << "; Paint(L"\"", 6); Paint(L"\\n\\n", 2); Paint(L"Введите позицию элемента", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "				<< "; Paint(L"\"Ввод: \"", 6); wcout << ";\n"
		<< "			cin >>"; Paint(L" pos", 8); wcout << ";\n\n";
	Paint(L"			if", 7); wcout << " ("; Paint(L"pos", 8); wcout << " < 1 || "; Paint(L"pos", 8); wcout << " > size)\n"
		<< "			{\n"
		<< "				cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Элемент отсутствует", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";\n";
	Paint(L"				Find", 2); wcout << "();\n"
		<< "			}\n";
	Paint(L"			else\n", 7);
	wcout << "			{\n";
	Paint(L"				for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " !="; Paint(L" pos", 8); wcout << ";"; Paint(L" i", 8); wcout << "++)\n"
		<< "				{\n";
	Paint(L"					tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L" //Находим адресс элемента на позиции перебором\n", 5);
	wcout << "				}\n";
	wcout << "					cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Элемент найден", 6); Paint(L"\\n", 2); Paint(L"Адрес: \"", 6); wcout << " << "; Paint(L"tempHead\n", 8);
	wcout << "						<< "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Содержание: \"", 6); wcout << " << "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "x"; wcout << " << "; Paint(L"endl", 2); wcout << ";\n";
	wcout << "			}\n";
	Paint(L"			break", 7); wcout << ";\n\n";
	Paint(L"		case", 7); wcout << " 2:"; Paint(L"	//Поиск элемента по числу\n", 5);
	wcout << "			cout << "; Paint(L"\"", 6); Paint(L"\\n\\n", 2); Paint(L"Введите число", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "				<< "; Paint(L"\"Ввод: \"", 6); wcout << ";\n"
		<< "			cin >>"; Paint(L" a", 8); wcout << ";\n\n";
	Paint(L"			for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " != size;"; Paint(L" i", 8); wcout << "++)\n"
		<< "			{\n";
	Paint(L"				if", 7); wcout << " ("; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "x == "; Paint(L"a", 8); wcout << ")"; Paint(L"						//Если элемент имеет нужное значение...\n", 5);
	wcout << "				{\n";
	Paint(L"					have", 8); wcout << " = 1;\n";
	wcout << "					cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Элемент найден", 6); Paint(L"\\n", 2); Paint(L"Адрес: \"", 6); wcout << " << "; Paint(L"tempHead", 8); Paint(L"		//...выводим его\n", 5);
	wcout << "						<< "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Содержание: \"", 6); wcout << " << "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "x"; wcout << " << "; Paint(L"endl\n", 2);
	wcout << "				}\n";
	Paint(L"				tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"					//Находим адресс элемента перебором\n", 5);
	wcout << "			}\n";
	Paint(L"			if", 7); wcout << " ("; Paint(L"have", 8); wcout << " == 0)"; wcout << " cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Элемент отсутствует", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";"; Paint(L" //Если не найдено ни одного элемента\n", 5);
	Paint(L"			break", 7); wcout << ";\n"
		<< "		}\n"
		<< "	}\n"
		<< "}\n\n";

	cout << "Впринципе, ничего сложного, ведь вся логика заключается в простейшем переборе адресов через "; Paint(L"for", 7); wcout << ".\n\n";
	system("pause");

	cout << "\nДавайте теперь, по традиции, ознакомимся с кодом:\n\n";
	Paint(L"List", 4); Paint(L" lst", 8); wcout << ";\n";
	Paint(L"lst", 8); wcout << "."; Paint(L"Find", 2); wcout << "();\n";

	int ch = 1;
	do
	{
		lst.Find();

		system("pause");
		cout << "\nЖелаете повторить поиск?\n"
			<< "1 - Да\n"
			<< "2 - Нет\n"
			<< "Ввод: ";
		CheckEnter(ch, 2);
	} while (ch == 1);

	cout << "\nСогласны, что ничего сложного? Если нет, пройдите заново)\n\n";
}

void DeleteElement(List& lst)
{
	cout << "    Тема: Удаление элемента из списка\n\n"
		<< "Соответственно, если нас какой-то элемент не устраивает, то его можно удалить.\n"
		<< "Сделать это можно также по позиции или по наличию данных:\n"
		<< "- для удаления по позиции нужно 2 указателя, после чего задать цикл нахождения адреса, начав с головы, найти и удалить;\n"
		<< "- для поиска по наличию нужно тоже 2 указателя, проверять поле данных, так же прогнать через цикл и потом удалить найденный элемент.\n\n"
		<< "Добавим в "; Paint(L"public", 1); wcout << L" ничего не возвращающую функцию удаления элемента в списке:\n\n";

	Paint(L"class ", 1); Paint(L"List\n", 4);
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Head, "; Paint(L"*", 3); wcout << " Tail;"; Paint(L"   //Объявляем первый элемент (голову) и тот, что последний (хвост)\n", 5);
	Paint(L"	int ", 1); wcout << "size"; wcout << ";"; Paint(L"             //Число элементов в списке\n", 5);
	Paint(L"public:\n", 1);
	Paint(L"	List", 2); wcout << "() : Head("; Paint(L"NULL", 8); wcout << "), Tail("; Paint(L"NULL", 8); wcout << "), size(0) {};"; Paint(L"	//Инициализация элементов в ноль с помощью конструктора\n", 5);
	Paint(L"	void", 1); Paint(L" Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");"; Paint(L"	//Функция добавления элементов в список\n", 5);
	Paint(L"	void", 1); Paint(L" Show", 2); wcout << "("; Paint(L"int", 1); Paint(L" size", 3); wcout << ");"; Paint(L"				//Функция отображения элементов списка\n", 5);
	Paint(L"	int", 1); Paint(L" Count", 2); wcout << "();"; Paint(L"					//Функция, возвращающая число элементов в списке\n", 5);
	Paint(L"	void", 1); Paint(L" Find", 2); wcout << "();"; Paint(L"					//Функция поиска элемента\n", 5);
	wcout << "	+ "; Paint(L"void", 1); Paint(L" DelEl", 2); wcout << "();"; Paint(L"					//Функция удаления элемента\n", 5);
	wcout << "}\n\n";
	system("Pause");

	cout << "\nРассмотрим код:\n\n";
	Paint(L"void", 1); Paint(L" List", 4); wcout << "::"; Paint(L"DelEl", 2); wcout << "()\n";
	wcout << "{\n";
	Paint(L"	int", 1); Paint(L" choice", 8); wcout << ","; Paint(L" ch", 8); wcout << ","; Paint(L" sum", 8); wcout << " = 0,"; Paint(L" pos", 8); wcout << ","; Paint(L" a", 8); wcout << ";\n";
	Paint(L"	if", 7); wcout << " (Head != "; Paint(L"NULL", 8); wcout << ")\n"
		<< "	{\n";
	Paint(L"		Node", 4); Paint(L"*", 3); Paint(L" tempHead", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";\n";
	Paint(L"		tempHead", 8); wcout << " = Head;"; Paint(L" //Создаём копию головы для указателя для перебора списка\n", 5);
	Paint(L"		Node", 4); Paint(L"*", 3); Paint(L" tempTail", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";\n";
	Paint(L"		tempHead", 8); wcout << " = Tail;"; Paint(L" //Второй указатель, \"хвостик\"\n\n", 5);
	wcout << "		cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Желаете удалить элемент по расположению или по наличию какого-нибудь числа в нём?", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";\n";
	wcout << "			<< "; Paint(L"\"1 - По расположению", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "			<< "; Paint(L"\"2 - По наличию числа", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "			<< "; Paint(L"\"Ввод: \"", 6); wcout << ";\n"
		<< "		cin >>"; Paint(L" choice", 8); wcout << ";\n";

	Paint(L"		switch", 7); wcout << " ("; Paint(L"choice", 8); wcout << ")\n"
		<< "		{\n";
	Paint(L"		case", 7); wcout << " 1:"; Paint(L"	//Удаление элемента по расположению\n", 5);
	wcout << "			cout << "; Paint(L"\"", 6); Paint(L"\\n\\n", 2); Paint(L"Введите позицию элемента", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "				<< "; Paint(L"\"Ввод: \"", 6); wcout << ";\n"
		<< "			cin >>"; Paint(L" pos", 8); wcout << ";\n\n";
	Paint(L"			if", 7); wcout << " ("; Paint(L"pos", 8); wcout << " < 1 || "; Paint(L"pos", 8); wcout << " > size)\n"
		<< "			{\n"
		<< "				cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Элемент отсутствует", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";\n";
	Paint(L"				DelEl", 2); wcout << "();\n"
		<< "			}\n";
	Paint(L"			else\n", 7);
	wcout << "			{\n";
	Paint(L"				for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " !="; Paint(L" pos", 8); wcout << ";"; Paint(L" i", 8); wcout << "++)\n"
		<< "				{\n";
	Paint(L"					tempTail", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << ";"; Paint(L"		//\"хвостик\" остаётся \"хвостиком\"\n", 5);
	Paint(L"					tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"	//А тут ищем адрес нужного элемента\n", 5);
	wcout << "				}\n\n";
	Paint(L"				if", 7); wcout << " ("; Paint(L"pos", 8); wcout << " == 1)\n"
		<< "				{\n";
	wcout << "					Head = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"		//Если удаляется голова, то головой становится следующий элемент\n", 5);
	wcout << "				}\n\n";
	Paint(L"				tempTail", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"	//Присваиваем указателю \"хвостика\" следующий...\n", 5);
	Paint(L"									//...за удаляемым элементом адрес, чтобы цепочка списка не распалась\n", 5);
	Paint(L"				delete", 1); Paint(L" tempHead", 8); wcout << ";"; Paint(L"			//После чего свободно удаляем наш элемент\n", 5);
	wcout << "				size--;"; Paint(L"					//Не забываем уменьшить размер\n", 5);
	wcout << "				cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Элемент найден и удалён", 6); Paint(L"\\n\\n", 2); Paint(L"\"\n", 6);
	wcout << "			}\n";
	Paint(L"			break", 7); wcout << ";\n\n";

	Paint(L"		case", 7); wcout << " 2:"; Paint(L"	//Поиск элемента по числу\n", 5);
	wcout << "			cout << "; Paint(L"\"", 6); Paint(L"\\n\\n", 2); Paint(L"Введите число", 6); Paint(L"\\n", 2); Paint(L"\"\n", 6);
	wcout << "				<< "; Paint(L"\"Ввод: \"", 6); wcout << ";\n"
		<< "			cin >>"; Paint(L" a", 8); wcout << ";\n\n";
	Paint(L"			for", 7); wcout << " ("; Paint(L"int", 1); Paint(L" i", 8); wcout << " = 1;"; Paint(L" i", 8); wcout << " != size;"; Paint(L" i", 8); wcout << "++)\n"
		<< "			{\n";
	Paint(L"				if", 7); wcout << " ("; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "x == "; Paint(L"a", 8); wcout << ")"; Paint(L"				//Если элемент имеет нужное значение\n", 5);
	wcout << "				{\n";
	Paint(L"					Node", 4); Paint(L"*", 3); Paint(L" del", 8); wcout << " = "; Paint(L"new ", 1); Paint(L"Node", 4); wcout << ";"; Paint(L"			//Создаём элемент, который можно будет удалить без осложнений\n\n", 5);
	Paint(L"					sum", 8); wcout << "++;"; Paint(L"					//Создаём счётчик удалённых элементов\n", 5);
	Paint(L"					tempTail", 8); Paint(L"->", 3); wcout << "Next = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"	//Присваиваем указателю \"хвостика\" следующий...\n", 5);
	Paint(L"										//...за удаляемым элементом адрес, чтобы цепочка списка не распалась\n", 5);
	Paint(L"					del", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << ";"; Paint(L"				//Удаляемый элемент переносим на только что созданный\n\n", 5);
	Paint(L"					if", 7);  wcout << " (size == "; Paint(L"sum", 8); wcout << ")"; Paint(L"				//Если мы удаляем голову и она одна в списке\n", 5);
	wcout << "					{\n";
	Paint(L"						delete", 1); Paint(L" del", 8); wcout << ";"; Paint(L"				//Удаляем элемент\n", 5);
	wcout << "						Head = Tail = "; Paint(L"NULL", 8); wcout << ";"; Paint(L"			//Обнуляем голову и хвост\n", 5);
	wcout << "					}\n";
	Paint(L"					else\n", 7);
	wcout << "					{\n";
	Paint(L"						if", 7); wcout << " (Head == "; Paint(L"tempHead", 8); wcout << ")\n"
		<< "						{\n";
	wcout << "							Head = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"		//Если удаляется голова, то головой становится следующий элемент\n", 5);
	wcout << "						}\n\n";
	Paint(L"						tempTail", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << ";"; Paint(L"			//\"хвостик\" остаётся \"хвостиком\"\n", 5);
	Paint(L"						tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"		//Переходим к следующему элементу\n\n", 5);
	Paint(L"						delete", 1); Paint(L" del", 8); wcout << ";"; Paint(L"				//И только потом удаляем\n", 5);
	wcout << "						cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Элемент найден и удалён", 6); Paint(L"\\n\\n", 2); Paint(L"\"\n", 6);
	wcout << "					}\n";
	wcout << "				}\n";
	Paint(L"				else", 7); Paint(L"						//Если не нашёл\n", 5);
	wcout << "				{\n";
	Paint(L"					tempTail", 8); wcout << " = "; Paint(L"tempHead", 8); wcout << ";"; Paint(L"			//\"хвостик\" остаётся \"хвостиком\"\n", 5);
	Paint(L"					tempHead", 8); wcout << " = "; Paint(L"tempHead", 8); Paint(L"->", 3); wcout << "Next;"; Paint(L"		//Переходим к следующему элементу\n", 5);
	wcout << "				}\n";
	wcout << "			}\n";
	wcout << "			size -= "; Paint(L"sum", 8); wcout << ";"; Paint(L"	//Получаем итоговый размер\n", 5);
	Paint(L"			if", 7); wcout << " ("; Paint(L"sum", 8); wcout << " == 0)"; wcout << " cout << "; Paint(L"\"", 6); Paint(L"\\n", 2); Paint(L"Элемент отсутствует", 6); Paint(L"\\n", 2); Paint(L"\"", 6); wcout << ";"; Paint(L" //Если не найдено ни одного элемента\n", 5);
	Paint(L"			break", 7); wcout << ";\n"
		<< "		}\n"
		<< "	}\n"
		<< "}\n\n";

	cout << "Чисто шаблонно, это повтор функции поиска, добавляется лишь пара условий и действий.\n\n";
	system("pause");

	cout << "\nПриступим к знакомству:\n\n";
	Paint(L"List", 4); Paint(L" lst", 8); wcout << ";\n";
	Paint(L"lst", 8); wcout << "."; Paint(L"DelEl", 2); wcout << "();\n";

	int ch = 1;
	do
	{
		lst.DelEl();

		system("pause");
		cout << "\nЖелаете повторить удаление?\n"
			<< "1 - Да\n"
			<< "2 - Нет\n"
			<< "Ввод: ";
		CheckEnter(ch, 2);
	} while (ch == 1);

	cout << endl;

}

void DeleteList(List& lst)
{
	cout << "    Тема: Удаление списка\n\n"
		<< "При динамическом программировании, если была выделена память, то выделенную память надо освобождать,\n"
		<< "чтобы не допустить утечки памяти. Освобождение памяти удобно описать в деструкторе (~\"Название класса\").\n"
		<< "Деструктор очень похож на функцию отображения списка.";
	Paint(L"\n\nclass ", 1); Paint(L"List\n", 4);
	wcout << "{\n";
	Paint(L"	Node", 4); Paint(L"*", 3); wcout << " Head, "; Paint(L"*", 3); wcout << " Tail;"; Paint(L"   //Объявляем первый элемент (голову) и тот, что последний (хвост)\n", 5);
	Paint(L"	int ", 1); wcout << "size"; wcout << ";"; Paint(L"             //Число элементов в списке\n", 5);
	Paint(L"public:\n", 1);
	Paint(L"	List", 2); wcout << "() : Head("; Paint(L"NULL", 8); wcout << "), Tail("; Paint(L"NULL", 8); wcout << "), size(0) {};"; Paint(L"	//Инициализация элементов в ноль с помощью конструктора\n", 5);
	Paint(L"	void", 1); Paint(L" Add", 2); wcout << "("; Paint(L"int", 1); Paint(L" n", 3); wcout << ", "; Paint(L"int", 1); Paint(L" count", 3); wcout << ", "; Paint(L"int", 1); Paint(L" BeforeChoice", 3); wcout << ");"; Paint(L"	//Функция добавления элементов в список\n", 5);
	Paint(L"	void", 1); Paint(L" Show", 2); wcout << "("; Paint(L"int", 1); Paint(L" size", 3); wcout << ");"; Paint(L"				//Функция отображения элементов списка\n", 5);
	Paint(L"	int", 1); Paint(L" Count", 2); wcout << "();"; Paint(L"					//Функция, возвращающая число элементов в списке\n", 5);
	Paint(L"	void", 1); Paint(L" Find", 2); wcout << "();"; Paint(L"					//Функция поиска элемента\n", 5);
	Paint(L"	void", 1); Paint(L" DelEl", 2); wcout << "();"; Paint(L"					//Функция удаления элемента\n", 5);
	wcout << "	+ "; Paint(L"~List", 2); wcout << "();"; Paint(L"					//Деструктор для освобождения памяти\n", 5);
	wcout << "}\n\n";
	system("pause");

	cout << "\nВот как выглядит сам деструктор:\n\n";
	Paint(L"List", 4); wcout << "::"; Paint(L"~List", 2); wcout << "()\n"
		<< "{\n";
	Paint(L"	while", 7); wcout << " ("; Paint(L"size", 8); wcout << " != 0)"; Paint(L"		 //Пока размерность списка не станет нулевой\n", 5);
	wcout << "	{\n";
	Paint(L"		Node", 4); Paint(L"*", 3); Paint(L" temp", 8); wcout << " = Head"; Paint(L"->", 3); wcout << "Next;"; Paint(L" //Создаём временный элемент, который будет хранить ссылку на последующие элементы, пока...\n", 5);
	Paint(L"		delete", 1); wcout << " Head;"; Paint(L"		 //... мы освобождаем память от активного элемента\n", 5);
	wcout << "		Head = "; Paint(L"temp", 8); wcout << ";"; Paint(L"		 //Смена адреса начала на адрес последующего элемента\n", 5);
	wcout << "		size"; Paint(L"--", 3); wcout << ";"; Paint(L"			 //Один элемент освобожден. Корректируем число элементов\n", 5);
	wcout << "	}\n"
		<< "}\n\n";

	system("pause");

	cout << "\nДавайте посмотрим, как это работает\n";
	lst.~List();
}

void DeleteListBeforeTheme(List& lst)
{
	cout << "После добавления элементов вы не проходили тему очистки списка, поэтому я вам насильно покажу работу деструктура ;)\n";
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
		if (check >= 9) cout << "\n---------------------------------------------------------\nВы прошли все темы, теперь вам доступен тест и чит-код на\nполучение доступа к тесту на случай выхода из программы\nЧит-код - 1489\n---------------------------------------------------------\n";
		if (ch == 1)
		{
			wcout << L"\nВыберите действие:\n"
				<< L"1 - Повтор темы\n"
				<< L"2 - Следующая тема\n"
				<< L"3 - Обратно к темам\n"
				<< L"4 - Обратно в меню\n"
				<< L"5 - Показать список\n\n"
				<< L"6 - Выход из программы\n"
				<< L"\nВвод: ";

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
				wcout << L"\nВыберите действие:\n"
					<< L"1 - Повтор темы\n"
					<< L"2 - Следующая тема\n"
					<< L"3 - Обратно к темам\n"
					<< L"4 - Обратно в меню\n"
					<< L"5 - Выход из программы\n"
					<< L"\nВвод: ";

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
			cout << "\nВыберите действие:\n"
				<< "1 - Повтор темы\n"
				<< "2 - Предыдущая тема\n"
				<< "3 - Обратно к темам\n"
				<< "4 - Обратно в меню\n"
				<< "5 - Показать список\n\n"
				<< "6 - Выход из программы\n"
				<< "\nВвод: ";

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
				wcout << L"\nВыберите действие:\n"
					<< L"1 - Повтор темы\n"
					<< L"2 - Следующая тема\n"
					<< L"3 - Обратно к темам\n"
					<< L"4 - Обратно в меню\n\n"
					<< L"5 - Выход из программы\n"
					<< L"\nВвод: ";

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
			cout << "\nВыберите действие:\n"
				<< "1 - Повтор темы\n"
				<< "2 - Следующая тема\n"
				<< "3 - Предыдущая тема\n"
				<< "4 - Обратно к темам\n"
				<< "5 - Обратно в меню\n"
				<< "6 - Показать список\n\n"
				<< "7 - Выход из программы\n"
				<< "\nВвод: ";

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
				wcout << L"\nВыберите действие:\n"
					<< L"1 - Повтор темы\n"
					<< L"2 - Следующая тема\n"
					<< L"3 - Предыдущая тема\n"
					<< L"4 - Обратно к темам\n"
					<< L"5 - Обратно в меню\n\n"
					<< L"6 - Выход из программы\n"
					<< L"\nВвод: ";

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
	cout << "    Список тем:\n\n"
		<< "1 - Об односвязном циклическом списке (быстро)\n"
		<< "2 - Создание структуры списка (быстро)\n"
		<< "3 - Создание класса списка (быстро)\n"
		<< "4 - Добавление элементов в конец списка (долго)\n"
		<< "5 - Добавление элементов между другими элементами списка (долго)\n"
		<< "6 - Вывод элементов списка (средне)\n"
		<< "7 - Поиск элемента по условию (долго)\n"
		<< "8 - Удаление элемента из списка (долго)\n"
		<< "9 - Удаление списка (средне)\n"
		<< "\n10 - Обратно в меню\n"
		<< "11 - Выход из программы\n"
		<< "\nВвод: ";

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
		cout << "    Теcт\n\n";
		if (num == 1)
		{
			cout << " Номер 1\n";
			cout << "У списка может быть неограниченное число элементов, какие из них главные?\n\n"
				<< "1 - Первый\n"
				<< "2 - Голова и Хвост\n"
				<< "3 - У кого информации больше\n"
				<< "Ввод: ";

			CheckEnter(answer, 3);
			if (answer == 2)
			{
				wrong[0] = 0;
				score++;
				cout << "\nВерно\n\n";
			}
			else
			{
				have = 1;
				wrong[0] = 1;
				cout << "\nНеверно\n\n";
			}
		}
		else if (num == 2)
		{
			cout << " Номер 2\n";
			cout << "Из каких параметров состоит структура списка?\n\n"
				<< "1 - Из данных\n"
				<< "2 - Из встроенных параметров\n"
				<< "3 - Из данных и указателей\n"
				<< "Ввод: ";

			CheckEnter(answer, 3);
			if (answer == 3)
			{
				wrong[1] = 0;
				score++;
				cout << "\nВерно\n\n";
			}
			else
			{
				have = 1;
				wrong[1] = 1;
				cout << "\nНеверно\n\n";
			}
		}
		else if (num == 3)
		{
			cout << " Номер 3\n";
			cout << "Что нужно сделать с начальными элементами списка в классе, чтобы начать работу с ним?\n\n"
				<< "1 - Назвать\n"
				<< "2 - Объявить и проинициализировать в ноль\n"
				<< "3 - Присвоить к имеющимся\n"
				<< "Ввод: ";

			CheckEnter(answer, 3);
			if (answer == 2)
			{
				wrong[2] = 0;
				score++;
				cout << "\nВерно\n\n";
			}
			else
			{
				have = 1;
				wrong[2] = 1;
				cout << "\nНеверно\n\n";
			}
		}
		else if (num == 4)
		{
			cout << " Номер 4\n";
			cout << "При добавлении в список элемента в конец, что будет, если список пустой?\n\n"
				<< "1 - Новый элемент станет головой и хвостом\n"
				<< "2 - Элемент не добавится\n"
				<< "3 - Элемент добавится с ошибкой\n"
				<< "Ввод: ";

			CheckEnter(answer, 3);
			if (answer == 1)
			{
				wrong[3] = 0;
				score++;
				cout << "\nВерно\n\n";
			}
			else
			{
				have = 1;
				wrong[3] = 1;
				cout << "\nНеверно\n\n";
			}
		}
		else if (num == 5)
		{
			cout << " Номер 5\n";
			cout << "Что произойдёт, если при добавлении в список элемента между другими элементами указать первую позицию?\n\n"
				<< "1 - Первый элемент сдвинется вправо, а добавленный станет головой\n"
				<< "2 - Код будет ругаться\n"
				<< "3 - Добавленный элемент вставиться после головы\n"
				<< "Ввод: ";

			CheckEnter(answer, 3);
			if (answer == 2)
			{
				wrong[4] = 0;
				score++;
				cout << "\nВерно\n\n";
			}
			else
			{
				have = 1;
				wrong[4] = 1;
				cout << "\nНеверно\n\n";
			}
		}
		else if (num == 6)
		{
			cout << " Номер 6\n";
			cout << "Вывод списка сразу осуществим?\n\n"
				<< "1 - Нет, нужно написать функцию, возвращающую размер\n"
				<< "2 - Да\n"
				<< "3 - Нет, нужно обеспечить целостность данных\n"
				<< "Ввод: ";

			CheckEnter(answer, 3);
			if (answer == 1)
			{
				wrong[5] = 0;
				score++;
				cout << "\nВерно\n\n";
			}
			else
			{
				have = 1;
				wrong[5] = 1;
				cout << "\nНеверно\n\n";
			}
		}
		else if (num == 7)
		{
			cout << " Номер 7\n";
			cout << "Как происходит поиск элемента?\n\n"
				<< "1 - Вбивается запрос и сразу выдаётся элемент, как у матрицы\n"
				<< "2 - Вбивается запрос и выполняется перебор элементов, начиная с головы\n"
				<< "3 - Вбивается запрос и выполняется метод Лагранжа\n"
				<< "Ввод: ";

			CheckEnter(answer, 3);
			if (answer == 2)
			{
				wrong[6] = 0;
				score++;
				cout << "\nВерно\n\n";
			}
			else
			{
				have = 1;
				wrong[6] = 1;
				cout << "\nНеверно\n\n";
			}
		}
		else if (num == 8)
		{
			cout << " Номер 8\n";
			cout << "Сколько нужно указателей, чтобы выполнить удаление элемента по данным без ошибок?\n\n"
				<< "1 - 3\n"
				<< "2 - 1\n"
				<< "3 - 2\n"
				<< "Ввод: ";

			CheckEnter(answer, 3);
			if (answer == 1)
			{
				wrong[7] = 0;
				score++;
				cout << "\nВерно\n\n";
			}
			else
			{
				have = 1;
				wrong[7] = 1;
				cout << "\nНеверно\n\n";
			}
		}
		else if (num == 9)
		{
			cout << " Номер 9\n";
			cout << "Являются ли элементы списка динамическими объектами и что нужно делать с динамическими объектами после завершения работы с ними?\n\n"
				<< "1 - Нет, удалять их\n"
				<< "2 - Да, ничего не делать\n"
				<< "3 - Да, удалять их\n"
				<< "Ввод: ";

			CheckEnter(answer, 3);
			if (answer == 3)
			{
				wrong[8] = 0;
				score++;
				cout << "\nВерно\n\n";
			}
			else
			{
				have = 1;
				wrong[8] = 1;
				cout << "\nНеверно\n\n";
			}
		}
		else if (num == 10)
		{
			cout << "Ваш итоговый балл - " << score;
			cout << "\nВаша оценка - ";
			if (score >= 8) cout << "5\nВы усвоили в полной мере каждую тему и можете работать с\nодносвязными циклическими списками самостоятельно\n\n";
			else if (score < 8 && score >= 5) cout << "4\nВам понятны большинство аспектов односвязного циклического списка,\nно для полной уверенности пройдите соответствующие неправильным номерам темы\n\n";
			else if (score < 5 && score >= 3) cout << "3\nВы разбираетесь в односвязном циклическом списке лишь поверхностно,\nрекомендуется пройти соответствующие неправильным номерам темы\n\n";
			else if (score < 3) cout << "2\nВы не усвоили изученный материал, настоятельно рекомендуется пройти все темы заново\n\n";
			if (have == 1)
			{
				cout << "Ответы на вопросы/темы:\n";
				for (int i = 0; i <= 8; i++)
				{
					if (wrong[i] == 1)
					{
						cout << "Вопрос номер " << i + 1 << " - Неверно\n";
					}
					else cout << "Вопрос номер " << i + 1 << " - Верно\n";
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
		cout << "\n\nПройдите все темы, и тогда вы получите доступ к тесту\n\n";
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
		cout << "Учебно-ознакомительная программа \"Односвязный циклический список\"\n"
			<< "Выполнил студент группы ИНР-11 Самодуров В.А.\n\n"
			<< "\nВыберите действие: "
			<< "\n1 - О программе"
			<< "\n2 - Выбор темы"
			<< "\n3 - Тест"
			<< "\n\n4 - Выход из программы"
			<< "\n\nВвод: ";
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
	system("title Учебно-ознакомительная программа \"Односвязный циклический список\"");
	HWND hwnd;
	hwnd = GetConsoleWindow();
	MoveWindow(hwnd, 150, 0, 1350, 850, TRUE); //xnew, ynew, wnew, hnew - новые положение x, y, ширина и высота
	List lst; int check = 0;
	Menu(0, lst, check);
	if (lst.Count() != 0) lst.~List();
	return 0;
}