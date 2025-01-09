class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakpoint =-1;
        //Finding the Breakpoint where the next element is greater than the previous element
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                breakpoint=i-1;
                break;
            }
        }
        if(breakpoint==-1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        //Finding the element greater than that element
        int idx=-1;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[breakpoint])
            {
                idx=i;
                break;
            }
        }   
        //Swapping both elements 
        swap(nums[idx],nums[breakpoint]);
        reverse(nums.begin()+breakpoint+1,nums.end());
    }
};