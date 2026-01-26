class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx=0;
        if(s.size()==0)return true;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]==s[idx])
            {
                idx++;
            }
            if(idx==s.size())return true;
        }
        return false;
    }
};