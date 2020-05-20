#include "Lots.hpp"
#include "Money.hpp"
#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Работаем с классом множество!\n";
    cout << "Создаем переменную А с 5 элементами:\n";
    Lots<int> a(5,0);
    cout << a << "\n";
    cin >> a;
    cout << a << "\n";
    cout << endl;
    cout << "Создаем переменную В с 10 элементами:\n";
    Lots<int> b(10,45);
    cout << b << "\n";
    cout << endl;
    cout << "Приравниваем В к А:\n";
    b = a;
    cout << b << "\n";
    cout << endl;
    cout << "Элемент переменной А с индексом 2 равен 100:\n";
    a[2] = 100;
    cout << endl;
    cout << "Создаем переменную С с 10 элементами\n";
    Lots<int> c(10,0);
    cout << endl;
    cout << "переменная С равена разности элементов B и A:\n";
    c = b - a;
    cout << c << "\n";
    cout << "Вывод длины А= " << a() << endl;

    cout << endl;
    cout << "Работаем с классом Money!\n";
    Money F;
    cin >> F;
    cout << F;
    cout << endl;
    Money L;
    cin >> L;
    cout << L;
    cout << endl;
    Money FL;
    FL = F - L;
    cout << FL;
    cout << endl;
    
    cout << "Выполним тестировани параметризированного класса Множество:\n";
    cout << "Для пользовательского типа данных Money:\n";
    cout << "Создаем переменную класса Money:\n";
    Money m;
    cin >> m;
    cout << m;
    cout << endl;
    cout << "Создаем переменную класса Множества с пользовательским типо данных Money:\n";
    Lots<Money>Al(5, m);
    cin >> Al;
    cout << Al << endl;
    cout << endl;
    cout << "Создаем вторую переменную класса Множества с пользовательским типо данных Money:\n";
    Lots<Money>Bl(10, m);
    cout << Bl << endl;
    cout << endl;
    cout << "Выводим 3 элемент первой переменной:\n";
    cout << Al[2] << endl;
    cout << "Размер первой переменной = " << Al() << endl;
    Lots<Money>Cl(10, m);
    cout << endl;
    cout << "Вычитаем из второй переменной элементы первой:\n";
    Cl = Bl - Al;
    cout << Cl;
    cout << endl;
    cout << "Приравниваем вторую переменную первой и выводи её:\n";
    Bl = Al;
    cout << Bl << endl;
}
