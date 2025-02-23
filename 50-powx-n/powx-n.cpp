class Solution {
public:
    double p(double x,long long m)
    {
        if(m==0)return 1;
        double half=p(x,m/2);
        if(m%2==0)return half*half;
        else return half*half*x;
    }
    double myPow(double x, int m) {
        long long n=m;
        if(m<0){
            n=(-1)*n;
            x=1/x;
        }
        return p(x,n);
    }
};