#include <iostream>
#include "Pair.hpp"

using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    Pair a;
    Pair b;
    Pair c;
    cout << "Ввод переменной a" << endl;
    cin >> a;
    cout << "Ввод переменной b" << endl;
    cin >> b;
    a = --a;
    cout << "a = " << a;
    b = b--;
    cout << "b = " << b;
    cout << "a < b?\t";
    c = a < b;
    cout << "b > a?\t";
    c = b > a;
}
