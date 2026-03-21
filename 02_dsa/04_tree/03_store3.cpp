//孩子兄弟表示法
#include <iostream>
using namespace std;
struct CSNode{
    char data;
    CSNode*firstChild;
    CSNode*nextSibling;
    CSNode(char val):data(val),firstChild(nullptr),nextSibling(nullptr){}
};
class CSTree{
    private:
    CSNode*root=nullptr;
    void preOrder(CSNode*node){
        if(!node){
            return;
        }
        cout<<node->data<<" ";
        preOrder(node->firstChild);
        preOrder(node->nextSibling);
    }
    public:
    void setRoot(char data){
        root=new CSNode(data);
    }
    CSNode* getRoot(){
        return root;
    }
    void addChild(CSNode*parent,char data){
        if(!parent) return;
        CSNode *newNode=new CSNode(data);
        if(!parent->firstChild){
            parent->firstChild=newNode;
        }else{
            CSNode*curr=parent->firstChild;
            while(curr->nextSibling){
                curr=curr->nextSibling;
            }
            curr->nextSibling=newNode;
        }
    }
    void preOrderTraverse(){
        preOrder(root);
    }
};
int main(){
    CSTree tree;
    tree.setRoot('A');
    CSNode*A=tree.getRoot();
    tree.addChild(A,'B');
    tree.addChild(A,'C');
    tree.addChild(A->firstChild,'D');
    tree.preOrderTraverse();
    return 0;
}