#include <iostream>
using namespace std;
template <typename T>
struct Node{
    T data;
    Node*next;
    Node(const T&val):data(val),next(nullptr){}
};
template <typename T>
class QueueList{
    private:
    Node<T>*front;
    Node<T>*rear;
    public:
    QueueList(){
        front=nullptr;
        rear=nullptr;
    }
    ~QueueList(){
        while(front!=nullptr){
            Node<T>*p=front;
            front=front->next;
            delete p;
        }
        rear=nullptr;
    }
    bool isEmpty()const{
        return front==nullptr;
    }
    bool enQueue(const T&val){
        Node<T>*newNode=new Node<T>(val);
        if(isEmpty()){
            front=newNode;
            rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
        }
        return true;
    }
    bool deQueue(){
        if(isEmpty()){
            return false;
        }
        Node<T>*p=front;
        front=front->next;
        if(front==nullptr){
            rear=nullptr;
        }
        delete p;
        return true;
    }
    bool getFront(T&val)const{
        if(isEmpty())return false;
        val =front->data;
        return true;
    }
};
int main(){
    QueueList<int> q;
    q.enQueue(100);
    q.enQueue(200);
    q.enQueue(300);
    int val;
    while(!q.isEmpty()){
        q.getFront(val);
        cout<<val<<" ";
        q.deQueue();
    }
    cout<<endl;
    return 0;
}