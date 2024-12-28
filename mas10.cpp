#include <iostream>
#include <vector>

using namespace std;

// Рекурсивна функція для сортування масиву за парністю
void sortArrayByParityRecursive(vector<int>& nums, int left, int right) {
    // Базовий випадок: якщо індекси перетнулися
    if (left >= right) {
        return;
    }

    // Якщо елемент зліва парний, рухаємось далі
    if (nums[left] % 2 == 0) {
        sortArrayByParityRecursive(nums, left + 1, right);
    }
    // Якщо елемент справа непарний, рухаємось далі
    else if (nums[right] % 2 != 0) {
        sortArrayByParityRecursive(nums, left, right - 1);
    }
    // Якщо зліва непарний, а справа парний — міняємо їх місцями
    else {
        swap(nums[left], nums[right]);
        sortArrayByParityRecursive(nums, left + 1, right - 1);
    }
}

// Основна функція для виклику рекурсії
vector<int> sortArrayByParity(vector<int>& nums) {
    sortArrayByParityRecursive(nums, 0, nums.size() - 1);
    return nums;
}

int main() {
    vector<int> nums1 = { 3, 1, 2, 4 };
    vector<int> result1 = sortArrayByParity(nums1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = { 0 };
    vector<int> result2 = sortArrayByParity(nums2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
