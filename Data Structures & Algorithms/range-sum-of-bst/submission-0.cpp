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
    int solve(TreeNode* root, int low, int high){
        if(!root){
            return 0;
        }
        int left =0,right=0;
        if(root->val >= low && root->val <= high){
            left = solve(root->left,low,high);
            right = solve(root->right,low,high);
            return root->val + left + right;
        }
        else if(root->val < low){
            right = solve(root->right,low,high);
        }
        else if(root->val > high){
            left = solve(root->left,low,high);
            
        }
        return left + right;
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root,low,high);
    }
};