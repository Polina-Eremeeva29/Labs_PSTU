#include <iostream>
#include <stdlib.h>

using namespace std;
int a[100];
int n, d, i = 1;

int main ()
{
    setlocale(LC_ALL, "ru");

    cout << "Введите количество элементов массива: ";
    cin >> n;

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
     {
        cin >> a[i];
     }

    while (i < n+n/2)
    {
        for (int j = (n+n/2)-1; j >= i; j--)
        {
            a[j + 1] = a[j];
        }
        a[i] = -1;
        i = i + 3;
    }
    for (int i = 0; i < n+n/2; i++)
    {
        cout << a[i] << " ";
    }
}
