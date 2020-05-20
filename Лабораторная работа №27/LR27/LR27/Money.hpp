#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Money {
private:
    long ruble;
    int penny;
public:
    Money();
    Money(long, int);
    Money(const Money&);
    ~Money() {};
    friend bool operator==(Money& a, Money& b);
    friend bool operator!=(Money& a, Money& b);
    friend Money operator-(Money& c, int);
    Money& operator++();
    Money operator++(int);
    friend ostream& operator <<(ostream& out_1, const Money& p);
    friend istream& operator >>(istream& in_1, Money& p);
    friend fstream& operator>>(fstream& in_2, Money& p);
    friend fstream& operator<<(fstream& out_2, const Money& p);
};
