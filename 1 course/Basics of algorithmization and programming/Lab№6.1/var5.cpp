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

public:

	Products(double f = 0, int s = 0)
	{
		if (!Init(f, s))
			throw exception("\n������������ �� ����������� ���� ������!");
	}
	friend istream& operator>>(istream& t, Products& r);
	friend ostream& operator<<(ostream& t, const Products& r);

	double cost()
	{
		cout << "\nC�������� �������: ";
		return first * second;
	}
};

ostream& operator<<(ostream& t, const Products& r)
{
	t << "\n����: " << r.first << "\n����������:" << r.second;
	return t;
}

istream& operator>>(istream& t, Products& r)
{
	float f = 0, s = 0;
	do
	{
		cout << "\n������� ���� ������: "; cin >> f;
		cout << "������� ���������� ������: "; cin >> s;
		if (f < 0 || s < 0) cout << "\n\n������������ ������\n";
	} while (!r.Init(f, s));
	r.first = f; r.second = s;
	return t;
}

Products make_Products(double f, int s)
{
	Products A(f,s);
	return A;
}



int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 5\n���������-����\n"
		<< "\n���� first � ������������ ������������� �����, ���� ������;"
		<< "\n���� second � ����� ������������� �����, ���������� ������ ������."
		<< "\n����������� ����� cost() � ���������� ��������� ������.\n\n";

	try
	{
		cout << "\n�������� ������ ������� � ������ �� ���������:\n";
		Products A;
		cout << A; cout << A.cost() << endl;

		cout << "\n�������� ������ �������:\n";
		Products D(34, 6);
		cout << D; cout << D.cost() << endl;
		system("pause");

		cout << "\n�������� ������������� �������:\n";
		Products* p = new Products(4, 3);
		cout << *p; cout << p->cost() << endl;
		delete p;
		system("pause");

		cout << "\n������������ make_Products\n";

		cout << "\n�������� ������� ��������:\n";
		Products M[2];
		for (int i = 0; i < 2; i++)
		{
			int f, s;
			cout << "\nM[" << i << "]";
			cout << "\n������� ���� ������: "; cin >> f;
			cout << "������� ���������� ������: "; cin >> s;
			M[i] = make_Products(f, s);
			cout << M[i]; cout << M[i].cost() << endl;
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
			m[i] = make_Products(f, s);
			cout << m[i]; cout << m[i].cost() << endl;
		}
		system("pause");
		// -----------------------------------
  // ������������ ��������� ��� make_Complex � ����������
		cout << "\n�������������� ����� ���������� ��� f = -7549, s = 6:\n";
		m[1] = make_Products(-7549, 6);
		delete[] m;
	}
	catch (exception err) { cout << err.what(); }
}