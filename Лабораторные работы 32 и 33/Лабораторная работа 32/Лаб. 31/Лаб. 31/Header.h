#pragma once
#include <iostream>
#include <fstream>

using namespace std;
const int maxn = 100;
int mas[6][6];
int n, i, s, min, c, found;
int a[maxn][maxn];
int m[maxn], minm[maxn];
void _input()
{
    ifstream fin("matrix.txt");
    fin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> a[i][j];
}

void _output(int q, int n)
{
    if (found)
    {
        cout << "Вес минимального пути: " << min << endl;
        cout << "Путь: ";
        int c = 1;
        for (int i = 1; i <= n; i++)
        {
            int j = 1;
            while ((j <= n) &&
                (minm[j] != c)) j++;
            cout << j << "->";
            c++;
        }
        cout << minm[1] << endl;
    }
    else cout << "Путь не найден";
}
void search(int x, int n)
{
    if ((c == n) &&
        (a[x][1] != 0) &&
        (s + a[x][1] < min))
    {
        found = 1;
        min = s + a[x][1];
        for (int i = 1; i <= n; i++)minm[i] = m[i];
    }
    else
    {
        for (int i = 1; i <= n; i++)
            if ((i != x) &&
                (a[x][i] != 0) &&
                (m[i] == 0) &&
                (s + a[x][i] < min))
            {
                s += a[x][i];
                c++;
                m[i] = c;
                search(i, n);
                m[i] = 0;
                c--;
                s -= a[x][i];
            }
    }
}
void run(int q, int n)
{
    s = 0;
    found = 0;
    min = 32767;
    for (int i = 1; i <= n; i++) m[i] = 0;
    c = 1;
    m[q] = c;
    search(q, n);
}
