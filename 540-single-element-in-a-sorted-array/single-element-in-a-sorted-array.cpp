class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 1) mid--;
            // Check if the pair starts at mid (i.e., nums[mid] == nums[mid + 1])
            if (nums[mid] == nums[mid + 1]) {
                // Unique element must be in the right half
                low = mid + 2;
            } else {
                // Unique element is in the left half or at mid
                high = mid;
            }
        }
        return nums[low];
    }
};