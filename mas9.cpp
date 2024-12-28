#include <iostream>
#include <vector>

using namespace std;

// Рекурсивна функція для заміни елементів на найбільший елемент з правого боку
void replaceWithGreatestRecursive(vector<int>& arr, int index, int maxRight) {
    // Базовий випадок: якщо індекс досяг останнього елемента
    if (index < 0) {
        return;
    }

    // Зберігаємо поточне значення елемента
    int current = arr[index];

    // Замінюємо поточний елемент на найбільший з правого боку
    arr[index] = maxRight;

    // Оновлюємо найбільший елемент для наступного виклику
    maxRight = max(maxRight, current);

    // Рекурсивний виклик для попереднього елемента
    replaceWithGreatestRecursive(arr, index - 1, maxRight);
}

// Основна функція для виклику рекурсії
vector<int> replaceElements(vector<int>& arr) {
    replaceWithGreatestRecursive(arr, arr.size() - 1, -1);
    return arr;
}

int main() {
    vector<int> arr1 = { 17, 18, 5, 4, 6, 1 };
    vector<int> result1 = replaceElements(arr1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arr2 = { 400 };
    vector<int> result2 = replaceElements(arr2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}