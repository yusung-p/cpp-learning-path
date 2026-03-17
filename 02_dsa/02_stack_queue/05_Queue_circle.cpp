#include <iostream>
using namespace std;
const int MAXSIZE=100;
template <typename T>
class QueueCircle{
    private:
    T data[MAXSIZE];
    int front;
    int rear;
    public:
    QueueCircle(){
        front=0;
        rear=0;
    }
    bool isEmpty()const{
        return front==rear;
    }
    bool isFull()const{
        return(rear+1)%MAXSIZE==front;
    }
    bool enQueue(const T&val){
        if(isFull()) return false;
        data[rear]=val;
        rear=(rear+1)%MAXSIZE;
        return true;
    }
    bool deQueue(){
        if(isEmpty()) return false;
        front=(front+1)%MAXSIZE;
        return true;
    }
    bool getFront(T&val)const{
        if(isEmpty()) return false;
        val=data[front];
        return true;
    }
    int size( )const{
        return(rear-front+MAXSIZE)%MAXSIZE;
    }
};
int main(){
    QueueCircle<int>q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    int val;
    while(!q.isEmpty()){
        q.getFront(val);
        cout<<val<<" ";
        q.deQueue();
    }
    cout<<endl;
    return 0;
}