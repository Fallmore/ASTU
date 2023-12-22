#ifndef MODULO_H_INCLUDED
#define MODULO_H_INCLUDED

#pragma once
#include <iostream>

using namespace std;

class Modulo
{
private:
    int num, N;

    string errors[3]{
        "Ошибка! Модуль не может быть нулём!\n",
        "Ошибка! Деление на ноль!\n",
        "Ошибка! Модуль левого аргумента меньше правого аргумента!\n"
    };
public:
	Modulo() noexcept;
	Modulo(const int& _num, const int& _N);

	int GetNum()const noexcept;
	int GetN()const noexcept;

	string toString() const noexcept;

	Modulo& operator+=(const int& mdl);
	Modulo& operator-=(const int& mdl);
	Modulo& operator*=(const int& mdl);
	Modulo& operator/=(const int& mdl);
	Modulo& operator%=(const int& mdl);

	Modulo& operator++();
	Modulo operator++(int);
	Modulo& operator--();
	Modulo operator--(int);
	Modulo& operator+=(const Modulo& rmdl);
	Modulo& operator-=(const Modulo& rmdl);
	Modulo& operator*=(const Modulo& rmdl);
	Modulo& operator/=(const Modulo& rmdl);
	Modulo& operator%=(const Modulo& rmdl);

	Modulo operator+(const Modulo& rmdl) const;
	Modulo operator-(const Modulo& rmdl) const;
	Modulo operator*(const Modulo& rmdl) const;
	Modulo operator/(const Modulo& rmdl) const;
	Modulo operator%(const Modulo& rmdl) const;

	bool operator>(const Modulo& rmdl) const noexcept;
	bool operator<(const Modulo& rmdl) const noexcept;
	bool operator==(const Modulo& rmdl) const noexcept;
	bool operator>=(const Modulo& rmdl) const noexcept;
	bool operator<=(const Modulo& rmdl) const noexcept;
	bool operator!=(const Modulo& rmdl) const noexcept;
};
ostream& operator<<(ostream& c, const Modulo& mdl) noexcept;
istream& operator>>(istream& c, Modulo& mdl);

Modulo operator+(const int& val, const Modulo& mdl);
Modulo operator-(const int& val, const Modulo& mdl);
Modulo operator*(const int& val, const Modulo& mdl);
Modulo operator/(const int& val, const Modulo& mdl);
Modulo operator%(const int& val, const Modulo& mdl);
Modulo operator+(const Modulo& mdl, const int& val);
Modulo operator-(const Modulo& mdl, const int& val);
Modulo operator*(const Modulo& mdl, const int& val);
Modulo operator/(const Modulo& mdl, const int& val);
Modulo operator%(const Modulo& mdl, const int& val);

bool operator>(const Modulo& mdl, const int& val) noexcept;
bool operator<(const Modulo& mdl, const int& val) noexcept;
bool operator==(const Modulo& mdl, const int& val) noexcept;
bool operator>=(const Modulo& mdl, const int& val) noexcept;
bool operator<=(const Modulo& mdl, const int& val) noexcept;
bool operator!=(const Modulo& mdl, const int& val) noexcept ;
bool operator>(const int& val, const Modulo& mdl) noexcept;
bool operator<(const int& val, const Modulo& mdl) noexcept;
bool operator==(const int& val, const Modulo& mdl) noexcept;
bool operator>=(const int& val, const Modulo& mdl) noexcept;
bool operator<=(const int& val, const Modulo& mdl) noexcept;
bool operator!=(const int& val, const Modulo& mdl) noexcept;

#endif // MODULO_H_INCLUDED
