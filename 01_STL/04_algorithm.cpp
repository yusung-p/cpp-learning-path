//算法，vector deque list string 普通数组都可以用
//注意：list不能用std::sort和std::reverse，必须用list自己的成员函数sort和reverse
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(int x){
    cout << x << " ";
}
int main(){
    vector<int> v = {3,1,4,1,5,9};
    // 1. 遍历
    cout<<"原数据： ";
    for_each(v.begin(), v.end(), print);
    cout << endl;
    // 2. 排序
    sort(v.begin(), v.end());
    cout<<"排序后： ";
    for_each(v.begin(),v.end(),print);
    cout << endl;
    //3.反转
    reverse(v.begin(),v.end());
    cout<<"反转后： "; 
    for_each(v.begin(),v.end(),print);
    cout << endl;
    //4.查找
    int val=5;
    auto it=find(v.begin(),v.end(),val);
    if(it!=v.end()){
        cout<<"找到"<<val<<endl;
    }else{
        cout<<"未找到"<<val<<endl;
    }
    //5.稳定排序
    stable_sort(v.begin(), v.end());
    cout<<"稳定排序后： ";
    for_each(v.begin(), v.end(), print);
    cout << endl;
    //6.去重，先排序再unique
    auto last=unique(v.begin(),v.end());
    v.erase(last,v.end());
    cout<<"去重后： ";
    for_each(v.begin(), v.end(), print);
    cout << endl;
    //7.数出现次数
    int count_val=1;
    int count_result=count(v.begin(),v.end(),count_val);
    cout<<"元素"<<count_val<<"出现次数："<<count_result<<endl;
    //8.二分查找，先排序
    sort(v.begin(), v.end());
    bool found=binary_search(v.begin(),v.end(),val);
    if(found){
        cout<<"二分查找找到"<<val<<endl;
    }else{
        cout<<"二分查找未找到"<<val<<endl;
    }
    return 0;
}