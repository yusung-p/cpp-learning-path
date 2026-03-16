#include <iostream>
#include <list>
using namespace std;
//list不支持随机访问迭代器，所以不能使用下标访问元素
//在任意位置插入和删除元素效率高（比vector和deque更高）
//只能用迭代器iterator遍历
int main(){
      list <int> lt;
      //头插，尾插
      lt.push_back(10);
        lt.push_back(20);
        lt.push_front(5);
        //遍历（只能用迭代器或范围for）
        cout << "list元素：";
        for(int x:lt){
            cout << x << " ";
        }
        cout << endl;
        //取元素大小
        cout << "list大小：" << lt.size() << endl;
        //判断是否为空
        if(lt.empty()){
            cout << "list为空" << endl;
        }else{
            cout << "list不为空" << endl;
        }
        //中间插入，删除
        lt.insert(++lt.begin(), 15); //在第二个位置插入15
        lt.erase(++lt.begin()); //删除第二个位置的元素
        //迭代器遍历
        cout << "修改后list元素：";
        for(auto it = lt.begin(); it != lt.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
        //取头部，尾部
        cout << "头部元素：" << lt.front() << endl;
        cout << "尾部元素：" << lt.back() << endl;
        //头尾删除
        lt.pop_back();
        lt.pop_front();
        cout<<"删除后：";
        for(int x:lt){
            cout<<x<<" ";
        }
        cout<<endl;
        //清空list
        lt.clear();
        return 0;
}