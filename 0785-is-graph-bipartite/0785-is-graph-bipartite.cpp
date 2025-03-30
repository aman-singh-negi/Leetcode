class Solution {
    private:
        bool dfs(vector<vector<int>>&graph,vector<int>&visited,int src)
        {
            for(int i=0;i<graph[src].size();i++)
            {
                if(visited[graph[src][i]]==-1)
                {
                    visited[graph[src][i]]=1-visited[src];
                    if(!dfs(graph,visited,graph[src][i]))return false;
                }
                else if(visited[graph[src][i]]==visited[src])
                {
                    return false;
                }
            }
            return true;
        }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,-1);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                visited[i]=0;
                if(!dfs(graph,visited,i))return false;
            }
        }
        return true;
    }
};
