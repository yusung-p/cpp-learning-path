#include <iostream>
using namespace std;
const int MAXSIZE=100;
template <typename T>
class StackShared{
    private:
    T data[MAXSIZE];
    int top1;//’ª1£¨¥”◊ÛµΩ”“
    int top2;//’ª2,¥””“œÚ◊Û
    public:
    StackShared(){
        top1=-1;
        top2=MAXSIZE;
    }
    //≈–∂œ’ª «∑Ò¬˙
    bool isFull()const{
        return top1+1==top2;
    }
    //’ª1≈–ø’
    bool isEmpty1()const{
        return top1==-1;
    }
    //’ª2≈–ø’
    bool isEmpty2()const{
        return top2==MAXSIZE;
    }
    //»Î’ª
    bool push(int stackNum,const T&val){
        if (isFull()) return false;
        if(stackNum==1){
            data[++top1]=val;
        }else if(stackNum==2){
            data[--top2]=val;
        }else{
            return false;
        }
        return true;
    }
    //≥ˆ’ª
    bool pop(int stackNum){
        if(stackNum==1){
            if(isEmpty1()){
                return false;
            }
            top1--;
        }else if(stackNum==2){
            if(isEmpty2()){
                return false;
            }
            top2++;
        }else{
            return false;
        }
        return true;
    }
    //ªÒ»°’ª∂•
    bool getTop(int stackNum,T& val) const{
        if(stackNum==1){
            if(isEmpty1()) return false;
            val=data[top1];
        }else if(stackNum==2){
            if(isEmpty2()) return false;
            val=data[top2];
        }else{
            return false;
        }
        return true;
    }
};
int main(){
    StackShared<int>st;
    st.push(1,10);
    st.push(1,20);
    st.push(2,100);
    st.push(2,200);
    int val;
    st.getTop(1,val);
    cout<<"’ª1∂•£∫"<<val<<endl;
    st.getTop(2,val);
    cout<<"’ª2∂•£∫"<<val<<endl;
    st.pop(1);
    st.pop(2);
    st.getTop(1,val);
    cout<<"pop∫Û’ª1∂•£∫"<<val<<endl;
    st.getTop(2,val);
    cout<<"pop∫Û’ª2∂•£∫"<<val<<endl;
    return 0;
}
