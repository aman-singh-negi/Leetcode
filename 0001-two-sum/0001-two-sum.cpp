class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int needmore=  target-nums[i];
            if(mp.find(needmore)!=mp.end())
            {
                return {mp[needmore],i};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};