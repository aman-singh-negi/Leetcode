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
    int findHeight(TreeNode* root)
    {
        if(root==NULL)return 0;
        int leftH=findHeight(root->left);
        int rightH=findHeight(root->right);
        if(abs(leftH-rightH)>1)return -1;
        //if((root->left==NULL && root->right!=NULL)||(root->left!=NULL && root->right==NULL))return -1;
        if(leftH==-1 || rightH==-1)return -1;
        else return 1+ max(leftH,rightH);
    }
    bool isBalanced(TreeNode* root) 
    {
        if(findHeight(root)!=-1)return true;
        else return false;
    }
};