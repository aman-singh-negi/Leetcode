class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int startTime=intervals[0][0];
        int endTime=intervals[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<intervals.size();i++)
        {
            if(endTime>=intervals[i][0])
            {
                //Merge
                endTime=max(endTime,intervals[i][1]);
            }
            else
            {
                ans.push_back({startTime,endTime});
                startTime=intervals[i][0];
                endTime=intervals[i][1];
            }
        }
        ans.push_back({startTime,endTime});
        return ans;
    }
};