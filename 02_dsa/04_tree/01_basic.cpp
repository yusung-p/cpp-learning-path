#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    char data;
    vector<TreeNode*>children;
    TreeNode (char val):data(val){} 
};
//插入子节点
void addChild(TreeNode*parent,TreeNode *child){
    parent->children.push_back(child);
}
//删除树
void deleteTree(TreeNode* root){
    if(!root) return;
    for(TreeNode* child : root->children){
        deleteTree(child);
    }
    delete root;
}
//前序遍历树
void preOrder(TreeNode* root){
    if(!root) return;
    cout<<root->data<<" ";
    for(TreeNode*child:root->children){
        preOrder(child);
    }
}
int main(){
    TreeNode*A=new TreeNode('A');
    TreeNode*B=new TreeNode('B');
    TreeNode*C=new TreeNode('C');
    TreeNode*D=new TreeNode('D');
    addChild(A,B);
    addChild(A,C);
    addChild(B,D);
    cout<<"树的前序遍历：";
    preOrder(A);
    deleteTree(A);
    return 0;
}