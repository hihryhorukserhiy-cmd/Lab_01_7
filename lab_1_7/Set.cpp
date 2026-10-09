#include "Set.h"
#include <iostream>

using namespace std;

Set::Set()
{
    bits.Init(0, 0);
}

bool Set::Init()
{
    return bits.Init(0, 0);
}

bool Set::Init(const BitString& b)
{
    bits = b;
    return true;
}

bool Set::Include(int element)
{
    if (element < 0 || element > 63)
    {
        return false;
    }

    BitString mask;
    if (element < 32)
    {
        mask.Init(0, 1UL << element);
    }
    else
    {
        mask.Init(1UL << (element - 32), 0);
    }

    bits = bits.Or(mask); // Делегування операції Or об'єкту bits
    return true;
}

bool Set::Exclude(int element)
{
    if (element < 0 || element > 63)
    {
        return false;
    }

    BitString mask;
    if (element < 32)
    {
        mask.Init(0, 1UL << element);
    }
    else
    {
        mask.Init(1UL << (element - 32), 0);
    }

    bits = bits.And(mask.Not()); // Вимикаємо біт: bits AND NOT(mask)
    return true;
}

bool Set::Contains(int element) const
{
    if (element < 0 || element > 63)
    {
        return false;
    }

    if (element < 32)
    {
        return (bits.GetLow() >> element) & 1UL;
    }
    else
    {
        return (bits.GetHigh() >> (element - 32)) & 1UL;
    }
}

Set Set::Union(const Set& other) const
{
    Set res;
    res.SetBits(bits.Or(other.bits)); // Делегування
    return res;
}

Set Set::Intersection(const Set& other) const
{
    Set res;
    res.SetBits(bits.And(other.bits)); // Делегування
    return res;
}

Set Set::Difference(const Set& other) const
{
    Set res;
    // Різниця A \ B = A AND NOT(B)
    res.SetBits(bits.And(other.bits.Not()));
    return res;
}

int Set::Count() const
{
    int c = 0;
    unsigned long h = bits.GetHigh();
    unsigned long l = bits.GetLow();

    while (h > 0)
    {
        if (h & 1UL) c++;
        h >>= 1;
    }
    while (l > 0)
    {
        if (l & 1UL) c++;
        l >>= 1;
    }
    return c;
}

string Set::toString() const
{
    string s = "{ ";
    bool first = true;
    for (int i = 0; i <= 63; i++)
    {
        if (Contains(i))
        {
            if (!first)
            {
                s += ", ";
            }
            s += to_string(i);
            first = false;
        }
    }
    s += " }";
    return s;
}

void Set::Display() const
{
    cout << toString() << " (потужність: " << Count() << ")" << endl;
}

void Set::Read()
{
    Init();
    int n, val;
    cout << "Введіть кількість елементів для додавання в множину: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Елемент " << (i + 1) << " (0..63): ";
        cin >> val;
        if (!Include(val))
        {
            cout << "Помилка! Елемент має бути в межах [0..63].\n";
        }
    }
}