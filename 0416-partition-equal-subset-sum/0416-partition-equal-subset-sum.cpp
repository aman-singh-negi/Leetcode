class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum&1)==1)return false;
        sum=sum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++)dp[i][0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j<nums[i-1])dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sum];
    }
};