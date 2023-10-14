#pragma once
#include <iostream>

using namespace std;

template<class T> struct Node
{

	T info;// �������������� �����.
	Node<T>* left, * right;// ��������� �� �������� ����.
	// ����������� �� ���������.
	Node() { left = right = nullptr; }
	// ����������� � �����������.
	Node(const T& d, Node<T>* l = nullptr, Node<T>* r = nullptr) :
		info(d), left(l), right(r) {};
};

template<class T> class BinaryTree
{
protected:
	Node<T>* root;	// ��������� �� ������ ������. 
	int count;		// ������� ���������
	//Node<T>* copyTree(BinaryTree<T>* otherTree) const; // �����, ��������� ����� ������ otherTree. 

	Node<T>* searchLeef(Node<T>* tree, T& data) const;	// ���� � ���������� ���� � �������.
	T* searchInfoLeef(Node<T>* tree, T& data) const;	// ���� � ���������� ������. (�� ����� ���)
	Node<T>* retriveLeef(T& item) const					// ���������� ��������� �� ������, ���� ������
	{
		return searchLeef(root, item);
	}

	void inorder(Node<T>* tree) const;			// ������������ ����� ������ 
	int inorderCountLeefs(Node<T>* tree) const; // ������������ ����� ������ � ��������� ��� �����
	//void preorder(Node<T>* tree) const;		// ����� ������ � ������
	//void postorder(Node<T>* tree) const;		// ����� ������ � �������

	void clear(Node<T>*& root);								// ������� ��� ���� ������ � ������������� ��������� root � NULL. 
	void deleteLeefs(T& data);								// ����� ����� ��� ��������
	void deleteNode(Node<T>*& tree, Node<T>*& root);		// ������� ����
	Node<T>* GetPredecessor(Node<T>* tree, Node<T>*& root);	// ������� "����������" �� �������� ����
	Node<T>* GetSuccessor(Node<T>* tree);					// ������� �������� ��������

	void insert(Node<T>*& tree, T& data); // ��������� ����
public:
	BinaryTree() : root(nullptr), count(0) {}; // ����������� �� ���������.

	//const BinaryTree<T>& operator=(const BinaryTree<T>& otherTree); // ���������� ��������� ������������.
	//BinaryTree(const BinaryTree<T>& otherTree); // ���������� �����������

	ostream& operator<<(T& d)
	{
		return (cout << d);
	}

	bool isEmpty() const // �������� �� ������ �������� ������ �������� ��� ���.
	{
		if (root == nullptr) return 1;
		return 0;
	}

	void print() const // ������� ������ �� ������.
	{
		inorderTree();
	}

	int nodeCount() const // ���������� ���������� ����� � ������.
	{
		return count;
	}

	void destroy() // ������� ��� ���� ������. � ���������� ������ ����� � root == NULL;
	{
		clear(root);
	}

	void inorderTree() const // ������������ ����� ������.
	{
		inorder(root);
	}
	int CountLeefs(T& item) const // ������������ ����� ������ � ��������� ��� �����.
	{
		return inorderCountLeefs(retriveLeef(item));
	}

	//void preorderTree()const // ����� ������ � ������.
	//{
	//	preorder(root);
	//}

	//void postorderTree()const // ����� ������ � �������.
	//{
	//	postorder(root);
	//}

	T* retriveItem(T& item) const // ���������� ��������� �� item, ���� �������
	{
		return searchInfoLeef(root, item);
	}

	void deleteItem(T& item) // ������� ���� � ������� item �� ������.
	{
		deleteLeefs(root, item);
	}

	void insertItem(T& item) // ��������� ���� � ������� item � ������.
	{
		insert(root, item);
	}

	~BinaryTree() // ����������
	{
		destroy();
	}
};

//template<class T> Node<T>* BinaryTree<T>::copyTree(BinaryTree<T>* otherTree) const
//{
//	if (otherTree->isEmpty()) return nullptr;
//
//	Node<T> ourTree = *this;
//	ourTree.insertItem(otherTree->root->info);
//	copyTree(otherTree->root->left);
//	copyTree(otherTree->root->right);
//	return ourTree;
//}

template<class T> void BinaryTree<T>::inorder(Node<T>* tree) const
{
	if (tree != NULL)
	{
		inorder(tree->left); //����������� �����
		cout << tree->info << " ";
		//��� ���������� � ������� ��� ����...
		inorder(tree->right); //����������� �����
	}
}
template<class T> int BinaryTree<T>::inorderCountLeefs(Node<T>* tree) const
{
	int cnt = 0;
	if (tree != NULL)
	{
		++cnt;
		cnt += inorderCountLeefs(tree->left);	//����������� �����
		cnt += inorderCountLeefs(tree->right);	//����������� �����
		return cnt;
	}
	else return 0;
}

template<class T> void BinaryTree<T>::clear(Node<T>*& root)
{
	while (!isEmpty()) // ���� ������ �� �����
		deleteNode(root, root); // ������� ��������
}

template<class T> Node<T>* BinaryTree<T>::searchLeef(Node<T>* tree, T& data) const
{
	if (data < tree->info)				// ���� ������ �������, ��� � �������� ���� ...
		searchLeef(tree->left, data);	// ��� ������
	else if (data > tree->info)			// ���� ������ �������, ��� � �������� ���� ...
		searchLeef(tree->right, data);	// ��� �������
	else if (data == tree->info) return tree; // ���������� ��������� �� ������
}
template<class T> T* BinaryTree<T>::searchInfoLeef(Node<T>* tree, T& data) const
{
	if (data < tree->info)				// ���� ������ �������, ��� � ��������� ���� ...
		searchLeef(tree->left, data);	// ��� ������
	else if (data > tree->info)			// ���� ������ �������, ��� � �������� ���� ...
		searchLeef(tree->right, data);	// ��� �������
	else if (data == tree->info) return new T(tree->info); // ���������� ��������� �� ������
	// �� ����������� ����, ����� ��� ������, � ��� �� ����� �������, �������, ���� ���� ������
}

template<class T> void BinaryTree<T>::deleteLeefs(T& data)
{
	deleteNode(retriveLeef(data), root); // ������� ������, ��������� �� ������
}

template<class T> void BinaryTree<T>::deleteNode(Node<T>*& tree, Node<T>*& root)
{
	Node<T>* temp; Node<T>* temproot;

	// ��� ������, � ������ �������� (�������� ����� 5 ����� �� ��� �����)

	temp = tree, temproot = root;
	if (tree->left == nullptr && tree->right != nullptr)		// ���� ������
	{
		temp = tree->right;										// ���������� ������
		tree->info = temp->info,								
			tree->left = temp->left, tree->right = temp->right;	// �������� (��������) ��� ������ � �����
		delete temp, --count;									// �������, ��������
		if (count == 0) tree = nullptr;							// ���� 0, �������� ���������
	}
	else if (tree->right == nullptr && tree->left != nullptr)	// ���� ������
	{
		temp = tree->left;										// ���������� �����
		tree->info = temp->info, 
			tree->right = temp->right, tree->left = temp->left;	// �������� (��������) ��� ������ � �����
		delete temp, --count;									// �������, ��������
		if (count == 0) tree = nullptr;							// ���� 0, �������� ���������

	}
	else if (tree->right == nullptr && tree->left == nullptr)	// ���� ���������
	{
		temproot = GetSuccessor(temp);			// ������� ������	
		if (temproot->right == temp) temproot->right = nullptr;	// �� � �������� � ������ 
		else temproot->left = nullptr;							// ��������� �� ������
		delete temp, --count;									// �������, ��������
		if (count == 0) tree = nullptr;							// ���� 0, �������� ���������
	}
	else														// ����� ��� �������� ����
	{
		Node<T>* pred = GetPredecessor(tree, temproot);	// ������� ����������� �������
		int leefs = inorderCountLeefs(pred);						// �������, ������� "�������"
		tree->info = pred->info;						// ���������� ������ � ���������� ����
		if (leefs == 1)												// ���� ������� ���������, ����� �������, � ��� �������, � �� ���� � � ��� >:(	
		{
			if (temproot->right == pred) temproot->right = nullptr;	// �� � �������� � ������..
			else temproot->left = nullptr;							// ..��������� �� ������
			delete pred, --count;									// �������, ��������
			if (count == 0) tree = nullptr;							// ���� 0, �������� ���������
		}
		else deleteNode(pred, temproot);				//������� ����������� �������
	}

}

template<class T> Node<T>* BinaryTree<T>::GetPredecessor(Node<T>* tree, Node<T>*& root)
{
	Node<T>* curr = tree->left;		// ���������� ����� (����� ������ �������, �� ����� � while ���� ���)
	while (curr->right != nullptr)	// ��� �������, ���� ���� ����...
	{
		root = curr;
		curr = curr->right;
	}
	return curr; //�������� ���������
}
template<class T> Node<T>* BinaryTree<T>::GetSuccessor(Node<T>* tree)
{
	// ��������� GetPredecessor � ���� � searchLeef, ������ ���������� ������, ��� ������� ��������

	Node<T>* curr = root;	// �������� � �����
	Node<T>* currRoot;		// ���������� ����� (����� ������ �������, �� ����� � while ���� ���)
	while (curr != tree)	// ��� �������, ���� ���� ����...
	{
		currRoot = curr;
		if (curr->info < tree->info)				// ���� ������ �������, ��� � �������� ���� ...
			curr = tree->left;	// ��� ������
		else if (curr->info > tree->info)			// ���� ������ �������, ��� � �������� ���� ...
			curr = tree->right;	// ��� �������
		else if (curr->info == tree->info) return currRoot; // ���������� ��������� �� ������
	}
	return curr; //�������� ���������
}

template<class T> void BinaryTree<T>::insert(Node<T>*& tree, T& data)
{
	{
		if (tree == nullptr) // �������� ������
			tree = new Node<T>(data, nullptr, nullptr), ++count;
		else if (data < tree->info)
			insert(tree->left, data);	// ��������
		else
			insert(tree->right, data);	// ��������
	}
}







template<class T>
class TreeCal� : public BinaryTree<T>
{
	using BinaryTree<T>::root;

protected:
	int num;
public:
	TreeCal�() : num(NULL) {};
	~TreeCal�();




};