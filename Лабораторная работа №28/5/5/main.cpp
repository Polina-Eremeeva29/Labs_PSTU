#include <iostream>
#include "Vector.hpp"
#include "Time.hpp"
#include <vector>
#include <stack>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    Vector<Time>v(3);
    v.print();
    cout << "Найти элемент с заданным ключом и удалить его из контейнера : ";
    int nom;
    cin >> nom;
    v.add(nom);
    v.print();
    cout << "Cреднее арифметическое в конеце контейнера : " << endl;
    v.add_sred();
    v.print();
    cout << "Из каждого элемента вычесть разность максимального и минимального элементов контейнера :" << endl;
    v.razn();
    v.print();

}
