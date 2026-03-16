//unordered_set更快，不自动排序，自动去重
//unordered_map更快，不自动排序，key唯一，value可以重复
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int main(){
    unordered_set<int>s={3,1,4,1,5};
    s.insert(2);
    s.insert(3);//重复元素不会被插入
    for(auto x:s){
        cout<<x<<" ";//输出顺序不固定
    }
    cout<<endl;
    //常用操作与set,map类似
    unordered_map<int,string>m;
    m[1001]="张三";
    m[1002]="李四";
    for(auto &p:m){
        cout<<p.first<<" "<<p.second<<endl;//输出顺序不固定
    }
    return 0;
}