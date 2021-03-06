#include <iostream>
#include <stdlib.h>
#include <ctime>
    
using namespace std;

void Sum(float mas[], int n, float sum1)
{
    sum1 = 0;

    for (int i = 0; i < n; i++)
    {
        mas[i] = (rand() % 1000) * 0.01;
        cout << mas[i] << "  ";

        sum1 = sum1 + mas[i];
    }
    cout << endl << "Сумма десятичных дробей: " << sum1;
}

void Sum(double matrix[], int n, double sum2)
{
    sum2 = 0;
    double k = 0;

    for (int i = 0; i < n + n; i++)
    {
        matrix[i] = rand() % 100;
        cout << matrix[i] << "/";
        matrix[i + 1] = rand() % 100;
        cout << matrix[i + 1];
        cout << "   ";

        k = matrix[i] / matrix[i + 1];
        sum2 = sum2 + k;
        i++;
    }
    cout << endl << "Сумма обыкновенных дробей: " << sum2;
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int n, sum1 = 0, sum2 = 0;

    cout << "Введите количество чисел: ";
    cin >> n;
    
    float* mas = new float [n];
    double* matrix = new double [n * 2];

    cout << endl;
    Sum(mas, n, sum1);
    
    cout << endl;

    cout << endl;
    Sum(matrix, n, sum2);

    cout << endl << endl;
    
    return 0;
}
