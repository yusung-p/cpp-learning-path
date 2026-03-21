//二叉树
#include <iostream>
using namespace std;
//二叉树节点
struct BiTNode{
    char data;
    BiTNode*lchild;
    BiTNode*rchild;
    BiTNode(char val):data(val),lchild(nullptr),rchild(nullptr){}
};
using BiTree =BiTNode*;
BiTree buildSampleTree(){
    BiTree A=new BiTNode('A');
    BiTree B=new BiTNode('B');
    BiTree C=new BiTNode('C');
    BiTree D=new BiTNode('D');
    A->lchild=B;
    A->lchild=C;
    B->lchild=D;
    return A;
}
//前序遍历
void preOrder(BiTree T){
    if(T){
        cout<<T->data<<"";
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}
int main(){
    BiTree T=buildSampleTree();
    cout<<"二叉树前序遍历：";
    preOrder(T);
    return 0;
}