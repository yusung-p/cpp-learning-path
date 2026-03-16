//静态链表，用数组模拟链表，不使用指针，next存数组下标
#include <iostream>
#define MaxSize 10
using namespace std;
//静态链表节点结构
typedef struct{
    int data;
    int next;
}SLinkList[MaxSize];
//初始化静态链表
void InitStaticList(SLinkList L){
    L[0].next = -1;
    for(int i=1;i<MaxSize-1;i++){
        L[i].next=i+1;
    }
    L[MaxSize-1].next = 1; // 备用链表头
}
//插入元素到第pos个位置
bool Insert(SLinkList L,int pos,int val){
    if(pos < 1 || pos > MaxSize-1) return false;
    int cur=0;
    for(int i=1;i<pos;i++){
        cur=L[cur].next;
        if(cur==-1){
            return false;
        }
    }
    int newSLinkList=L[MaxSize-1].next;
    if(newSLinkList == -1) return false;
    L[MaxSize-1].next=L[newSLinkList].next;
    L[newSLinkList].data=val;
    L[newSLinkList].next=L[cur].next;
    L[cur].next=newSLinkList;
    return true;
}
//遍历静态列表
void Traverse(SLinkList L){
    int p = L[0].next;
    while(p != -1){
        cout<<L[p].data<<" ";
        p = L[p].next;
    }
    cout<<endl;
}
int main(){
    SLinkList L;
    InitStaticList(L);
    Insert(L,1,11);
    Insert(L,2,22);
    Insert(L,3,33);
    Insert(L,4,44);
    cout<<"静态链表:";
    Traverse(L);
    return 0;
}