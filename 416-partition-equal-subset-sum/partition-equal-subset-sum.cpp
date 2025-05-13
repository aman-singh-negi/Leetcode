class Solution {
private:
    bool checkSubset(vector<int>&arr,int sum,int n)
    {
        vector<bool> prev(sum + 1, false), move(sum + 1);
        prev[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j < arr[i - 1])
                    move[j] = prev[j];
                else
                    move[j] = (prev[j] || prev[j - arr[i - 1]]);
            }
            prev = move;
        }
        return prev[sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1==1)return false;
        int target=sum/2;
        int n=nums.size();
        return checkSubset(nums,target,n);
    }
};