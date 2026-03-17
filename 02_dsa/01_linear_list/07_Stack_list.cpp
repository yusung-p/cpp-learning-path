#include <iostream>
using namespace std;
template <typename T>
struct Node{
    T data;
    Node *next;
    Node (T val):data(val),next(nullptr){}
};
template <typename T>
class Stack{
    private:
    Node<T>* topNode;
    public:
    Stack(){
        topNode=nullptr;
    }
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }
    //»Î’ª
    void push(T val){
        Node<T>* newNode=new Node<T>(val);
        newNode->next=topNode;
        topNode=newNode;
    }
    //≥ˆ’ª
    bool pop(){
        if(isEmpty()){
            cout <<"’ªø’"<<endl;
            return false;
        }
        Node <T>*p=topNode;
        topNode=topNode->next;
        delete p; 
        return true;
    }
    //»°’ª∂•
    T getTop(){
        if(isEmpty()){
            cout <<"’ªø’"<<endl;
            return -1;
        }
        return topNode->data;
    }
    bool isEmpty(){
        return topNode==nullptr;
    }
};
int main(){
    Stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<"’ª∂•"<<st.getTop()<<endl;
    st.pop();
    cout<<"pop∫Û’ª∂•"<<st.getTop()<<endl;
    return 0;
}
