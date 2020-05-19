#include <iostream>
#include "Time.hpp"
#include <vector>
#include <cstdlib>

bool j = true;
using namespace std;

Time& Time::operator=(const Time& t)
{
    if (&t == this)return *this;
    min = t.min;
    sec = t.sec;
    return *this;
}

istream& operator>>(istream& in, Time& t)
{
    cout << "min?"; cin >> t.min;
    cout << "sec?"; cin >> t.sec;
    return in;
}

ostream& operator<<(ostream& out, const Time& t)
{
    return (out << t.min << " : " << t.sec);
}

bool Time::operator<(const Time& t)
{
    if (min < t.min)return true;
    if (min == t.min && sec < t.sec)return true;
    return false;
}

bool Time::operator>(const Time& t)
{
    if (min > t.min)return true;
    if (min == t.min && sec > t.sec)return true;
    return false;
}
Time operator*(const Time& t, const Time& r)
{
    int temp1 = t.min * 60 + t.sec;
    int temp2 = r.min * 60 + r.sec;
    Time p;
    p.min = (temp1 * temp2) / 60;
    p.sec = (temp1 * temp2) % 60;
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

typedef vector<Time>Vec;

Vec make_vector(int n)
{
    Vec v;
    for (int i = 0; i < n; i++)
    {
        Time a;
        cin >> a;
        v.push_back(a);
    }
    return v;
}

void print_vector(Vec v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

bool operator ==(const Time& a, const Time& b)
{
    int k = a.min * 60 + a.sec;
    int e = b.min * 60 + b.sec;
    if (k == e)
        return true;
    else
        return false;
}


void add_vector(Vec& v, int s, int pos)
{
    swap(v[s], v[pos]);
}

Vec srednee(Vec v)
{
    Time s;//переборвектора
    for (int i = 0; i < v.size();i++) {
        s = s + v[i];
    }
    int n = v.size();//количество элементов в векторе
    v.push_back(s / n);
    return v;
}

int elem(Vec v, int z)
{
    int m = 0;
    Time k = v[z];
    for (int i = 0; i < v.size(); i++)
    {
        if (k == v[i])
        {
            k = v[i];
            m = i;
        }

    }
    return m;
}
int min_elem(Vec v)
{
    int m = 0;
    Time k = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if (k > v[i])
        {
            k = v[i];
            m = i;
        }

    }
    return m;
}
int max_elem(Vec v)
{
    int m = 0;
    Time k = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if (k < v[i])
        {
            k = v[i];
            m = i;
        }

    }
    return m;
}
void raz(Vec& v, int m, int x)
{
    Time t = v[m];
    Time z = v[x];
    t = t + v[x];
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = v[i] - t;
    }

}



int main()
{
    int sw;
    setlocale(LC_ALL, "rus");
    try
    {
        vector<Time> v;

        vector<Time>::iterator vi = v.begin();
        int n;
        cout << "Задание 1\n";
        cout << "N?";
        cin >> n;
        v = make_vector(n);
        print_vector(v);
        if (j)
        {
            cout << "\nCреднее арифметическое в конец контейнера: ";
            v = srednee(v);
            print_vector(v);
            cout << "\n---------------------------------------------------------\n";
            cout << "Задание 2\n\n";
            cout << "\nВведите искомый элемент: ";
            int k;
            cin >> k;
            int Elem = elem(v, k);
            v.erase(v.begin() + Elem);
            print_vector(v);
            cout << "\n---------------------------------------------------------\n";
            cout << "Задание 3\n\n";
            int MIN = min_elem(v);
            int MAX = max_elem(v);
            raz(v, MIN, MAX);
            print_vector(v);
        }
        else
        {
            cout << "\nДанного объекта в векторе нет\n";
        }

    }
    catch (int)
    {
        cout << "error!";
    }

}
