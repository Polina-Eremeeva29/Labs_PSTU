#include <iostream> 
#include <string>

using namespace std;


bool f(const string& s, int i, int j) 
{
	if (s[j] != s[i])
	{
		return false;
	}
	if ((j - i) <= 1) 
	{
		return true;
	}
	f(s, i + 1, j - 1);
}

int main()
{
	setlocale(LC_ALL, "ru");
	int i, j;
	string s;
	cout << "Введите строку:\n";
	getline(cin, s);
	cout << "Введите интервал:\n";
	cout << "i = ";
	cin >> i;
	cout << "j = ";
	cin >> j;
	i--;
	j--;
	cout << "Вывод данных: " << f(s, i, j) << "\n";
	system("pause");
	return 0;
}
