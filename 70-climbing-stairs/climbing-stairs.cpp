class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)return 1;
        int prev0=1;
        int prev1=1;
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            ans=prev0+prev1;
            prev0=prev1;
            prev1=ans;
        }
        return ans;
    }
};