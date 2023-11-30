#include <iostream>

using namespace std;

struct Products
{
	double first; //���� ������
	int second; //���������� ������ ������
	bool Init(double f, int s)
	{
		if (f < 0 || s < 0) return false;
		else
		{
			first = f;
			second = s;
			return true;
		}
	}
	void Read();
	void Display();
	double cost()
	{
		cout << "\nC�������� �������: ";
		return first * second;
	}
};

void Products::Read()
{
	double f = 0;
	int s = 0;
	do
	{
		cout << "\n������� ���� ������: "; cin >> f;
		cout << "������� ���������� ������: "; cin >> s;
		if (f < 0 || s < 0) cout << "\n\n������������ ������\n";
	} while (!Init(f, s));
}

Products make_Products(double f, int s)
{
	Products A;
	if (A.Init(f, s)) return A;
	else throw "������� �� ����������� ���� ������!";
}

void Products::Display()
{
	cout << "\n����: " << first << "\n����������:" << second;
}


int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 5\n���������-����\n"
		<< "\n���� first � ������������ ������������� �����, ���� ������;"
		<< "\n���� second � ����� ������������� �����, ���������� ������ ������."
		<< "\n����������� ����� cost() � ���������� ��������� ������.\n\n";

	cout << "\n�������� ���������� �������:\n";
	Products A;
	A.Read();
	A.Display();
	cout << A.cost() << endl;
	system("pause");

	cout << "\n�������� ������������� �������:\n";
	Products* p = new Products;
	p->Read();
	p->Display();
	cout << p->cost() << endl;
	delete p;
	system("pause");


	try 
	{
		cout << "\n������������ make_Products\n";

		cout << "\n�������� ������� ��������:\n";
		Products M[2];
		for (int i = 0; i < 2; i++)
		{
			int f, s;
			cout << "\nM[" << i << "]";
			cout << "\n������� ���� ������: "; cin >> f;
			cout << "������� ���������� ������: "; cin >> s;
			M[i] = make_Products(f, s); M[i].Display();
			cout << M[i].cost() << endl;
		}
		system("pause");
	// -----------------------------------
		cout << "\n�������� ������������� ������� ��������:\n";
		Products* m = new Products[2];
		for (int i = 0; i < 2; i++)
		{
			int f, s;
			cout << "\nM[" << i << "]";
			cout << "\n������� ���� ������: "; cin >> f;
			cout << "������� ���������� ������: "; cin >> s;
			m[i] = make_Products(f, s); m[i].Display();
			cout << m[i].cost() << endl;
		}
		system("pause");
		// -----------------------------------
  // ������������ ��������� ��� make_Complex � ����������
		cout << "\n�������������� ����� ���������� ��� f = -7549, s = 6:\n";
		m[1] = make_Products(-7549, 6);
		delete[] m;
	}
	catch (...) { cout << "\n������ ������ �#\n"; }
}