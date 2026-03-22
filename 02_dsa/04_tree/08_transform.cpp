#include <iostream>
using namespace std;

// 二叉树结构
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 前序遍历
void PreOrder(BiTree T)
{
    if (T)
    {
        cout << T->data << " ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 孩子兄弟表示法
typedef struct CSNode
{
    char data;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;

//============================
// 直接创建一棵测试树，不用输入
//============================
CSTree CreateTree()
{
    // 构造树:
    //        A
    //      / | \
    //     B  C  D
    CSTree A = new CSNode{'A', NULL, NULL};
    CSTree B = new CSNode{'B', NULL, NULL};
    CSTree C = new CSNode{'C', NULL, NULL};
    CSTree D = new CSNode{'D', NULL, NULL};

    A->firstchild = B;
    B->nextsibling = C;
    C->nextsibling = D;

    return A;
}

//============================
// 树转二叉树
//============================
void TreeToBiTree(CSTree T, BiTree &BT)
{
    if (!T)
    {
        BT = NULL;
        return;
    }
    BT = new BiTNode;
    BT->data = T->data;
    TreeToBiTree(T->firstchild, BT->lchild);
    TreeToBiTree(T->nextsibling, BT->rchild);
}

//============================
// 测试函数
//============================
void Test6_11()
{
    cout << "====== 6.11 树转二叉树 ======" << endl;

    CSTree T = CreateTree(); // 直接创建，不用输入
    BiTree BT;
    TreeToBiTree(T, BT);

    cout << "转换后二叉树前序遍历：";
    PreOrder(BT);
    cout << endl;
}

int main()
{
    Test6_11();
    return 0;
}
