#include <iostream>
#include <cstring>
using namespace std;

// ====================== 哈夫曼树结点结构 ======================
typedef struct {
    // 结点的权值
    int weight;
    // 双亲结点下标
    int parent;
    // 左孩子下标
    int lchild;
    // 右孩子下标
    int rchild;
} HuffNode;

// 哈夫曼编码类型：字符串数组
typedef char** HuffCode;

// ====================== 选择函数 ======================
// 功能：在前k个结点中，选两个parent=0（未合并）且权值最小的结点，下标为s1、s2
void Select(HuffNode HT[], int k, int& s1, int& s2) {
    int min1 = 0x3f3f3f3f; // 设一个很大的数
    int min2 = 0x3f3f3f3f;
    s1 = s2 = 0;

    // 找第一个最小
    for (int i = 1; i <= k; i++) {
        if (HT[i].parent == 0 && HT[i].weight < min1) {
            min1 = HT[i].weight;
            s1 = i;
        }
    }

    // 找第二个最小
    for (int i = 1; i <= k; i++) {
        // 不能和s1相同，且未被合并
        if (HT[i].parent == 0 && HT[i].weight < min2 && i != s1) {
            min2 = HT[i].weight;
            s2 = i;
        }
    }
}

// ====================== 创建哈夫曼树 ======================
// HT：哈夫曼树数组
// w[]：权值数组，w[1..n]有效
// n：叶子结点个数
void CreateHuffTree(HuffNode*& HT, int w[], int n) {
    // 哈夫曼树总结点个数：2n-1
    int m = 2 * n - 1;

    // 动态分配数组，下标从1开始用，0不用
    HT = new HuffNode[m + 1];

    // --------------- 1. 初始化叶子结点 ---------------
    for (int i = 1; i <= n; i++) {
        // 权值
        HT[i].weight = w[i];
        // 初始都无双亲、无孩子
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    // --------------- 2. 初始化非叶子结点 ---------------
    for (int i = n + 1; i <= m; i++) {
        HT[i].weight = 0;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    // --------------- 3. 循环构建哈夫曼树 ---------------
    // 从n+1到m，依次构造非叶子结点
    for (int i = n + 1; i <= m; i++) {
        int s1, s2;
        // 选出两个权值最小的结点
        Select(HT, i - 1, s1, s2);

        // 这两个结点的双亲设为当前i
        HT[s1].parent = i;
        HT[s2].parent = i;

        // 左、右孩子（0/1无所谓，不影响编码）
        HT[i].lchild = s1;
        HT[i].rchild = s2;

        // 当前结点权值 = 两个孩子权值之和
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

// ====================== 生成哈夫曼编码 ======================
// HT：已建好的哈夫曼树
// HC：存储每个叶子的编码
// n：叶子个数
void CreateHuffCode(HuffNode HT[], HuffCode& HC, int n) {
    // 分配n个编码串的空间（下标1~n）
    HC = new char* [n + 1];
    // 临时存放编码
    char* cd = new char[n];
    // 编码结束符
    cd[n - 1] = '\0';

    // --------------- 逐个求叶子编码 ---------------
    for (int i = 1; i <= n; i++) {
        // 编码从末尾开始往前存
        int start = n - 1;
        // 当前结点
        int c = i;
        // 双亲结点
        int f = HT[i].parent;

        // 从叶子向上走到根
        while (f != 0) {
            // c是f的左孩子，编码0
            if (HT[f].lchild == c)
                cd[--start] = '0';
            // c是f的右孩子，编码1
            else
                cd[--start] = '1';

            // 向上继续走
            c = f;
            f = HT[f].parent;
        }

        // 为第i个编码分配空间
        HC[i] = new char[n - start];
        // 复制编码
        strcpy(HC[i], &cd[start]);
    }
    // 释放临时空间
    delete[] cd;
}

// ====================== 测试函数 ======================
void Test6_12() {
    cout << "========== 6.12 哈夫曼树与哈夫曼编码 ==========" << endl;
    // 叶子结点数
    int n = 4;
    // 权值数组，w[1]~w[4]
    int w[] = { 0, 7, 5, 2, 4 };

    HuffNode* HT;
    HuffCode HC;

    // 1. 创建哈夫曼树
    CreateHuffTree(HT, w, n);
    // 2. 生成哈夫曼编码
    CreateHuffCode(HT, HC, n);

    // 输出编码
    for (int i = 1; i <= n; i++) {
        cout << "权值 " << w[i] << " 的哈夫曼编码：" << HC[i] << endl;
    }
}

// 主函数
int main() {
    Test6_12();
    return 0;
}
