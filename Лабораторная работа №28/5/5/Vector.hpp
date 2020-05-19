#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template<class T> class Vector
{
    stack <T> s;
    int len;
public:
    Vector();
    Vector(int n);
    Vector(const Vector<T>&);
    void add(int pos);
    void print();
    T sredn();
    T add_sred();
    T max();
    T min();
    void razn();
};
template <class T>
vector<T> copy_stack(stack<T> s)
{
    vector<T> v;

    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}
template <class T>
stack<T> copy_vector(vector<T> v)
{
    stack<T> s;
    for (int i = 0; i < v.size(); i++)
    {
        s.push(v[i]);
    }
    return s;
}
template <class T>
Vector<T>::Vector()
{
    len = 0;
}
template <class T>
Vector<T>::Vector(int n)
{
    T a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s.push(a);
    }
    len = s.size();
}
template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
    vector<T> v;
    len = v.len;
    vector v = copy_stack(Vec.s);
    s = copy_vector(v);
}
template <class T>
void Vector<T>::add(int pos)
{
    vector <T>v;
    T t;
    int i = 1;
    while (!s.empty())
    {
        t = s.top();
        if (i != pos)v.push_back(t);
        s.pop();
        i++;
    }
    s = copy_vector(v);
}
template <class T>
void Vector<T>::print()
{
    vector<T> v = copy_stack(s);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    s = copy_vector(v);
}
template <class T>
T Vector<T>::sredn()
{
    vector<T> v = copy_stack(s);
    int n = 1;
    T sum = s.top();
    s.pop();
    while (!s.empty())
    {
        sum = sum + s.top();
        s.pop();
        n++;
    }
    s = copy_vector(v);
    return sum / n;
}


template <class T>
T Vector<T>::add_sred()
{
    T m = sredn();
    vector<T> v = copy_stack(s);
    T t;
    int i = 1;
    v.push_back(m);
    s = copy_vector(v);
    return m;
}
template <class T>
T Vector<T>::max()
{
    T m = s.top();

    vector<T> v = copy_stack(s);
    while (!s.empty())
    {
        if (s.top() > m)m = s.top();
        s.pop();
    }
    s = copy_vector(v);
    return m;
}
template <class T>
T Vector<T>::min()
{
    T m = s.top();
    vector<T> v = copy_stack(s);
    while (!s.empty())
    {
        if (s.top() < m)m = s.top();
        s.pop();
    }
    s = copy_vector(v);
    return m;
}
template <class T>
void Vector<T>::razn()
{
    T m = min();
    m = m + max();
    vector<T> v;
    T t;
    while (!s.empty())
    {
        t = s.top(); v.push_back(t - m);
        s.pop();
    }
    s = copy_vector(v);
}

