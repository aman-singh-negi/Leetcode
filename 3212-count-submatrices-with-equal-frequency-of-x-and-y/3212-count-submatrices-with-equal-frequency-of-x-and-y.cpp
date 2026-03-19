class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>gridX(n,vector<int>(m,0));
        vector<vector<int>>gridY(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x = (grid[i][j] == 'X');
                int y = (grid[i][j] == 'Y');

                gridX[i][j] = x;
                gridY[i][j] = y;

                if(i > 0) {
                    gridX[i][j] += gridX[i-1][j];
                    gridY[i][j] += gridY[i-1][j];
                }
                if(j > 0) {
                    gridX[i][j] += gridX[i][j-1];
                    gridY[i][j] += gridY[i][j-1];
                }
                if(i > 0 && j > 0) {
                    gridX[i][j] -= gridX[i-1][j-1];
                    gridY[i][j] -= gridY[i-1][j-1];
                }
                if(gridX[i][j]==gridY[i][j] && gridX[i][j]>0)count++;
            }
        }
        return count;
    }
};