#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#pragma once
#include <cstdint>
#include <cmath>
#include <climits>
#include "Modulo.h"

using uchar = uint8_t;

class Time : private Modulo {
  private:

    Modulo hour, minute, second;

    string errors[1] {
        "Ошибка! Левый аргумент меньше правого аргумент!\n"
    };

  public:
    Time() noexcept;
    Time(const unsigned int& h, const unsigned int& m, const unsigned int& s) noexcept;
    Time(const unsigned int& m, const unsigned int& s) noexcept;
    Time(const unsigned int& s) noexcept;

    string toString() const noexcept;

    Time ConvertInTimeFromSeconds(const unsigned int& val) const noexcept;
    Time ConvertInTimeFromMinutes(const unsigned int& val) const noexcept;

    unsigned int ConvertInSeconds() const noexcept;
    unsigned short ConvertInMinutes() const noexcept;

    unsigned int Difference(const Time& rtm) const noexcept;

    Time operator-(const Time& rtm) const;
    Time operator+(const Time& rtm) const;
    Time operator-(const unsigned int& val) const;
    Time operator+(const unsigned int& val) const;

    bool operator>(const Time& rtm) const noexcept;
    bool operator<(const Time& rtm) const noexcept;
    bool operator==(const Time& rtm) const noexcept;
    bool operator>=(const Time& rtm) const noexcept;
    bool operator<=(const Time& rtm) const noexcept;
    bool operator!=(const Time& rtm) const noexcept;
};
ostream& operator<<(ostream& c, const Time& tm) noexcept;
istream& operator>>(istream& c, Time& tm);

#endif // TIME_H_INCLUDED
