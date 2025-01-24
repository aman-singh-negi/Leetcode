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
        if(leftH<0)leftH=0;
        int rightH=calculate(root->right,ans);
        if(rightH<0)rightH=0;
        *ans=max(*ans,root->val + leftH + rightH);
        return root->val + max(leftH,rightH);
    }
    int maxPathSum(TreeNode* root) 
    {
        int ans=INT_MIN;
        calculate(root,&ans);
        return ans;
    }
};