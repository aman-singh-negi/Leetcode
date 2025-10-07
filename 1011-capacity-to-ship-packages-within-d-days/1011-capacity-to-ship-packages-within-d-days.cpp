class Solution {
public:
    bool B(vector<int>& weights,int cap, int days )
    {
        int d=1;
        int c=cap;
        for(int i=0;i<weights.size();i++)
        {
            if(c>=weights[i])
            {
                c-=weights[i];
            }
            else
            {
                d++;
                c=cap;
                c-=weights[i];
            }
        }
        if(d<=days)return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(B(weights,mid,days))
            {
                //True Sahi hai
                ans=mid;
                high=mid-1;
            }
            else
            {
                //False 
                low=mid+1;
            }
        }
        return ans;
    }
};