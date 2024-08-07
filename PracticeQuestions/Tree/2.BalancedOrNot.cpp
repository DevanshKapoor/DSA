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

    bool isBalanced(treeNode* root){
        if(treeHeight(root)==-1) return false;
        return true;
    }

    int treeHeight(treeNode* root){
        
        if(root==NULL) return 0;
        int lh=treeHeight(root->left);
        int rh=treeHeight(root->right);

        if(lh==-1 || rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        
        return 1+max(lh,rh);
    }    
};


int main() {
    treeNode* root=new treeNode(1);
    root->left=new treeNode(1);
    root->right=new treeNode(1);
    root->left->right=new treeNode(1);
    Solution sol;
    string ans;
    if(sol.isBalanced(root)){
        ans="balanced";
    } else{
        ans="not balanced";
    }
    cout<<"Given tree is "<<ans<<endl;
    return 0;
}