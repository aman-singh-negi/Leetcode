class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long sumx = 0;
            for (int j = 0; j < m; j++) {
                total += grid[i][j];
                sumx += grid[i][j];
            }
            row[i] = sumx;
        }
        for (int i = 0; i < m; i++) {
            long long sumy = 0;
            for (int j = 0; j < n; j++) {
                sumy += grid[j][i];
            }
            col[i] = sumy;
        }
        // Horizontal Cut
        long long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += row[i];
            if (sum == total - sum)
                return true;
        }
        sum = 0;
        for (int i = 0; i < m - 1; i++) {
            sum += col[i];
            if (sum == total - sum)
                return true;
        }
        return false;
    }
};