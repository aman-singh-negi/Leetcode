class Solution {
public: 
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int starttime=intervals[0][0];
        int endtime=intervals[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++)
        {
            if(endtime>=intervals[i][0])
            {
                //Merge
                endtime=max(endtime,intervals[i][1]);
            }
            else
            {
                ans.push_back({starttime,endtime});
                starttime=-1;
                starttime=intervals[i][0];
                endtime=intervals[i][1];
            }
        }
            ans.push_back({starttime,endtime});
        return ans;

    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};