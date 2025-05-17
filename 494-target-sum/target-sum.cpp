class Solution {
private:
    int find(vector<int>&nums,int target,int n,int sum)
    {
        if(target==0 && n==0)return 1;
        if(n==0)return 0;
        return find(nums,target-nums[n-1],n-1,sum+nums[n-1]) + find(nums,target+nums[n-1],n-1,sum-nums[n-1]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //BruteForce Pure Recursive
        int n=nums.size();
        return find(nums,target,n,0);
    }
};