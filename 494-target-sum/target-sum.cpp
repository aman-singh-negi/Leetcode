class Solution {
private:
    int find(vector<int>&nums,int target,int n,int sum,vector<vector<int>>&dp,int maxi)
    {
        if(target==0 && n==0)return 1;
        if(n==0)return 0;
        if(dp[n][sum+maxi]!=-1)return dp[n][sum+maxi];
        return  dp[n][sum+maxi]=find(nums,target-nums[n-1],n-1,sum+nums[n-1],dp,maxi)+find(nums,target+nums[n-1],n-1,sum-nums[n-1],dp,maxi);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //Memoization
        int n=nums.size();
        int SUM=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(2*SUM+1,-1));
        return find(nums,target,n,0,dp,SUM);
    }
};