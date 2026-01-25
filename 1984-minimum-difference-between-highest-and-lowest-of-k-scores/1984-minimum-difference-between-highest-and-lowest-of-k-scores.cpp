class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=0,ans=INT_MAX;
        for(int i=k-1;i<n;i++)
        {
            ans=min(ans,abs(nums[mini]-nums[i]));
            mini++;
        }
        return ans;
    }
};