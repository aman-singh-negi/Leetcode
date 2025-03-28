class Solution {
private:
    void dfs(vector<vector<int>>&graph,int src,vector<bool>&visited)
    {
        visited[src]=true;
        for(int i=0;i<graph[src].size();i++)
        {
            if(visited[graph[src][i]]==false)
            dfs(graph,graph[src][i],visited);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<bool>visited(n,false);
        vector<vector<int>>graph(n,vector<int>());
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(graph,source,visited);
        return visited[destination];
    }
};