class Solution {
private:
    void dfs(vector<vector<int>>&image,int base,int color,int idx[],int idy[],int sr,int sc)
    {
        image[sr][sc]=color;
        for(int i=0;i<4;i++)
        {
            int new_I=idx[i]+sr;
            int new_J=idy[i]+sc;
            if(0<= new_I && new_I<image.size() && 0<=new_J && new_J<image[0].size() && image[new_I][new_J]==base)
            {
                dfs(image,base,color,idx,idy,new_I,new_J);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int base=image[sr][sc];
        if(base==color)return image;
        int idx[]={-1,0,+1,0};
        int idy[]={0,+1,0,-1};
        dfs(image,base,color,idx,idy,sr,sc);
        return image;
    }
};