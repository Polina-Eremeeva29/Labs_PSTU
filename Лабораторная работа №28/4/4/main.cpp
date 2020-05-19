#include "Time.hpp"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef stack<Time>st;
typedef vector<Time>Vec;
st make_stack(int n)
{
    st s;
    Time m;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        s.push(m);
    }
    return s;
}
void print_stack(st s) {
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}
Vec copy_stack(st s)
{
    Vec v;
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}
st copy_vector(Vec v)
{
    st s;
    for (int i = 0; i < v.size(); i++)
    {
        s.push(v[i]);
    }
    return s;
}
Time Srednee(st s)
{
    Vec v;
    int n = 1;
    Time sum = s.top();
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
void Add_sredn(st& s)
{
    Time z;
    Vec v = copy_stack(s);
    Time m = Srednee(s);
    v.push_back(m);
    s = copy_vector(v);
}
void Del_el(st& s, int pos)
{
    Vec v;
    Time m;
    Time k;
    int i = 1;
    while (!s.empty())
    {
        m = s.top();
        if (i != pos)v.push_back(m);
        s.pop();
        i++;
    }
    s = copy_vector(v);
}
Time Min(st s)
{
    Time m = s.top();
    Vec v = copy_stack(s);
    while (!s.empty())
    {
        if (s.top() < m)m = s.top();
        s.pop();
    }
    s = copy_vector(v);
    return m;
}
Time Max(st s)
{
    Time m = s.top();
    Vec v = copy_stack(s);
    while (!s.empty())
    {
        if (s.top() > m)m = s.top();
        s.pop();
    }
    s = copy_vector(v);
    return m;
}
void Razn(st& s)
{
    Time m = Min(s);
    m = m + Max(s);
    Vec v;
    Time t;
    while (!s.empty())
    {
        t = s.top();
        v.push_back(t - m);
        s.pop();
    }
    s = copy_vector(v);
}

int main() {
    setlocale(LC_ALL, "ru");
    Time z;
    Time m;
    st s;
    int    n;
    cout << "Количество элементов стека : ";
    cin >> n;
    s = make_stack(n);
    print_stack(s);
    cout << "Найти элемент с заданным ключом и удалить его из контейнера : ";
    int pos;
    cin >> pos;
    Del_el(s, pos);
    print_stack(s);
    cout << "Cреднее арифметическое в конеце контейнера : " << endl;
    Add_sredn(s);
    print_stack(s);
    cout << "Из каждого элемента вычесть разность максимального и минимального элементов контейнера : " << endl;
    Razn(s);
    print_stack(s);
}
