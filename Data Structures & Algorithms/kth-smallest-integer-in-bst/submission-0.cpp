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
    int solve(TreeNode* root,int &curr,int k){
        if(!root) return -1;

        int left = solve(root->left,curr,k);
        if(left!=-1) return left;

        curr++;
        if(curr == k) return root->val;

        return solve(root->right,curr,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return solve(root,i,k);
    }
};
