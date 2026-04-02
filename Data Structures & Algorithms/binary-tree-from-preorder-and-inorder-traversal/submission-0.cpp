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
    void map_pre(unordered_map<int,int>& map,vector<int>& inorder){
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
    unordered_map<int,int>& map,int &index,
    int inorderstart,int inorderend){

        if(index > preorder.size() ||  inorderstart>inorderend) return NULL;

        TreeNode* root = new TreeNode(preorder[index]);
        int pos = map[preorder[index]];
        index++;
        root->left = solve(preorder,inorder,map,index,inorderstart,pos-1); 
        root->right = solve(preorder,inorder,map,index,pos+1,inorderend); 
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorder_map;
        map_pre(inorder_map,inorder);
        int s = 0;
        return solve(preorder,inorder,inorder_map,s,0,inorder.size()-1);
    }
};
