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
    bool check (TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }
        if((p==NULL && q!=NULL)|| (p!=NULL && q==NULL) || (p->val != q->val) ){
            return false;
        }
        bool leftans = check(p->left,q->left);
        bool rightans = check(p->right,q->right);

        return leftans && rightans;
    }

    bool solve(TreeNode* root, TreeNode* subRoot){
        if(!root) return false;

        if(root->val == subRoot->val){
            if(check(root,subRoot)) return true;
        }

        bool leftans = solve(root->left,subRoot);
        bool rightans = solve(root->right,subRoot);

        return leftans || rightans;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root,subRoot);
    }
};
