#ifndef PAIR_H_INCLUDED
#define PAIR_H_INCLUDED

#include <iostream>

using namespace std;

class Pair
{
private:
	long long first, second;

public:
	Pair(const long long f = 0, const long long s = 0) noexcept;

	string toString() const noexcept;

	long long getFirst() const noexcept;
	long long getSecond() const noexcept;

	Pair setFirst(const long long f) noexcept;
	Pair setSecond(const long long s) noexcept;

	Pair operator+=(Pair& rp);
	Pair operator+(Pair& rp) const;
};
ostream& operator<<(ostream& o, Pair& p) noexcept;
istream& operator>>(istream& i, Pair& p);

#endif // PAIR_H_INCLUDED
