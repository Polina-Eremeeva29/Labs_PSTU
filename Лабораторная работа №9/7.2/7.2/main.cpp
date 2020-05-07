#include <iostream>

using namespace std;

double max(double k, ...)
{
    double min = 0;
    double* p = &k;

    min = *p;

    for (; k != 0; k--)
    {
        if (min > * (++p))
        {
            min = *p;
        }
    }

    return min;
}

int max(int k, ...)
{
    int min = 0;
    int* p = &k;

    min = *p;

    for (; k != 0; k--)
    {
        if (min > * (++p))
        {
            min = *p;
        }
    }

    return min;
}

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "Min (6,12,10,11,4) = " << max(5,6,12,10,11,4) << endl << endl;

    cout << "Min (6,12,10,11,4,7,5,3,8,1) = " << max(10,6,12,10,11,4,7,5,3,8,1) << endl << endl;

    cout << "Min (6,12,10,11,4,7,5,3,8,2,16,14) = " << max(12,6,12,10,11,4,7,5,3,8,2,16,14) << endl << endl;

    cout << "Min (6.34,12.23,10.51,11.84,4.89) = " << max(5.0,6.34,12.23,10.51,11.84,4.89) << endl << endl << endl;
    
    return 0;
}
