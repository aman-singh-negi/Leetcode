class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        if(n==1)return nums[0];
        dp[0]=0;
        dp[1]=nums[1];
        for(int i=2;i<n;i++)
        {
            int take=nums[i]+dp[i-2];
            int notTake=dp[i-1];
            dp[i]=max(notTake,take);
        }
        int first=dp[n-1];
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<n;i++)
        {
            int take=nums[i-1]+dp[i-2];
            int notTake=dp[i-1];
            dp[i]=max(notTake,take);
        }
        int second =dp[n-1];
        return max(first,second);
    }
};