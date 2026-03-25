// ch09_sort_01_bubble_basic.cpp
#include <iostream>
#include <vector>
using namespace std;

// 基础版冒泡排序
void bubbleSortBasic(vector<int>& arr) {
    int n = arr.size();
    // 外层循环：控制排序轮数，共n-1轮
    for (int i = 0; i < n - 1; i++) {
        // 内层循环：两两比较，每轮少比较i个（末尾i个已有序）
        for (int j = 0; j < n - i - 1; j++) {
            // 前一个 > 后一个，交换
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    bubbleSortBasic(arr);
    for (int num : arr) cout << num << " ";
    return 0;
}
