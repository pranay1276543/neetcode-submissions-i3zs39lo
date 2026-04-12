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
    int solve(TreeNode* root, int k,int& cnt){
        if(!root) return -1;

        int leftans = solve(root->left,k,cnt);
        if(leftans!=-1) return leftans;
        cnt++;
        if(k==cnt) return root->val;
        

        int rightans = solve(root->right,k,cnt);
        return rightans;

    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        return solve(root,k,cnt);
    }
};
