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
    int max_ans = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;

        int leftans = solve(root->left);
        leftans = leftans<0?0:leftans;
        int rightans = solve(root->right);
        rightans = rightans<0?0:rightans;

        max_ans = max(max_ans,leftans+rightans+root->val);

        return root->val+max(leftans,rightans);
    }
    int maxPathSum(TreeNode* root) {
        int a = solve(root);
        return max_ans;
    }
};
