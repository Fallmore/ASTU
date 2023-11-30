#include <iostream>

using namespace std;

struct Products
{
	double first; //цена товара
	int second; //количество единиц товара
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
			throw exception("\nКонструктору не понравились ваши данные!");
	}
	friend istream& operator>>(istream& t, Products& r);
	friend ostream& operator<<(ostream& t, const Products& r);

	double cost()
	{
		cout << "\nCтоимость покупки: ";
		return first * second;
	}
};

ostream& operator<<(ostream& t, const Products& r)
{
	t << "\nЦена: " << r.first << "\nКоличество:" << r.second;
	return t;
}

istream& operator>>(istream& t, Products& r)
{
	float f = 0, s = 0;
	do
	{
		cout << "\nВведите цену товара: "; cin >> f;
		cout << "Введите количество товара: "; cin >> s;
		if (f < 0 || s < 0) cout << "\n\nНеправильные данные\n";
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
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\nСтруктура-пара\n"
		<< "\nПоле first — вещественное положительное число, цена товара;"
		<< "\nполе second — целое положительное число, количество единиц товара."
		<< "\nРеализовать метод cost() — вычисление стоимости товара.\n\n";

	try
	{
		cout << "\nСоздание одного объекта с полями по умолчанию:\n";
		Products A;
		cout << A; cout << A.cost() << endl;

		cout << "\nСоздание одного объекта:\n";
		Products D(34, 6);
		cout << D; cout << D.cost() << endl;
		system("pause");

		cout << "\nСоздание динамического объекта:\n";
		Products* p = new Products(4, 3);
		cout << *p; cout << p->cost() << endl;
		delete p;
		system("pause");

		cout << "\nДемонстрация make_Products\n";

		cout << "\nСоздание массива объектов:\n";
		Products M[2];
		for (int i = 0; i < 2; i++)
		{
			int f, s;
			cout << "\nM[" << i << "]";
			cout << "\nВведите цену товара: "; cin >> f;
			cout << "Введите количество товара: "; cin >> s;
			M[i] = make_Products(f, s);
			cout << M[i]; cout << M[i].cost() << endl;
		}
		system("pause");
		// -----------------------------------
		cout << "\nСоздание динамического массива объектов:\n";
		Products* m = new Products[2];
		for (int i = 0; i < 2; i++)
		{
			int f, s;
			cout << "\nM[" << i << "]";
			cout << "\nВведите цену товара: "; cin >> f;
			cout << "Введите количество товара: "; cin >> s;
			m[i] = make_Products(f, s);
			cout << m[i]; cout << m[i].cost() << endl;
		}
		system("pause");
		// -----------------------------------
  // неправильные параметры для make_Complex – исключение
		cout << "\nПринудительный показ исключения при f = -7549, s = 6:\n";
		m[1] = make_Products(-7549, 6);
		delete[] m;
	}
	catch (exception err) { cout << err.what(); }
}