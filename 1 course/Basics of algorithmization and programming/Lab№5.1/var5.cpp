#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#define M_PI


using namespace std;

class Point
{
	double X;
	double Y;

public:
	bool Init(double x, double y)
	{
		if (x <= 0 || x >= 0 || y <= 0 || y >= 0)
		{
			X = x;
			Y = y;
			return true;
		}
		else return false;
	}
	
	void Init(const Point& t) { *this = t; }

	string toString()
	{
		string s = "\nКоординаты: ";
		ostringstream os;
		os << "\nX - " << X
			<< "\nY - " << Y << endl;
		return s + os.str();
	}

	void read();
	void display();

	void Move(Point& obj);
	double Path_OXY(Point obj);
	double Path_Dots(Point obj);
	void Polar(Point obj);
};

void Point::read()
{
	cin.clear();
	double X = 0;
	double Y = 0;
	cout << "\nВведите X: "; cin >> X;
	cout << "Введите Y: "; cin >> Y;
	if (!Init(X, Y)) read();
}

void Point::display()
{
	cout << toString() << endl;
}

void Point::Move(Point& obj)
{
	int a;
	cout << "\nВведите числа, на которые хотите изменить координаты (x/y + ваше число):\n1 число: ";
	cin >> a; obj.X += a;
	cout << "2 число: ";
	cin >> a; obj.Y += a;
	cout << toString() << endl;
}

double Point::Path_OXY(Point obj)
{
	cout << "\nРасстояние до начала = ";
	return sqrt(X * X + Y * Y);
}

double Point::Path_Dots(Point obj)
{
	int x, y;
	cout << "\nВведите координаты новой точки для вычисления расстояния между ней и начальной:";
	cout << "\nx = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "(" << x << ";" << y << ")\nРасстояние = ";
	return sqrt(pow(abs(X - x), 2) + pow(abs(Y - y), 2));
}

void Point::Polar(Point obj)
{
	obj.display();
	double p, phi, arctg, pi;
	p = sqrt(X * X + Y * Y);
	cout << "Полярный радиус r = " << p;
	arctg = atan(Y / X);
	phi = 180 / 3.14159265358979323846 * arctg;
	cout << "\nПолярный угол фи = " << phi << " градусов\n\n";

}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-11/2\nВариант 5\nКласс с полями и методами\n\n"
		<< "Создать класс Point для работы с точками на плоскости. Координаты точки — декартовые.\n"
		<< "Обязательно должны быть реализованы:\n1. Перемещение точки по оси X;\n2. Перемещение по оси Y;\n"
		<< "3. Определение расстояния до начала координат;\n4. Расстояния между двумя точками;\n"
		<< "5. Преобразование в полярные координаты;\n6. Сравнение на совпадение и несовпадение.\n\n\n";
	Point A;

	cout << "Создание объекта:\n";
	A.read(); A.display();
	system("pause");

	cout << "\n1,2. Перемещение точки по оси X и по оси Y\n";
	A.Move(A);
	system("pause");

	cout << "\n3. Определение расстояния до начала координат\n";
	cout << A.Path_OXY(A) << "\n\n";
	system("pause");

	cout << "\n4. Расстояния между двумя точками\n";
	cout << A.Path_Dots(A) << "\n\n";
	system("pause");

	cout << "\n5. Преобразование в полярные координаты\n";
	A.Polar(A);
}