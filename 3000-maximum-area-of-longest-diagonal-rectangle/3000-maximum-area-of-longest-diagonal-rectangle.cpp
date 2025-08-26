#define ll long long
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        ll maxi_d=0;
        int maxi_a=0;
        int n=dimensions.size();
        for(int i=0;i<n;i++)
        {
            ll diag=(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]);
            //No need to take Square Root as we are comparing (:
            if(diag>maxi_d)
            {
                maxi_d=diag;
                maxi_a=dimensions[i][0]*dimensions[i][1];
            }
            else if(diag==maxi_d && maxi_a<dimensions[i][0]*dimensions[i][1])
            {
                maxi_a=dimensions[i][0]*dimensions[i][1];
            }
        }
        return maxi_a;
    }
};