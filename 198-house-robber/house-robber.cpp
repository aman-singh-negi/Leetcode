class Solution {
public:
    int rob(vector<int>& money) {
        int n=money.size();
        vector<int>dp(n+1,0);
        dp[1]=money[0];
        for(int i=2;i<=n;i++)
        {
            dp[i]=max(dp[i-1],money[i-1]+dp[i-2]);
        }
        return dp[n];
    }
};