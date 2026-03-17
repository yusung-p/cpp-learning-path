#include <iostream>
using namespace std;
const int MAXSIZE=100;
template <typename T>
class Stack{
    private:
        T data[MAXSIZE];
        int top;//Õ»¶¥Ö¸Õë
    public:
    Stack(){
        top=-1;
    }
    //ÈëÕ»
    bool push(T val){
        if(top>=MAXSIZE-1){
            cout<<"Õ»Âú"<<endl;
            return false;
        }
        data[++top]=val;
        return true;
    }
    //³öÕ»
    bool pop(){
        if(top==-1){
            cout<<"Õ»¿Õ"<<endl;
            return false;
        }
        top--;
        return true;
    }
    //È¡Õ»¶¥
    T getTop(){
        if(top==-1){
            cout<<"Õ»¿Õ"<<endl;
            return false;
        }
        return data[top];
    }
    //ÅÐ¶Ï¿Õ
    bool isEmpty(){
        return top==-1;
    }
};
int main(){
    Stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<"Õ»¶¥£º"<<st.getTop()<<endl;
    st.pop();
    cout<<"popºóÕ»¶¥£º"<<st.getTop()<<endl;
    return 0;
}