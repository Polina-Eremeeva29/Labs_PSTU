#include <iostream>
#include <stdlib.h>

using namespace std;

int summa (int** a, int m)
{
    int i, j, s = 0;
    for (i = 0; i < m; i++)
    for (j = 0; j < m; j++)
        if (i > j)
        {
          s += a[i][j];
        }
    return s;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n,m;
    
    cout << "Введите количество матриц: ";
    cin >> n;
    
    cout << "Введите квадратную матрицу: ";
    cin >> m;
    
    int **a = new int*[m], i, j, *sum = new int[n], max, k;
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[m];
    }
    
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
            {
                a[i][j] = rand() % 100 - 50;
                cout << a[i][j] << "\t";
            }
        cout << endl;
        }
        cout << "____________" << endl;
       
        sum[k] = summa(a, m);
        cout << endl << sum[k] << endl << endl;
    }
    max = sum[0];
    for (i = 1; i < n; i++)
        if (sum[i] > max)
        {
            max = sum[i];
        }
    cout << "Максимальная сумма равна " << max << endl;
    return 0;
}
