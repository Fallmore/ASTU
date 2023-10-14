#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include "binarytrees.h"

using namespace std;

int Check()
{
	int a;
	while (!(cin >> a))
		cout << "\nНеверный Ввод!\n\nВведите снова: ", cin.clear(), cin.ignore();
	return a;
}
void Check(int& choice, int NumberOfChoice)
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
	if (rep != 0) Check(choice, NumberOfChoice);
}

//								64
//				32								96
//		16				48				80				112
//	8		24		40		56		72		88		104		120
//4	  10  20  28  36  44  52  60  68  76 82	  92 100  108 116 124
//																														64
//													32													Ты хочешь что-нибудь сделать?											96
//					16					У тебя есть долги/домашка?						48																	80			Ты хочешь отдохнуть?						112
//			Делай долги/домашку						40						У тебя есть дела по дому?				56									Отдыхай			104						Ты хочешь что-то сделать, но без усилий?		120
//												Делай дела					52							У тебя хоть есть силы на дела?				60			Попроси помощи у Славы										116				Ты пиццу хочешь?				124
//									50					У тебя сейчас есть много свободного времени?			54						58	И долго это у тебя?		62												Иди закажи/поешь					122			А просто есть хочешь?					126
//					Помоги кому-нибудь или саморазвивайся											Посмотри полезное видео		Обратись за помощью				Отдохни																	Иди поешь что-нибудь и вернись				Тогда просто подкрепись, а затем возвращайся сюда

struct Desire
{
	int order, level;
	string text;
	Desire(int o = 0, int l = -1, string t = "") : order(o), level(l), text(t) {};
	bool operator<(Desire rd)
	{
		return (order < rd.order);
	}
	bool operator<(int rd)
	{
		return (order < rd);
	}
	bool operator>(Desire rd)
	{
		return (order > rd.order);
	}
	bool operator>(int rd)
	{
		return (order > rd);
	}
	bool operator==(int rd)
	{
		return (order == order);
	}
	bool operator==(Desire rd)
	{
		return (order == rd.order);
	}
};

ostream& operator<<(ostream& t, Desire& d)
{
	return (t << d.text);
}


void Will(BinaryTree<Desire>& desireTree)
{
	cout << "ДЕРЕВО РЕШЕНИЙ\n------------------------------------------------------\n";
	int rootOrd = 64, ord = 64, lvl = 0, ch = 0;
	Desire temp = Desire(ord, lvl, "");

	do
	{
		if (ch == 1)
			ord -= rootOrd / static_cast<int>(pow(2, lvl));
		else if (ch == 2) ord += rootOrd / static_cast<int>(pow(2, lvl));
		ch = 0;

		temp = Desire(ord, lvl, "");

		if (desireTree.CountLeefs(temp) != 1)
		{
			cout << "\n" << *(desireTree.retriveItem(temp))
				<< R"(
1. Да
2. Нет

Ввод: )";
			while (ch > 2 || ch < 1) ch = Check();

			++lvl;
		}
		else cout << "\n-----------------------------\n" << *(desireTree.retriveItem(temp)) << "\n-----------------------------";

	} while (desireTree.CountLeefs(temp) != 1);
}

void DesireTree()
{
	int ch = 0;
	BinaryTree<Desire> desireTree;
	Desire desires[21];
	desires[0] = Desire(64, 0, "Ты хочешь что-нибудь сделать?"),
		//Левая ветка от главного вопроса
		desires[1] = Desire(32, 1, "У тебя есть долги/домашка?"),
		desires[2] = Desire(16, 2, "Делай долги/домашку"),
		desires[3] = Desire(48, 2, "У тебя есть дела по дому?"),
		desires[4] = Desire(40, 3, "Делай дела"),
		desires[5] = Desire(56, 3, "У тебя хоть есть силы на дела?"),
		desires[6] = Desire(52, 4, "У тебя сейчас есть много свободного времени?"),
		desires[7] = Desire(60, 4, "И долго это у тебя?"),
		desires[8] = Desire(50, 5, "Помоги кому-нибудь или саморазвивайся"),
		desires[9] = Desire(54, 5, "Посмотри полезное видео"),
		desires[10] = Desire(58, 5, "Обратись за помощью"),
		desires[11] = Desire(62, 5, "Отдохни"),
		//Правая ветка от главного вопроса
		desires[12] = Desire(96, 1, "Ты хочешь отдохнуть?"),
		desires[13] = Desire(80, 2, "Отдыхай"),
		desires[14] = Desire(112, 2, "Ты хочешь что-то сделать, но без усилий?"),
		desires[15] = Desire(104, 3, "Попроси помощи у Славы"),
		desires[16] = Desire(120, 3, "Ты пиццу хочешь?"),
		desires[17] = Desire(116, 4, "Иди закажи/поешь"),
		desires[18] = Desire(124, 4, "А просто есть хочешь?"),
		desires[19] = Desire(122, 5, "Иди поешь что-нибудь и вернись"),
		desires[20] = Desire(126, 5, "Тогда просто подкрепись, а затем возвращайся сюда");

	for (auto& des : desires)
	{
		desireTree.insertItem(des);
	}

	/*do
	{
		ch = 0;
		Will(desireTree);

		cout << R"(


Повторить?

1. Да
2. Нет

Ввод: )"; while (ch < 1 || ch > 2) Check(ch, 2);
		if (ch == 1) system("cls");
	} while (ch != 2);

	cout << endl;*/
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-21/2\n\n\n";
	DesireTree();
	return 0;
}

//temp = tree, temproot = root;
//if (tree->left == nullptr && tree->right != nullptr)	// Один ребёнок
//{
//	temp = tree->right;
//	tree->info = temp->info, tree->left = temp->left;
//	temp->right == nullptr
//		? tree->right = nullptr
//		: tree->right = temp->right;
//	delete temp, --count;
//	if (count == 0) tree = nullptr;
//}
//else if (tree->right == nullptr && tree->left != nullptr) // Один ребёнок
//{
//	temp = tree->left;
//	tree->info = temp->info, tree->right = temp->right;
//	temp->left == nullptr
//		? tree->left = nullptr
//		: tree->left = temp->left;
//	delete temp, --count;
//	if (count == 0) tree = nullptr;
//
//}
//else if (tree->right == nullptr && tree->left == nullptr)
//{
//	temproot = GetSuccessor(temp, (*this).root);
//	if (temproot->right == temp) temproot->right = nullptr;
//	else temproot->left = nullptr;
//	delete temp, --count;
//	if (count == 0) tree = nullptr;
//}
//else // Ровно два дочерних узла
//{
//	Node<T>* pred = GetPredecessor(tree, temproot);	// Находит «предыдущий» элемент
//	int leefs = inorderCountLeefs(pred);
//	tree->info = pred->info;					// Записывает данные в «удаляемый» узел
//	if (leefs == 1)
//	{
//		if (temproot->right == pred) temproot->right = nullptr;
//		else temproot->left = nullptr;
//		delete pred, --count;
//		if (count == 0) tree = nullptr;
//	}
//	else deleteNode(pred, temproot);						//Удаляет «предыдущий» элемент
//}