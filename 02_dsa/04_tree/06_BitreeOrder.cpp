//遍历二叉树
#include <iostream>
#include <queue>
using namespace std;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T){
    char ch;
    cin>>ch;
    if(ch=='#'){
        T=NULL;
    }else{
        T=new BiTNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
//前序遍历
void PreOrder(BiTree T){
    if(T){
        cout<<T->data<<" ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历
void InOrder(BiTree T){
    if(T){
        InOrder(T->lchild);
        cout<<T->data<<" ";
        InOrder(T->rchild);
    }
}
//后序遍历
void PostOrder(BiTree T){
    if(T){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout<<T->data<<" ";
    }
}
//层序遍历
void LevelOrder(BiTree T){
    if(!T) return;
    queue<BiTree>q;
    q.push(T);
    while(!q.empty()){
        BiTree p=q.front();
        q.pop();
        cout<<p->data<<" ";
        if(p->lchild) q.push(p->lchild);
        if(p->rchild) q.push(p->rchild);
    }
}
int main(){
    BiTree T;
    cout<<"请输入二叉树先序序列："<<endl;
    CreateBiTree(T);
    cout<<"前序遍历：";
    PreOrder(T);
    cout<<endl;
    cout<<"中序遍历：";
    InOrder(T);
    cout<<endl;
    cout<<"后序遍历：";
    PostOrder(T);
    cout<<endl;
    cout<<"层序遍历：";
    LevelOrder(T);
    cout<<endl;
    return 0;
}