// ch09_sort_02_select_basic.cpp
#include <iostream>
#include <vector>
using namespace std;

// 简单选择排序（升序）
void selectSortBasic(vector<int>& arr) {
    int n = arr.size();
    // 外层循环：控制排序轮数，共n-1轮
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i; // 记录未排序区间最小元素的下标，初始为区间第一个元素
        // 内层循环：遍历未排序区间[i+1, n-1]，找最小值下标
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j; // 更新最小值下标
            }
        }
        // 将最小值与未排序区间第一个元素交换
        if (minIdx != i) { // 避免自身交换
            swap(arr[i], arr[minIdx]);
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    selectSortBasic(arr);
    for (int num : arr) cout << num << " ";
    return 0;
}
