#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector <int> v={3,5,6,0,2,0,5,9,3,6};
    //1.输出原始数组
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    //2.排序
    sort(v.begin(),v.end());
    for(auto i=v.begin();i!=v.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    //3.去重
    auto i=unique(v.begin(),v.end());
    v.erase(i,v.end());
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    //4.反转
    reverse(v.begin(),v.end());
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    //5.查找
    int val;
    cout<<"请输入要查找的元素：";
    cin>>val;
    auto it=find(v.begin(),v.end(),val);
    if(it!=v.end()){
        cout<<"找到了，位置是"<<distance(v.begin(),it)<<endl;
    }else{
        cout<<"没找到"<<endl;
    }
    return 0;
}