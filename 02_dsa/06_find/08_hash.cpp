#include <iostream>
#include <vector>
using namespace std;

// 散列表大小（素数最好）
const int HashSize = 11;

class HashTable {
private:
    vector<int> table;
    int nullVal = -1;   // 空标记

    // 散列函数：除留余数法
    int hash(int key) {
        return key % HashSize;
    }

public:
    HashTable() {
        table.resize(HashSize, nullVal);
    }

    // 插入：线性探测法
    bool insert(int key) {
        int pos = hash(key);
        int i = 0;

        // 线性探测
        while (i < HashSize) {
            int idx = (pos + i) % HashSize;
            if (table[idx] == nullVal) {
                table[idx] = key;
                return true;
            }
            if (table[idx] == key) { // 已存在
                return false;
            }
            i++;
        }
        return false; // 表满
    }

    // 查找
    int search(int key) {
        int pos = hash(key);
        int i = 0;
        while (i < HashSize) {
            int idx = (pos + i) % HashSize;
            if (table[idx] == key) {
                return idx; // 返回下标
            }
            if (table[idx] == nullVal) {
                return -1; // 查找失败
            }
            i++;
        }
        return -1;
    }

    // 打印散列表
    void print() {
        for (int i = 0; i < HashSize; i++) {
            cout << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht;
    int arr[] = {19, 14, 23, 1, 68, 20, 84, 27, 55, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        ht.insert(arr[i]);
    }

    cout << "散列表：" << endl;
    ht.print();

    int key = 27;
    int pos = ht.search(key);
    if (pos != -1)
        cout << key << " 在位置：" << pos << endl;
    else
        cout << key << " 不存在" << endl;

    return 0;
}
