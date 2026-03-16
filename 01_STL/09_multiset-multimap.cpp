//multiset multimap可以存储重复的元素，自动排序
//multimap不能用【】访问元素，因为可能有重复的key
#include <iostream>
#include <set>
#include <map>  
using namespace std;
int main(){
    multiset<int>ms;
    ms.insert(2);
    ms.insert(1);
    ms.insert(2);//可以重复
    //删除
    ms.erase(2);//删除所有的2
    ms.erase(ms.find(1));//删除一个1
    multimap<int,string>mm;
    mm.insert({1,"a"});
    mm.insert({1,"b"});//key可以重复
    //查找一组相同key
    auto range=mm.equal_range(1);
    for(auto it=range.first;it!=range.second;it++){
        cout<<it->second<<" ";//输出a b
    }
    cout<<endl;
    return 0;
}