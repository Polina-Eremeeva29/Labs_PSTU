#include<iostream>

using namespace std;

class Base
{
public:
    int first;
    int second;
    int third;
    virtual void input() = 0;
    virtual void output() = 0;
    virtual void output_1() = 0;
};


class Triad : public Base
{
public:
    Triad(int a, int b, int c)
    {
        cout << "Конструктор: " << this << endl;
        this->first = a;
        this->second = b;
        this->third = c;
    }

    Triad(const Triad& p)
    {
        cout << "Конструктор: " << this << endl;
        this->first = p.first;
        this->second = p.second;
        this->third = p.third;
    }

    ~Triad()
    {
        cout << endl << endl << "Дестркутор: " << this << endl << endl << endl;;
    }

    void input_1(Base* p)
    {
        p->output();
    }

    void sorting()
    {
        if (this->first > this->second) swap(this->first, this->second);
        if (this->first > this->third) swap(this->first, this->third);
        if (this->second > this->third) swap(this->second, this->third);
    }

    void input() override
    {
        cout << "Конструктор: " << this << endl;
        cout << "Введите 1 число: ";
        cin >> this->first;
        cout << "Введите 2 число: ";
        cin >> this->second;
        cout << "Введите 3 число: ";
        cin >> this->third;
        cout << endl;
    }

    void output() override
    {
        sorting();
        cout << "Min: " << first << endl << "Med: " << second << endl << "Max: " << third << endl << endl;
    }

    void output_1() override
    {
        cout << "Time: " << first << ":" << second << ":" << third;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    Triad input1(Base * p);
    Triad num1(4, 6, 2);
    num1.input_1(&num1);

    num1.input();
    num1.output();
    num1.output_1();
}
