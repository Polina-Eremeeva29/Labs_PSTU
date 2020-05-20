#include "Money.hpp"
#include <iostream>
#include <fstream>

int make_file(const char* file)
{
    fstream stream(file, ios::out | ios::trunc);
    if (!stream)return -1;
    Money m;
    int n;
    cout << "Количество: ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        stream << m << endl;
    }
    stream.close();
    return n;
}
int print_file(const char* file)
{
    fstream stream(file, ios::in);
    if (!stream)return -1;
    Money m;
    int i = 0;
    cout << endl;
    while (stream >> m)
    {
        cout << m << " ";
        i++;
    }
    cout << endl << endl;
    stream.close();
    return i;
}

bool comparison(const char* file, Money& c)
{
    fstream temp("temp", ios::out);
    fstream stream(file, ios::in);
    if (!stream)return -1;
    bool f = false;
    Money m;
    while (stream >> m)
    {
        if (stream.eof())break;
        if ((m == c))
        {
            temp << m;
            f = true;
        }
    }
    stream.close();
    temp.close();
    remove(file);
    rename("temp", file);
    return f;
}

void reduce_file(const char* f_name, Money& c)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    //if (!stream)return -1;
    int i = 0;
    Money m;
    while (stream >> m)
    {
        if (stream.eof())break;
        i++;
        if (m == c)
        {
            temp << m - 1;
            cout << m << " " << endl;
        }
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
}
int add_end(const char* f_name)
{
    int i = 0;
    fstream stream(f_name, ios::app);
    if (!stream)return -1;
    Money A;
    cout << "New object\n";
    cin >> A;
    stream << A;
    i++;
    return i;
}
int add_file(const char* f_name, int k, int v)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream)return -1;
    Money m;
    int x = 0;
    int i = 0;
    int l = 0;
    while (stream >> m)
    {
        if (stream.eof())break;
        if (i == k)
        {
            while (x < v)
            {
                Money mm;
                cin >> mm;
                temp << mm;
                x++;
                l++;
            }
        }
        i++;
        temp << m;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return l;
}
