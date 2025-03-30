class Solution {
    private:
        void bfs(vector<vector<int>>&grid,queue<pair<int,int>>&q,int& fresh,int& cnt,int idx[],int idy[])
        {
            while(!q.empty())
            {
                int size=q.size();
                bool flag=false;
                for(int i=0;i<size;i++)
                {
                    pair<int,int>temp=q.front();
                    q.pop();
                    int ff=temp.first;
                    int ss=temp.second;
                    for(int j=0;j<4;j++)
                    {
                        int new_x=ff+idx[j];
                        int new_y=ss+idy[j];
                        if(0<= new_x && new_x<grid.size() && new_y>=0 && new_y<grid[0].size() && grid[new_x][new_y]==1)
                        {
                            q.push({new_x,new_y});
                            grid[new_x][new_y]=2;
                            fresh--;
                            flag=true;
                        }
                    }
                }
                if(flag)cnt++;
            }
        }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
        int fresh=0;
        int idx[4]={-1,0,+1,0};
        int idy[4]={0,+1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fresh++;
            }
        }
        if(q.empty() && fresh)return -1;
        if(q.empty())return 0;
        int cnt=0;
        bfs(grid,q,fresh,cnt,idx,idy);
        if(fresh>0)return -1;
        return cnt;
    }
};