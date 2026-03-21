//双亲表示法
#include <iostream>
#include <vector>
using namespace std;
struct PNode{
    char data;
    int parent;
};
class ParentTree {
    private:
    vector<PNode>nodes;
    int rootIndex=-1;
    public:
    void addNode(char data,int parentIndex){
        nodes.push_back({data,parentIndex});
        if(parentIndex==-1){
            rootIndex=nodes.size()-1;
        }
    }
    void printTree(){
        for(size_t i=0;i<nodes.size();++i){
            cout<<"节点"<<i<<":数据="<<nodes[i].data<<",双亲下标="<<nodes[i].parent<<endl;
        }
    }
};
int main(){
    ParentTree tree;
    tree.addNode('A',-1);
    tree.addNode('B',0);
    tree.addNode('C',0);
    tree.addNode('D',1);
    tree.printTree();
    return 0;
}