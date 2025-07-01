class Solution {
public:
    int possibleStringCount(string word) 
    {
        int ans=1;
        for(int i=0;i<word.size()-1;i++)
        {
            ans+=(word[i]==word[i+1])?1:0;
        }
        return ans;
    }
};