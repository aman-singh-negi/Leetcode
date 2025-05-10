class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)cnt++;
            else
            {
                if(ans<cnt)ans=cnt;
                cnt=0;
            }
        }
        if(ans<cnt)ans=cnt;
        return ans;
    }
};