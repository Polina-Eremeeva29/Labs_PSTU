#include <iostream>
#include "Tree.hpp"
#include "Print.hpp"
#include "Dialog.hpp"
#include "Magazin.hpp"
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "m: Создать группу\n+: Добавить элемент\n-: Удалить элемент\ns: Информация о членах группы\n";
    cout << "z: Информация о названиях элементов группы\nq: Конец работы\n";
    Dialog D;
    D.Execute();
}
