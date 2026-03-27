class Solution {
public: 
    static bool comp(vector<int>&a,vector<int>&b)
    {
        if(a[0]<b[0])return true;
        if(a[0]==b[0])
        {
            if(a[1]<b[1])return true;
            return false;
        }
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int starttime=intervals[0][0];
        int endtime=intervals[0][1];
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(endtime>=intervals[i][0])
            {
                //Merge
                endtime=max(endtime,intervals[i][1]);
            }
            else
            {
                if(starttime!=-1)
                {
                    ans.push_back({starttime,endtime});
                    starttime=-1;
                }
                starttime=intervals[i][0];
                endtime=intervals[i][1];
            }
        }
        if(starttime!=-1)
        {
            ans.push_back({starttime,endtime});
        }
        return ans;

    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};