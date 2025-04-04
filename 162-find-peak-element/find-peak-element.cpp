class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int low=1,high=arr.size()-2;
        if(arr.size()==1)return 0;
        if(arr[0]>arr[1])return 0;
        if(arr[arr.size()-1]>arr[arr.size()-2])return arr.size()-1;
        while(low<=high)
        {
            int mid=low +(high-low)/2;
            if(arr[mid-1]< arr[mid] && arr[mid+1]<arr[mid])return mid;
            else if(arr[mid-1]<arr[mid])low=mid+1;
            else if(arr[mid+1]<arr[mid])high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};