#include <iostream>
#include <deque>
using namespace std;
int main(){
    //创建deque
    deque<int> dq;
    //头尾插入
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);
    //遍历
    cout <<"deque元素：";
    for(int num:dq){
        cout<<num<<" ";
    }
    cout<<endl;
    //访问元素
    cout<<"第一个元素："<<dq.front()<<endl;
    cout<<"最后一个元素："<<dq.back()<<endl;
    //删除头尾
    dq.pop_front();
    dq.pop_back();
    cout<<"删除后deque元素：";
    for(int num:dq){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}