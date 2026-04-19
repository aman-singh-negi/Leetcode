class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int idx=0,idy=0;
        int maxi=0;
        while(idx < nums1.size() && idy<nums2.size())
        {
            if(idx==idy)
            {
                if(nums1[idx]<=nums2[idy])
                {
                    maxi=max(maxi,idy-idx);
                    idy++;
                }
                else
                {
                    idx++;
                    idy++;
                }
            }
            else if(idx<idy)
            {
                if(nums1[idx]<=nums2[idy])
                {
                    maxi=max(maxi,idy-idx);
                    idy++;
                }
                else
                {
                    idx++;
                }
            }
            else
            {
                idy++;
            }
        }
        return maxi;
    }
};