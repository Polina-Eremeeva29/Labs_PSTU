#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>

using namespace std;


void counting(int n, int* mas)
{
	const int k = 50;
	int c[k] = { 0 };
	for (int i = 0; i < n; i++) {
		c[mas[i]] = c[mas[i]] + 1;
	}

	int b = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < c[i]; j++) {
			mas[b] = i;
			b = b + 1;
		}
	}
}

void qsort(int* mas, int n)
{
	int i = 0;
	int j = n - 1;
	int mid = mas[n / 2];
	do
	{
		while (mas[i] < mid)
		{
			i++;
		}
		while (mas[j] > mid)
		{
			j--;
		}
		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
	{
		qsort(mas, j + 1);
	}

	if (i < n)
	{
		qsort(&mas[i], n - i);

	}
}
int* rand(int* mas, int n)
{
	cout << "Получившийся массив: ";
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 10 + 1;
		cout << mas[i] << " ";
	}
	cout << endl;
	return mas;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int n = 10, k = 0;
	int* mas = new int[n];
	do
	{
		cout << "\n-------------------------\n";
		cout << "1. Сортировка подсчётом\n" << "2. Быстрая сортировка\n" << "3. Выход\n";
		cout << "-------------------------\n";
		cin >> k;
		switch (k)
		{
		case 1:
		{
			rand(mas, n);
			clock_t start = clock();
			cout << "Сортировка подсчетом: ";
			counting(n, mas);
			for (int i = 0; i < n; i++)
			{
				cout << mas[i] << " ";
			}
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "\nВремя работы программы: " << seconds;
		}break;
		system("cls");
		case 2:
		{
			rand(mas, n);
			clock_t start = clock();
			cout << "Метод быстрой сортировки: ";
			qsort(mas, n);
			for (int i = 0; i < n; i++)
			{
				cout << mas[i] << " ";
			}
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "\nВремя работы программы: " << seconds;
		}break;
		system("cls");
		case 3:
			return 0;
			break;
		default:
			cout << "Ошибка, ввести нужно от 1 до 3, попробуйте еще раз!";
		}
	} while (k != 4);
}
