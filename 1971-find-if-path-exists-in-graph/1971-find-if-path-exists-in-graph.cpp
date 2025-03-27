class Solution {
private:
    void dfs(vector<vector<int>>&graph,vector<bool>&visited,int src)
    {
        visited[src]=true;
        for(int i=0;i<graph[src].size();i++)
        {
            if(visited[graph[src][i]]==false)dfs(graph,visited,graph[src][i]);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n,vector<int>());
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,false);
        dfs(graph,visited,source);
        return visited[destination];
    }
};