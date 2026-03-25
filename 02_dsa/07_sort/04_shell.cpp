#include <iostream>
#include <vector>
using namespace std;

// 希尔排序
void shellSort(vector<int>& arr) {
    int n = arr.size();
    // 增量 gap 不断缩小
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个分组进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];    // 待插入元素
            int j = i;

            // 同一组内，前面的元素后移
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;       // 插入
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    shellSort(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
