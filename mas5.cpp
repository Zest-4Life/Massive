#include <iostream>
#include <vector>

using namespace std;

// Рекурсивна функція для об'єднання двох відсортованих масивів
void mergeRecursive(vector<int>& nums1, int m, const vector<int>& nums2, int n, int index1, int index2, int writeIndex) {
    // Базовий випадок: якщо всі елементи з nums2 об'єднані
    if (index2 < 0) return;

    // Якщо всі елементи з nums1 (першої частини) об'єднані
    if (index1 < 0) {
        nums1[writeIndex] = nums2[index2];
        mergeRecursive(nums1, m, nums2, n, index1, index2 - 1, writeIndex - 1);
        return;
    }

    // Порівнюємо поточні елементи nums1 і nums2
    if (nums1[index1] > nums2[index2]) {
        nums1[writeIndex] = nums1[index1];
        mergeRecursive(nums1, m, nums2, n, index1 - 1, index2, writeIndex - 1);
    }
    else {
        nums1[writeIndex] = nums2[index2];
        mergeRecursive(nums1, m, nums2, n, index1, index2 - 1, writeIndex - 1);
    }
}

// Основна функція для виклику рекурсії
void merge(vector<int>& nums1, int m, const vector<int>& nums2, int n) {
    mergeRecursive(nums1, m, nums2, n, m - 1, n - 1, m + n - 1);
}

int main() {
    vector<int> nums1_1 = { 1, 2, 3, 0, 0, 0 };
    vector<int> nums2_1 = { 2, 5, 6 };
    merge(nums1_1, 3, nums2_1, 3);
    for (int num : nums1_1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums1_2 = { 1 };
    vector<int> nums2_2 = {};
    merge(nums1_2, 1, nums2_2, 0);
    for (int num : nums1_2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums1_3 = { 0 };
    vector<int> nums2_3 = { 1 };
    merge(nums1_3, 0, nums2_3, 1);
    for (int num : nums1_3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}