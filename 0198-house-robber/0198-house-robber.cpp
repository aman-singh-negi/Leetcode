class Solution {
private:
    int solve(vector<int>& nums,int n,vector<int>&dp)
    {
        //Memoization
        if(n<=0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=max(nums[n-1] + solve(nums,n-2,dp), solve(nums,n-1,dp));
    }
public:
    int rob(vector<int>& nums) {
        //Tabulation
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int prev0=nums[0];
        int prev1=max(nums[0],nums[1]);
        int ans=0;
        for (int i = 2; i < n; i++) {
            ans= max(prev1, prev0 + nums[i]);
            prev0=prev1;
            prev1=ans;
        }
        return ans;
    
}
};