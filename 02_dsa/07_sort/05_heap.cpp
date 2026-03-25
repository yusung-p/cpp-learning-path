#include <iostream>
#include <vector>
using namespace std;

// 调整以i为根的子树为大顶堆
// n：堆的有效长度
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // 最大值下标
    int left = 2 * i + 1;   // 左孩子
    int right = 2 * i + 2;  // 右孩子

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 最大值不是根，交换并继续调整
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 1. 建堆：从最后一个非叶子结点向上调整
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // 2. 逐个取出堆顶
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);   // 堆顶放到末尾
        heapify(arr, i, 0);     // 调整堆，长度变为i
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    heapSort(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
