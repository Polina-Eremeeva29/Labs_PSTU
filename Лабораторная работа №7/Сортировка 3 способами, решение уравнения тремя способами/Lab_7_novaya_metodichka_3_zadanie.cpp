#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip> 
#include <string.h>

using namespace std;

template <typename T>
T Input(T mas[], int n)
{
	cout << "Введите 1 элемент массива: ";
	cin >> mas[0];
	cout << endl;

	for (int i = 1; i < n; i++)
	{
		cout << "Введите " << i + 1 << " элемент массива: ";
		cin >> mas[i];
		cout << endl;
	}
	return 0;
}

template <typename T1>
T1 Fun(T1 mas[], int n, T1 k) // метод пузырька с заданным числом
{
	int count = 0, h;
	T1 r = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > 0; j--)
		{
			if (mas[j - 1] > mas[j])
			{
				swap(mas[j - 1], mas[j]);
			}
		}
		count++;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (k == mas[i])
		{
			r = mas[i];
			h = i;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << "  ";
	}

	cout << endl << endl << "Количество итераций: " << count << endl << endl;

	if (r != 0)
	{
		cout << "Число: " << r << " индекс: " << h;
	}
	else
	{
		cout << "Такого числа нет";
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n, p;

	cout << "1 - int, 0 - double: ";
	cin >> p;

	if (p == 1)
	{
		int k;

		cout << "Введите размер массива: ";
		cin >> n;

		cout << endl;

		int* mas = new int[n];

		cout << "Введите число: ";
		cin >> k;

		cout << endl;

		cout << "Массив: " << endl;
		Input(mas, n);

		cout << endl << endl;

		cout << "Массив после преоброзования (метод пузырька): " << endl;
		Fun(mas, n, k);
	}
	else
	{
		double k;

		cout << "Введите размер массива: ";
		cin >> n;

		cout << endl;

		double* mas = new double[n];

		cout << "Введите число: ";
		cin >> k;

		cout << endl;

		cout << "Массив: " << endl;
		Input(mas, n);

		cout << endl << endl;

		cout << "Массив после преоброзования (метод пузырька): " << endl;
		Fun(mas, n, k);
	}

	cout << endl << endl << endl;

	return 0;
}