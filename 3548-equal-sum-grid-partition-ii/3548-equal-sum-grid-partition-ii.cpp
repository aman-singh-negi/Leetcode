class Solution {
public:
    bool solve(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,int> bottom, top;
        long long bottomsum=0,topsum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                bottomsum+=grid[i][j];
                bottom[grid[i][j]]++;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m;j++)
            {
                topsum+=grid[i][j];
                top[grid[i][j]]++;
                bottomsum-=grid[i][j];
                bottom[grid[i][j]]--;
                if(bottom[grid[i][j]]==0)bottom.erase(grid[i][j]);
            }
            //Conditions
            if(topsum==bottomsum)return true;
            long long diff=topsum-bottomsum;
            if(diff>0 && abs(diff)<=100000)
            {
                //Top section is greater
                if(grid[0][0]==diff || grid[0][m-1]==diff)return true;
                if(m==1 && diff==grid[i][0])return true;
                if(i>0 && m>1  && top.count(diff))return true;
            }
            else if(abs(diff)<=100000){
                //Bottom section is Greater
                diff=diff*(-1);
                if(grid[i+1][0]==diff || grid[i+1][m-1]==diff)return true;
                if(m==1 && grid[n-1][0]==diff)return true;
                if((n-i-1)>1 && m>1 && bottom.count(diff))return true;
            }
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        //Horizontal Cuts
        if(solve(grid))return true;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>transpose(m,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                transpose[j][i]=grid[i][j];
            }
        }
        //Vertical Cuts
        if(solve(transpose))return true;
        return false;
    }
};