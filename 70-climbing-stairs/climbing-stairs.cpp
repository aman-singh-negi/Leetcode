class Solution {
private:
    int memo(int n,vector<int>&v)
    {
        if(n<=1)return 1;
        if(v[n]!=-1)return v[n];
        return v[n]=memo(n-1,v)+memo(n-2,v);
    }
public:
    int climbStairs(int n) {
        vector<int>v(n+1,-1);
        return memo(n,v);
    }
};