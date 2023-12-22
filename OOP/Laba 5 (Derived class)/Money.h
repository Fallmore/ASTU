#ifndef MONEY_H_INCLUDED
#define MONEY_H_INCLUDED

#include "Pair.h"

class Money : public Pair {
private:
    Money kopToMoney(const long long k) noexcept;

    string errors[4] {
        "Ошибка! Левый аргумент меньше правого!",
        "Ошибка! Отрицательное значение!",
        "Ошибка! Деление на ноль!",
        "Ошибка! Отрицательное значение!"
    };
public:
    Money(const long long k = 0);

    string toString() const noexcept;

    Money setRub(const long long r);
    Money setKop(const long long k);

    Money operator+=(Money& rm);
    Money operator-=(const long long val);
    Money operator/=(const long long val);

    Money operator+(Money& rm) const;
    Money operator-(const long long val) const;
    Money operator/(const long long val) const;
};
ostream& operator<<(ostream& o, Money& m) noexcept;

#endif // MONEY_H_INCLUDED
