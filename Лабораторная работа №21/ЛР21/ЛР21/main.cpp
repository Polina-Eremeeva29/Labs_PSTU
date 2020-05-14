#include <iostream>

using namespace std;

class Triad
{
public:
    int* mas = new int[3];

    Triad()
    {
        this->mas[0];
        this->mas[1];
        this->mas[2];
    }

    Triad(int a, int b, int c)
    {
        cout << "Конструктор: " << this << endl;
        this->mas[0] = a;
        this->mas[1] = b;
        this->mas[2] = c;
    }

    Triad(Triad& p)
    {
        cout << "Конструктор: " << this << endl;
        this->mas[0] = p.mas[0];
        this->mas[1] = p.mas[1];
        this->mas[2] = p.mas[2];
    }

    ~Triad()
    {
        cout << endl << endl << "Дестркутор: " << this << endl;
        delete mas;
    }

    void sorting(int* array)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2 - i; j++)
            {
                if (array[j] > array[j + 1])
                {
                    swap(array[j], array[j + 1]);
                }
            }
        }
    }

    void output_1()
    {
        sorting(this->mas);
        cout << "Min: " << this->mas[0] << endl << "Med: " << this->mas[1] << endl << "Max: " << this->mas[2] << endl << endl;
    }

    void input()
    {
        cout << "Введите 1 число: ";
        cin >> this->mas[0];

        for (int i = 1; i < 3; i++)
        {
            cout << "Введите " << i + 1 << " число: ";
            cin >> this->mas[i];
        }
        cout << endl;
    }
};

class  Time :public Triad
{
public:
    int hours, minutes, seconds;

    Time(Triad& p)
    {
        this->hours = p.mas[0];
        this->minutes = p.mas[1];
        this->seconds = p.mas[2];
    }

    ~Time(){}

    void output_2()
    {
        cout << "Time: " << hours << ":" << minutes << ":" << seconds;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    int a = 0, b = 0, c = 0;

    Triad num1(4, 6, 2);
    num1.output_1();

    Triad num2(a,b,c);
    num2.input();
    num2.output_1();

    Time time(num2);
    time.output_2();
}
