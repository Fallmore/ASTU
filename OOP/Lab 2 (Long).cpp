#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>
#include <typeinfo>
#define maxui MAXUINT32
#define maxi MAXINT32
#define is_digit(c) ((c) >= '0' && (c) <= '9')
typedef unsigned int uint;

using namespace std;

class Long
{
private:
	uint pos = 0, neg = 0;

	// Проверка на переполнение
	bool overflow(uint& val, int typeCompare) const {
		if (typeCompare == 0)
			return (pos > maxui - val || neg > maxui - val);
		else if (typeCompare == 1)
			return (pos > maxui / val || neg > maxui / val);
		throw logic_error(errors[2]);
	}
	// Подсчёт положительного и отрицательного чисел
	void calculate() noexcept {
		if (pos != 0 && neg != 0) {
			if (pos > neg) pos -= neg, neg = 0;
			else neg -= pos, pos = 0;
		}
	}
	// Преобразование типов
	template<typename T>
	uint convert(const T& val) {
		if (typeid(T) != typeid(Long))
		{
			int a = 0, b = 0;
			if (val > maxi) a = maxi, b = val - maxi;
			else a = abs(static_cast<int>(val));
			return a + b;
		}
		return val;
	}

	string errors[10]{
		"Ошибка: Вызвано переполнение!",
		"Ошибка: Деление на ноль!",
		"Ошибка: Неверный тип булевой функции!"
	};
public:
	Long() : pos(0), neg(0) {};
	template<typename T> Long(const T& val) {
		*this = val;
	};

	string toString() const noexcept;

	friend ostream& operator<<(ostream& c, Long& a) noexcept;
	friend istream& operator>>(istream& c, Long& a);

	template<typename T> Long& operator=(const T& val) noexcept;
	template<typename T> Long& operator+=(const T& val);
	template<typename T> Long& operator-=(const T& val);
	template<typename T> Long& operator*=(const T& val);
	template<typename T> Long& operator/=(const T& val);

	Long& operator=(Long& val) noexcept;
	Long& operator+=(Long& val);
	Long& operator-=(Long& val);
	Long& operator*=(Long& val);
	Long& operator/=(Long& val);

	template<typename T> bool operator>(const T& val) const noexcept;
	template<typename T> bool operator<(const T& val) const noexcept;
	template<typename T> bool operator==(const T& val) const noexcept;
	template<typename T> bool operator>=(const T& val) const noexcept;
	template<typename T> bool operator<=(const T& val) const noexcept;
	template<typename T> bool operator!=(const T& val) const noexcept;
	bool operator>(Long& val) const noexcept;
};

//==============================================================================================
string Long::toString() const noexcept {
	if (pos != 0) return to_string(pos);
	else if (neg != 0) return "-" + to_string(neg);
	return "0";
}

ostream& operator<<(ostream& c, Long& a) noexcept {
	return (c << a.toString());
}
istream& operator>>(istream& c, Long& a) {
	string s; c >> s;
	a = stoi(s);
	return c;

}
//==============================================================================================

template<typename T> Long& Long::operator=(const T& val) noexcept {
	uint temp = convert(val);
	if (val > 0) pos = temp, neg = 0;
	else neg = temp, pos = 0;
	return *this;
}
template<typename T> Long& Long::operator+=(const T& val) {
	uint temp = convert(val);
	if (!overflow(temp, 0)) {
		if (val > 0) pos += temp;
		else neg += temp;
		calculate();
		return *this;
	}
	else throw overflow_error(errors[0]);
}
template<typename T> Long& Long::operator-=(const T& val) {
	uint temp = convert(val);
	if (!overflow(temp, 0)) {
		if (val > 0) neg += temp;
		else pos += temp;
		calculate();
		return *this;
	}
	else throw overflow_error(errors[0]);
}
template<typename T> Long& Long::operator*=(const T& val) {
	uint temp = convert(val);
	if (!overflow(temp, 1)) {
		if (val > 0) {
			if (pos != 0) pos *= temp;
			else neg *= temp;
		}
		else {
			if (neg != 0) neg *= temp, pos = neg, neg = 0;	// - на - даёт +
			else pos *= temp, neg = pos, pos = 0;			// + на - даёт -
		}
		return *this;
	}
	else throw overflow_error(errors[0]);
}
template<typename T> Long& Long::operator/=(const T& val) {
	uint temp = convert(val);
	if (temp != 0) {
		if (val > 0) {
			if (pos != 0) pos /= temp;
			else neg /= temp;
		}
		else {
			if (neg != 0) neg /= temp, pos = neg, neg = 0;	// - на - даёт +
			else pos /= temp, neg = pos, pos = 0;			// + на - даёт -
		}
		return *this;
	}
	else throw overflow_error(errors[1]);
}
//==============================================================================================

Long& Long::operator=(Long& val) noexcept {
	pos = val.pos, neg = val.neg;
	return *this;
}
Long& Long::operator+=(Long& val) {
	if (val.pos != 0) return *this += val.pos;
	else return *this += val.neg;
}
Long& Long::operator-=(Long& val) {
	if (val.pos != 0) return *this -= val.pos;
	else return *this -= val.neg;
}
Long& Long::operator*=(Long& val) {
	if (val.pos != 0) return *this *= val.pos;
	else return *this *= val.neg;
}
Long& Long::operator/=(Long& val) {
	if (val.pos != 0) return *this /= val.pos;
	else return *this /= val.neg;
}
//==============================================================================================

template<typename T> bool Long::operator>(const T& val) const noexcept {
	return (stoi(toString()) > val);
}

bool Long::operator>(Long& val) const noexcept {
	return (stoi(toString()) > stoi(val.toString()));
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-21/2\nВариант 7\n\n\n";
	Long a = 20;
	Long b = maxui;
	Long c(b);
	a = b = c;
	cout << maxui;

	return 0;
}
