// ch09_sort_01_bubble_optimized.cpp
#include <iostream>
#include <vector>
using namespace std;

// 优化版冒泡排序（提前终止）
void bubbleSortOptimized(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // 标记本轮是否发生交换
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true; // 发生交换，标记为true
            }
        }
        // 本轮无交换，数组已有序，直接结束
        if (!swapped) {
            break;
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    bubbleSortOptimized(arr);
    for (int num : arr) cout << num << " ";
    return 0;
}
