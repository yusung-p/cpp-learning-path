#include <iostream>
#include <cstring>
using namespace std;

#define MAXSIZE 100

// ==================== 8.5.1 稠密索引 ====================
// 稠密索引结点
typedef struct {
    int key;    // 关键字
    int addr;   // 对应记录地址
} DenseIndex;

// 稠密索引查找
int DenseSearch(int r[], DenseIndex idx[], int n, int key) {
    // 索引有序，对索引表折半查找
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (idx[mid].key == key) {
            return idx[mid].addr; // 返回真实位置
        } else if (idx[mid].key < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// ==================== 8.5.2 分块索引(块间有序，块内无序) ====================
// 分块索引结点
typedef struct {
    int max;    // 块内最大关键字
    int start;  // 块起始下标
    int length; // 块长度
} BlockIndex;

// 分块查找
int BlockSearch(int r[], BlockIndex idx[], int b, int key) {
    // 1.先确定在哪一块（折半）
    int low = 0, high = b - 1;
    int blk = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (idx[mid].max >= key) {
            blk = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (blk == -1) return -1;

    // 2.在块内顺序查找
    int start = idx[blk].start;
    int end = start + idx[blk].length - 1;
    for (int i = start; i <= end; i++) {
        if (r[i] == key) {
            return i;
        }
    }
    return -1;
}

// ==================== 8.5.3 倒排索引(了解) ====================
typedef struct {
    int key;
    int count;
    int pos[MAXSIZE];
} InvertIndex;

// ==================== 主函数测试 ====================
int main() {
    cout << "===== 8.5 线性索引查找 =====" << endl << endl;

    // 原表
    int r[] = {22, 12, 15, 48, 32, 45, 70, 62, 88, 90, 82, 96};
    int n = 12;

    // ========== 稠密索引测试 ==========
    DenseIndex denseIdx[MAXSIZE];
    for (int i = 0; i < n; i++) {
        denseIdx[i].key = r[i];
        denseIdx[i].addr = i;
    }
    // 简单排序一下索引（实际应用中索引是有序的）
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (denseIdx[i].key > denseIdx[j].key) {
                swap(denseIdx[i], denseIdx[j]);
            }
        }
    }

    int key1 = 45;
    int addr1 = DenseSearch(r, denseIdx, n, key1);
    cout << "稠密索引查找 " << key1 << " 位置：" << addr1 << endl;

    // ========== 分块索引测试 ==========
    // 分3块
    BlockIndex blockIdx[3];
    // 第0块：22,12,15 → max=22
    blockIdx[0].max = 22;
    blockIdx[0].start = 0;
    blockIdx[0].length = 3;
    // 第1块：48,32,45 → max=48
    blockIdx[1].max = 48;
    blockIdx[1].start = 3;
    blockIdx[1].length = 3;
    // 第2块：70,62,88,90,82,96 → max=96
    blockIdx[2].max = 96;
    blockIdx[2].start = 6;
    blockIdx[2].length = 6;

    int key2 = 45;
    int addr2 = BlockSearch(r, blockIdx, 3, key2);
    cout << "分块索引查找 " << key2 << " 位置：" << addr2 << endl;

    return 0;
}
