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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        int flag=0;
        vector<vector<int>>result;
        if(root==NULL)return result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>level(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(flag==0)level[i]=node->val;
                else level[size-i-1]=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            flag=!flag;
            result.push_back(level);
        }
        return result;
    }
};