class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int idx=0,idy=m-1;
        while(idx<n && idy>=0)
        {
            if(matrix[idx][idy]<target)
            {
                idx++;
            }
            else if(matrix[idx][idy]>target)
            {
                idy--;
            }
            else return true;
        }
        return false;
    }
};