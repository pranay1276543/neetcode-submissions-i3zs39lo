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
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};

        pair<int,int> leftans = solve(root->left);
        pair<int,int> rightans = solve(root->right);

        int ans = 1+leftans.second+rightans.second;
        ans = max(ans,max(leftans.first,rightans.first));

        return {ans,1+max(leftans.second,rightans.second)};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first-1;
    }
};
