#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Рекурсивна функція для злиття двох відсортованих частин масиву
void mergeSortedSquares(const vector<int>& left, const vector<int>& right, vector<int>& result, int i, int j, int k) {
    if (i == left.size() && j == right.size()) return;

    if (i < left.size() && (j == right.size() || left[i] <= right[j])) {
        result[k] = left[i];
        mergeSortedSquares(left, right, result, i + 1, j, k + 1);
    }
    else {
        result[k] = right[j];
        mergeSortedSquares(left, right, result, i, j + 1, k + 1);
    }
}

// Рекурсивна функція для сортування квадратів масиву
void sortSquaresRecursive(const vector<int>& nums, vector<int>& result, int left, int right) {
    if (left == right) {
        result[0] = nums[left] * nums[left];
        return;
    }

    int mid = left + (right - left) / 2;

    vector<int> leftSquares(mid - left + 1);
    vector<int> rightSquares(right - mid);

    sortSquaresRecursive(nums, leftSquares, left, mid);
    sortSquaresRecursive(nums, rightSquares, mid + 1, right);

    mergeSortedSquares(leftSquares, rightSquares, result, 0, 0, 0);
}

// Основна функція для сортування квадратів
vector<int> sortedSquares(const vector<int>& nums) {
    vector<int> result(nums.size());
    sortSquaresRecursive(nums, result, 0, nums.size() - 1);
    return result;
}

int main() {
    vector<int> nums1 = { -4, -1, 0, 3, 10 };
    vector<int> result1 = sortedSquares(nums1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = { -7, -3, 2, 3, 11 };
    vector<int> result2 = sortedSquares(nums2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}