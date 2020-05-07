#include <iostream>
#include <stdlib.h>

using namespace std;

void outputArray(int* array, int lenght) {
    cout << "Массив: ";
    for (int i = 0; i < lenght; i++) cout << array[i] << '\t';
    cout << endl;
}

void inputArray(int* array, int lenght) {
    srand(time(0));
    for (int i = 0; i < lenght; i++) {
        array[i] = rand() % 101 - 50;
    }
    outputArray(array, lenght);
}

void insertion(int* array, int lenght) {
    for (int i = 1; i < lenght; i++) {
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {
            swap(array[j - 1], array[j]);
        }
    }
}
    
void bubble(int* array, int lenght) {
    for (int i = 0; i < lenght - 1; i++) {
        for (int j = 0; j < lenght - i - 1; j++) {
            if (array[j + 1] < array[j]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}
    
void selection(int* array, int lenght) {
    for (int i = 0; i < lenght - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < lenght; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap(array[i], array[min]);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int lenght, button = 1;
    
    while (0 < button && button < 4) {
        cout << "Введите количество элементов массива: ";
        cin >> lenght;
        int* array = new int[lenght];
        inputArray(array, lenght);
        
        cout << "Для сортировки \n- Методом вставки введите 1;\n- Методом пузырька введите 2;\n- Методом выбора введите 3;\n- Для выхода введите 4.\nВведите: ";
        cin >> button;
    
        if (button == 1) insertion(array, lenght);
        else if (button == 2) bubble(array, lenght);
        else if (button == 3) selection(array, lenght);
        outputArray(array, lenght);
    }
}
