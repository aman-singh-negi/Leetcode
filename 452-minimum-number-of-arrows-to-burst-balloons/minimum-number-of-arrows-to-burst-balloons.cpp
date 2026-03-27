class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        if(a[1]<b[1])return true;
        return false;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        long long endtime=LLONG_MIN;
        sort(points.begin(),points.end(),comp);
        int cnt=0;
        for(int i=0;i<points.size();i++)
        {
            if(endtime<points[i][0])
            {
                cnt++;
                endtime=points[i][1];
            }
        }
        return cnt;
    }
};