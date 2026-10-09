#include "BitString.h"
#include <iostream>

using namespace std;

BitString::BitString()
{
	high = 0;
	low = 0;
}

bool BitString::Init(unsigned long h, unsigned long l)
{
	SetHigh(h);
	SetLow(l);
	return false;
}

void BitString::Read()
{
	unsigned long h, l;
	cout << "¬вед≥ть старшу частину (high): ";
	cin >> h;
	cout << "¬вед≥ть молодшу частину (low): ";
	cin >> l;
	Init(h, l);
}


string BitString::toString() const
{
	string res = "";

	for (int i = 31; i >= 0; i--)
	{
		if ((high >> i) & 1)
			res += "1";
		else
			res += "0";
	}
	res += "";
	for (int i = 31; i >= 0; i--)
	{
		if ((low >> i) & 1)
			res += "1";
		else
			res += "0";
	}
	return res;
}




void BitString::Display() const
{
	cout << toString() << endl;
}


BitString BitString::And(const BitString& other) const
{
	BitString res;
	res.Init(high & other.high, low & other.low);
	return res;
}

BitString BitString::Or(const BitString& other) const
{
	BitString res;
	res.Init(high | other.high, low | other.low);
	return res;

}

BitString BitString::Xor(const BitString& other) const
{
	BitString res;
	res.Init(high ^ other.high, low ^ other.low);
	return res;

}

BitString BitString::Not() const
{
	BitString res;
	res.Init(~high, ~low);
	return res;
}

BitString BitString::ShiftLeft(int n) const
{
	BitString res;
	if (n <= 0)
	{
		return *this;
	}
	if (n >= 64)
	{
		res.Init(0, 0);
		return res;
	}

	if (n < 32)
	{
		unsigned long newHigh = (high << n) | (low >> (32 - n));
		unsigned long newLow = low << n;
		res.Init(newHigh, newLow);
	}
	else
	{
		unsigned long newHigh = low << (n - 32);
		res.Init(newHigh, 0);
	}
	return res;
}

BitString BitString::ShiftRight(int n) const
{
	BitString res;
	if (n <= 0)
	{
		return *this;
	}
	if (n >= 64)
	{
		res.Init(0, 0);
		return res;
	}

	if (n < 32)
	{
		unsigned long newLow = (low >> n) | (high << (32 - n));
		unsigned long newHigh = high >> n;
		res.Init(newHigh, newLow);
	}
	return res;
}








