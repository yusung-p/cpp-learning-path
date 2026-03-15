//按key值自动排序（默认升序），key值不能重复
#include <iostream>
#include <map>
using namespace std;
int main(){
    map<int,string>m;
    //插入（两种方式）
    m[1]="张三";
    m.insert({2,"李四"});
    m[1]="张三改";//覆盖已有的key的值
    //访问
    cout<<m[1]<<endl;
    //查找
    auto it=m.find(2);
    if(it!=m.end()){
        cout<<it->first<<"->"<<it->second<<endl;
    }else{
        cout<<"没有找到"<<endl;
    }
    //遍历
    for(auto&p:m){
        cout<<p.first<<"->"<<p.second<<endl;
    }
    //删除
    m.erase(1);
    //大小
    cout<<"大小:"<<m.size()<<endl;
    return 0;
}