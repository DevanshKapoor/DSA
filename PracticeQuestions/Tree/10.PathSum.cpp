//https://leetcode.com/problems/path-sum/submissions/1355765358/
//followed top down approach as compared to the bottom up approach of height problem 
// used finalsum as the carrier of remaining sum , subtracted node value from it and called its child nodes with new value
// on reaching leaf node checked if sum is 0 or not




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
    bool isLeaf(TreeNode* node){
        if(node->left==NULL && node->right==NULL){
            return true;
        }

        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }

        int newSum=targetSum-root->val;

        if(isLeaf(root)){
            if(newSum==0){
                return true;
            }
            return false;
        }

        return hasPathSum(root->left, newSum) || hasPathSum(root->right, newSum);


    }
};