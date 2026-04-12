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
    int solve(TreeNode* root, int m){
        if(!root) return 0;
        int ans=0;
        int max = m;
        if(root->val>=m){
            ans = 1;
            max=root->val;
        }
        return ans+solve(root->left,max)+solve(root->right,max);
    }
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};
