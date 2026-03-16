#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    LNode *next;
}LNode,*LinkList;
void InitList(LinkList &L){
    L=new LNode;
    L->next=L;//指向自己形成环
}
//尾插法创建链表
void InsertTail(LinkList L,int val){
    LNode *p=L;
    while(p->next!=L){
        p=p->next;
    }
    LNode *s=new LNode;
    s->data=val;
    s->next=L;
    p->next=s;
}
//遍历循环列表
void Traverse(LinkList L){
    LNode *p=L->next;
    if(p==L){
        cout<<"链表为空"<<endl;
        return;
    }
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=L);
    cout<<endl;
}
int main(){
    LinkList L;
    InitList(L);
    //尾插
    InsertTail(L,10);
    InsertTail(L,20);
    InsertTail(L,30);
    InsertTail(L,40);
    cout<<"循环链表：";
    Traverse(L);
    return 0;
}
