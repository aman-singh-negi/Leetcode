class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        if(k%n==0)return true;
        k=k%n;
        vector<vector<int>>rotated=mat;
        for(int i=0;i<m;i++)
        {
            if(i % 2 == 0)
            {
                // left rotate
                reverse(mat[i].begin(), mat[i].begin() + k);
                reverse(mat[i].begin() + k, mat[i].end());
                reverse(mat[i].begin(), mat[i].end());
            }
            else
            {
                // right rotate
                reverse(mat[i].begin(), mat[i].end() - k);
                reverse(mat[i].end() - k, mat[i].end());
                reverse(mat[i].begin(), mat[i].end());
            }
        }
        if(mat==rotated)return true;
        return false;
    }
};