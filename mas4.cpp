#include <iostream>
#include <vector>

using namespace std;

// Рекурсивна функція для дублювання нулів у масиві
void duplicateZerosRecursive(vector<int>& arr, int index) {
    // Базовий випадок: якщо індекс виходить за межі масиву
    if (index >= arr.size()) return;

    // Якщо поточний елемент є нулем
    if (arr[index] == 0) {
        // Зрушуємо елементи вправо, починаючи з кінця
        for (int i = arr.size() - 1; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        // Дублюємо нуль
        if (index + 1 < arr.size()) {
            arr[index + 1] = 0;
        }
        // Пропускаємо наступний елемент, бо це дубльований нуль
        duplicateZerosRecursive(arr, index + 2);
    }
    else {
        // Переходимо до наступного елемента
        duplicateZerosRecursive(arr, index + 1);
    }
}

// Основна функція для виклику рекурсії
void duplicateZeros(vector<int>& arr) {
    duplicateZerosRecursive(arr, 0);
}

int main() {
    vector<int> arr1 = { 1, 0, 2, 3, 0, 4, 5, 0 };
    duplicateZeros(arr1);
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arr2 = { 1, 2, 3 };
    duplicateZeros(arr2);
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
