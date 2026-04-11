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
    TreeNode* findleftmax(TreeNode* root){
        if(root->right != NULL){
            return findleftmax(root->right);
        }
        else{
            return root;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val == key){
            if(!root->left && !root->right){
                delete(root);
                return NULL;
            }
            else if(!root->left || !root->right){
                TreeNode* temp = (root->left)?root->left:root->right;
                delete(root);
                return temp;
            }
            else{
                TreeNode* temp = findleftmax(root->left);
                root->val = temp->val;
                root->left = deleteNode(root->left,temp->val);
                return root;
            }
        }
        else if(key<root->val){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};