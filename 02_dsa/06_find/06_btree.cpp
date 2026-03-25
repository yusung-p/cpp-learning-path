#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 阶数M
const int M = 3; // 改成3就是2-3树，改成4就是2-3-4树

struct BTreeNode {
    vector<int> keys;       // 关键字
    vector<BTreeNode*> children; // 子树
    bool isLeaf;            // 是否叶子

    BTreeNode(bool leaf = true) : isLeaf(leaf) {}
};

class BTree {
private:
    BTreeNode* root;

    // 分裂孩子
    void splitChild(BTreeNode* x, int i) {
        BTreeNode* y = x->children[i];
        BTreeNode* z = new BTreeNode(y->isLeaf);

        // 后M-1个key给z
        for (int j = 0; j < M-1; j++) {
            z->keys.push_back(y->keys[j+M]);
        }
        // 后M个孩子给z
        if (!y->isLeaf) {
            for (int j = 0; j < M; j++) {
                z->children.push_back(y->children[j+M]);
            }
        }

        // 中间key上提
        int mid = y->keys[M-1];
        x->keys.insert(x->keys.begin() + i, mid);
        x->children.insert(x->children.begin() + i + 1, z);

        // y保留前M-1个key
        y->keys.resize(M-1);
        if (!y->isLeaf) {
            y->children.resize(M);
        }
    }

    // 插入非满结点
    void insertNonFull(BTreeNode* x, int key) {
        int i = x->keys.size() - 1;

        if (x->isLeaf) {
            // 叶子直接插
            x->keys.push_back(key);
            sort(x->keys.begin(), x->keys.end());
        } else {
            // 找孩子位置
            while (i >= 0 && key < x->keys[i]) {
                i--;
            }
            i++;
            // 孩子满了先分裂
            if (x->children[i]->keys.size() == 2*M-1) {
                splitChild(x, i);
                if (key > x->keys[i]) {
                    i++;
                }
            }
            insertNonFull(x->children[i], key);
        }
    }

    // 中序遍历
    void inorder(BTreeNode* x) {
        if (x == nullptr) return;
        int i;
        for (i = 0; i < x->keys.size(); i++) {
            if (!x->isLeaf) {
                inorder(x->children[i]);
            }
            cout << x->keys[i] << " ";
        }
        if (!x->isLeaf) {
            inorder(x->children[i]);
        }
    }

public:
    BTree() {
        root = new BTreeNode();
    }

    void insert(int key) {
        if (root->keys.size() == 2*M-1) {
            // 根满了，分裂
            BTreeNode* s = new BTreeNode(false);
            s->children.push_back(root);
            root = s;
            splitChild(s, 0);
            insertNonFull(s, key);
        } else {
            insertNonFull(root, key);
        }
    }

    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }
};

// 测试
int main() {
    BTree t;

    // 测试插入
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        t.insert(arr[i]);
    }

    cout << "中序遍历: ";
    t.inorderTraversal();

    return 0;
}
