#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int n;
int main ()
{
    cout << "Введите количество элементов: ";
    cin >> n;
    void** mass = new void* [n];
    mass [0] = new int [n];
    mass [1] = new float [n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> ((int*)mass[0])[i] >> ((float*)mass[1])[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ((int*)mass [0])[i] << '\t'<< ((float*)mass[1])[i] << endl;
    }
}
