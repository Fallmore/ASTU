#pragma once
#include <iostream>

using namespace std;

template<class T> struct Node
{

	T info;// Информационная часть.
	Node<T>* left, * right;// Указатели на дочерние узлы.
	// Конструктор по умолчанию.
	Node() { left = right = nullptr; }
	// Конструктор с параметрами.
	Node(const T& d, Node<T>* l = nullptr, Node<T>* r = nullptr) :
		info(d), left(l), right(r) {};
};

template<class T> class BinaryTree
{
protected:
	Node<T>* root;	// Указатель на корень дерева. 
	int count;	// Счётчик элементов

	Node<T>* searchLeef(Node<T>* tree, T& data) const;	// Ищет и возвращает лист с данными.
	T* searchInfoLeef(Node<T>* tree, T& data) const;	// Ищет и возвращает данные. (хз зачем так)
	Node<T>* retriveLeef(T& item) const			// Возвращает указатель на объект, если найден
	{
		return searchLeef(root, item);
	}

	void inorder(Node<T>* tree) const;		// Симметричный обход дерева 
	int inorderCountLeefs(Node<T>* tree) const; 	// Симметричный обход дерева с подсчётом его детей
	//void preorder(Node<T>* tree) const;		// Обход дерева в ширину
	//void postorder(Node<T>* tree) const;		// Обход дерева в глубину

	void clear(Node<T>*& root);					// Удаляет все узлы дерева и устанавливает указатель root в NULL. 
	void deleteLeefs(T& data);					// Поиск листа для удаления
	void deleteNode(Node<T>*& tree, Node<T>*& root);		// Удаляет лист
	Node<T>* GetPredecessor(Node<T>* tree, Node<T>*& root);		// Находит "предыдущий" по значению лист
	Node<T>* GetSuccessor(Node<T>* tree);				// Находит родителя элемента

	void insert(Node<T>*& tree, T& data); // Добавляет лист
public:
	BinaryTree() : root(nullptr), count(0) {}; // Конструктор по умолчанию.

	ostream& operator<<(T& d)
	{
		return (cout << d);
	}

	bool isEmpty() const // Отвечает на вопрос содержит дерево элементы или нет.
	{
		if (root == nullptr) return 1;
		return 0;
	}

	void print() const // Выводит данные из дерева.
	{
		inorderTree();
	}

	int nodeCount() const // Возвращает количество узлов в дереве.
	{
		return count;
	}

	void destroy() // Удаляет все узлы дерева. В результате дерево пусто и root == NULL;
	{
		clear(root);
	}

	void inorderTree() const // Симметричный обход дерева.
	{
		inorder(root);
	}
	int CountLeefs(T& item) const // Симметричный обход дерева с подсчётом его детей.
	{
		return inorderCountLeefs(retriveLeef(item));
	}

	//void preorderTree()const // Обход дерева в ширину.
	//{
	//	preorder(root);
	//}

	//void postorderTree()const // Обход дерева в глубину.
	//{
	//	postorder(root);
	//}

	T* retriveItem(T& item) const // Возвращает указатель на item, если найдено
	{
		return searchInfoLeef(root, item);
	}

	void deleteItem(T& item) // Удаляет узел с данными item из дерева.
	{
		deleteLeefs(root, item);
	}

	void insertItem(T& item) // Добавляет узел с данными item в дерево.
	{
		insert(root, item);
	}

	~BinaryTree() // Деструктор
	{
		destroy();
	}
};
template<class T> void BinaryTree<T>::inorder(Node<T>* tree) const
{
	if (tree != NULL)
	{
		inorder(tree->left); //Рекурсивный вызов
		cout << tree->info << " ";
		//Или добавление в очередь или стэк...
		inorder(tree->right); //Рекурсивный вызов
	}
}
template<class T> int BinaryTree<T>::inorderCountLeefs(Node<T>* tree) const
{
	int cnt = 0;
	if (tree != NULL)
	{
		++cnt;
		cnt += inorderCountLeefs(tree->left);	//Рекурсивный вызов
		cnt += inorderCountLeefs(tree->right);	//Рекурсивный вызов
		return cnt;
	}
	else return 0;
}

template<class T> void BinaryTree<T>::clear(Node<T>*& root)
{
	while (!isEmpty()) // Пока дерево не пусто
		deleteNode(root, root); // Удаляем элементы
}

template<class T> Node<T>* BinaryTree<T>::searchLeef(Node<T>* tree, T& data) const
{
	if (data < tree->info)				// Если данные «меньше», чем у текущего узла ...
		searchLeef(tree->left, data);	// Идём налево
	else if (data > tree->info)			// Если данные «больше», чем у текущего узла ...
		searchLeef(tree->right, data);	// Идём направо
	else if (data == tree->info) return tree; 	// Возвращаем указатель на объект
}
template<class T> T* BinaryTree<T>::searchInfoLeef(Node<T>* tree, T& data) const
{
	if (data < tree->info)				// Если данные «меньше», чем у текущеыго узла ...
		searchLeef(tree->left, data);	// Идём налево
	else if (data > tree->info)			// Если данные «больше», чем у текущего узла ...
		searchLeef(tree->right, data);	// Идём направо
	else if (data == tree->info) return new T(tree->info); // Возвращаем указатель на данные
	// Не спрашивайте меня, зачем возвращать ссылку (или что это), я сам не очень понимаю, скажите, если сами знаете
}

template<class T> void BinaryTree<T>::deleteLeefs(T& data)
{
	deleteNode(retriveLeef(data), root); // Удаляем объект, найденный по данным
}

template<class T> void BinaryTree<T>::deleteNode(Node<T>*& tree, Node<T>*& root)
{
	Node<T>* temp; Node<T>* temproot;

	// Это пиздец, я просто промолчу (потратил свыше 15 часов на эту хуйню)

	temp = tree, temproot = root;
	if (tree->left == nullptr && tree->right != nullptr)		// Один ребёнок
	{
		temp = tree->right;						// Спускаемся вправо
		tree->info = temp->info,								
			tree->left = temp->left, tree->right = temp->right;	// Копируем (отбираем) там данные и детей
		delete temp, --count;						// Удаляем, вычитаем
		if (count == 0) tree = nullptr;					// Если 0, обнуляем указатель
	}
	else if (tree->right == nullptr && tree->left != nullptr)	// Один ребёнок
	{
		temp = tree->left;						// Спускаемся влево
		tree->info = temp->info, 
			tree->right = temp->right, tree->left = temp->left;	// Копируем (отбираем) там данные и детей
		delete temp, --count;						// Удаляем, вычитаем
		if (count == 0) tree = nullptr;					// Если 0, обнуляем указатель

	}
	else if (tree->right == nullptr && tree->left == nullptr)	// Если бездетный
	{
		temproot = GetSuccessor(temp);				// Находим предка	
		if (temproot->right == temp) temproot->right = nullptr;	// Ну и обнуляем у предка 
		else temproot->left = nullptr;				// указатель на ребёнка
		delete temp, --count;					// Удаляем, вычитаем
		if (count == 0) tree = nullptr;				// Если 0, обнуляем указатель
	}
	else								// Ровно два дочерних узла
	{
		Node<T>* pred = GetPredecessor(tree, temproot);		// Находит «предыдущий» элемент
		int leefs = inorderCountLeefs(pred);				// Смотрим, сколько "листьев"
		tree->info = pred->info;				// Записывает данные в «удаляемый» узел
		if (leefs == 1)							// Если элемент бездетный, сразу удаляем, я так захотел, а то ебал я в рот >:(	
		{
			if (temproot->right == pred) temproot->right = nullptr;	// Ну и обнуляем у предка..
			else temproot->left = nullptr;				// ..указатель на ребёнка
			delete pred, --count;					// Удаляем, вычитаем
			if (count == 0) tree = nullptr;				// Если 0, обнуляем указатель
		}
		else deleteNode(pred, temproot);			//Удаляет «предыдущий» элемент
	}

}

template<class T> Node<T>* BinaryTree<T>::GetPredecessor(Node<T>* tree, Node<T>*& root)
{
	Node<T>* curr = tree->left;	// Спускаемся влево (можно вправо сделать, но тогда и while тоже так)
	while (curr->right != nullptr)	// Идём направо, пока есть узлы...
	{
		root = curr;
		curr = curr->right;
	}
	return curr; //Получаем указатель
}
template<class T> Node<T>* BinaryTree<T>::GetSuccessor(Node<T>* tree)
{
	// Идентично GetPredecessor в купе с searchLeef, только возвращаем предка, при находке элемента

	Node<T>* curr = root;	// Начинаем с корня
	Node<T>* currRoot;	// Спускаемся влево (можно вправо сделать, но тогда и while тоже так)
	while (curr != tree)	// Идём направо, пока есть узлы...
	{
		currRoot = curr;
		if (curr->info < tree->info)				// Если данные «меньше», чем у текущего узла ...
			curr = tree->left;	// Идём налево
		else if (curr->info > tree->info)			// Если данные «больше», чем у текущего узла ...
			curr = tree->right;	// Идём направо
		else if (curr->info == tree->info) return currRoot; 	// Возвращаем указатель на объект
	}
	return curr; //Получаем указатель
}

template<class T> void BinaryTree<T>::insert(Node<T>*& tree, T& data)
{
	{
		if (tree == nullptr) 			// Основной случай
			tree = new Node<T>(data, nullptr, nullptr), ++count;
		else if (data < tree->info)
			insert(tree->left, data);	// Рекурсия
		else
			insert(tree->right, data);	// Рекурсия
	}
}






// Задаток калькулятора
template<class T>
class TreeCalс : public BinaryTree<T>
{
	using BinaryTree<T>::root;

protected:
	int num;
public:
	TreeCalс() : num(NULL) {};
	~TreeCalс();




};
