class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& matrix, int x, int y, int k) {
        int top=x;
        int bottom=x+k-1;
        while(top<bottom)
        {
            for(int i=y;i<y+k;i++)
            {
                swap(matrix[top][i],matrix[bottom][i]);
            }
            top++;
            bottom--;
        }
        return matrix;
    }
};