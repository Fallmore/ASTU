#include "Time.h"

//==============================================================================================1
Modulo::Modulo() noexcept : num(0), N(0) {};
Modulo::Modulo(const int& _num, const int& _N) {
    if (_N == 0) throw std::underflow_error(errors[0]);
    num = _num; *this %= _N;
};
int Modulo::GetNum() const noexcept { return num; }
int Modulo::GetN()const noexcept { return N; };
//==============================================================================================
string Modulo::toString() const noexcept {
    return "\nЧисло по модулю: " + to_string(num) + "\nМодуль: " + to_string(N);
}
ostream& operator<<(ostream& c, Modulo const& mdl) noexcept {
    return (c << mdl.toString());
}
istream& operator>>(istream& in, Modulo& mdl) {
    int n, N; in >> n >> N;
    if (in)
    {
        Modulo temp(n,N);
        mdl = temp;
    }
    return in;
}
//==============================================================================================
Modulo& Modulo::operator+=(const int& val) {
    num += val; return *this %= N;
}
Modulo& Modulo::operator-=(const int& val) {
    num -= val; return *this %= N;
}
Modulo& Modulo::operator*=(const int& val) {
    num *= val; return *this %= N;
}
Modulo& Modulo::operator/=(const int& val) {
    if (val == 0) throw underflow_error(errors[1]);
    num /= val; return *this %= N;
}
Modulo& Modulo::operator%=(const int& val) {
    N = val, num %= N;
    if (num < 0) num += abs(N);
    return *this;
}
//==============================================================================================
Modulo& Modulo::operator++() {
    return *this += 1;
}
Modulo Modulo::operator++(int) {
    return *this += 1;
}
Modulo& Modulo::operator--() {
    return *this -= 1;
}
Modulo Modulo::operator--(int) {
    return *this -= 1;
}
Modulo& Modulo::operator+=(const Modulo& rmdl) {
    if (N < rmdl.N) throw overflow_error(errors[2]);
    num += rmdl.num; return *this %= N;
}
Modulo& Modulo::operator-=(const Modulo& rmdl) {
    if (N < rmdl.N) throw overflow_error(errors[2]);
    num -= rmdl.num; return *this %= N;
}
Modulo& Modulo::operator*=(const Modulo& rmdl) {
    if (N < rmdl.N) throw overflow_error(errors[2]);
    num *= rmdl.num; return *this %= N;
}
Modulo& Modulo::operator/=(const Modulo& rmdl) {
    if (N < rmdl.N) throw overflow_error(errors[2]);
    if (rmdl.num == 0) throw underflow_error(errors[1]);
    num /= rmdl.num; return *this %= N;
}
Modulo& Modulo::operator%=(const Modulo& rmdl) {
    if (N < rmdl.N) throw overflow_error(errors[2]);
    return *this %= rmdl.num;
}
//==============================================================================================
Modulo operator+(const int& val, const Modulo& rmdl) {
    Modulo temp(val + rmdl.GetNum(), rmdl.GetN());
    return temp;
}
Modulo operator-(const int& val, const Modulo& rmdl) {
    Modulo temp(val - rmdl.GetNum(), rmdl.GetN());
    return temp;
}
Modulo operator*(const int& val, const Modulo& rmdl) {
    Modulo temp(val * rmdl.GetNum(), rmdl.GetN());
    return temp;
}
Modulo operator/(const int& val, const Modulo& rmdl) {
    Modulo temp(val / rmdl.GetNum(), rmdl.GetN());
    return temp;
}
Modulo operator%(const int& val, const Modulo& rmdl) {
    Modulo temp(val % rmdl.GetNum(), rmdl.GetN());
    return temp;
}
Modulo operator+(const Modulo& mdl, const int& val) {
    Modulo temp = mdl;
    return temp += val;
}
Modulo operator-(const Modulo& mdl, const int& val) {
    Modulo temp = mdl;
    return temp -= val;
}
Modulo operator*(const Modulo& mdl, const int& val) {
    Modulo temp = mdl;
    return temp *= val;
}
Modulo operator/(const Modulo& mdl, const int& val) {
    Modulo temp = mdl;
    return temp /= val;
}
Modulo operator%(const Modulo& mdl, const int& val) {
    Modulo temp = mdl;
    return temp %= val;
}
Modulo Modulo::operator+(const Modulo& rmdl) const {
    Modulo temp = *this;
    return temp += rmdl;
}
Modulo Modulo::operator-(const Modulo& rmdl) const {
    Modulo temp = *this;
    return temp -= rmdl;
}
Modulo Modulo::operator*(const Modulo& rmdl) const {
    Modulo temp = *this;
    return temp *= rmdl;
}
Modulo Modulo::operator/(const Modulo& rmdl) const {
    Modulo temp = *this;
    return temp /= rmdl;
}
Modulo Modulo::operator%(const Modulo& rmdl) const {
    Modulo temp = *this;
    return temp %= rmdl;
}
//==============================================================================================
bool operator>(const Modulo& mdl, const int& val) noexcept {
    return (mdl.GetNum() > val);
}
bool operator<(const Modulo& mdl, const int& val) noexcept {
    return (mdl.GetNum() < val);
}
bool operator==(const Modulo& mdl, const int& val) noexcept {
    return (mdl.GetNum()== val);
}
bool operator>=(const Modulo& mdl, const int& val) noexcept {
    return (mdl > val || mdl == val);
}
bool operator<=(const Modulo& mdl, const int& val) noexcept {
    return (mdl < val || mdl == val);
}
bool operator!=(const Modulo& mdl, const int& val) noexcept {
    return !(mdl == val);
}
bool operator>(const int& val, const Modulo& mdl) noexcept {
    return (mdl < val);
}
bool operator<(const int& val, const Modulo& mdl) noexcept {
    return (mdl > val);
}
bool operator==(const int& val, const Modulo& mdl) noexcept {
    return (mdl == val);
}
bool operator>=(const int& val, const Modulo& mdl) noexcept {
    return (mdl <= val);
}
bool operator<=(const int& val, const Modulo& mdl) noexcept {
    return (mdl >= val);
}
bool operator!=(const int& val, const Modulo& mdl) noexcept {
    return (mdl != val);
}
bool Modulo::operator>(const Modulo& rmdl) const noexcept {
    return (GetNum() > rmdl.GetNum());
}
bool Modulo::operator==(const Modulo& rmdl) const noexcept {
    return (GetNum() == rmdl.GetNum());
}
bool Modulo::operator<(const Modulo& rmdl) const noexcept {
    return (rmdl > *this);
}
bool Modulo::operator>=(const Modulo& rmdl) const noexcept {
    return (*this > rmdl || *this == rmdl);
}
bool Modulo::operator<=(const Modulo& rmdl) const noexcept {
    return (rmdl > *this || *this == rmdl);
}
bool Modulo::operator!=(const Modulo& rmdl) const noexcept {
    return !(*this == rmdl);
}
//==============================================================================================
