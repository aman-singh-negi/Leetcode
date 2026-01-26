class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        vector<int>ans(n);
        int idx=n-1;
        while(left <= right)
        {
            if(abs(nums[left])<abs(nums[right]))
            {
                ans[idx]=nums[right]*nums[right];
                idx--;
                right--;
            }
            else
            {
                ans[idx]=nums[left]*nums[left];
                idx--;
                left++;
            }
        }   
        return ans;
    }
};