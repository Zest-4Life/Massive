#include <iostream>
#include <vector>

using namespace std;

// Рекурсивна функція для знаходження максимальної кількості повторень 1-ці
int maxConsecutiveOnes(const vector<int>& nums, int index, int currentCount, int maxCount) {
    // Базовий випадок: якщо досягли кінця масиву
    if (index == nums.size()) {
        return max(maxCount, currentCount);
    }

    // Якщо поточний елемент дорівнює 1
    if (nums[index] == 1) {
        return maxConsecutiveOnes(nums, index + 1, currentCount + 1, maxCount);
    }
    else {
        // Якщо поточний елемент дорівнює 0
        return maxConsecutiveOnes(nums, index + 1, 0, max(maxCount, currentCount));
    }
}

// Основна функція для виклику рекурсії
int findMaxConsecutiveOnes(const vector<int>& nums) {
    return maxConsecutiveOnes(nums, 0, 0, 0);
}

int main() {
    vector<int> nums1 = { 1, 1, 0, 1, 1, 1 };
    cout << "Output: " << findMaxConsecutiveOnes(nums1) << endl; // Очікуваний результат: 3

    vector<int> nums2 = { 1, 0, 1, 1, 0, 1 };
    cout << "Output: " << findMaxConsecutiveOnes(nums2) << endl; // Очікуваний результат: 2

    return 0;
}
