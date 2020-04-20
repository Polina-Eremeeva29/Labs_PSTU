#include <iostream>
#include <stdlib.h>

using namespace std;
int n, j;
int a[100];

int main ()
{
    setlocale(LC_ALL, "ru");

    cout << "Введите количество элементов массива: ";
    cin >> n;

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
     {
        cin >> a[i];
        cout << a[i] << " ";
     }
    cout << endl;
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            j = n;
            while (j > i)
            {
                a[j] = a[j - 1];
                j--;
            }
            a[i] = -1;
            i += 1;
            n += 1;
        }
    }
    cout << "Массив: ";
    for ( int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
