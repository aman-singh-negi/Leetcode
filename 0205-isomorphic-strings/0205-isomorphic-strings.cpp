class Solution {
private:
    bool check(string s, string t)
    {
        unordered_map<char,char>mpp;
        for(int i=0;i<s.length();i++)
        {
            if(mpp.find(s[i])==mpp.end())
            {
                mpp[s[i]]=t[i];
            }
            else
            {
                if(mpp[s[i]]!=t[i])return false;
            }
        }
        return true;
    }
public:
    bool isIsomorphic(string s, string t) {
        return check(s,t) && check(t,s);
    }
};