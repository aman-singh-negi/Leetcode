class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int src) {
        for (int neighbor : graph[src]) {
            if (visited[neighbor] == -1) {
                visited[neighbor] = 1 - visited[src];
                if (!dfs(graph, visited, neighbor)) return false;
            } 
            else if (visited[neighbor] == visited[src]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);

        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) { 
                visited[i] = 0;
                if (!dfs(graph, visited, i)) return false;
            }
        }
        return true;
    }
};
