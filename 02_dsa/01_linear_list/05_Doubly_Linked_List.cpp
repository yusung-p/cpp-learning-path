#include <iostream>
using namespace std;
//双向链表结点定义
typedef struct DNode{
    int data;
    DNode*prior;
    DNode*next;
}DNode ,*DLinkList;
//初始化
void InitList(DLinkList &L){
    L=new DNode;
    L->prior=L;
    L->next=L;
}
//尾插法
void InsertTail(DLinkList L,int val){
    DNode *p=L;
    while(p->next!=L){
        p=p->next;
    }
    DNode *s=new DNode;
    s->data=val;
    s->prior=p;
    s->next=L;
    p->next=s;
    L->prior=s;
}
//遍历
void Traverse(DLinkList L){
    DNode *p=L->next;
    while(p!=L){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    DLinkList L;
    InitList(L);
    InsertTail(L,10);
    InsertTail(L,20);
    InsertTail(L,30);
    InsertTail(L,40);
    cout<<"双向链表：";
    Traverse(L);
    return 0;
}
