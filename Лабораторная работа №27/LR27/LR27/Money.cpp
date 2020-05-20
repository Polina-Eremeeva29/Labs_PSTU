#include "Money.hpp"
#include <iostream>
#include <string>

using namespace std;
Money::Money()
{
    ruble = 0;
    penny = 0;
}
Money::Money(long rub, int pen)
{
    ruble = rub;
    penny = pen;
}
Money::Money(const Money& p)
{
    ruble = p.ruble;
    penny = p.penny;
}
bool operator==(Money& a, Money& b)
{
    if ((a.ruble == b.ruble) && (a.penny == b.penny))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator!=(Money& a, Money& b)
{
    if ((a.ruble != b.ruble) && (a.penny != b.penny))
    {
        return true;
    }
    else
    {
        return false;
    }
}
Money operator-(Money& c, int q)
{
    long k = c.ruble - 1;
    int t = c.penny - 5;
    c.ruble = k;
    c.penny = t;

    return c;
}
Money& Money::operator++()
{
    ++penny;
    return *this;
}
Money Money::operator++(int)
{
    Money temp(ruble, penny);
    long k = 0;
    k = temp.ruble * 100 + temp.penny;
    k++;
    temp.ruble = k / 100;
    temp.penny = k - ((k / 100) * 100);

    return temp;
}
ostream& operator<<(ostream& out_1, const Money& p)
{
    long k = 0;
    k = p.ruble * 100 + p.penny;
    out_1 << k / 100 << "," << k % 100 << "  ";
    return out_1;
}
istream& operator>>(istream& in_1, Money& p)
{
    cout << "Рубли: "; in_1 >> p.ruble;
    cout << "Копейки: "; in_1 >> p.penny;
    return in_1;
}
fstream& operator>>(fstream& in_2, Money& p)
{
    in_2 >> p.ruble;
    in_2 >> p.penny;
    return in_2;
}
fstream& operator<<(fstream& out_2, const Money& p)
{
    out_2 << p.ruble << endl << p.penny << endl;
    return out_2;
}
