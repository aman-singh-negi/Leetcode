class Solution {
public:
    bool check(vector<int>& nums) {
        int check=0;
        if(nums[0]>=nums[nums.size()-1])check++;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(check==1 && nums[i]>nums[i+1])
            {
                check++;
            }
            else if(check==0 && nums[i]>nums[i+1])return false;
            else if(nums[i] >nums[i+1] && check==2)return false;
        }
        return true;
    }
};