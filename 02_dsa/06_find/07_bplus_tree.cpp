#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// B+树阶数
const int M = 3;

struct BPlusNode {
    vector<int> keys;
    vector<BPlusNode*> children;
    BPlusNode* next;  // 叶子链表指针
    bool isLeaf;

    BPlusNode(bool leaf = true) : isLeaf(leaf), next(nullptr) {}
};

class BPlusTree {
private:
    BPlusNode* root;

    // 分裂孩子
    void splitChild(BPlusNode* x, int i) {
        BPlusNode* y = x->children[i];
        BPlusNode* z = new BPlusNode(y->isLeaf);

        int mid = y->keys.size() / 2;
        int promoteKey = y->keys[mid];

        if (y->isLeaf) {
            // 叶子结点：复制中间值上去
            for (int j = mid; j < y->keys.size(); j++) {
                z->keys.push_back(y->keys[j]);
            }
            y->keys.resize(mid);

            // 维护链表
            z->next = y->next;
            y->next = z;
        } else {
            // 非叶子：中间值上浮
            for (int j = mid + 1; j < y->keys.size(); j++) {
                z->keys.push_back(y->keys[j]);
            }
            for (int j = mid + 1; j < y->children.size(); j++) {
                z->children.push_back(y->children[j]);
            }
            y->keys.resize(mid);
            y->children.resize(mid + 1);
        }

        x->keys.insert(x->keys.begin() + i, promoteKey);
        x->children.insert(x->children.begin() + i + 1, z);
    }

    // 插入非满节点
    void insertNonFull(BPlusNode* x, int key) {
        int i = x->keys.size() - 1;

        if (x->isLeaf) {
            x->keys.push_back(key);
            sort(x->keys.begin(), x->keys.end());
        } else {
            while (i >= 0 && key < x->keys[i]) {
                i--;
            }
            i++;

            if (x->children[i]->keys.size() == M) {
                splitChild(x, i);
                if (key > x->keys[i]) {
                    i++;
                }
            }
            insertNonFull(x->children[i], key);
        }
    }

    // 遍历叶子链表（有序）
    void leafTraverse(BPlusNode* x) {
        while (x && !x->isLeaf) {
            x = x->children[0];
        }
        while (x) {
            for (int k : x->keys) {
                cout << k << " ";
            }
            x = x->next;
        }
        cout << endl;
    }

public:
    BPlusTree() {
        root = new BPlusNode();
    }

    void insert(int key) {
        if (root->keys.size() == M) {
            BPlusNode* s = new BPlusNode(false);
            s->children.push_back(root);
            root = s;
            splitChild(s, 0);
            insertNonFull(s, key);
        } else {
            insertNonFull(root, key);
        }
    }

    // 有序遍历
    void inorder() {
        leafTraverse(root);
    }
};

int main() {
    BPlusTree t;
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        t.insert(arr[i]);
    }

    cout << "B+树有序遍历: ";
    t.inorder();

    return 0;
}
