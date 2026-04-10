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
    void add(TreeNode* root, int val){
        if(!root->left && root->val>val){
            TreeNode* temp = new TreeNode(val);
            root->left = temp;
            return ;
        }
        if(!root->right && root->val<val){
            TreeNode* temp = new TreeNode(val);
            root->right = temp;
            return ;
        }
        if(val<root->val) add(root->left,val);
        if(val>root->val) add(root->right,val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        add(root,val);
        return root;
    }
};