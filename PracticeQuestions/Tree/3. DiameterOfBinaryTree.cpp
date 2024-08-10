//maximum length of path between any 2 nodes of tree is diameter of tree.
// length of path is nodes in path - 1.
#include <iostream>
using namespace std;
//height of binary tree.
//1+max(l+r).
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

    int diameter(treeNode* root){
        int dia=0;
        treeHeight(root,dia);
        return dia;
    }

    int treeHeight(treeNode* root,int & diameter){
        
        if(root==NULL) return 0;
        int lh=treeHeight(root->left,diameter);
        int rh=treeHeight(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }    
};

int main() {
    treeNode* root=new treeNode(1);
    root->left=new treeNode(1);
    root->right=new treeNode(1);
    root->left->right=new treeNode(1);
    Solution sol;
    cout<<"maximum diameter of tree is : "<<sol.diameter(root)<<endl;

    return 0;
}