#include <iostream>
using namespace std;

int board[8][8];
int rcount = 0; //количество решений

//отображение доски
void Board()
{
    int k = 1;
    while (k < 9)
    {
        cout << k << "-ый шаг: " << endl;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout <<  "---------------" << endl;
        k++;
    }
}

//с
bool setQueen(int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        if (board[i][b]) return false; //проверка совпадений по горизонтали и вертикали
    }
    for (int i = 1; i <= a && b - i >= 0; i++)
    {
        if (board[a - i][b - i]) return false; //проверка главной диагонали
    }
    for (int i = 1; i <= a && b + i < 8; i++)
    {
        if (board[a - i][b + i]) return false; // проверка побочной диагонали
    }
    return true;
}

void Queen(int a)
{
    
    if (a == 8)
    {
        Board();
        ++rcount;
    }
    if (rcount == 1)
    {
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (setQueen(a, i))
        {
                board[a][i] = 1;
                Queen(a + 1);
                board[a][i] = 0;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "ru");
    Queen(0);
    return 0;
}
