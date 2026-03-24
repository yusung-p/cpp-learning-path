#include <iostream>
using namespace std;

// 二叉排序树结点结构
typedef struct BSTNode
{
    int data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// ==================== 8.6.1 二叉排序树查找 ====================
// 递归查找
BSTNode* BST_Search(BSTree T, int key)
{
    if(T == NULL || T->data == key)
        return T;
    if(key < T->data)
        return BST_Search(T->lchild, key);
    else
        return BST_Search(T->rchild, key);
}

// 非递归查找
BSTNode* BST_Search_NonRecur(BSTree T, int key)
{
    while(T != NULL && T->data != key)
    {
        if(key < T->data)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}

// ==================== 8.6.2 二叉排序树插入 ====================
// 插入成功返回true，已存在返回false
bool BST_Insert(BSTree &T, int key)
{
    if(T == NULL)
    {
        T = new BSTNode;
        T->data = key;
        T->lchild = T->rchild = NULL;
        return true;
    }
    if(key == T->data)
        return false;
    else if(key < T->data)
        return BST_Insert(T->lchild, key);
    else
        return BST_Insert(T->rchild, key);
}

// ==================== 8.6.3 二叉排序树删除 ====================
// 删除key结点
bool BST_Delete(BSTree &T, int key)
{
    if(T == NULL)
        return false;
    if(key < T->data)
        return BST_Delete(T->lchild, key);
    else if(key > T->data)
        return BST_Delete(T->rchild, key);
    else
    {
        BSTNode *p = T;
        // 右空，用左孩子顶替
        if(T->rchild == NULL)
        {
            T = T->lchild;
            delete p;
        }
        // 左空，用右孩子顶替
        else if(T->lchild == NULL)
        {
            T = T->rchild;
            delete p;
        }
        // 左右都不空，找前驱（左子树最右）
        else
        {
            BSTNode *q = T->lchild;
            while(q->rchild != NULL)
                q = q->rchild;
            // 前驱值覆盖
            T->data = q->data;
            // 删除前驱结点
            BST_Delete(T->lchild, q->data);
        }
        return true;
    }
}

// ==================== 中序遍历（验证：递增有序） ====================
void InOrder(BSTree T)
{
    if(T)
    {
        InOrder(T->lchild);
        cout << T->data << " ";
        InOrder(T->rchild);
    }
}

// ==================== 主函数测试 ====================
int main()
{
    BSTree T = NULL;

    // 插入序列
    int arr[] = {62, 88, 58, 47, 73, 99, 35, 51, 93};
    int n = sizeof(arr)/sizeof(int);

    for(int i=0; i<n; i++)
    {
        BST_Insert(T, arr[i]);
    }

    cout << "===== 二叉排序树中序遍历 =====" << endl;
    InOrder(T);
    cout << endl << endl;

    // 查找测试
    int key1 = 51;
    BSTNode *res1 = BST_Search(T, key1);
    if(res1)
        cout << key1 << " 查找成功" << endl;
    else
        cout << key1 << " 不存在" << endl;

    // 删除测试
    int key2 = 58;
    BST_Delete(T, key2);
    cout << endl << "删除 " << key2 << " 后中序遍历：" << endl;
    InOrder(T);
    cout << endl;

    return 0;
}
