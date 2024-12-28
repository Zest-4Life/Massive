#include <iostream>
#include <vector>

using namespace std;

// Рекурсивна функція для перевірки умови arr[i] == 2 * arr[j]
bool checkIfExistRecursive(const vector<int>& arr, int i, int j) {
    // Базовий випадок: якщо перевірили всі елементи
    if (i >= arr.size()) {
        return false;
    }
    if (j >= arr.size()) {
        return checkIfExistRecursive(arr, i + 1, 0);
    }

    // Пропускаємо випадок, коли i == j
    if (i != j && arr[i] == 2 * arr[j]) {
        return true;
    }

    // Переходимо до наступного j
    return checkIfExistRecursive(arr, i, j + 1);
}

// Основна функція для виклику рекурсії
bool checkIfExist(const vector<int>& arr) {
    return checkIfExistRecursive(arr, 0, 0);
}

int main() {
    vector<int> arr1 = { 10, 2, 5, 3 };
    cout << (checkIfExist(arr1) ? "true" : "false") << endl;

    vector<int> arr2 = { 3, 1, 7, 11 };
    cout << (checkIfExist(arr2) ? "true" : "false") << endl;

    return 0;
}
