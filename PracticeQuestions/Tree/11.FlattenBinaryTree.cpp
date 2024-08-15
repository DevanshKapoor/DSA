//leetcode problem: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

//MY SOLUTION (perfectly fine but optimal possible)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void preorder(TreeNode* node, queue<int>& qu){
        if(node==NULL){
            return ;
        }
       qu.push(node->val);
       preorder(node->left, qu);
       preorder(node->right, qu); 
    }



public:
    void flatten(TreeNode* root) {
        queue<int> qu;
        preorder(root,qu);
        qu.pop();
        if(root==NULL){
            return;
        }
        while(!qu.empty()){
            if(!root->right){
                root->right= new TreeNode();
            }
            root->left=NULL;
            root=root->right;
            root->val=qu.front();
            qu.pop();

            
        }
    }
};


//OPTIMAL SOLUTION
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        
       if(root==NULL){
           return;
       }
       flatten(root->right);
       flatten(root->left);
       root->right = prev;
       root->left = NULL;
       prev = root;
    }
};


