#include "Money.h"

Money Money::kopToMoney(const long long k) noexcept {
    setFirst(k/100), setSecond(k%100);
    return *this;
}

Money::Money(const long long k) {
    if (k < 0) throw underflow_error(errors[3]);
    Pair(); *this = kopToMoney(k + getFirst()*100);
}

string Money::toString() const noexcept {
    return to_string(getFirst()) + " руб. " + to_string(getSecond()) + " коп.";
}

Money Money::setRub(const long long r) {
    if (r < 0) throw underflow_error(errors[3]);
    setFirst(r);    return *this;
}
Money Money::setKop(const long long k) {
    if (k < 0) throw underflow_error(errors[3]);
    return kopToMoney(k + getFirst()*100);
}

ostream& operator<<(ostream& o, Money& m) noexcept {
    return (o << m.toString());
}

Money Money::operator+=(Money& rm) {
    (*this).Pair::operator+=(rm); kopToMoney(getSecond() + getFirst()*100);
    return  *this;
}
Money Money::operator-=(const long long val) {
    if (val/100 > getFirst()) throw underflow_error(errors[0]);
    setRub(getFirst() - val/100), setKop(getSecond() - val%100);
    return *this;
}
Money Money::operator/=(const long long val) {
    if (val < 0) throw underflow_error(errors[1]);
    if (val == 0) throw underflow_error(errors[2]);
    long long t = static_cast<long long>((static_cast<unsigned long long>(getFirst()) * 100 + getSecond()) / val);
    return kopToMoney(t);
}

Money Money::operator+(Money& rm) const {
    Money a = *this;
    return a += rm;
}
Money Money::operator-(const long long val) const {
    Money a = *this;
    return a -= val;
}
Money Money::operator/(const long long val) const {
    Money a = *this;
    return a /= val;
}
