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
		string s = "\n����������: ";
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
	cout << "\n������� X: "; cin >> X;
	cout << "������� Y: "; cin >> Y;
	if (!Init(X, Y)) read();
}

void Point::display()
{
	cout << toString() << endl;
}

void Point::Move(Point& obj)
{
	int a;
	cout << "\n������� �����, �� ������� ������ �������� ���������� (x/y + ���� �����):\n1 �����: ";
	cin >> a; obj.X += a;
	cout << "2 �����: ";
	cin >> a; obj.Y += a;
	cout << toString() << endl;
}

double Point::Path_OXY(Point obj)
{
	cout << "\n���������� �� ������ = ";
	return sqrt(X * X + Y * Y);
}

double Point::Path_Dots(Point obj)
{
	int x, y;
	cout << "\n������� ���������� ����� ����� ��� ���������� ���������� ����� ��� � ���������:";
	cout << "\nx = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "(" << x << ";" << y << ")\n���������� = ";
	return sqrt(pow(abs(X - x), 2) + pow(abs(Y - y), 2));
}

void Point::Polar(Point obj)
{
	obj.display();
	double p, phi, arctg, pi;
	p = sqrt(X * X + Y * Y);
	cout << "�������� ������ r = " << p;
	arctg = atan(Y / X);
	phi = 180 / 3.14159265358979323846 * arctg;
	cout << "\n�������� ���� �� = " << phi << " ��������\n\n";

}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 5\n����� � ������ � ��������\n\n"
		<< "������� ����� Point ��� ������ � ������� �� ���������. ���������� ����� � ����������.\n"
		<< "����������� ������ ���� �����������:\n1. ����������� ����� �� ��� X;\n2. ����������� �� ��� Y;\n"
		<< "3. ����������� ���������� �� ������ ���������;\n4. ���������� ����� ����� �������;\n"
		<< "5. �������������� � �������� ����������;\n6. ��������� �� ���������� � ������������.\n\n\n";
	Point A;

	cout << "�������� �������:\n";
	A.read(); A.display();
	system("pause");

	cout << "\n1,2. ����������� ����� �� ��� X � �� ��� Y\n";
	A.Move(A);
	system("pause");

	cout << "\n3. ����������� ���������� �� ������ ���������\n";
	cout << A.Path_OXY(A) << "\n\n";
	system("pause");

	cout << "\n4. ���������� ����� ����� �������\n";
	cout << A.Path_Dots(A) << "\n\n";
	system("pause");

	cout << "\n5. �������������� � �������� ����������\n";
	A.Polar(A);
}