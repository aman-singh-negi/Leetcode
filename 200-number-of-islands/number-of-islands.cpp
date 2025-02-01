class Solution {
public:
    void bfs(vector<vector<char>>&grid,int i,int j)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='0';
        while(!q.empty())
        {
            pair<int,int>temp=q.front();
            q.pop();
            if(temp.first>0 && grid[temp.first-1][temp.second]=='1')
            {
                q.push({temp.first-1,temp.second});
                grid[temp.first-1][temp.second]='0';
            }
            if(temp.second>0 && grid[temp.first][temp.second-1]=='1')
            {
                q.push({temp.first,temp.second-1});
                grid[temp.first][temp.second-1]='0';
            }
            if(temp.second+1<grid[0].size() && grid[temp.first][temp.second+1]=='1')
            {
                q.push({temp.first,temp.second+1});
                grid[temp.first][temp.second+1]='0';
            }
            if(temp.first+1<grid.size() && grid[temp.first+1][temp.second]=='1')
            {
                q.push({temp.first+1,temp.second});
                grid[temp.first+1][temp.second]='0';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    bfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};