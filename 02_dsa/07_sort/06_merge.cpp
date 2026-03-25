#include <iostream>
#include <vector>
#include <algorithm> // min
using namespace std;

// 合并函数（递归、非递归共用）
void merge(vector<int>& arr, int left, int mid, int right)
{
    vector<int> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int p = 0; p < temp.size(); p++)
        arr[left + p] = temp[p];
}

// 1. 递归版归并排序
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(vector<int>& arr)
{
    mergeSort(arr, 0, arr.size() - 1);
}

// 2. 非递归（迭代）版归并排序
void mergeSortNonRecursive(vector<int>& arr)
{
    int n = arr.size();
    for (int step = 1; step < n; step *= 2)
    {
        for (int l = 0; l + step < n; l += 2 * step)
        {
            int mid = l + step - 1;
            int r = min(l + 2 * step - 1, n - 1);
            merge(arr, l, mid, r);
        }
    }
}

// 打印数组
void printArr(vector<int>& arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main()
{
    // 测试递归版
    vector<int> arr1 = {5, 2, 9, 1, 5, 6};
    cout << "原数组：";
    printArr(arr1);

    mergeSort(arr1);
    cout << "递归归并排序后：";
    printArr(arr1);

    cout << "-------------------------" << endl;

    // 测试非递归版
    vector<int> arr2 = {7, 3, 8, 2, 4, 1};
    cout << "原数组：";
    printArr(arr2);

    mergeSortNonRecursive(arr2);
    cout << "非递归归并排序后：";
    printArr(arr2);

    return 0;
}
