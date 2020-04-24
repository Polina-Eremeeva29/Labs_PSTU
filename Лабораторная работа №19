#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;
struct el {
double a;
el* r; el* l;
}; el*tek; el*first;

void add() {
    double k; int i = 1; first = new el; first-> a = 0.01 * (rand() % 101);
    cout << "Введите кол-во чисел для дерева: ";
    cin >> i;
    while(i > 0) {
        tek = first;
        k = 0.01 * (rand() % 101);
    
    while (tek->a != 0) {
        if (k >= tek->a) {
            if (tek->r == NULL) {
                tek->r = new el; tek = tek->r;
            }
            else {
                tek = tek->r;
            }
        }
        else
        if (tek->l == NULL) {
                tek->l = new el; tek = tek->l;
            }
            else {
                tek = tek->l;
            }
       }
        tek->a = k; cout << tek->a << endl; i--;
    }
}

double poisk (double l)
{
    tek = first; l = tek->a;
    while (tek->r != 0)
    {
        tek = tek->r;
    }
    l = tek->a; return l;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    
    int z = 1;
    cout << "1. Заполнить дерево случайными числами с плавающей точкой\n" << "2. Найти максимальное число\n" << "3. Выход" << endl;
    while (z != 0)
    {
        cin >> z;
        if (z == 1) {
            add();
        }
        else
            if (z==2) {
                cout << "Максимальное число в дереве: " << poisk(0) << endl;
            }
            else
                if (z == 0) {z = 0;}
    }
cout << "\nВы вышли.";
}
