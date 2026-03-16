//顺序表：用数组实现，随机访问快，插入删除慢（连续内存地址）
#include <iostream>
using namespace std;
#define MAXSIZE 100//顺序表最大容量
//1.顺序表结构体定义
typedef struct{
    int data[MAXSIZE];//存放数据的数组
    int length;//当前长度
}SqList;
//2.初始化顺序表
void InitList(SqList &L){
    L.length=0;
}
//3.打印顺序表
void PrintList(SqList L){
    for(int i=0;i<L.length;i++){
        cout <<L.data[i]<<" ";
    }
    cout <<endl;
}
//4.尾插元素
bool ListAdd(SqList &L,int e){
    if(L.length>=MAXSIZE){
        return false;
    }
    L.data[L.length++]=e;
    return true;
}
//5.顺序表原地逆置
void Reverse(SqList &L){
    int i=0;
    int j=L.length-1;
    while(i<j){
        //交换data[i]和data[j]
        int temp=L.data[i];
        L.data[i]=L.data[j];
        L.data[j]=temp;
        i++;
        j--;
    }
}
//主函数测试
int main(){
    SqList L;
    InitList(L);
    //造测试数据
    ListAdd(L,1);
    ListAdd(L,2);
    ListAdd(L,3);
    ListAdd(L,4);
    ListAdd(L,5);
    cout<<"原顺序表：";
    PrintList(L);
    Reverse(L);
    cout<<"倒置后：";
    PrintList(L);
    return 0;
}