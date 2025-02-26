class Solution {
private:
    void dfs(vector<vector<int>>&v,int sr,int sc,int color,int target,int idx[],int idy[])
    {
        v[sr][sc]=color;
        for(int i=0;i<4;i++)
        {
            int newSr = sr + idx[i];
            int newSc = sc + idy[i];

            if (0 <= newSr && newSr < v.size() && 0 <= newSc && newSc < v[0].size() && v[newSr][newSc] == target) {
                dfs(v, newSr, newSc, color, target, idx, idy);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> v=image;
        int idx[4]={-1,0,+1,0};
        int idy[4]={0,+1,0,-1};
        int target=image[sr][sc];
        if(target==color)return v;
        dfs(v,sr,sc,color,target,idx,idy);
        return v;
    }
};