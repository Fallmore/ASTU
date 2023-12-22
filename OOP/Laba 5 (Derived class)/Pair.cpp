#include "Pair.h"

Pair::Pair(const long long f, const long long s) noexcept : first(f), second(s) {}

string Pair::toString() const noexcept {
    return to_string(first) + " " + to_string(second);
}

ostream& operator<<(ostream& o, Pair& p) noexcept {
    return (o << p.toString());
}
istream& operator>>(istream& i, Pair& p) {
    long long a, b;
    i >> a >> b;
    if (i) p.setFirst(a), p.setSecond(b);
    return i;
}

long long Pair::getFirst() const noexcept { return first; }
long long Pair::getSecond() const noexcept { return second; }

Pair Pair::setFirst(const long long f) noexcept { first = f; return *this; }
Pair Pair::setSecond(const long long s) noexcept { second = s; return *this; }

Pair Pair::operator+=(Pair& rp) {
    first += rp.first, second += rp.second;
    return *this;
}
Pair Pair::operator+(Pair& rp) const {
    Pair t = *this;
    return t += rp;
}
