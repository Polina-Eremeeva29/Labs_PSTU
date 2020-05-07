#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main ()
{
    srand (time(NULL));
    setlocale(LC_ALL, "ru");
    
    int n, k;
    int *a = new int[100];
    
    cout <<  "Введите количество элементов массива: ";
    cin >> n;
    
    for (int i = 0; i < n; i++)
       {
           a[i] = rand() % 100-50;
           cout << a[i] << " ";
       }
    
    k = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            k++;
        }
    }

    int *b = new int[k];
    int j = 0;
    
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                b[j] = a[i];
                j++;
            }
        }
    
    cout << endl << "Конечный массив: ";
    
    for (int i = 0; i < k; i++)
    {
        cout << b[i] << " ";
    }
    delete [] a;
    delete [] b;
    
    return 0;
}
