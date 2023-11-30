#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

const int K = 11;
long double Asn[K];
long double Ase[K];
long double As[K];

void ab(double& a, double& b) //���� ���������
{
	cout << "\n\n����� �������� [a;b] = ";
	cin >> a >> b;
	if (a > b)
	{
		cout << "\n\n� �� ����� ���� ������ b";
		ab(a, b);
	}

}

void Nin(double& n) //���� ���������� ���������
{
	cout << "\n\n����� ���������� ��������� = ";
	cin >> n;
	if (n < 1)
	{
		cout << "\n\n���������� �� ����� ���� �����";
		Nin(n);
	}
}

void EPS(double& eps) //���� ��������
{
	cout << "\n\n����� ��������, ������������� � ������� � ���� = ";
	cin >> eps;
	if (eps <= 0 || eps >= 1)
	{
		cout << "\n\n������������ ��������";
		EPS(eps);
	}
}

long long fact(long long n) //���������
{
	long long a = 1;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i < n + 1; i++)
		{
			a *= i;
		}
		return a;
	}
}

long double fx(double x, long long n) //������� ���������� ���� �������
{
	long double s = cos(x * n) / fact(n);
	return s;
}

long double Sn(double x, double a, double b, double n) //�-��� �� ���������� ���������
{
	double h = (b - a) / 10; //��� ���������
	long double sum = 0, SUM = 0;
	int k = 0;
	while (x < b)
	{
		for (int i = 0; i < n+1; i++)
		{
			sum += fx(x, i); //����� ���������� ���� ������������ �
		}
		Asn[k] = sum; //���������� ������� ��� ������
		SUM += sum; //����� �����
		sum = 0;
		k++;
		x += h;
	}
	return SUM;
}

long double Se(double x, double a, double b, double eps) //�-��� �� ��������
{
	double h = (b - a) / 10; //��� ���������
	long double sum1 = 0, sum = 0, SUM = 0, n = 0;
	int k = 0;
	while (x < b)
	{
		do
		{
			sum = sum1;
			sum1 += fx(x, n); //����� ���������� ���� ������������ �
			n++;
		} while (fabsl(sum - sum1) > eps);
		Ase[k] = sum1; //���������� ������� ��� ������
		SUM += sum1; //����� �����
		sum1 = 0;
		n = 0;
		k++;
		x += h;
	}
	return SUM;
}

long double S(double x, double a, double b) //��������
{
	double h = (b - a) / 10; //��� ���������
	long double sum = 0, n = 1, s = 0;
	int k = 0;
	while (x < b)
	{
		s = exp(cos(x)) * cos(sin(x)); //����� ���������� ���� ������������ �
		As[k] = s; //���������� ������� ��� ������
		sum += s; //����� �����
		k++;
		x += h;
	}
	return sum;
}

void out(double x, double a, double b , long double x1, long double x2, long double x3) //�����
{
	double h = (b - a) / 10; //��� ���������
	int n = 1, k = 0;
	cout << "| " << setw(6) << "N n/n" << setw(6) << "|" << setw(6) << "x" << setw(5) << "|" << setw(6) << "Sn" << setw(10) << "|" << setw(6) << "Se" << setw(10) << "|" << setw(6) << "S" << setw(7) << "|\n";
	cout << "---------------------------------------------------------------------" << endl;
	while (n != 12)
	{
		cout  << "| " << setw(6) << n << setw(6) << "|" << setw(6) << x << setw(6) <<  "| " << setw(8) << Asn[k] << setw(8) << "| " << setw(8) << Ase[k] << setw(8) << "| " << setw(8)  << As[k] << setw(4) << "|\n";
		cout << "---------------------------------------------------------------------" << endl;
		k++;
		x += h;
		n++;
	}
	cout  << "| " << setw(6) << "�����" << setw(6) << "|" << setw(5) << "" << setw(6) << "|" << setw(8) << x1 << setw(8) << "|" << setw(8) << x2 << setw(8) << "|" << setw(8) <<  x3 << setw(5) << "|\n";
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "��������� �����-11/2\n������� 4\n������������� �������\n";
	double a, b;
	ab(a, b);
	double x = a;
	double N;
	Nin(N);
	long double x1, x2, x3;
	x1 = Sn(x, a, b, N);
	double eps;
	EPS(eps);
	x2 = Se(x, a, b, eps);
	x3 = S(x, a, b);
	out(x, a, b, x1, x2, x3);
}