//自动排序 自动去重
//查找/插入/删除：O(logn)
#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> s;
    //插入
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(3);//重复，自动忽略
    //遍历
    for(int x:s){
        cout<<x<<" ";
    }
    cout<<endl;
    //查找
    auto it=s.find(2);
    if(it!=s.end()){
        cout<<"Found: "<<*it<<"位置在"<<distance(s.begin(),it)<<endl;
    }else{
        cout<<"Not found"<<endl;
    }
    //删除
    s.erase(2);
    //大小
    cout<<"Size: "<<s.size()<<endl;
    //清空
    s.clear();
    cout<<"Size after clear: "<<s.size()<<endl;
    return 0;
}