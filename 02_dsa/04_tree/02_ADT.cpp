#include <iostream>
#include <vector>
using namespace std;
//树的抽象数据类型接口
template <typename T>
class TreeADT{
    public:
    virtual ~TreeADT()=default;
    virtual bool isEmpty() const=0;
    virtual T getRoot() const=0;
    virtual void setRoot(T data)=0;
    virtual void addChild(T parentData,T childData)=0;
    virtual void preOrderTraverse() const=0;
};
//基于孩子表示法的实现
template <typename T>
class Tree:public TreeADT<T>{
    private:
    struct Node{
        T data;
        vector <Node*>children;
        Node(T val):data(val){};
    };
    Node*root=nullptr;
    Node*findNode(Node*node,T data)const{
        if(!node){
            return nullptr;
        }
        if(node->data==data)return node;
        for(Node*child:node->children){
            Node*res=findNode(child,data);
            if(res) return res;
        }
        return nullptr;
    }
    void preOrder(Node*node)const{
        if(!node){
            return;
        }
        cout<<node->data<<" ";
        for(Node*child:node->children){
            preOrder(child);
        }
    }
    public:
    bool isEmpty() const override{
        return root==nullptr;
    }
    T getRoot()const override{
        return root?root->data:T();
    }
    void setRoot(T data) override{
        root=new Node(data);
    }
    void addChild(T parentData,T childData) override{
        Node*parent=findNode(root,parentData);
        if(parent){
            parent->children.push_back(new Node(childData));
        }
    }
    void preOrderTraverse()const override{
        preOrder(root);
    }
};
int main(){
    Tree<char> tree;
    tree.setRoot('A');
    tree.addChild('A','B');
    tree.addChild('A','C');
    tree.addChild('B','D');
    cout<<"树是否为空："<<(tree.isEmpty()?"是":"否")<<endl;
    cout<<"根结点："<<tree.getRoot()<<endl;
    cout<<"前序遍历：";
    tree.preOrderTraverse();
    return 0;
}