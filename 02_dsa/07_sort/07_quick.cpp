#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

// 打印数组
void printArr(vector<int> arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// 划分函数
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot) i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    return i;
}

// 1. 普通快速排序
void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int pos = partition(arr, left, right);
    quickSort(arr, left, pos - 1);
    quickSort(arr, pos + 1, right);
}

// 2. 优化快排：三数取中 + 小区间插入排序
void insertSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int getMid(vector<int>& arr, int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid]) swap(arr[left], arr[mid]);
    if (arr[left] > arr[right]) swap(arr[left], arr[right]);
    if (arr[mid] > arr[right]) swap(arr[mid], arr[right]);
    swap(arr[mid], arr[left]);
    return arr[left];
}

void quickSortOpt(vector<int>& arr, int left, int right) {
    if (right - left + 1 <= 10) {
        insertSort(arr, left, right);
        return;
    }
    getMid(arr, left, right);
    int pos = partition(arr, left, right);
    quickSortOpt(arr, left, pos - 1);
    quickSortOpt(arr, pos + 1, right);
}

// 3. 非递归快排
void quickSortNonRecursive(vector<int>& arr) {
    int n = arr.size();
    stack<pair<int, int>> st;
    st.push({0, n - 1});
    while (!st.empty()) {
        auto cur = st.top();
        st.pop();
        int l = cur.first, r = cur.second;
        if (l >= r) continue;
        int pos = partition(arr, l, r);
        st.push({pos + 1, r});
        st.push({l, pos - 1});
    }
}

int main() {
    vector<int> arr1 = {5, 2, 9, 1, 5, 6};
    vector<int> arr2 = arr1;
    vector<int> arr3 = arr1;

    cout << "原数组: ";
    printArr(arr1);

    // 普通快排
    quickSort(arr1, 0, arr1.size() - 1);
    cout << "普通快排: ";
    printArr(arr1);

    // 优化快排
    quickSortOpt(arr2, 0, arr2.size() - 1);
    cout << "优化快排: ";
    printArr(arr2);

    // 非递归快排
    quickSortNonRecursive(arr3);
    cout << "非递归快排: ";
    printArr(arr3);

    return 0;
}
