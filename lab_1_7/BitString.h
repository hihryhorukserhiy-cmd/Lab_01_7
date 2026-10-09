#pragma once
#include <string> 

class BitString
{
private:
	unsigned long high;
	unsigned long low;

public:
	BitString();

	unsigned long GetHigh() const { return high; }
	unsigned long GetLow() const { return low;  }

	void SetHigh(unsigned long value) { high = value; }
	void SetLow(unsigned long value) { low = value; }

	bool Init(unsigned long h, unsigned long l);
	void Read();
	void Display() const;
	std::string toString() const;

	BitString And(const BitString& other) const;
	BitString Or(const BitString& other) const;
	BitString Xor(const BitString& other) const;
	BitString Not() const;

	BitString ShiftLeft(int n) const;
	BitString ShiftRight(int n) const;


};

