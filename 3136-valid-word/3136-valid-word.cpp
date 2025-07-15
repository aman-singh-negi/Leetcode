class Solution {
public:
    bool isVowel(char ch)
    {
        ch=tolower(ch);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;
        return false;
    }
    bool isValid(string word) {
        if(word.size()<3)return false;
        int vFlag=0,cFlag=0;
        for(int i=0;i<word.size();i++)
        {
            if(!isalnum(word[i]))return false;
            if(isalpha(word[i]) && isVowel(word[i]))vFlag=1;
            else if(isalpha(word[i])) cFlag=1;
        }
        if(vFlag==0)return false;
        if(cFlag==0)return false;
        return true;
    }
};