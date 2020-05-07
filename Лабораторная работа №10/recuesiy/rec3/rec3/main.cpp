#include <iostream>
using namespace std;
int NOD (int a, int b)
{
    if (b == 0)
        return a;
    if (a > b)
        return NOD (b, a % b);
    else
        return NOD (a, b % a);
}
 
int main ()
{
    setlocale (0, "");
    int a, b;
    cout << "Введите а и б: " << endl;
    cin >> a >> b;
    cout << "Наибольший общий делитель равен: " << NOD (b, a % b) << endl;
    
    cin.get();
    cin.get();
    return 0;
}
