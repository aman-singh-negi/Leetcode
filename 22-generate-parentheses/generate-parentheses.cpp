class Solution {
public:
    void f(vector<string>&ans,int open,int close,int n,string s)
    {
        if(s.size()==2*n)
        {
            ans.push_back(s);
            return;
        }
        if(open<n)f(ans,open+1,close,n,s+"(");
        if(close<open)f(ans,open,close+1,n,s+")");
    }
    vector<string> generateParenthesis(int n) 
    {
        //Number of Open Brackets < N
        //Number of Close Brackers < Number of Open Brackts
        vector<string>ans;
        f(ans,0,0,n,"");
        return ans;
    }
};