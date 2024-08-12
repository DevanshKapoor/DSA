#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//zig-zag traversal
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
    vector<vector<int>> zigZagTraversal(treeNode* root){
        vector<vector<int>> result; // stores traversal
        if(root==NULL){ // if tree is empty
            return result;
        }

        queue<treeNode*> nodeQueue;
        nodeQueue.push(root);
        bool leftToRight =true; // flag variable
        
        while(!nodeQueue.empty()){
            int size=nodeQueue.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                treeNode* node=nodeQueue.front();
                nodeQueue.pop();

                int index= (leftToRight)? i:(size-1-i);

                row[index]=node->data;
                if(node->left){// agar left child exist karta hai toh queue mai push kar do
                    nodeQueue.push(node->left)
                }
                if(node->right){// agar right child exist karta hai toh queue mai push kar do
                    nodeQueue.push(node->right)
                }
            }

            //after this level switch the flag
            leftToRight= !leftToRight;
            result.push_back(row);
        }
        return result;

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