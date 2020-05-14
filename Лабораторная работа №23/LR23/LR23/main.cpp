#include <iostream>
#include "Vector.hpp"

using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    cout << "Создаем контейнер A с 5 элементами:\n";
    Vector a(5);
    cout << a << "\n";
    cin >> a;
    cout << a <<"\n";
    cout << "Элемент с индексом 2 равен 100:\n";
    a[2] = 100;
    cout << a << "\n";
    cout << "Создаем контейнер В с 10 элементами:\n";
    Vector b(10);
    cout << b << "\n";
    cout << "Приравниваем В к А:\n";
    b = a;
    cout << b << "\n";
    cout << "Создаем контейнер С с 10 элементами:\n";
    Vector c(10);
    cout << "Контейнер С равен перемноженым элементам А и В:\n";
    c = a * b;
    cout << c << "\n";
    cout << "Вывод длины А= " << a() << endl;
    cout << "Nачинаем работу с итератором(А)!\n\n";
    cout << "Выводим первый элемент:\n";
    cout << *(a.first()) << endl;
    Iterator it = a.first();
    cout << "Переходим ко второму элемнту:\n";
    it++;
    cout << *it << endl;
    cout << "Переходим еще через 2 элемнта:\n";
    it + 2;
    cout << *it << endl;
    cout << "Выводим все элементы контейнера:\n";
    for (it = a.first(); it != a.last(); it++) cout << *it << endl;
}
