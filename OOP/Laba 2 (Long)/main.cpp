#include "Longtype.h"


string Long::toString() const noexcept {
    return to_string(static_cast<ull>(major) * maxui + minor);
}
ostream& operator<<(ostream& c, Long& lng) noexcept {
    return (c << lng.toString());
}
istream& operator>>(istream& c, Long& lng) {
    string s; c >> s;
    Long temp(s);
    lng = temp;
    return c;
}
//==============================================================================================
Long& Long::operator=(const long& val) {
    if (val < 0) throw underflow_error(errors[2]);
    major = 0, minor = static_cast<uint>(val);
    return *this;
}
Long& Long::operator+=(const long& val) {
    uint temp = static_cast<uint>(val);
    if (major == 0 && temp > minor && val < 0) throw underflow_error(errors[2]);
    if (val >= 0) {
        if (overflowMinorSum(temp)) {
            if (overflowMajorSum()) throw overflow_error(errors[0]);
            // Находим minor с учётом переполнения
            temp -= maxui - minor, minor = temp, ++major;
        } else minor += temp;
    } else *this -= abs(val);
    return *this;
}
Long& Long::operator-=(const long& val) {
    uint temp = static_cast<uint>(val);
    if (major == 0 && temp > minor && val > 0) throw underflow_error(errors[2]);
    if (val >= 0) {
        if (temp > minor) {
            if (major == 0) throw underflow_error(errors[2]);
            // Находим minor с учётом нижнего переполнения
            minor = maxui - (temp - minor), --major;
        } else minor -= temp;
    } else *this += abs(val);
    return *this;
}
Long& Long::operator*=(const long& val) {
    if (val < 0) throw underflow_error(errors[2]);
    uint temp = static_cast<uint>(val);
    major *= temp;
    AddULL(static_cast<ull>(temp) * minor);
    return *this;
}
Long& Long::operator/=(const long& val) {
    if (val == 0) throw underflow_error(errors[1]);
    if (val < 0) throw underflow_error(errors[3]);
    uint temp = static_cast<uint>(val);
    // Находим остаток от деления major
    double rest = static_cast<double>(major) / temp - (major / temp);
    double r = fmod(static_cast<double>(minor), temp);
    // Делим нацело.
    if (major != 0 && fmod(static_cast<double>(minor), temp) != static_cast<double>(temp) / 2)
        // В minor используем округление вверх, избавляясь от неточности +-1
        minor = static_cast<uint>(ceil(static_cast<double>(minor) / temp));
    else minor /= temp;
    major /= temp;
    // Прибавляем остаток к minor
    // Если rest будет больше 0.5, то у long будет переполнение
    if (rest > 0.5) rest -= 0.5, * this += static_cast<long>(rest * maxui);
    // rest <= 0.5
    *this += static_cast<long>(rest * maxui);
    return *this;
}
Long& Long::operator%=(const long& val) {
    Long templong = *this;
    // Делим нацело, затем умножаем обратно
    templong /= val, templong *= val;
    // Находим разницей остаток
    *this -= templong;
    return *this;
}
//==============================================================================================
Long& Long::operator++() {
    return *this += 1;
}
Long Long::operator++(int) {
    return *this += 1;
}
Long& Long::operator--() {
    return *this -= 1;
}
Long Long::operator--(int) {
    return *this -= 1;
}
Long& Long::operator+=(const Long& rlng) {
    if (overflowMajorSum(rlng.major)) throw overflow_error(errors[0]);
    major += rlng.major;
    uint temp = static_cast<uint>(rlng.minor);
    if (overflowMinorSum(temp)) {
        if (overflowMajorSum()) throw overflow_error(errors[0]);
        // Находим minor с учётом переполнения
        temp -= maxui - minor, minor = temp, ++major;
    } else minor += temp;
    return *this;
}
Long& Long::operator-=(const Long& rlng) {
    if (major < rlng.major) throw underflow_error(errors[2]);
    major -= rlng.major;
    uint temp = static_cast<uint>(rlng.minor);
    if (temp > minor) {
        if (major == 0) throw underflow_error(errors[2]);
        // Находим minor с учётом нижнего переполнения
        minor = maxui - (temp - minor), --major;
    } else minor -= temp;
    return *this;
}
Long& Long::operator*=(const Long& rlng) {
    ull mul1 = static_cast<ull>(major) * maxui + minor;
    ull mul2 = static_cast<ull>(rlng.major) * maxui + rlng.minor;
    *this = 0;
    return AddULL(mul1 * mul2);
}
Long& Long::operator/=(const Long& rlng) {
    ull dividend = static_cast<ull>(major) * maxui + minor;
    ull divider = static_cast<ull>(rlng.major) * maxui + rlng.minor;
    *this = 0;
    // Т.к. 2^64 / 2^32 = 2^32, то long не подходит диапазону (2^16;2^32]
    // И принято задействовать метод AddULL, включая во внимание случай 2^64 / [1;2^32)
    return AddULL(dividend / divider);
}
Long& Long::operator%=(const Long& rlng) {
    ull dividend = static_cast<ull>(major) * maxui + minor;
    ull divider = static_cast<ull>(rlng.major) * maxui + rlng.minor;
    *this = 0;
    return AddULL(dividend % divider);
}
//==============================================================================================
Long operator+(const long& val, const Long& lng) {
    Long temp = lng;
    return (temp += val);
}
Long operator-(const long& val, const Long& lng) {
    Long temp = lng;
    return temp = val - (static_cast<ull>(temp.GetMajor()) * maxui + temp.GetMinor());
}
Long operator*(const long& val, const Long& lng) {
    Long temp = lng;
    return temp *= val;
}
Long operator/(const long& val, const Long& lng) {
    Long temp = lng;
    return temp = val / (static_cast<ull>(temp.GetMajor()) * maxui + temp.GetMinor());
}
Long operator%(const long& val, const Long& lng) {
    Long temp = lng;
    return temp = val % (static_cast<ull>(temp.GetMajor()) * maxui + temp.GetMinor());
}
Long operator+(const Long& lng, const long& val) {
    Long temp = lng;
    return temp += val;
}
Long operator-(const Long& lng, const long& val) {
    Long temp = lng;
    return temp -= val;
}
Long operator*(const Long& lng, const long& val) {
    Long temp = lng;
    return temp *= val;
}
Long operator/(const Long& lng, const long& val) {
    Long temp = lng;
    return temp /= val;
}
Long operator%(const Long& lng, const long& val) {
    Long temp = lng;
    return temp %= val;
}
Long Long::operator=(const Long& rlng) {
    minor = rlng.minor, major = rlng.major;
    return *this;
}
Long Long::operator+(const Long& rlng) const {
    Long temp = *this;
    return temp += rlng;
}
Long Long::operator-(const Long& rlng) const {
    Long temp = *this;
    return temp -= rlng;
}
Long Long::operator*(const Long& rlng) const {
    Long temp = *this;
    return temp *= rlng;
}
Long Long::operator/(const Long& rlng) const {
    Long temp = *this;
    return temp /= rlng;
}
Long Long::operator%(const Long& rlng) const {
    Long temp = *this;
    return temp %= rlng;
}
//==============================================================================================
bool operator>(const Long& lng, const long& val) noexcept {
    return (static_cast<ull>(lng.GetMajor()) * maxui + lng.GetMinor() > val);
}
bool operator<(const Long& lng, const long& val) noexcept {
    return (static_cast<ull>(lng.GetMajor()) * maxui + lng.GetMinor() < val);
}
bool operator==(const Long& lng, const long& val) noexcept {
    return (static_cast<ull>(lng.GetMajor()) * maxui + lng.GetMinor() == val);
}
bool operator>=(const Long& lng, const long& val) noexcept {
    return (lng > val || lng == val);
}
bool operator<=(const Long& lng, const long& val) noexcept {
    return (lng < val || lng == val);
}
bool operator!=(const Long& lng, const long& val) noexcept {
    return !(lng == val);
}
bool operator>(const long& val, const Long& lng) noexcept {
    return (lng < val);
}
bool operator<(const long& val, const Long& lng) noexcept {
    return (lng > val);
}
bool operator==(const long& val, const Long& lng) noexcept {
    return (lng == val);
}
bool operator>=(const long& val, const Long& lng) noexcept {
    return (lng <= val);
}
bool operator<=(const long& val, const Long& lng) noexcept {
    return (lng >= val);
}
bool operator!=(const long& val, const Long& lng) noexcept {
    return (lng != val);
}
bool Long::operator>(const Long& rlng) const noexcept {
    if (major == rlng.major) return (minor > rlng.minor);
    return (major > rlng.major);
}
bool Long::operator==(const Long& rlng) const noexcept {
    return (major == rlng.major && minor == rlng.minor);
}
bool Long::operator<(const Long& rlng) const noexcept {
    return (rlng > *this);
}
bool Long::operator>=(const Long& rlng) const noexcept {
    return (*this > rlng || *this == rlng);
}
bool Long::operator<=(const Long& rlng) const noexcept {
    return (rlng > *this || *this == rlng);
}
bool Long::operator!=(const Long& rlng) const noexcept {
    return !(*this == rlng);
}
//==============================================================================================
void Tests() {
    try {
        Long a = 32313213;
        assert(a == 32313213);
        Long b = INT32_MAX;
        assert(b == INT32_MAX);
        Long c;
        assert(c == 0);
        Long d(b);
        assert(d == b);
        Long e("234234234234234");
        Long f("234234234234230");
        // Знаки сравнения
        assert(e < f == false);
        assert(e > f == true);
        assert(e <= f == false);
        assert(e >= f == true);
        assert(e <= f + 4 == true);
        assert(e >= f + 4 == true);
        assert(e != f == true);
        assert(c < 1 == true);
        assert(c > 1 == false);
        assert(c >= 1 == false);
        assert(c <= 1 == true);
        assert(c != 1 == true);
        assert(1 < c == false);
        assert(1 > c == true);
        assert(1 >= c == true);
        assert(1 <= c == false);
        assert(1 != c == true);
        // Арифметические операции. Слева Long
        assert(e == f + 4);
        assert(e - 4 == f);
        assert(e * 2 == f * 2 + 8);
        assert(e / 2 == f / 2 + 2);
        assert((e + 1) % 2 == 1);
        // Арифметические операции. Справа Long
        assert(e == 4 + f);
        assert(0 == 32313213 - a);
        assert(2 * a == 64626426);
        assert(64626426 / a == 2);
        assert(14 % a == 14);
        // Арифметические операции. Оба Long
        assert(a + a == 64626426);
        assert(0 == a - a);
        assert(a * c == 0);
        assert(a / a == 1);
        assert(a % a == 0);
        // Арифметические операции. C присваиванием
        c += f; assert(c == f);
        c += 4; assert(c == e);
        c -= 4; assert(c == f);
        c -= f - 1; assert(c == 1);
        c *= 2; assert(c == 2);
        c *= a; assert(c == 64626426);
        c /= a; assert(c == 2);
        c /= 2; assert(c == 1);
        c %= 6; assert(c == 1);
        c %= a; assert(c == 1);
        ++c; assert(c == 2);
        c++; assert(c == 3);
        --c; assert(c == 2);
        c--; assert(c == 1);
        cout << "Тест пройден!\n";
    } catch (const exception& e) {
        cerr << e.what();
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    cout << "Самодуров ДИНРБ-21/2\nВариант 13\n\n\n";
    Tests();
    Long a = 32313213;
    Long b = 2343242;
    Long d("4294967296");
    bool fd = a < b;
    a += d;
    a /= 2343242;
    cout << b << endl << a << endl << maxui;
    // 112244521 1282852550
    //	0 1248124284
    return 0;
}
