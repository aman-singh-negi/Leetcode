class Solution {
public:
    int findClosest(int x, int y, int z) {
        int x_z=abs(x-z);
        int y_z=abs(y-z);
        if(x_z>y_z)return 2;
        else if(x_z<y_z)return 1;
        else return 0;
    }
};