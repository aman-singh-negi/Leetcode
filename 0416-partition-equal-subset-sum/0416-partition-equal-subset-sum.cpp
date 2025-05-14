class Solution {
public:
    bool check(vector<int>&nums,int sum,int n,vector<vector<int>>&dp)
    {
        if(sum==0)return true;
        if(n==0)return false;
        if(sum<nums[n-1])return dp[n][sum]= check(nums,sum,n-1,dp);
        return dp[n][sum]=check(nums,sum,n-1,dp) || check(nums,sum-nums[n-1],n-1,dp);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1==1)return false;
        sum=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        for(int i=0;i<=sum;i++)dp[0][i]=0;
        for(int i=0;i<=n;i++)dp[i][0]=0;
        return check(nums,sum,n,dp);
    }
};