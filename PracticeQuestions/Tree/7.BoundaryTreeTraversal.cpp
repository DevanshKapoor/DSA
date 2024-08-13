#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//boundary tree traversal
// first root then left boundary excluding leaf
// then leaf nodes usinf any dfs (eg: preorder)
// then right boundary excluding leaf
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
    
    bool isLeaf(treeNode* node){
        if(node->left==NULL && node->right==NULL){
            return true;
        }
        return false;
    }

    void leftTraversal(vector<int> & result, treeNode* root){
        treeNode* node=root->left;
        while(!isLeaf(node)){
            result.push_back(node->data);
            if(node->left){
                node=node->left;
            }
            else{
                node=node->right;
            }
        }
    }

    void rightTraversal(vector<int> & result, treeNode* root){
        stack<int> st;
        treeNode* node= root->right;
        while(!isLeaf(node)){
            st.push(node->data);
            if(node->right){
                node=node->right;
            }
            else{
                node=node->left;
            }
        }
        int val;
        while(!st.empty()){
            val=st.top();
            result.push_back(val);
            st.pop();
        }
    }

    void leafTraversal(vector<int> & result, treeNode* root){
        if(!root){
            return;
        }
        if(isLeaf(root)){
            result.push_back(root->data);
            return;
        }

        leafTraversal(result, root->left);
        leafTraversal(result, root->right);
    }

    
    public:
    
    vector<int> boundaryTreeTraversal(treeNode* root){
        vector<int>vec;
        vec.push_back(root->data);
        if(root->left) leftTraversal(vec, root);
        leafTraversal(vec, root);
        if(root->right) rightTraversal(vec, root);

        return vec;
    }
    
};

int main() {
    treeNode* root=new treeNode(-10);
    root->left=new treeNode(9);
    root->left->right=new treeNode(10);
    root->left->right->right=new treeNode(5);
    root->right=new treeNode(20);
    root->right->left=new treeNode(15);
    root->left->left=new treeNode(7);
    root->left->left->right=new treeNode(8);
    root->left->left->right->left=new treeNode(7);
    Solution sol;
    vector<int> vec;
    vec=sol.boundaryTreeTraversal(root);
    cout<<"boundary traversal is :"<<endl;
    for(int num:vec){
        cout<<num<<endl;
    }  
    return 0;
}