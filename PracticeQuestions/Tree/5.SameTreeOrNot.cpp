#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//maximum path sum
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
    
};

int main() {
    treeNode* root=new treeNode(-10);
    root->left=new treeNode(9);
    root->right=new treeNode(20);
    root->right->left=new treeNode(15);
    root->right->right=new treeNode(7);
    Solution sol;
    cout<<"maximum path Sum is : "<<sol.maxPathSum(root)<<endl;
    
    return 0;
}