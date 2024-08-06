#include <iostream>
using namespace std;
//height of binary tree
//1+max(l+r)
struct treeNode{
    int data;
    treeNode* right;
    treeNode* left;
    treeNode(int val){
        data=val;
        left=right=NULL;
    }
};
    
class Solution{
    public:

    int treeHeight(treeNode* root){
        
        if(root==NULL) return 0;
        int lh=treeHeight(root->left);
        int rh=treeHeight(root->right);
        
        return 1+max(lh,rh);
    }    
};
int main() {
    treeNode* root=new treeNode(1);
    root->left=new treeNode(1);
    root->right=new treeNode(1);
    root->left->right=new treeNode(1);
    Solution sol;
    cout<<"maximum height is : "<<sol.treeHeight(root)<<endl;
    return 0;
}