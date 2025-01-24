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
    void getCnt(TreeNode* root,int key,int* cnt,int* ans)
    {
        if(root==NULL)
        {
            return;
        }
        getCnt(root->left,key,cnt,ans);
        (*cnt)++;
        if(*cnt==key)
        {
            *ans=root->val;
            return;
        }
        getCnt(root->right,key,cnt,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0,ans=-1;
        getCnt(root,k,&cnt,&ans);
        return ans;
    }
};