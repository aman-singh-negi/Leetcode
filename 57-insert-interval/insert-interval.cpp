class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int i=0;
        for(i=0;i<intervals.size();i++)
        {
            if(newInterval[0]>intervals[i][1])
            {
                ans.push_back(intervals[i]);
            }
            else break;
        }
        if(i==intervals.size())
        {
            ans.push_back(newInterval);
            return ans;
        }
        //Merge
        int startTime=min(intervals[i][0],newInterval[0]);
        int endTime=max(intervals[i][1],newInterval[1]);
        i++;
        for(i;i<intervals.size();i++)
        {
            if(endTime>=intervals[i][0])
            {
                //Merge
                endTime=max(intervals[i][1],endTime);
            }
            else break;
        }
        ans.push_back({startTime,endTime});
        for(i;i<intervals.size();i++)
        {
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};