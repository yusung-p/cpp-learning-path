#include <iostream>
#include <algorithm>
using namespace std;

// AVL树结点结构
typedef struct AVLNode {
    int data;
    int height;         // 高度
    AVLNode *lchild, *rchild;
    AVLNode(int val) : data(val), height(1), lchild(NULL), rchild(NULL) {}
} AVLNode, *AVLTree;

// 获取结点高度
int getHeight(AVLNode *node) {
    if (!node) return 0;
    return node->height;
}

// 更新高度
void updateHeight(AVLNode *node) {
    if (!node) return;
    node->height = 1 + max(getHeight(node->lchild), getHeight(node->rchild));
}

// 获取平衡因子
int getBF(AVLNode *node) {
    if (!node) return 0;
    return getHeight(node->lchild) - getHeight(node->rchild);
}

// 右旋 LL
AVLNode* rightRotate(AVLNode *y) {
    AVLNode *x = y->lchild;
    AVLNode *T3 = x->rchild;

    x->rchild = y;
    y->lchild = T3;

    updateHeight(y);
    updateHeight(x);
    return x;
}

// 左旋 RR
AVLNode* leftRotate(AVLNode *x) {
    AVLNode *y = x->rchild;
    AVLNode *T2 = y->lchild;

    y->lchild = x;
    x->rchild = T2;

    updateHeight(x);
    updateHeight(y);
    return y;
}

// 插入并调整平衡
AVLNode* AVLInsert(AVLTree &T, int key) {
    if (!T) {
        T = new AVLNode(key);
        return T;
    }

    if (key < T->data)
        T->lchild = AVLInsert(T->lchild, key);
    else if (key > T->data)
        T->rchild = AVLInsert(T->rchild, key);
    else
        return T;   // 不允许重复

    updateHeight(T);
    int bf = getBF(T);

    // LL 右旋
    if (bf > 1 && key < T->lchild->data)
        return rightRotate(T);

    // RR 左旋
    if (bf < -1 && key > T->rchild->data)
        return leftRotate(T);

    // LR 先左旋左孩子，再右旋
    if (bf > 1 && key > T->lchild->data) {
        T->lchild = leftRotate(T->lchild);
        return rightRotate(T);
    }

    // RL 先右旋右孩子，再左旋
    if (bf < -1 && key < T->rchild->data) {
        T->rchild = rightRotate(T->rchild);
        return leftRotate(T);
    }

    return T;
}

// 中序遍历（验证有序）
void InOrder(AVLTree T) {
    if (T) {
        InOrder(T->lchild);
        cout << T->data << " ";
        InOrder(T->rchild);
    }
}

// 测试主函数
int main() {
    AVLTree T = NULL;
    int arr[] = {1, 3, 5, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        T = AVLInsert(T, arr[i]);
    }

    cout << "中序遍历（递增）：" << endl;
    InOrder(T);
    cout << endl;

    return 0;
}
