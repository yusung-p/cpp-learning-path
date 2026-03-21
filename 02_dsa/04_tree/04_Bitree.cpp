//二叉树
#include <iostream>
#include <cmath>
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
//二叉树的性质
//计算二叉树的深度
int treeDepth(BiTNode*root){
    if(!root) return 0;
    return 1+max(treeDepth(root->lchild),treeDepth(root->rchild));
}
//计算节点总数
int nodeCount(BiTNode*root){
    if(!root) return 0;
    return 1+nodeCount(root->lchild)+nodeCount(root->rchild);
}
//计算叶子节点数
int leafCount(BiTNode*root){
    if(!root){
        return 0;
    }
    if(!root->lchild&&!root->rchild){
        return 1;
    }
    return leafCount(root->lchild)+leafCount(root->rchild);
}
int main(){
    BiTree T=buildSampleTree();
    cout<<"二叉树前序遍历：";
    preOrder(T);
    cout<<"树的深度:"<<treeDepth(T)<<endl;
    cout<<"节点总数："<<nodeCount(T)<<endl;
    cout<<"叶子节点数："<<leafCount(T)<<endl;
    int k=treeDepth(T);
    cout<<"深度"<<k<<"的二叉树最多节点数："<<(pow(2,k)-1)<<endl;
    return 0;
}