class Solution {
private:
    int solve(vector<int>& nums,int n,vector<int>&dp)
    {
        if(n<=0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=max(nums[n-1] + solve(nums,n-2,dp), solve(nums,n-1,dp));
    }
public:
    int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)return nums[0];
    vector<int>dp(n+1,-1);
    return solve(nums,n,dp);
    }
};