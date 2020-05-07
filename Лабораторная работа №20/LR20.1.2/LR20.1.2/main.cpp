#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
class fraction
{
public:
    double first; //координата точки
    double second; //координата точки
    double distans (int first, int second, int x1, int y1)
    {
        double distans = sqrt((first - x1) * (first - x1) + (second - y1) * (second - y1));
        return distans;
    };
};

using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    fraction fr;
    cout << "Введите первую координату первой точки: \n";
    cin >> fr.first;
    cout << "Введите вторую координату первой точки: \n";
    cin >> fr.second;
    int x1, y1;
    cout << "Введите координаты второй точки: \n";
    cin >> x1 >> y1;
    double distans = fr.distans (fr.first, fr.second, x1, y1);
    cout << "Расстояние между точками: " << distans << endl;
}
