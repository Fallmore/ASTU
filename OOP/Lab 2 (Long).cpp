#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>
#include <typeinfo>

using uint = unsigned int;
using namespace std;

constexpr uint maxui = MAXUINT32;
constexpr int maxi = MAXINT32;

class Long
{
private:
	uint major = 0, minor = 0;

	// Проверка на переполнение младшего разряда
	template<typename T>
	bool overflowMinor(int typeCompare, T& val) const {
		if (typeCompare == 0)
			return (minor > maxui - val || val >= maxui);
		else if (typeCompare == 1)
			return (minor > maxui / val || val >= maxui);
		throw logic_error(errors[2]);
	}
	// Проверка на переполнение старшего разряда
	template<typename T>
	bool overflowMajor(int typeCompare, const T& val) const {
		if (typeCompare == 0)
			return (major > maxui - val);
		else if (typeCompare == 1)
			return (major > maxui / val);
		throw logic_error(errors[2]);
	}
	string errors[10]{
		"Ошибка: Вызвано верхнее переполнение!",
		"Ошибка: Деление на ноль!",
		"Ошибка: Неверный тип булевой функции!"
		"Ошибка: Вызвано нижнее переполнение!"
	};
public:
	Long() : major(0), minor(0) {};
	template<typename T> Long(const T& val) { *this = val; };

	string toString() const noexcept;

	friend ostream& operator<<(ostream& c, const Long& major) noexcept;
	friend istream& operator>>(istream& c, Long& lng);

	template<typename T> Long& operator=(const T& val);
	template<typename T> Long& operator+=(const T& val);
	template<typename T> Long& operator-=(const T& val);
	template<typename T> Long& operator*=(const T& val);
	template<typename T> Long& operator/=(const T& val);
	template<typename T> Long& operator%=(const T& val);

	Long& operator=(const Long& val) noexcept;
	Long& operator++();
	Long operator++(int);
	Long& operator--();
	Long operator--(int);
	Long& operator+=(const Long& val);
	Long& operator-=(const Long& val);
	Long& operator*=(const Long& val);
	Long& operator/=(const Long& val);
	Long& operator%=(const Long& val);

	template<typename T> friend Long& operator+(const T& val, const Long& lng);
	template<typename T> friend Long& operator-(const T& val, const Long& lng);
	template<typename T> friend Long& operator*(const T& val, const Long& lng);
	template<typename T> friend Long& operator/(const T& val, const Long& lng);
	template<typename T> friend Long& operator%(const T& val, const Long& lng);
	template<typename T> friend Long& operator+(const Long& lng, const T& val);
	template<typename T> friend Long& operator-(const Long& lng, const T& val);
	template<typename T> friend Long& operator*(const Long& lng, const T& val);
	template<typename T> friend Long& operator/(const Long& lng, const T& val);
	template<typename T> friend Long& operator%(const Long& lng, const T& val);
	friend Long& operator+(const Long& lng, const Long& rlng);
	friend Long& operator-(const Long& lng, const Long& rlng);
	friend Long& operator*(const Long& lng, const Long& rlng);
	friend Long& operator/(const Long& lng, const Long& rlng);
	friend Long& operator%(const Long& lng, const Long& rlng);

	template<typename T> friend bool operator>(const Long& lng, const T& val) noexcept;
	template<typename T> friend bool operator<(const Long& lng, const T& val) noexcept;
	template<typename T> friend bool operator==(const Long& lng, const T& val) noexcept;
	template<typename T> friend bool operator>=(const Long& lng, const T& val) noexcept;
	template<typename T> friend bool operator<=(const Long& lng, const T& val) noexcept;
	template<typename T> friend bool operator!=(const Long& lng, const T& val) noexcept;
	template<typename T> friend bool operator>(const T& val, const Long& lng) noexcept;
	template<typename T> friend bool operator<(const T& val, const Long& lng) noexcept;
	template<typename T> friend bool operator==(const T& val, const Long& lng) noexcept;
	template<typename T> friend bool operator>=(const T& val, const Long& lng) noexcept;
	template<typename T> friend bool operator<=(const T& val, const Long& lng) noexcept;
	template<typename T> friend bool operator!=(const T& val, const Long& lng) noexcept;
	friend bool operator>(const Long& lng, const Long& rlng) noexcept;
	friend bool operator<(const Long& lng, const Long& rlng) noexcept;
	friend bool operator==(const Long& lng, const Long& rlng) noexcept;
	friend bool operator>=(const Long& lng, const Long& rlng) noexcept;
	friend bool operator<=(const Long& lng, const Long& rlng) noexcept;
	friend bool operator!=(const Long& lng, const Long& rlng) noexcept;
};

//==============================================================================================
string Long::toString() const noexcept { return to_string(major) + " " + to_string(minor); }

ostream& operator<<(ostream& c, Long& a) noexcept {
	return (c << a.toString());
}
istream& operator>>(istream& c, Long& lng) {
	string s; c >> s;
	lng = stoll(s);
	return c;
}
//==============================================================================================

template<typename T> Long& Long::operator=(const T& val) {
	if (val < 0) throw underflow_error(errors[3]);
	major = minor = 0;
	return *this += val;
}
template<typename T> Long& Long::operator+=(const T& val) {
	uint temp = static_cast<uint>(val);
	if (major == 0 && temp > minor && val < 0) throw underflow_error(errors[3]);
	auto tempval = floor(val);
	if (val >= 0) {
		if (overflowMinor(0, tempval)) {
			double count = tempval / maxui;	// Ищем количество переполнений
			if (overflowMajor(0, count)) throw overflow_error(errors[0]); // Проверяем на переполнение старшего разряда
			major += static_cast<uint>(count); // Добавляем количество переполнений в старший разряд
			temp = static_cast<uint>(fmod(tempval, maxui)); // Находим остаток от деления
		}
		if (overflowMinor(0, temp)) {
			if (overflowMajor(0, 1)) throw overflow_error(errors[0]); // Проверяем на переполнение старшего разряда
			temp -= maxui - minor, minor = temp, ++major; // Находим minor с учётом переполнения 
		}
		else minor += temp;
	}
	else *this -= abs(tempval);
	return *this;
}
template<typename T> Long& Long::operator-=(const T& val) {
	uint temp = static_cast<uint>(val);
	if (major == 0 && temp > minor && val > 0) throw underflow_error(errors[3]);
	auto tempval = floor(val);
	if (val >= 0) {
		if (tempval > maxui) {
			double count = tempval / maxui; // Ищем количество переполнений
			if (major < count) throw underflow_error(errors[3]);
			major -= static_cast<uint>(count); // Вычитаем количество переполнений в старший разряд
			temp = static_cast<uint>(fmod(tempval, maxui)); // Находим остаток от деления
		}
		if (temp > minor) {
			if (major == 0) throw underflow_error(errors[3]);
			minor = maxui - (temp - minor), --major; // Находим minor с учётом переполнения 
		}
		else minor -= temp;
	}
	else *this += abs(tempval);
	return *this;
}
template<typename T> Long& Long::operator*=(const T& val) {
	if (val < 0) throw underflow_error(errors[3]);
	uint temp = static_cast<uint>(val);
	auto tempval = floor(val);
	if (val <= maxui) {
		if (overflowMajor(1, temp)) throw overflow_error(errors[0]);
		major *= temp;
		if (overflowMinor(1, temp)) {
			uint mult, count, countmult;
			// Определяем наименьший множитель и наибольшее множимое для ускорения цикла
			if (temp < minor) count = temp, mult = minor;
			else count = minor, mult = temp;
			minor = 0;
			countmult = maxui / mult;
			for (count; count != 0; --count) {
				if (count >= countmult) *this += countmult * mult, count -= countmult - 1;
				else *this += mult;
			}
		}
		else minor *= temp;
	}
	else {
		// При major >= 1 будет всегда ошибка
		if (overflowMajor(1, tempval)) throw overflow_error(errors[0]);
		uint count = minor; minor = 0;
		for (count; count != 0; --count, *this += tempval);
	}
	return *this;
}
template<typename T> Long& Long::operator/=(const T& val) {
	if (val == 0) throw underflow_error(errors[1]);
	if (val < maxui) {
		uint temp = static_cast<uint>(val);
		double rest = static_cast<double>(major) / temp - (major / temp); // Находим остаток от деления major
		major /= temp, minor /= temp; // Делим нацело
		*this += static_cast<uint>(rest * maxui); // Прибавляем остаток к minor
	}
	else {
		auto temp = floor(val);
		double rest = static_cast<double>(major) / temp; // Всегда будет <1
		major = static_cast<uint>(major / temp), minor /= static_cast<uint>(minor / temp);
		*this += static_cast<uint>(rest * maxui);
	}
	return *this;
}
template<typename T> Long& Long::operator%=(const T& val) {
	if (val == 0) throw underflow_error(errors[1]);
	Long templong = *this;
	templong /= val, templong *= val; // Делим нацело, затем умножаем обратно
	*this -= templong; // Находим разницей остаток
	return *this;
}
//==============================================================================================
Long& Long::operator=(const Long& val) noexcept {
	major = val.major, minor = val.minor;
	return *this;
}
Long& Long::operator++() { return *this += maxui; }
Long Long::operator++(int) { return *this += 1; }
Long& Long::operator--() { return *this -= maxui; }
Long Long::operator--(int) { return *this -= 1; }
Long& Long::operator+=(const Long& val) {
	if (overflowMajor(0, val.major)) throw overflow_error(errors[0]);
	major += val.major;
	return *this += val.minor;
}
Long& Long::operator-=(const Long& val) {
	if (major < val.major) throw underflow_error(errors[3]);
	major -= val.major;
	return *this -= val.minor;
}
Long& Long::operator*=(const Long& val) {
	for (uint i = 0; i < major; ++i, *this *= maxui);
	return *this *= val.minor;
}
Long& Long::operator/=(const Long& val) {
	long long div = static_cast<unsigned long long>(val.major) * maxui + val.minor;
	return *this /= div;
}
Long& Long::operator%=(const Long& val) {
	long long div = static_cast<unsigned long long>(val.major) * maxui + val.minor;
	return *this %= div;
}
//==============================================================================================
template<typename T> Long& operator+(const T& val, const Long& lng) {
	Long temp = lng;
	return temp += val;
}
template<typename T> Long& operator-(const T& val, const Long& lng) {
	Long temp = lng;
	return temp -= val;
}
template<typename T> Long& operator*(const T& val, const Long& lng) {
	Long temp = lng;
	return temp *= val;
}
template<typename T> Long& operator/(const T& val, const Long& lng) {
	Long temp = lng;
	return temp /= val;
}
template<typename T> Long& operator%(const T& val, const Long& lng) {
	Long temp = lng;
	return temp %= val;
}
template<typename T> Long& operator+(const Long& lng, const T& val) {
	Long temp = lng;
	return temp += val;
}
template<typename T> Long& operator-(const Long& lng, const T& val) {
	Long temp = lng;
	return temp -= val;
}
template<typename T> Long& operator*(const Long& lng, const T& val) {
	Long temp = lng;
	return temp *= val;
}
template<typename T> Long& operator/(const Long& lng, const T& val) {
	Long temp = lng;
	return temp /= val;
}
template<typename T> Long& operator%(const Long& lng, const T& val) {
	Long temp = lng;
	return temp %= val;
}
Long& operator+(const Long& lng, const Long& rlng) {
	Long temp = lng;
	return temp += rlng;
}
Long& operator-(const Long& lng, const Long& rlng) {
	Long temp = lng;
	return temp -= rlng;
}
Long& operator*(const Long& lng, const Long& rlng) {
	Long temp = lng;
	return temp *= rlng;
}
Long& operator/(const Long& lng, const Long& rlng) {
	Long temp = lng;
	return temp /= rlng;
}
Long& operator%(const Long& lng, const Long& rlng) {
	Long temp = lng;
	return temp %= rlng;
}
//==============================================================================================
template<typename T> bool operator>(const Long& lng, const T& val) noexcept {
	return (static_cast<unsigned long long>(lng.major) * maxui + lng.minor > val);
}
template<typename T> bool operator<(const Long& lng, const T& val) noexcept {
	return (static_cast<unsigned long long>(lng.major) * maxui + lng.minor < val);
}
template<typename T> bool operator==(const Long& lng, const T& val) noexcept {
	return (!(static_cast<unsigned long long>(lng.major) * maxui + lng.minor == val));
}
template<typename T> bool operator>=(const Long& lng, const T& val) noexcept {
	return (lng > val || lng == val);
}
template<typename T> bool operator<=(const Long& lng, const T& val) noexcept {
	return (lng < val || lng == val);
}
template<typename T> bool operator!=(const Long& lng, const T& val) noexcept {
	return !(lng == val);
}
template<typename T> bool operator>(const T& val, const Long& lng) noexcept {
	return (lng < val);
}
template<typename T> bool operator<(const T& val, const Long& lng) noexcept {
	return (lng > val);
}
template<typename T> bool operator==(const T& val, const Long& lng) noexcept {
	return (lng == val);
}
template<typename T> bool operator>=(const T& val, const Long& lng) noexcept {
	return (lng <= val);
}
template<typename T> bool operator<=(const T& val, const Long& lng) noexcept {
	return (lng >= val);
}
template<typename T> bool operator!=(const T& val, const Long& lng) noexcept {
	return (lng != val);
}
bool operator>(const Long& lng, const Long& rlng) noexcept {
	if (lng.major == rlng.major) return (lng.minor > rlng.minor);
	return (lng.major > rlng.major);
}
bool operator==(const Long& lng, const Long& rlng) noexcept {
	return (lng.major == rlng.major && lng.minor == rlng.minor);
}
bool operator<(const Long& lng, const Long& rlng) noexcept { return (rlng > lng); }
bool operator>=(const Long& lng, const Long& rlng) noexcept { return (lng > rlng && lng == rlng); }
bool operator<=(const Long& lng, const Long& rlng) noexcept { return (rlng > lng && lng == rlng); }
bool operator!=(const Long& lng, const Long& rlng) noexcept { return !(lng == rlng); }

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	cout << "Самодуров ДИНРБ-21/2\nВариант 13\n\n\n";
	long long c = 1111111111111113LL;
	Long a = c;
	Long b = MAXULONG64 / 2;
	Long d = b;
	a /= 2570000;
	bool fd = a < b;
	b = 3 + a;
	cout << b << endl << a << endl << maxui;
	// 112344531 1382853550
	//	0 1348134384
	return 0;
}
