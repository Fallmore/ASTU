#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#pragma once
#include <cstdint>
#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

using uchar = uint8_t;

class Time {
  private:

    class Modulo {
      private:
        int num, N;

        string errors[3] {
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

        friend ostream& operator<<(ostream& c, const Modulo& mdl) noexcept;
        friend istream& operator>>(istream& c, Modulo& mdl);

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

    friend ostream& operator<<(ostream& c, const Time& tm) noexcept;
    friend istream& operator>>(istream& c, Time& tm);
    friend ostream& operator<<(ostream& c, const Modulo& mdl) noexcept;
    friend istream& operator>>(istream& c, Modulo& mdl);

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
//====================Modulo========================
    friend class ModuloTest; //Для тестов

    friend Modulo operator+(const int& val, const Modulo & mdl);
    friend Modulo operator-(const int& val, const Modulo & mdl);
    friend Modulo operator*(const int& val, const Modulo & mdl);
    friend Modulo operator/(const int& val, const Modulo & mdl);
    friend Modulo operator%(const int& val, const Modulo & mdl);
    friend Modulo operator+(const Modulo & mdl, const int& val);
    friend Modulo operator-(const Modulo & mdl, const int& val);
    friend Modulo operator*(const Modulo & mdl, const int& val);
    friend Modulo operator/(const Modulo & mdl, const int& val);
    friend Modulo operator%(const Modulo & mdl, const int& val);

    friend bool operator>(const Modulo & mdl, const int& val) noexcept;
    friend bool operator<(const Modulo & mdl, const int& val) noexcept;
    friend bool operator==(const Modulo & mdl, const int& val) noexcept;
    friend bool operator>=(const Modulo & mdl, const int& val) noexcept;
    friend bool operator<=(const Modulo & mdl, const int& val) noexcept;
    friend bool operator!=(const Modulo & mdl, const int& val) noexcept ;
    friend bool operator>(const int& val, const Modulo & mdl) noexcept;
    friend bool operator<(const int& val, const Modulo & mdl) noexcept;
    friend bool operator==(const int& val, const Modulo & mdl) noexcept;
    friend bool operator>=(const int& val, const Modulo & mdl) noexcept;
    friend bool operator<=(const int& val, const Modulo & mdl) noexcept;
    friend bool operator!=(const int& val, const Modulo & mdl) noexcept;
};

#endif // TIME_H_INCLUDED
