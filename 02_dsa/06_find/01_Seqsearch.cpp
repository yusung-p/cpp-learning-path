#include <iostream>
using namespace std;

// -------------------------- 1. 基础版顺序查找（无哨兵） --------------------------
// 功能：在数组a[1..n]中查找key，返回下标（0表示未找到）
int SequentialSearch_Basic(int a[], int n, int key) {
    for (int i = 1; i <= n; i++) {
        if (a[i] == key) {
            return i; // 找到，返回对应下标
        }
    }
    return 0; // 遍历完未找到，返回0
}

// -------------------------- 2. 优化版顺序查找（哨兵优化） --------------------------
// 功能：在数组a[1..n]中查找key，返回下标（0表示未找到）
int SequentialSearch_Sentinel(int a[], int n, int key) {
    a[0] = key; // 设置哨兵，放在数组第0位（预留位）
    int i = n;
    // 仅需判断元素是否相等，无需额外判断i的边界
    while (a[i] != key) {
        i--;
    }
    return i; // i=0表示未找到，否则为目标下标
}

// -------------------------- 3. 链表版顺序查找（适配链式存储） --------------------------
// 链表结点定义
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 功能：在单链表L中查找key，找到返回结点指针，否则返回NULL
LNode* LinkList_Search(LinkList L, int key) {
    LNode *p = L->next; // 从首元结点开始遍历
    while (p != NULL && p->data != key) {
        p = p->next;
    }
    return p;
}

// -------------------------- 辅助函数：创建单链表（尾插法） --------------------------
LinkList CreateLinkList(int a[], int n) {
    LinkList L = (LinkList)malloc(sizeof(LNode)); // 头结点
    L->next = NULL;
    LNode *r = L; // 尾指针
    for (int i = 1; i <= n; i++) {
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = NULL;
        r->next = s;
        r = s;
    }
    return L;
}

// -------------------------- 主函数：完整测试 --------------------------
int main() {
    // 测试数组：a[0]预留哨兵位，a[1..11]为有效数据
    int arr[] = {0, 5, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int n = 11; // 有效元素个数
    int key = 64; // 目标查找值

    cout << "===== 8.3 顺序表查找 完整测试 =====" << endl << endl;

    // 1. 测试基础版顺序查找
    cout << "【1. 基础版顺序查找（无哨兵）】" << endl;
    int res1 = SequentialSearch_Basic(arr, n, key);
    if (res1 != 0) {
        cout << "查找成功！元素 " << key << " 的下标为：" << res1 << endl;
    } else {
        cout << "查找失败！元素 " << key << " 不存在" << endl;
    }

    // 2. 测试哨兵优化版顺序查找
    cout << endl << "【2. 哨兵优化版顺序查找】" << endl;
    int res2 = SequentialSearch_Sentinel(arr, n, key);
    if (res2 != 0) {
        cout << "查找成功！元素 " << key << " 的下标为：" << res2 << endl;
    } else {
        cout << "查找失败！元素 " << key << " 不存在" << endl;
    }

    // 3. 测试链表版顺序查找
    cout << endl << "【3. 链表版顺序查找】" << endl;
    LinkList L = CreateLinkList(arr, n); // 用数组创建单链表
    LNode* res3 = LinkList_Search(L, key);
    if (res3 != NULL) {
        cout << "查找成功！元素 " << key << " 存在于链表中" << endl;
    } else {
        cout << "查找失败！元素 " << key << " 不存在于链表中" << endl;
    }

    // 4. 测试查找不存在的元素（验证失败逻辑）
    cout << endl << "【4. 测试查找不存在的元素（key=100）】" << endl;
    int res4 = SequentialSearch_Sentinel(arr, n, 100);
    if (res4 != 0) {
        cout << "查找成功！元素 100 的下标为：" << res4 << endl;
    } else {
        cout << "查找失败！元素 100 不存在" << endl;
    }

    return 0;
}
