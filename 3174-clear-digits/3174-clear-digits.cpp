class Solution {
public:
    string clearDigits(string s) 
    {
        int i=0;
        while(i<s.size())
        {
            if(s[i]>='0' && s[i]<='9')
            {
                s.erase(i-1,2);
                i-=2;
            }
            else i++;
        }
        return s;
    }
};