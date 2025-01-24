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
    int calculate(TreeNode* root,int* ans)
    {
        if(root==NULL)return 0;
        int leftH=calculate(root->left,ans);
        int rightH=calculate(root->right,ans);
        *ans=max(*ans,leftH+rightH);
        return 1 + max(leftH,rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        calculate(root,&ans);
        return ans;
    }
};