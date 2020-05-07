#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Variant9 (bool isStaticArray)
{
    srand (time(NULL));
    setlocale(LC_ALL, "ru");
    
    int n, p, K;
    int a[100];
    
    cout <<  "Введите количество элементов массива: ";
    cin >> n;
    
    for (int i = 0; i < n; i++)
       {
           a[i]=rand() % 100-50;
       }
       for (int i = 0; i < n; i++)
       {
           cout << a[i] << " ";
       }
       cout << endl;
    
    cout << "Введите заданное значение: ";
    cin >> p;
    
    for (int i = 0; i < n; i++)
    {
        if (int p = a[i])
        {
            for (int j = i; j < n-1; j++)
                a[j] = a[j+1];
            a[n-1] = 0;
            break;
        }
    }
    
    cout << "Введите значение К: ";
    cin >> K;
    
    for ( int j = n - 1; j > K -1; j--)
        a[j] = a[j - K];
    
    for ( int i = 0; i < n; i++)
        cout << a[i] << ' ';
}
