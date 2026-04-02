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
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;

        int left = solve(root->left);
        left = (left<0)?0:left;
        int right = solve(root->right);
        right = (right<0)?0:right;
        if(root->val+left+right > ans) ans = root->val+left+right;

        return root->val + max(left,right); 
    }
    int maxPathSum(TreeNode* root) {
        int a = solve(root);
        return ans;
    }
};
