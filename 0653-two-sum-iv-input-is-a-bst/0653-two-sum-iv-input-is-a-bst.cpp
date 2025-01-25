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
class BstIterator
{
    private:
        bool n=false;
        stack<TreeNode*>st;
        void pushNode(TreeNode* root,bool n)
        {
            while(root!=NULL)
            {
                st.push(root);
                if(n) root=root->left;
                else root=root->right;
            }
        }
    public:
        BstIterator(TreeNode* root,bool n)
        {
            this->n=n;
            pushNode(root,n);
        }
        int next()
        {
            TreeNode* temp=st.top();
            st.pop();
            int v=temp->val;
            if(n && temp->right)pushNode(temp->right,n);
            else if(!n && temp->left)pushNode(temp->left,n);
            return v;
        }
        bool hasNext()
        {
            if(st.empty())return false;
            return true;
        }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) 
    {
        BstIterator N(root,true);
        BstIterator B(root,false);
        int i=N.next();
        int j=B.next();
        while(i<j)
        {
            if(i+j>k)j=B.next();
            else if(i+j<k)i=N.next();
            else return true;
        }
        return false;
    }
};