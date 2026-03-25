#include <iostream>
#include <vector>
using namespace std;

// 直接插入排序（标准版）
void insertSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {  // 从第二个开始插
        int temp = arr[i];          // 待插入元素
        int j = i - 1;

        // 比temp大的元素往后挪
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;  // 插入
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    insertSort(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
