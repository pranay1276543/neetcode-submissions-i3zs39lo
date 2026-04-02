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

        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        int curr = left.second+right.second+1;

        return {max(curr,max(left.first,right.first)), 1+max(left.second,right.second)};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = solve(root);
        return ans.first-1;        
    }
};
