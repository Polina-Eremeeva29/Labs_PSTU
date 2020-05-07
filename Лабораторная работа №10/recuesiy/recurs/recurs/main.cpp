#include <iostream>
#include <cmath>

using namespace std;

int NOD (int a, int b)
{
    int c;
    if (a < b)
      {
        b -= a;
        a += b;
        b = a - b;
      }
    c = a % b;
    if (c == 0) return b;
    else return NOD(b, c);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int a, b;
    
    cout << "Введите a и b: ";
    cin >> a >> b;
    
    cout << "Наибольший общий делитель a и b = " << NOD(a, b) << endl;
    
    return 0;
}
