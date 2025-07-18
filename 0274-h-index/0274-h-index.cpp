class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            if(maxi<citations[i])maxi=citations[i];
        }
        vector<int>hash(maxi+1,0);
        for(int i=0;i<n;i++)
        {
            hash[citations[i]]++;
        }
        for(int i=maxi-1;i>=0;i--)
        {
            hash[i]=hash[i]+hash[i+1];
        }
        int ans=-1;
        for(int i=0;i<=maxi;i++)
        {
            if(hash[i]>=i)
            {
                ans=max(i,ans);
            }
        }
        return ans;
    }
};