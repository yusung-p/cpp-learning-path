//孩子表示法
#include <iostream>
#include <vector>
using namespace std;
struct ChildNode{
    int childIndex;
    ChildNode*next;
    ChildNode(int idx):childIndex(idx),next(nullptr){}
};
//表头结点
struct HeaderNode{
    char data;
    ChildNode*firstChild;
    HeaderNode(char val):data(val),firstChild(nullptr){}
};
class ChildTree{
    private:
    vector<HeaderNode*>nodes;
    int rootIndex=-1;
    public:
    void addNode(char data,int parentIndex=-1){
        nodes.push_back(new HeaderNode(data));
        int newIndex=nodes.size()-1;
        if(parentIndex==-1){
            rootIndex=newIndex;
        }else{
            ChildNode*newChild=new ChildNode(newIndex);
            newChild->next=nodes[parentIndex]->firstChild;
            nodes[parentIndex]->firstChild=newChild;
        }
    }
    void printTree(){
        for(size_t i=0;i<nodes.size();++i){
            cout<<"节点"<<i<<"("<<nodes[i]->data<<"):";
            ChildNode*curr=nodes[i]->firstChild;
            while(curr){
                cout<<curr->childIndex<<" ";
                curr=curr->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    ChildTree tree;
    tree.addNode('A');
    tree.addNode('B',0);
    tree.addNode('C',0);
    tree.addNode('D',1);
    tree.printTree();
    return 0;
}
