#include <iostream>
#include <vector>
using namespace std;
int main(){
    //定义一个存int类型的vector
    vector<int> v;
    //尾部插入元素
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    //访问元素：支持【】随机访问
    cout <<"第一个元素"<< v[0] << endl;
    cout <<"第二个元素"<< v[1] << endl;
    //遍历方式1：使用普通for循环
    cout <<"普通for循环遍历：";
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";    
    }
    //遍历方式2：使用范围for循环
    cout << "\n范围for循环遍历：";
    for(int num : v){
        cout << num << " ";
    }
    //删除尾部元素
    v.pop_back();
    cout << "\n删除尾部元素后，当前vector大小：" << v.size() << endl;
    cout<<"是否为空"<<v.empty()<<endl;
    return 0;
}