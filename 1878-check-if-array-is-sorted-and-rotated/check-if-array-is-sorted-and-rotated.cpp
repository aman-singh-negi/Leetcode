class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int cnt=0;
        if(nums[0]<nums[nums.size()-1])cnt++;
        int flag=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1])flag=1;
        }
        if(!flag)return true;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])cnt++;
        }
        if(cnt==1)return true;
        return false;
    }
};