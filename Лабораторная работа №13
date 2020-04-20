#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main ()
{
    srand (time(NULL));
    setlocale(LC_ALL, "ru");
    
    int n, k, m, tmp;
    int *a = new int[100];
    
    cout << "Введите количество элементов массива: ";
    cin >> n;
    
    cout << "Данный массив: ";
    for (int i = 0; i < n; i++)
       {
           a[i] = rand() % 100-50;
           cout << a[i] << " ";
       }
    
    cout << endl << "Введите заданное значение: ";
    cin >> k;
    
    int *b = new int[n-1];
    int i = 0;
    bool flag = false;
    
    while (i < n && flag == false)
    {
        if (a[i] == k)
        {
            for (int j = i; j < n; j++)
            {
                b[j] = a[i+1];
                i++;
            }
            flag = true;
        }
        else
        {
            b[i] = a[i];
            i++;
        }
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        cout << b[i] << " ";
    }
    
    cout << endl << "Введите количество k сдвигов впрaво: ";
    cin >> m;
    
    m = m % (n-1);
    int p = 0;
    
       while (p++ < m)
       {
           tmp = b[n-2];
           for (int i = n - 2; i > 0; i--)
           {
               b[i] = b[i-1];
           }
           b[0] = tmp;
       }
        
    cout << "Конечный массив: ";
    for (int i = 0; i < n - 1; i++)
        {
            cout << b[i] << " ";
        }
        delete [] a;
        delete [] b;
        
        return 0;
}
