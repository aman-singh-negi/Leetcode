class Solution {
private:
    // int find(vector<int>&nums,int n,int dp[])
    // {
    //     if(n==0)return nums[n];
    //     if(n<=0)return 0;
    //     if(dp[n]!=-1)return dp[n];
    //     return dp[n]=max(nums[n]+find(nums,n-2,dp),find(nums,n-1,dp));
    // }
public:
    int rob(vector<int>& nums) 
    {
        //Tabulation
        int n=nums.size();
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++)
        {
            dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        }
        return dp[n];
    }
};