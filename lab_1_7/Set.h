#pragma once
#include "BitString.h"
#include <string>

class Set
{
private:
	BitString bits;
	 
public:
	Set();

	BitString GetBits() const { return bits; }
	void SetBits(const BitString& b) { bits = b; }
	
	bool Init();
	bool Init(const BitString& b);
	void Read();
	void Display() const;
	std::string toString() const;

	bool Include(int element);
	bool Exclude(int element);
	bool Contains(int element) const;

	Set Union(const Set& other) const;
	Set Intersection(const Set& other) const;
	Set Difference(const Set& other) const;

	int Count() const;

};

