//单链表不是一整块数组，是一个结点连一个结点
//每个结点=数据+指向下一个结点的指针
//优点：插入删除不用移动大量元素  缺点：不能随机访问，只能从头遍历
#include <iostream>
using namespace std;
//单链表结点结构
typedef struct LNode{
    int data;//数据域
    struct LNode *next;//指针域,指向下一个结点
} LNode, *LinkList;
//初始化单链表（带头结点）
bool InitList(LinkList &L){
    L=new LNode;//创建头结点
    if(L==NULL) return false;//内存分配失败
    L->next=NULL;//暂时没有后继
    return true;
}
//尾插：在链表最后加一个值为e的结点
bool ListInsertTail(LinkList &L,int e){
    LNode *s=new LNode;//创建新结点
    if(s==NULL) return false;//内存分配失败
    s->data=e;//赋值
    s->next=NULL;//新结点暂时没有后继
    //找到链表最后一个结点
    LNode *p=L;//从头结点开始
    while(p->next!=NULL){
        p=p->next;//继续往后找
    }
    p->next=s;//将新结点连接到链表末尾
    return true;
}
//头插：在链表头部加一个值为e的结点
bool ListInsertHead(LinkList &L,int e){
    LNode *s=new LNode;//创建新的结点
    if(s==NULL) return false;//内存分配失败
    s->data=e;//赋值
    s->next=L->next;//新结点的后继指向原来头结点的后继
    L->next=s;//头结点的后继指向新结点
    return true;
}
//在第i个位置插入一个值为e的结点
bool ListInsertINI(LinkList &L,int i,int e){
    if(i<1) return false;//位置不合法
    LNode *p=L;
    int j=0;//j记录p指向的结点位置
    //找到第i-1个结点
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL) return false;//位置不合法
    LNode *s=new LNode;//创建新结点
    if(s==NULL) return false;//内存分配失败
    s->data=e;//赋值
    s->next=p->next;//将新结点的后继指向第i个结点
    p->next=s;//将第i-1个结点的后继指向新结点
    return true;
}
//删除第i个位置的结点
bool ListDeleteINI(LinkList &L,int i){
    if(i<1){
        return false;//位置不合法
    }
    LNode *p=L;
    int j=0;//j记录p指向的结点位置
    //找到第i-1个结点
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL||p->next==NULL){
        return false;//位置不合法
    }LNode *q=p->next;//q指向第i个结点
    p->next=q->next;//将第i-1个结点的后继指向第i+1个结点
    delete q;//释放第i个结点的内存
    return true;
}
//按值查找，返回第一个值为e的结点位置
LNode*LocateElem(LinkList L,int e){
    LNode *p=L->next;//从第一个结点开始
    while(p!=NULL){
        if(p->data==e){
            return p;//找到返回指针
        }
        p=p->next;//继续往后走
    }
    return NULL;//没找到返回NULL
}
//链表反转
void ReverseList(LinkList &L){
    LNode *pre=NULL;
    LNode *cur=L->next;
    LNode *next;
    while(cur!=NULL){
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    L->next=pre;
}
//打印链表
void PrintList(LinkList L){
    LNode *p=L->next;//从第一个结点开始
    while(p!=NULL){
        cout<<p->data<<" ";//输出数据
        p=p->next;//继续往后走
    }
    cout<<endl;
}
int main(){
    LinkList L;
    InitList(L);//初始化链表
    //尾插
    ListInsertTail(L,1);
    ListInsertTail(L,2);
    ListInsertTail(L,3);
    ListInsertTail(L,4);
    ListInsertTail(L,5);
    cout<<"初始链表：";
    PrintList(L);//打印链表
    //在第三个位置插入9
    ListInsertINI(L,3,9);
    cout<<"在第三位插入9后：";
    PrintList(L);
    //删除第二位
    ListDeleteINI(L,2);
    cout<<"删除第二位后：";
    PrintList(L);
    //查找值为4的结点
    LNode *node=LocateElem(L,4);
    if(node){
        cout<<"找到"<<node->data<<endl;
    }
    //反转链表
    ReverseList(L);
    cout<<"反转后：";
    PrintList(L);
    return 0;
}