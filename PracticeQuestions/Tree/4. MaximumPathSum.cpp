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
    int maxPath(treeNode* root,int & maxi){
        if(root==NULL) return 0;
        int maxL= max(0, maxPath(root->left, maxi));
        int maxR = max(0, maxPath(root->right, maxi));
        
        
        maxi= max(maxi,root->data+maxL+maxR);//stores maximum path sum till current node propogation
        return max(maxL, maxR)+root->data;//returns maximum of left or right to its parent node.
    } 
    
    public:
    int maxPathSum(treeNode* root){
        int maxi=INT_MIN;
        maxPath(root,maxi);
        return maxi;
    }
   
       
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