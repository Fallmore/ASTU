#ifndef HEADER_99F54CF457064E77
#define HEADER_99F54CF457064E77

#pragma once
#include <cstdint>
#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <cassert>

using namespace std;
using uint = uint32_t;
using ull = uint64_t;

constexpr uint maxui = UINT32_MAX;

class Long
{
private:
	uint major = 0, minor = 0;

	// �������� �� ������������ �������� �������
	bool overflowMinorSum(const long& val) const noexcept {
		return (minor > maxui - val);
	}
	bool overflowMinorMul(const long& val) const noexcept {
		return (minor > maxui / val);
	}
	// �������� �� ������������ �������� �������
	bool overflowMajorSum(const long& val = 1) const noexcept {
		return (major > maxui - val);
	}
	bool overflowMajorMul(const long& val) const noexcept {
		return (major > maxui / val);
	}
	string errors[4]{
		"������: ������� ������� ������������!",
		"������: ������� �� ����!",
		"������: ������� ������ ������������!",
		"������: ������� �� ������������� �����!"
	};
	// ��������� ����� ���������������� ������ unsigned int
	Long& AddULL(const ull& val)
	{
		uint temp = static_cast<uint>(val);
		if (val > maxui) {
			// ���� ���������� ������������
			ull count = val / maxui;
			if (major > maxui - val) throw overflow_error(errors[0]);
			// ��������� ���������� ������������ � ������� ������
			major += static_cast<uint>(count);
			// ������� ������� �� �������
			temp = static_cast<uint>(val % maxui);
		}
		minor = temp;
		return *this;
	}

public:
	Long() noexcept;
	Long(const string& val) noexcept;
	Long(const long& val) noexcept;
    class LongError{};
	Long(const char val);
	uint GetMajor() const noexcept;
	uint GetMinor() const noexcept;

	string toString() const noexcept;

	friend ostream& operator<<(ostream& c, const Long& lng) noexcept;
	friend ostream& operator<<(ostream& c,  Long const& major) noexcept;
	friend istream& operator>>(istream& c, Long& lng);

	Long& operator=(const long& val);
	Long& operator+=(const long& val);
	Long& operator-=(const long& val);
	Long& operator*=(const long& val);
	Long& operator/=(const long& val);
	Long& operator%=(const long& val);

	Long& operator++();
	Long operator++(int);
	Long& operator--();
	Long operator--(int);
	Long& operator+=(const Long& rlng);
	Long& operator-=(const Long& rlng);
	Long& operator*=(const Long& rlng);
	Long& operator/=(const Long& rlng);
	Long& operator%=(const Long& rlng);

	Long operator+(const Long& rlng) const;
	Long operator-(const Long& rlng) const;
	Long operator*(const Long& rlng) const;
	Long operator/(const Long& rlng) const;
	Long operator%(const Long& rlng) const;

	bool operator>(const Long& rlng) const noexcept;
	bool operator<(const Long& rlng) const noexcept;
	bool operator==(const Long& rlng) const noexcept;
	bool operator>=(const Long& rlng) const noexcept;
	bool operator<=(const Long& rlng) const noexcept;
	bool operator!=(const Long& rlng) const noexcept;
};
Long operator+(const long& val, const Long& lng);
Long operator-(const long& val, const Long& lng);
Long operator*(const long& val, const Long& lng);
Long operator/(const long& val, const Long& lng);
Long operator%(const long& val, const Long& lng);
Long operator+(const Long& lng, const long& val);
Long operator-(const Long& lng, const long& val);
Long operator*(const Long& lng, const long& val);
Long operator/(const Long& lng, const long& val);
Long operator%(const Long& lng, const long& val);

bool operator>(const Long& lng, const long& val) noexcept;
bool operator<(const Long& lng, const long& val) noexcept;
bool operator==(const Long& lng, const long& val) noexcept;
bool operator>=(const Long& lng, const long& val) noexcept;
bool operator<=(const Long& lng, const long& val) noexcept;
bool operator!=(const Long& lng, const long& val) noexcept ;
bool operator>(const long& val, const Long& lng) noexcept;
bool operator<(const long& val, const Long& lng) noexcept;
bool operator==(const long& val, const Long& lng) noexcept;
bool operator>=(const long& val, const Long& lng) noexcept;
bool operator<=(const long& val, const Long& lng) noexcept;
bool operator!=(const long& val, const Long& lng) noexcept;

#endif // header guard
