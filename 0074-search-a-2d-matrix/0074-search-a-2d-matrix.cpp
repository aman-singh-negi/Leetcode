class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]<=target && target<=matrix[i][matrix[0].size()-1])
            {
                int low=0,high=matrix[0].size()-1;
                while(low<=high)
                {
                    int mid=low+(high-low)/2;
                    if(matrix[i][mid]>target)
                    {
                        high=mid-1;
                    }
                    else if(matrix[i][mid]<target)
                    {
                        low=mid+1;
                    }
                    else return true;
                }
            }
        }
        return false;
    }
    //Most Optimised
    //TC:- O(log(n*m))
    //SC:- O(1)
};