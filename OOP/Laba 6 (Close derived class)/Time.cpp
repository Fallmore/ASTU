#include "Time.h"

//==============================================================================================
Time::Time() noexcept : hour(0, 24), minute(0, 60), second(0, 60) {};
Time::Time(const unsigned int& h, const unsigned int& m, const unsigned int& s) noexcept : hour(0, 24), minute(0, 60), second(s, 60) {
    minute += s / 60 + m;
    hour += s / 3600 + m / 60 + h;
}
Time::Time(const unsigned int& m, const unsigned int& s) noexcept {
    Time temp(0, m, s);
    *this = temp;
}
Time::Time(const unsigned int& s) noexcept {
    Time temp(0, 0, s);
    *this = temp;
}
//==============================================================================================
string Time::toString() const noexcept {
    string space = "";
    return (hour.GetNum() > 9 ? space : "0" ) + to_string(hour.GetNum()) +
        ":" + (minute.GetNum() > 9 ? space :  "0") + to_string(minute.GetNum()) +
        ":" + (second.GetNum() > 9 ? space :  "0") + to_string(second.GetNum());
}
ostream& operator<<(ostream& c, Time const& tm) noexcept {
    return (c << tm.toString());
}
istream& operator>>(istream& in, Time& tm) {
    int h, m, s;
    in >> h >> m >> s;
    if (in) {
        Time temp(h, m, s);
        tm = temp;
    }
    return in;
}
//==============================================================================================
Time Time::ConvertInTimeFromSeconds(const unsigned int& val) const noexcept {
    return Time(val);
}
Time Time::ConvertInTimeFromMinutes(const unsigned int& val) const noexcept {
    return Time(val, 0);
}
//==============================================================================================
unsigned int Time::ConvertInSeconds() const noexcept {
    return hour.GetNum() * minute.GetN() * second.GetN()  + minute.GetNum() * second.GetN()  + second.GetNum();
}
unsigned short Time::ConvertInMinutes() const noexcept {
    return static_cast<unsigned short>(round(static_cast<float>(ConvertInSeconds()) / minute.GetN()));
}
//==============================================================================================
unsigned int Time::Difference(const Time& rtm) const noexcept {
    return (*this > rtm ? ConvertInSeconds() - rtm.ConvertInSeconds() : rtm.ConvertInSeconds() - ConvertInSeconds());
}
//==============================================================================================
Time Time::operator-(const Time& rtm) const {
    return *this - rtm.ConvertInSeconds();
}
Time Time::operator+(const Time& rtm) const {
    return *this + rtm.ConvertInSeconds();
}
Time Time::operator-(const unsigned int& val) const {
    if (ConvertInSeconds() < val) throw underflow_error(errors[0]);
    return ConvertInTimeFromSeconds(ConvertInSeconds() - val);
}
Time Time::operator+(const unsigned int& val) const {
    return ConvertInTimeFromSeconds(ConvertInSeconds() + val);
}
//==============================================================================================
bool Time::operator>(const Time& rtm) const noexcept {
    return ConvertInSeconds() > rtm.ConvertInSeconds();
}
bool Time::operator<(const Time& rtm) const noexcept {
    return ConvertInSeconds() < rtm.ConvertInSeconds();
}
bool Time::operator==(const Time& rtm) const noexcept {
    return ConvertInSeconds() == rtm.ConvertInSeconds();
}
bool Time::operator>=(const Time& rtm) const noexcept {
    return !(*this < rtm);
}
bool Time::operator<=(const Time& rtm) const noexcept {
    return !(*this > rtm);
}
bool Time::operator!=(const Time& rtm) const noexcept {
    return !(*this == rtm);
}
