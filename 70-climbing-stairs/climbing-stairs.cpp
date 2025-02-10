class Solution {
public:
    int calculate(int n,vector<int>&v)
    {
        if(n<=2)return n;
        if(v[n]!=-1)return v[n];
        v[n]=calculate(n-1,v)+calculate(n-2,v);
        return v[n];
    }
    int climbStairs(int n) {
        //Memoization
        vector<int>v(n+1,-1);
        return calculate(n,v);
    }
};