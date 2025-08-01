class Solution {
public:
    void make(int open,int close,int n,vector<string>&ans,string s)
    {
        if(s.length()==2*n)
        {
            ans.push_back(s);
        }   
        if(open>close)
        {
            make(open,close+1,n,ans,s+')');
        }
        if(open<n)make(open+1,close,n,ans,s+'(');
    }
    vector<string> generateParenthesis(int n) {
        //your code goes here
        vector<string>ans;
        make(0,0,n,ans,"");
        return ans;
    }
};