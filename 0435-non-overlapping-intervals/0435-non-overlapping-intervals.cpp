class Solution {
public: 
    static bool comp(vector<int>a,vector<int>b)
    {
        if(a[1]<b[1])return true;
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int endtime=INT_MIN;
        int cnt=0;
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0]<endtime)
            {
                cnt++;
            }
            else
            {
                endtime=intervals[i][1];
            }
        }
        return cnt;
    }
};