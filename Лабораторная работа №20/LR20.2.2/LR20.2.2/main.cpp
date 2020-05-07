#include <iostream>
#include <string>

using namespace std;
class sotrudnik {
public:
string FIO;
string dolgnost;
double mani;
    
sotrudnik() {
FIO = "Петров Иван Алексеевич";
dolgnost = "Менеджер по продажам";
mani = 40000;
};
    
sotrudnik (string a, string b, double c)
{
FIO = a;
dolgnost = b;
mani = c;
};
    
sotrudnik (const sotrudnik& p)
{
FIO = p.FIO;
dolgnost = p.dolgnost;
mani = p.mani;
};
    
~sotrudnik()
{
};
    
void print()
{
    cout << "Вывод\n";
    cout << "ФИО: " << FIO << endl;
    cout << "Должность: " << dolgnost << endl;
    cout << "Зарплата: " << mani << endl;
    cout << "\n\n";
}
};
    
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <iomanip>

    using namespace std;
    int main()
    {
        setlocale(LC_ALL, "ru");
        cout << "Консруктор с параметрами:\n\n";
        sotrudnik a("Митрошин Александр Питрович", "Зам. директора", 50000);
        a.print();
        cout << "Конструктор без параметров:\n\n";
        sotrudnik b;
        b.print();
        cout <<"Конструктор копирования:\n\n";
        sotrudnik c = a;
        c.print();
    }
