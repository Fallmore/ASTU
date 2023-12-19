#include "Time.h"

//==============================================================================================1
Time::Modulo::Modulo() noexcept : num(0), N(0) {};
Time::Modulo::Modulo(const int& _num, const int& _N) {
    if (_N == 0) throw std::underflow_error(errors[0]);
    num = _num; *this %= _N;
};
int Time::Modulo::GetNum() const noexcept { return num; }
int Time::Modulo::GetN()const noexcept { return N; };
//==============================================================================================
string Time::Modulo::toString() const noexcept {
    return "\nЧисло по модулю: " + to_string(num) + "\nМодуль: " + to_string(N);
}
ostream& operator<<(ostream& c, Time::Modulo const& mdl) noexcept {
    return (c << mdl.toString());
}
istream& operator>>(istream& in, Time::Modulo& mdl) {
    int n, N; in >> n >> N;
    if (in)
    {
        Time::Modulo temp(n,N);
        mdl = temp;
    }
    return in;
}
//==============================================================================================
Time::Modulo& Time::Modulo::operator+=(const int& val) {
    num += val; return *this %= N;
}
Time::Modulo& Time::Modulo::operator-=(const int& val) {
    num -= val; return *this %= N;
}
Time::Modulo& Time::Modulo::operator*=(const int& val) {
    num *= val; return *this %= N;
}
Time::Modulo& Time::Modulo::operator/=(const int& val) {
    if (val == 0) throw underflow_error(errors[1]);
    num /= val; return *this %= N;
}
Time::Modulo& Time::Modulo::operator%=(const int& val) {
    N = val, num %= N;
    if (num < 0) num += abs(N);
    return *this;
}
//==============================================================================================
Time::Modulo& Time::Modulo::operator++() {
    return *this += 1;
}
Time::Modulo Time::Modulo::operator++(int) {
    return *this += 1;
}
Time::Modulo& Time::Modulo::operator--() {
    return *this -= 1;
}
Time::Modulo Time::Modulo::operator--(int) {
    return *this -= 1;
}
Time::Modulo& Time::Modulo::operator+=(const Modulo& rmdl) {
    if (N < rmdl.N) throw overflow_error(errors[2]);
    num += rmdl.num; return *this %= N;
}
Time::Modulo& Time::Modulo::operator-=(const Modulo& rmdl) {
    if (N < rmdl.N) throw overflow_error(errors[2]);
    num -= rmdl.num; return *this %= N;
}
Time::Modulo& Time::Modulo::operator*=(const Modulo& rmdl) {
    if (N < rmdl.N) throw overflow_error(errors[2]);
    num *= rmdl.num; return *this %= N;
}
Time::Modulo& Time::Modulo::operator/=(const Modulo& rmdl) {
    if (N < rmdl.N) throw overflow_error(errors[2]);
    if (rmdl.num == 0) throw underflow_error(errors[1]);
    num /= rmdl.num; return *this %= N;
}
Time::Modulo& Time::Modulo::operator%=(const Modulo& rmdl) {
    if (N < rmdl.N) throw overflow_error(errors[2]);
    return *this %= rmdl.num;
}
//==============================================================================================
Time::Modulo operator+(const int& val, const Time::Modulo& rmdl) {
    Time::Modulo temp(val + rmdl.GetNum(), rmdl.GetN());
    return temp;
}
Time::Modulo operator-(const int& val, const Time::Modulo& rmdl) {
    Time::Modulo temp(val - rmdl.GetNum(), rmdl.GetN());
    return temp;
}
Time::Modulo operator*(const int& val, const Time::Modulo& rmdl) {
    Time::Modulo temp(val * rmdl.GetNum(), rmdl.GetN());
    return temp;
}
Time::Modulo operator/(const int& val, const Time::Modulo& rmdl) {
    Time::Modulo temp(val / rmdl.GetNum(), rmdl.GetN());
    return temp;
}
Time::Modulo operator%(const int& val, const Time::Modulo& rmdl) {
    Time::Modulo temp(val % rmdl.GetNum(), rmdl.GetN());
    return temp;
}
Time::Modulo operator+(const Time::Modulo& mdl, const int& val) {
    Time::Modulo temp = mdl;
    return temp += val;
}
Time::Modulo operator-(const Time::Modulo& mdl, const int& val) {
    Time::Modulo temp = mdl;
    return temp -= val;
}
Time::Modulo operator*(const Time::Modulo& mdl, const int& val) {
    Time::Modulo temp = mdl;
    return temp *= val;
}
Time::Modulo operator/(const Time::Modulo& mdl, const int& val) {
    Time::Modulo temp = mdl;
    return temp /= val;
}
Time::Modulo operator%(const Time::Modulo& mdl, const int& val) {
    Time::Modulo temp = mdl;
    return temp %= val;
}
Time::Modulo Time::Modulo::operator+(const Time::Modulo& rmdl) const {
    Time::Modulo temp = *this;
    return temp += rmdl;
}
Time::Modulo Time::Modulo::operator-(const Time::Modulo& rmdl) const {
    Time::Modulo temp = *this;
    return temp -= rmdl;
}
Time::Modulo Time::Modulo::operator*(const Time::Modulo& rmdl) const {
    Time::Modulo temp = *this;
    return temp *= rmdl;
}
Time::Modulo Time::Modulo::operator/(const Time::Modulo& rmdl) const {
    Time::Modulo temp = *this;
    return temp /= rmdl;
}
Time::Modulo Time::Modulo::operator%(const Time::Modulo& rmdl) const {
    Time::Modulo temp = *this;
    return temp %= rmdl;
}
//==============================================================================================
bool operator>(const Time::Modulo& mdl, const int& val) noexcept {
    return (mdl.GetNum() > val);
}
bool operator<(const Time::Modulo& mdl, const int& val) noexcept {
    return (mdl.GetNum() < val);
}
bool operator==(const Time::Modulo& mdl, const int& val) noexcept {
    return (mdl.GetNum()== val);
}
bool operator>=(const Time::Modulo& mdl, const int& val) noexcept {
    return (mdl > val || mdl == val);
}
bool operator<=(const Time::Modulo& mdl, const int& val) noexcept {
    return (mdl < val || mdl == val);
}
bool operator!=(const Time::Modulo& mdl, const int& val) noexcept {
    return !(mdl == val);
}
bool operator>(const int& val, const Time::Modulo& mdl) noexcept {
    return (mdl < val);
}
bool operator<(const int& val, const Time::Modulo& mdl) noexcept {
    return (mdl > val);
}
bool operator==(const int& val, const Time::Modulo& mdl) noexcept {
    return (mdl == val);
}
bool operator>=(const int& val, const Time::Modulo& mdl) noexcept {
    return (mdl <= val);
}
bool operator<=(const int& val, const Time::Modulo& mdl) noexcept {
    return (mdl >= val);
}
bool operator!=(const int& val, const Time::Modulo& mdl) noexcept {
    return (mdl != val);
}
bool Time::Modulo::operator>(const Modulo& rmdl) const noexcept {
    return (GetNum() > rmdl.GetNum());
}
bool Time::Modulo::operator==(const Modulo& rmdl) const noexcept {
    return (GetNum() == rmdl.GetNum());
}
bool Time::Modulo::operator<(const Modulo& rmdl) const noexcept {
    return (rmdl > *this);
}
bool Time::Modulo::operator>=(const Modulo& rmdl) const noexcept {
    return (*this > rmdl || *this == rmdl);
}
bool Time::Modulo::operator<=(const Modulo& rmdl) const noexcept {
    return (rmdl > *this || *this == rmdl);
}
bool Time::Modulo::operator!=(const Modulo& rmdl) const noexcept {
    return !(*this == rmdl);
}
//==============================================================================================
