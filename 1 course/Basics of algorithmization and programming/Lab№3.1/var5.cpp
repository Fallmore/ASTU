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
	void Read();
	void Display();
	double cost()
	{
		cout << "\nCтоимость покупки: ";
		return first * second;
	}
};

void Products::Read()
{
	double f = 0;
	int s = 0;
	do
	{
		cout << "\nВведите цену товара: "; cin >> f;
		cout << "Введите количество товара: "; cin >> s;
		if (f < 0 || s < 0) cout << "\n\nНеправильные данные\n";
	} while (!Init(f, s));
}

Products make_Products(double f, int s)
{
	Products A;
	if (A.Init(f, s)) return A;
	else throw "Функции не понравились ваши данные!";
}

void Products::Display()
{
	cout << "\nЦена: " << first << "\nКоличество:" << second;
}


int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\nСтруктура-пара\n"
		<< "\nПоле first — вещественное положительное число, цена товара;"
		<< "\nполе second — целое положительное число, количество единиц товара."
		<< "\nРеализовать метод cost() — вычисление стоимости товара.\n\n";

	cout << "\nСоздание локального объекта:\n";
	Products A;
	A.Read();
	A.Display();
	cout << A.cost() << endl;
	system("pause");

	cout << "\nСоздание динамического объекта:\n";
	Products* p = new Products;
	p->Read();
	p->Display();
	cout << p->cost() << endl;
	delete p;
	system("pause");


	try 
	{
		cout << "\nДемонстрация make_Products\n";

		cout << "\nСоздание массива объектов:\n";
		Products M[2];
		for (int i = 0; i < 2; i++)
		{
			int f, s;
			cout << "\nM[" << i << "]";
			cout << "\nВведите цену товара: "; cin >> f;
			cout << "Введите количество товара: "; cin >> s;
			M[i] = make_Products(f, s); M[i].Display();
			cout << M[i].cost() << endl;
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
			m[i] = make_Products(f, s); m[i].Display();
			cout << m[i].cost() << endl;
		}
		system("pause");
		// -----------------------------------
  // неправильные параметры для make_Complex – исключение
		cout << "\nПринудительный показ исключения при f = -7549, s = 6:\n";
		m[1] = make_Products(-7549, 6);
		delete[] m;
	}
	catch (...) { cout << "\nПривет кодеры С#\n"; }
}