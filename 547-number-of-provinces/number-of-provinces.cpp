class Solution {
private:
    void dfs(vector<vector<int>>&graph,vector<bool>&visited,int src)
    {
        visited[src]=true;
        for(int i=0;i<graph[src].size();i++)
        {
            if(visited[graph[src][i]]==false)
            {
                dfs(graph,visited,graph[src][i]);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        vector<vector<int>>graph(n,vector<int>());
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    graph[i].push_back(j);
                }
            }
        }
        vector<bool>visited(n,false);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfs(graph,visited,i);
                cnt++;
            }
        }
        return cnt;
    }
};