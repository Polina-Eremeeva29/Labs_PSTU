#include <iostream>
#include <string>

using namespace std;
struct pacient
{
    string FIO;
    string adress;
    int numbermed;
    int numberstr;
};
int n;
pacient* arr = nullptr;

void create_arr();
void delete_elem(int zad_numbermed);
void new_elem();
void print_arr();

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите количество пациентов: ";
    cin >> n;
    arr = new pacient[n + 2];
    create_arr();
    cout << "Введите номер медецинской карты: \n";
    float zad_numbermed;
    cin >> zad_numbermed;
    delete_elem(zad_numbermed);
    print_arr();
    new_elem();
    print_arr();
}

void create_arr()
{
    cout << "Заполните структуру\n\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << endl;
        cout << "Фамилия: ";
        cin >> arr[i].FIO;
        cout << "Домашний адресс: ";
        cin >> arr[i].adress;
        cout << "Номер медецинской карты: ";
        cin >> arr[i].numbermed;
        cout << "Номер страхового полиса: ";
        cin >> arr[i].numberstr;
        cout << endl;
    }
}

void delete_elem(int zad_numbermed)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].numbermed <= zad_numbermed)
        {
            for (int j = i; j < n - 1; j++)
            {
                arr[i].FIO = arr[i + 1].FIO;
                arr[i].adress = arr[i + 1].adress;
                arr[i].numbermed = arr[i + 1].numbermed;
                arr[i].numberstr = arr[i + 1].numberstr;
            }
            n--;
        }
    }
}

void new_elem()
{
    n += 2;
    cout << "Введите еще 2 элемента\n\n";
    for (int k = n - 2; k < n; k++)
    {
        cout << "Фамилия: ";
        cin >> arr[k].FIO;
        cout << "Домашний адресс: ";
        cin >> arr[k].adress;
        cout << "Номер медецинской карты: ";
        cin >> arr[k].numbermed;
        cout << "Номер страхового полиса: ";
        cin >> arr[k].numberstr;
    }
}

void print_arr()
{
    cout << "\n\nВывод\n\n";
    for (int j = 0; j < n; j++)
    {
        cout << j + 1 << endl;
        cout << "Фамилия: " << arr[j].FIO << endl;
        cout << "Домашний адресс: " << arr[j].adress << endl;
        cout << "Номер медецинской карты: " << arr[j].numbermed << endl;
        cout << "Номер страхового полиса: " << arr[j].numberstr << endl;;
        cout << endl;
    }
}
