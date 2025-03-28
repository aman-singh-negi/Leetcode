class Solution {
private:
    void dfs(vector<vector<int>>&image,int sr,int sc,int idx[],int idy[],int target,int color)    
    {
        image[sr][sc]=color;
        for(int i=0;i<4;i++)
        {
            int new_sr=sr+idx[i];
            int new_sc=sc+idy[i];
            if(new_sr>=0 && new_sr<image.size() && new_sc>=0 && new_sc<image[0].size() && image[new_sr][new_sc]==target)
            {
                dfs(image,new_sr,new_sc,idx,idy,target,color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        if(color==image[sr][sc])return image;
        int target=image[sr][sc];
        int idx[]={-1,0,+1,0};
        int idy[]={0,+1,0,-1};
        dfs(image,sr,sc,idx,idy,target,color);
        return image;
    }
};