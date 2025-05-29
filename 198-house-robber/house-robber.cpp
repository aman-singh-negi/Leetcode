class Solution {
private:
    int find(vector<int>&nums,int n,int dp[])
    {
        if(n==0)return nums[n];
        if(n<=0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=max(nums[n]+find(nums,n-2,dp),find(nums,n-1,dp));
    }
public:
    int rob(vector<int>& nums) 
    {
        //Memoization
        int n=nums.size();
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return find(nums,n-1,dp);
    }
};