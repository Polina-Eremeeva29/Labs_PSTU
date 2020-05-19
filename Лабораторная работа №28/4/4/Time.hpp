#include <iostream>
using namespace std;

class Time
{
    int min;
    int sec;
public:
    Time(void);
public:
    virtual ~Time(void);
    Time(long, int);
    Time(const Time&);
    long Get_min() { return min; }
    int Get_sec() { return sec; }
    void Set_min(long);
    void Set_sec(int);
    Time& operator=(const Time&);
    Time operator+(const Time&);
    Time operator/(const Time&);
    Time operator/(const int&);
    Time operator*(const Time&);
    Time operator*(const int&);
    bool operator >(const Time&);
    bool operator <(const Time&);
    friend istream& operator>>(istream& in, Time& c);
    friend ostream& operator<<(ostream& out, const Time& c);
    friend Time operator-(const Time& t, const Time& r);
};
Time::Time(void)
{
    min = 0;
    sec = 0;
}
Time::~Time(void)
{
}
Time::Time(long N, int S)
{
    int b, c;
    if (S >= 60)
    {
        b = S / 60;
        c = S % 60;
        S = c;
        N = N + b;
    }
    this->min = N;
    this->sec = S;
}
Time::Time(const Time& Time)
{
    min = Time.min;
    sec = Time.sec;
}
void Time::Set_sec(int C)
{
    sec = C;
}
void Time::Set_min(long M)
{
    min = M;

}
Time& Time::operator=(const Time& c)
{
    if (&c == this)return *this;
    min = c.min;
    sec = c.sec;
    return *this;
}
istream& operator>>(istream& in, Time& c)
{
    cout << "\nmin : "; in >> c.min;
    cout << "\nsec : "; in >> c.sec;
    return in;
}
ostream& operator<<(ostream& out, const Time& c)
{
    out << c.min << ':' << c.sec;
    out << "\n";
    return out;
}
bool Time::operator <(const Time& t)
{

    if (min < t.min)return true;
    if (min == t.min && sec < t.sec)return true;
    return false;
}
bool Time::operator >(const Time& t)
{
    if (min > t.min)return true;
    if (min == t.min && sec > t.sec)return true;
    return false;
}
Time Time::operator+(const Time& t)
{
    int temp1 = min * 60 + sec;
    int temp2 = t.min * 60 + t.sec;
    Time p;
    p.min = (temp1 + temp2) / 60;
    p.sec = (temp1 + temp2) % 60;
    return p;
}
Time Time::operator/(const Time& t)
{
    int temp1 = min * 60 + sec;
    int temp2 = t.min * 60 + t.sec;
    Time p;
    p.min = (temp1 / temp2) / 60;
    p.sec = (temp1 / temp2) % 60;
    return p;
}
Time Time::operator/(const int& t)
{
    int temp1 = min * 60 + sec;
    Time p;
    p.min = (temp1 / t) / 60;
    p.sec = (temp1 / t) % 60;
    return p;
}
Time Time::operator*(const Time& t)
{
    int temp1 = min * 60 + sec;
    int temp2 = t.min * 60 + t.sec;
    Time p;
    p.min = (temp1 * temp2) / 60;
    p.sec = (temp1 * temp2) % 60;
    return p;
}
Time Time::operator*(const int& t)
{
    int temp1 = min * 60 + sec;
    Time p;
    p.min = (temp1 * t) / 60;
    p.sec = (temp1 * t) % 60;
    return p;
}
Time operator-(const Time& t, const Time& r)
{
    int temp1 = t.min * 60 + t.sec;
    int temp2 = r.min * 60 + r.sec;
    Time p;
    p.min = (temp1 - temp2) / 60;
    p.sec = (temp1 - temp2) % 60;
    return p;
}
