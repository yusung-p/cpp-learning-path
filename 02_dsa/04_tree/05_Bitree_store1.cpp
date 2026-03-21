//¶þ²æÊ÷µÄ´æ´¢½á¹¹£¬Ë³Ðò´æ´¢
#include <iostream>
#include <vector>
using namespace std;
class SeqBiTree{
    private:
    vector<char>tree;
    int size;
    public:
    SeqBiTree(int maxSize):tree(maxSize,'#'),size(0){}
    void insert(int index,char data){
        if(index<(int)tree.size()){
            tree[index]=data;
            size++;
        }
    }
    void printTree(){
        for(size_t i=1;i<tree.size();++i){
            if(tree[i]!='#'){
                cout<<tree[i]<<" ";
            }
        }
        cout<<endl;
    }
};
int main(){
    SeqBiTree tree(10);
    tree.insert(1,'A');
    tree.insert(2,'B');
    tree.insert(3,'C');
    tree.insert(4,'D');
    cout<<"Ë³Ðò´æ´¢¶þ²æÊ÷£º";
    tree.printTree();
    return 0;
}