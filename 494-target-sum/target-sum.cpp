class Solution {
private:
    int find(vector<int>&nums,int target,int n,int sum)
    {
        if(target==sum && n==0)return 1;
        if(n==0)return 0;
        return find(nums,target,n-1,sum+nums[n-1]) + find(nums,target,n-1,sum-nums[n-1]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return find(nums,target,n,0);
    }
};