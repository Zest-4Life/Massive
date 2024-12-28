#include <iostream>
#include <vector>

using namespace std;

// Рекурсивна функція для видалення дублікатів з відсортованого масиву
int removeDuplicatesRecursive(vector<int>& nums, int current, int writeIndex) {
    // Базовий випадок: якщо досягли кінця масиву
    if (current >= nums.size()) {
        return writeIndex;
    }

    // Якщо поточний елемент не дублюється, записуємо його
    if (current == 0 || nums[current] != nums[current - 1]) {
        nums[writeIndex] = nums[current];
        return removeDuplicatesRecursive(nums, current + 1, writeIndex + 1);
    }

    // Пропускаємо дублікати
    return removeDuplicatesRecursive(nums, current + 1, writeIndex);
}

// Основна функція для виклику рекурсії
int removeDuplicates(vector<int>& nums) {
    return removeDuplicatesRecursive(nums, 0, 0);
}

int main() {
    vector<int> nums1 = { 1, 1, 2 };
    int k1 = removeDuplicates(nums1);
    cout << "k = " << k1 << ", nums = ";
    for (int i = 0; i < k1; ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    vector<int> nums2 = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int k2 = removeDuplicates(nums2);
    cout << "k = " << k2 << ", nums = ";
    for (int i = 0; i < k2; ++i) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}
