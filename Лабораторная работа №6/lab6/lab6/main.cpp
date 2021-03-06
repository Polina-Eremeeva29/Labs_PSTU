#include <cmath>
#include <iostream>

using namespace std;

void iter() //Метод итераций
{
    double x = 0;
    double k = 0;
    double x0;
    int count = 0;

    do
    {
        x0 = x;
        x = (1 / (3 + sin(3.6 * x)));
        k += 0.000001;
        count++;
    }
    while (fabs(x0 - x) > 0.000001 && k <= 1);

    cout << x << endl;
    cout << "Количество итераций: " << count;
}

void newton() //Метод Ньютона
{
    double f, df, k = 0, x = 0;
    int count = 0;

    do
    {
        f = x - (1 / (3 + sin(3.6 * x)));
        df = 1 + (1 / ((3 + sin(3.6 * x)) * (3 + sin(3.6 * x)))) * cos(3.6 * x) * 3.6;
        x = x - f / df;
        k += 0.000001;
        count++;
    }
    while (fabs(f) > 0.000001 && k <= 0.85);

    cout << x << endl;
    cout << "Количество итераций: " << count;
}

double fun (double x)
{
    return x - (1 / (3 + sin(3.6 * x)));
}

double pold (double a = 0.0, double b = 0.85, double epsilant = 0.000001) //Метод половинного деления
{
    double mid = (a + b) / 2;
    double x = 0;
    int count = 0;

    if (abs (b - a) > epsilant)
    {
        if ((fun(a) * fun(mid)) <= 0)
        {
            mid = pold (a, mid);
        }
        else
        {
            mid = pold (mid, b);
        }
    }

    x = mid;
    return x;
}

int poldcount(double a = 0.0, double b = 0.85, double epsilant = 0.000001) //Метод половинного деления
{
    double mid = (a + b) / 2;
    double x = 0;
    int count = 0;

    if (abs(b - a) > epsilant)
    {
        if ((fun(a) * fun(mid)) <= 0)
        {
            mid = pold (a, mid);
        }
        else
        {
            mid = pold (mid, b);
        }
        count++;
    }
    return count;
}

int main()
{
    setlocale (LC_ALL, "ru");

    double x = 0;
    int count = 0;

    cout << endl;

    cout << "Метод итераций: ";
    iter();

    cout << endl << endl;

    cout << "Метод Ньютона: ";
    newton();

    cout << endl << endl;

    cout << "Метод половинного деления: " << pold(x) << endl << "Количество итераций: " << poldcount(count);
    
    cout << endl << endl << endl;

    return 0;
}
