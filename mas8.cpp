#include <iostream>
#include <vector>

using namespace std;

// Рекурсивна функція для перевірки строго зростаючої послідовності
bool isIncreasing(const vector<int>& arr, int index) {
    if (index == arr.size() - 1 || arr[index] >= arr[index + 1]) {
        return index > 0 && arr[index] > arr[index - 1];
    }
    return isIncreasing(arr, index + 1);
}

// Рекурсивна функція для перевірки строго спадної послідовності
bool isDecreasing(const vector<int>& arr, int index) {
    if (index == arr.size() - 1) {
        return true;
    }
    if (arr[index] <= arr[index + 1]) {
        return false;
    }
    return isDecreasing(arr, index + 1);
}

// Рекурсивна функція для пошуку вершини "гірського масиву"
bool isValidMountainArray(const vector<int>& arr) {
    if (arr.size() < 3) {
        return false;
    }

    int peakIndex = 0;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > arr[i - 1]) {
            peakIndex = i;
        }
        else {
            break;
        }
    }

    // Перевірка, чи вершина не є першою або останньою
    if (peakIndex == 0 || peakIndex == arr.size() - 1) {
        return false;
    }

    // Перевірка строго зростаючої та строго спадної частин
    return isIncreasing(arr, 0) && isDecreasing(arr, peakIndex);
}

int main() {
    vector<int> arr1 = { 2, 1 };
    cout << (isValidMountainArray(arr1) ? "true" : "false") << endl;

    vector<int> arr2 = { 3, 5, 5 };
    cout << (isValidMountainArray(arr2) ? "true" : "false") << endl;

    vector<int> arr3 = { 0, 3, 2, 1 };
    cout << (isValidMountainArray(arr3) ? "true" : "false") << endl;

    return 0;
}