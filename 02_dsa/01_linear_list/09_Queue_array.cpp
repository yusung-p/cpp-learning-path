# include <iostream>
using namespace std;
const int MAXSIZE=100;
template <typename T>
class QueueArray{
    private:
    T data[MAXSIZE];
    int front;
    int rear;
    public:
    QueueArray(){
        front=0;
        rear=0;
    }
    bool isEmpty()const{
        return front==rear;
    }
    bool isFull()const{
        return rear==MAXSIZE;
    }
    bool enQueue(const T&val){
        if(isFull()) return false;
        data[rear++]=val;
        return true;
    }
    bool deQueue(){
        if(isEmpty()) return false;
        front++;
        return true;
    }
    bool getFront(T&val)const{
        if(isEmpty()) return false;
        val=data[front];
        return true;
    }
    int size()const{
        return rear-front;
    }
};
int main(){
    QueueArray<int>q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    int val;
    while(!q.isEmpty()){
        q.getFront(val);
        cout<<val<<" ";
        q.deQueue();
    }
    cout<<endl;
    return 0;
}