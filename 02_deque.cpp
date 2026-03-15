#include <iostream>
#include <deque>
using namespace std;
int main(){
    //创建deque
    deque<int> dq;
    //头尾插入
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);//vector是队列先进先出，只能从后端插入和删除，deque是双端队列，可以在头尾插入和删除
    dq.push_front(1);
    //中间插入
    dq.insert(dq.begin()+2,15);//在索引2的位置插入15，中间插入删除效率略优于vector，因为deque底层是分段连续的内存，而vector是连续的内存，插入删除需要移动元素
    //删除中间元素
    dq.erase(dq.begin()+3);//删除索引3的元素
    //遍历
    cout <<"deque元素：";
    for(int num:dq){
        cout<<num<<" ";
    }
    cout<<endl;
    //访问元素
    cout<<"第一个元素："<<dq.front()<<endl;
    cout<<"最后一个元素："<<dq.back()<<endl;
    cout<<"索引1的元素："<<dq[1]<<endl;
    //deque长度
    cout<<"deque长度："<<dq.size()<<endl;
    //删除头尾
    dq.pop_front();
    dq.pop_back();
    cout<<"删除后deque元素：";
    for(int num:dq){
        cout<<num<<" ";
    }
    cout<<endl;
    //清空deque
    dq.clear();
    cout<<"清空后deque长度："<<dq.size()<<endl;
    return 0;
}