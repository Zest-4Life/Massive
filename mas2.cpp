#include <iostream>
#include <vector>

using namespace std;

// Рекурсивна функція для підрахунку кількості цифр у числі
int countDigits(int num) {
    if (num == 0) return 0;
    return 1 + countDigits(num / 10);
}

// Рекурсивна функція для підрахунку чисел з парною кількістю цифр
int countEvenDigitNumbers(const vector<int>& nums, int index, int count) {
    // Базовий випадок: якщо досягли кінця масиву
    if (index == nums.size()) {
        return count;
    }

    // Перевірка кількості цифр у поточному числі
    if (countDigits(nums[index]) % 2 == 0) {
        return countEvenDigitNumbers(nums, index + 1, count + 1);
    }
    else {
        return countEvenDigitNumbers(nums, index + 1, count);
    }
}

// Основна функція для виклику рекурсії
int findNumbersWithEvenDigits(const vector<int>& nums) {
    return countEvenDigitNumbers(nums, 0, 0);
}

int main() {
    vector<int> nums1 = { 12, 345, 2, 6, 7896 };
    cout << "Output: " << findNumbersWithEvenDigits(nums1) << endl; // Очікуваний результат: 2

    vector<int> nums2 = { 555, 901, 482, 1771 };
    cout << "Output: " << findNumbersWithEvenDigits(nums2) << endl; // Очікуваний результат: 1

    return 0;
}