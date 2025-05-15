class Solution {
private:
    int find(vector<int>&nums,int n,vector<int>&dp)
    {
        if(n<=0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]= max(nums[n-1]+find(nums,n-2,dp),find(nums,n-1,dp)); 
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        dp[0]=0;
        for(int i=1;i<=nums.size();i++)
        {
            if(i==1)
            {
                dp[i]=nums[i-1]+dp[i-1];
            }
            else dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
        }
        return dp[n];
    }
};