class Solution {
public:
    int find(int n)
    {
        int sum=0;
        while(n!=0)
        {
            int d=n%10;
            n=n/10;
            sum+=d;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            mini=min(mini,find(nums[i]));
        }
        return mini;
    }
};