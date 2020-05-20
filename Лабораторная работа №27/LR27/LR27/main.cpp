#include "file_work.hpp"
#include "Money.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    char Name[10] = "File.txt";
    make_file(Name);
    print_file(Name);
    Money num1;
    bool f;

    int t;
    int h;
    cout << "После какой записи добавить: ";
    cin >> t;
    cout << "Количество: ";
    cin >> h;
    int k;
    k = add_file(Name, t, h);
    if (k < 0) cout << "Can't read file";
    if (k == 0) k = add_end(Name);
    print_file(Name);
    cout << "Введите число для сравнения: " << endl;
    cin >> num1;
    f = comparison(Name, num1);
    if (f == true)
    {
        cout << "Есть число" << endl;
        cout << endl << "Уменьшено на 1,5: ";
        reduce_file(Name, num1);
    }
    else
    {
        cout << "Нет числа" << endl;
    }
    cout << endl << endl << endl;
}
