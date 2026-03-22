#include <iostream>
using namespace std;

// 状态码定义
#define OK 1
#define ERROR 0
typedef int Status;

// 指针标志：Link=0 表示指向孩子，Thread=1 表示线索
#define Link 0
#define Thread 1

// 线索二叉树结点结构
struct BiThrNode {
    char data;
    BiThrNode *lchild, *rchild;
    int LTag, RTag;

    // 构造函数（C++风格初始化）
    BiThrNode(char ch = '\0') 
        : data(ch), lchild(nullptr), rchild(nullptr), LTag(Link), RTag(Link) {}
};

typedef BiThrNode* BiThrTree;

// 全局前驱指针，用于线索化
BiThrTree pre = nullptr;

// --------------------------
// 1. 前序创建普通二叉树（用于测试）
// --------------------------
void CreateBiTree(BiThrTree &T) {
    char ch;
    cin >> ch;
    if(ch=='@'){
        T=nullptr;
        return;
    }
    if (ch == '#') {
        T = nullptr;
    } else {
        T = new BiThrNode(ch);
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

// --------------------------
// 2. 中序线索化核心函数
// --------------------------
void InThread(BiThrTree p) {
    if (p != nullptr) {
        InThread(p->lchild); // 左子树线索化
        
        // 处理当前结点：建立前驱线索
        if (p->lchild == nullptr) {
            p->LTag = Thread;
            p->lchild = pre;
        } else {
            p->LTag = Link;
        }
        
        // 处理前驱结点：建立后继线索
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->RTag = Thread;
            pre->rchild = p;
        } else if (pre != nullptr) {
            pre->RTag = Link;
        }
        
        pre = p; // 更新前驱
        InThread(p->rchild); // 右子树线索化
    }
}

// --------------------------
// 3. 创建带头结点的中序线索二叉树
// --------------------------
Status CreateInThread(BiThrTree &T) {
    // 创建头结点
    BiThrTree head = new BiThrNode();
    head->LTag = Link;
    head->RTag = Thread;
    head->rchild = head; // 右指针指向自身，遍历结束判断用
    
    if (T == nullptr) { // 空树
        head->lchild = head;
    } else {
        head->lchild = T;   // 头结点左孩子指向根结点
        pre = head;         // 初始化前驱为头结点
        InThread(T);        // 中序线索化
        // 处理最后一个结点：后继线索指向头结点
        pre->RTag = Thread;
        pre->rchild = head;
    }
    T = head; // 让T指向头结点
    return OK;
}

// --------------------------
// 4. 你提供的中序遍历算法（带头结点版）
// --------------------------
Status InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild;      /* p指向根结点 */
    while (p != T)      /* 空树或遍历结束时,p==T */
    {
        while (p->LTag == Link) /* 当LTag==0时循环到中序序列第一个结点 */
            p = p->lchild;
        cout << p->data; /* 显示结点数据 */
        while (p->RTag == Thread && p->rchild != T)
        {
            p = p->rchild;
            cout << p->data;
        }
        p = p->rchild;   /* p进至其右子树根 */
    }
    return OK;
}

// --------------------------
// 5. 前序遍历（递归版，适用于线索二叉树）
// --------------------------
void PreOrder(BiThrTree T) {
    if (T != nullptr && T->data != '\0') { // 跳过头结点
        cout << T->data;
        if (T->LTag == Link) PreOrder(T->lchild);
        if (T->RTag == Link) PreOrder(T->rchild);
    }
}

// 包装成带头结点的前序遍历接口
Status PreOrderTraverse_Thr(BiThrTree T) {
    if (T == nullptr) return OK;
    PreOrder(T->lchild); // 从根结点开始遍历
    return OK;
}

// --------------------------
// 6. 后序遍历（递归版，适用于线索二叉树）
// --------------------------
void PostOrder(BiThrTree T) {
    if (T != nullptr && T->data != '\0') { // 跳过头结点
        if (T->LTag == Link) PostOrder(T->lchild);
        if (T->RTag == Link) PostOrder(T->rchild);
        cout << T->data;
    }
}

// 包装成带头结点的后序遍历接口
Status PostOrderTraverse_Thr(BiThrTree T) {
    if (T == nullptr) return OK;
    PostOrder(T->lchild); // 从根结点开始遍历
    return OK;
}

// --------------------------
// 7. 测试函数
// --------------------------
void Test() {
    cout << "=== 带头结点的中序线索二叉树遍历测试 ===" << endl;
    cout << "请输入前序序列（空结点用#，如：ABC##DE##F##）：" << endl;
    
    BiThrTree T = nullptr;
    CreateBiTree(T);    // 先创建普通二叉树
    CreateInThread(T);  // 线索化并建立头结点
    
    cout << "前序遍历结果：";
    PreOrderTraverse_Thr(T);
    cout << endl;

    cout << "中序遍历结果：";
    InOrderTraverse_Thr(T);
    cout << endl;

    cout << "后序遍历结果：";
    PostOrderTraverse_Thr(T);
    cout << endl;
}

// --------------------------
// 主函数
// --------------------------
int main() {
    Test();
    return 0;
}
