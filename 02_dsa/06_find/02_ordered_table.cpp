#include <iostream>
#include <cmath>
using namespace std;

// -------------------------- 工具函数：打印数组 --------------------------
void PrintArray(int a[], int n) {
    cout << "数组内容：";
    for (int i = 1; i <= n; i++) { // 按原书约定，a[1..n]为有效数据
        cout << a[i] << " ";
    }
    cout << endl;
}

// -------------------------- 8.4.1 折半查找（二分查找，非递归版） --------------------------
// 功能：在有序数组a[1..n]中查找key，返回下标（0表示未找到）
int BinarySearch(int a[], int n, int key) {
    int low = 1;    // 查找区间左边界
    int high = n;   // 查找区间右边界
    int mid;        // 中间位置

    while (low <= high) {
        mid = low + (high - low) / 2; // 等价于(low+high)/2，避免整数溢出
        if (key == a[mid]) {
            return mid; // 查找成功，返回下标
        } else if (key < a[mid]) {
            high = mid - 1; // 目标在左半区间，更新右边界
        } else {
            low = mid + 1;  // 目标在右半区间，更新左边界
        }
    }
    return 0; // 查找失败
}

// -------------------------- 8.4.2 插值查找 --------------------------
// 功能：在有序数组a[1..n]中查找key，返回下标（0表示未找到）
// 核心优化：用比例位置代替固定mid，适合元素分布均匀的有序表
int InterpolationSearch(int a[], int n, int key) {
    int low = 1;
    int high = n;
    int mid;

    while (low <= high && key >= a[low] && key <= a[high]) {
        // 插值公式：mid = low + (key - a[low])/(a[high]-a[low]) * (high - low)
        mid = low + (int)((double)(key - a[low]) / (a[high] - a[low]) * (high - low));
        
        // 边界保护：防止mid越界（极端情况）
        if (mid < low) mid = low;
        if (mid > high) mid = high;

        if (key == a[mid]) {
            return mid;
        } else if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
}

// -------------------------- 8.4.3 斐波那契查找 --------------------------
// 功能：生成斐波那契数列，用于斐波那契查找
void Fibonacci(int F[], int size) {
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < size; i++) {
        F[i] = F[i-1] + F[i-2];
    }
}

// 功能：在有序数组a[1..n]中查找key，返回下标（0表示未找到）
// 核心：用斐波那契数列分割区间，黄金分割比例优化
int FibonacciSearch(int a[], int n, int key) {
    int low = 1;
    int high = n;
    int k = 0; // 斐波那契数列的索引
    int F[20]; // 足够大的斐波那契数组（覆盖常见数据规模）
    Fibonacci(F, 20);

    // 找到满足 F[k]-1 >= n 的最小k
    while (F[k] - 1 < n) {
        k++;
    }

    // 补全数组到长度F[k]-1（用最后一个元素填充，不影响查找）
    int *temp = new int[F[k]];
    for (int i = 1; i <= n; i++) {
        temp[i] = a[i];
    }
    for (int i = n + 1; i <= F[k] - 1; i++) {
        temp[i] = a[n];
    }

    while (low <= high) {
        int mid = low + F[k-1] - 1; // 按斐波那契分割取mid
        if (key < temp[mid]) {
            high = mid - 1;
            k = k - 1; // 左半区间，对应F[k-1]
        } else if (key > temp[mid]) {
            low = mid + 1;
            k = k - 2; // 右半区间，对应F[k-2]
        } else {
            // 查找成功，判断是否是补全的元素
            delete[] temp;
            if (mid <= n) return mid;
            else return n;
        }
    }

    delete[] temp;
    return 0;
}

// -------------------------- 主函数：完整测试 --------------------------
int main() {
    // 测试用有序数组（严格递增，符合有序表要求）
    // 按原书约定，a[0]预留，a[1..11]为有效数据
    int arr[] = {0, 5, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = 11; // 有效元素个数
    int key = 64; // 目标查找值
    int key_not_exist = 100; // 不存在的元素，用于测试失败逻辑

    cout << "===== 8.4 有序表查找 3种算法完整测试 =====" << endl << endl;
    PrintArray(arr, n);
    cout << "目标查找值：" << key << endl << endl;

    // 1. 测试折半查找
    cout << "【1. 折半查找（二分查找）】" << endl;
    int res1 = BinarySearch(arr, n, key);
    if (res1 != 0) {
        cout << "查找成功！元素 " << key << " 的下标为：" << res1 << endl;
    } else {
        cout << "查找失败！元素 " << key << " 不存在" << endl;
    }

    // 2. 测试插值查找
    cout << endl << "【2. 插值查找】" << endl;
    int res2 = InterpolationSearch(arr, n, key);
    if (res2 != 0) {
        cout << "查找成功！元素 " << key << " 的下标为：" << res2 << endl;
    } else {
        cout << "查找失败！元素 " << key << " 不存在" << endl;
    }

    // 3. 测试斐波那契查找
    cout << endl << "【3. 斐波那契查找】" << endl;
    int res3 = FibonacciSearch(arr, n, key);
    if (res3 != 0) {
        cout << "查找成功！元素 " << key << " 的下标为：" << res3 << endl;
    } else {
        cout << "查找失败！元素 " << key << " 不存在" << endl;
    }

    // 4. 测试查找不存在的元素（验证失败逻辑）
    cout << endl << "【4. 测试查找不存在的元素（key=100）】" << endl;
    int res4 = BinarySearch(arr, n, key_not_exist);
    if (res4 != 0) {
        cout << "折半查找：查找成功！元素 100 的下标为：" << res4 << endl;
    } else {
        cout << "折半查找：查找失败！元素 100 不存在" << endl;
    }

    return 0;
}
