#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
int n;
bool q = false;
void push(vector<double>&, int);
void print(vector<double>&);
void modify_lst(vector<double>);
double sredn(vector<double>& l);
void del(vector<double>& l, double k);
void zad3(vector<double>&);

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");
    cout << "Найти среднее арифметическое и добавить его в конец контейнера\n";
    vector<double> l;
    cout << "Введите кол-во элементов контейнера: ";
    cin >> n;
    cout << endl;
    push(l, n);
    print(l);
    cout << endl;
    double s = sredn(l);
    l.push_back(s);
    print(l);
    cout << "\n---------------------------------------------------------\n";
    cout << "Найти элемент с заданным ключом и удалить его из контейнера\n";
    cout << "\nВведите искомый элемент: ";
    double k;
    cin >> k;
    del(l,k);
    print(l);
    cout << "\n---------------------------------------------------------\n";
    cout << "Из каждого элемента вычесть разность максимального и минимального элементов контейнера\n";
    zad3(l);
    print(l);
}

void push(vector<double>& l, int n)
{
    for (int i = 0; i < n; i++)
    {
        double a = rand() % 50-25;
        l.push_back(a*1.11);
    }

}

void print(vector<double>& l)
{
    cout << "Vector: ";
    for (vector<double>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it;
        cout << ' ';
    }
}


    
    
double sredn(vector<double>& l)
{
    double s = 0;//перебор вектора
    for (int i = 0; i < l.size();i++)
        s += l[i];
    int n = l.size();//количество элементов в векторе
    return s/n;
}

void del(vector<double>& l, double k)
{
    vector<double>::iterator it = l.begin();
    vector<double>::iterator w;
        for (vector<double>::iterator it = l.begin(); it != l.end(); it++)
        {
            if ((*it == k) && (q == false))
            {
                w = it;
                q = true;
            }
        }
        if (q == false)
        {
            cout << "Такого числа нет в контейнере!\n";
        }
        else
        {
            l.erase(w);
        }
}

void zad3(vector<double>& l)
{
    vector<double>::iterator it = l.begin();
    vector<double>::iterator z = it;
    vector<double>::iterator v = it;
    for (vector<double>::iterator it = l.begin(); it != l.end(); it++)
    {
        if (*z > * it)
        {
            z = it;
        }
    }
    double min = *z;
    for (vector<double>::iterator it = l.begin(); it != l.end(); it++)
    {
        if (*v < * it)
        {
            v = it;
        }
    }
    double max = *v;
    for (vector<double>::iterator it = l.begin(); it != l.end(); it++)
    {
        *it = (*it) - (max - min);
    }
}
