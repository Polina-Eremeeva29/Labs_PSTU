#include <iostream>
#include <stdlib.h>

using namespace std;
int n, j = 0;
bool k = false;
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
     }

    while (k == false && j < n-1)
    {
        if (a[j] < a[j+1])
        { j++;
          k = false;
        }
        else
        {
            k = true;
        }

    }
    if (k == false)
    {
        cout << "Массив упорядочен по возрастанию";
    }
    else
    {
        cout << "Массив не упорядочен по возрастанию";
    }

}

