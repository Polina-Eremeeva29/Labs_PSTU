#include<iostream>
#include<stdlib.h>
#include<time.h>
 
using namespace std;
 
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
 
    int n,m;
 
    cout << "Введите количество строк: ";
    cin >> n;
    
    cout << "Введите количество столбцов: ";
    cin >> m;
    
    int**A = new int*[n]; // строк в массиве
    
    for (int i = 0; i < n; i++)
        A[i] = new int [m]; // столбцов в массиве
    
    
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
         {
            A[i][j] = rand() % 100;
            cout << A[i][j] << "\t";
         }
        cout << endl;
    }
    
    int k = 0;
    
    cout << "Введите количество строк для добавления: ";
    cin >> k;
    
    int nums;
    nums = n + k;
    
      int** B = new int* [nums]; // строк в массиве
    for (int i = 0; i < n + k; i++)
        B[i] = new int [m]; // столбцов в массиве
    
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            B[i][j] = rand() % 100 - 50;
        }
    }
    
    int g = 0;
    
     for (int i = n - 1; i < nums; i++)
    {
        for (int j = 0; j < m; j++)
         {
            B[i][j] = A[g][j];
             
         }
        g++;
    }
    
    for (int i = 0; i < n + k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << B[i][j] << '\t';
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[]B[i];
        delete[]A[i];
    }
    delete [] B;
    delete [] A;
    
    return 0;
}
