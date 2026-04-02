class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt=0;
        sort(intervals.begin(),intervals.end(),comp);
        int endPoint=INT_MIN;
        for(int i=0;i<intervals.size();i++)
        {
            if(endPoint>intervals[i][0])
            {
                cnt++;
                continue;
            }
            endPoint=max(endPoint,intervals[i][1]);
        }
        return cnt;
    }
};