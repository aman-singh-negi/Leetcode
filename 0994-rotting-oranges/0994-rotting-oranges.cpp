class Solution {
private:
    void bfs(vector<vector<int>>&grid,int& cnt,queue<pair<int,int>>&q,int idx[],int idy[],int& fresh)
    {
        while(!q.empty())
        {
            int size=q.size();
            bool isOrange=false;
            for(int j=0;j<size;j++)
            {
                pair<int,int>temp=q.front();
                int sr=temp.first;
                int sc=temp.second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int newSr=sr+idx[i];
                    int newSc=sc+idy[i];
                    if(newSr>=0 && newSr<grid.size() && newSc>=0 && newSc<grid[0].size() && grid[newSr][newSc]==1)
                    {
                        fresh--;
                        q.push({newSr,newSc});
                        grid[newSr][newSc]=2;
                        isOrange=true;
                    }
                }
            }
            if(isOrange)cnt++;
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int cnt=0;
        int idx[4]={-1,0,+1,0};
        int idy[4]={0,+1,0,-1};
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)fresh++;
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        bfs(grid,cnt,q,idx,idy,fresh);
        if(fresh)return -1;
        return cnt;
    }
};