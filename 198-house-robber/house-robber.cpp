class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev0=0;
        int prev1=nums[0];
        for(int i=2;i<=n;i++)
        {
            int take=INT_MIN;
            int notTake=prev1;
            take=nums[i-1]+prev0;
            prev0=prev1;
            prev1=max(take,notTake);
        }
        return prev1;
    }
};