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
    TreeNode* insertIntoBST(TreeNode* root, int key) 
    {
        
        if(root==NULL)return new TreeNode(key);
        else if(root->val>key)root->left=insertIntoBST(root->left,key);
        else if(root->val<key)root->right=insertIntoBST(root->right,key);
        return root;
    }
};