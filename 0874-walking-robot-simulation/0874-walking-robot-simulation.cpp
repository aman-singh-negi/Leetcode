class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int flag=0;
        //0->North
        //1->East
        //2->South
        //3->West
        unordered_set<long long> st;
        for (auto &o : obstacles) {
            long long key = ((long long)o[0] << 32) | (o[1] & 0xffffffff);
            st.insert(key);
        }
        int x=0,y=0;
        int maxi=INT_MIN;
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]==-2)
            {
                flag-=1;
                if(flag==-1)flag=3;
            }
            else if(commands[i]==-1)
            {
                flag+=1;
                if(flag==4)flag=0;
            }
            else
            {
                int dist=commands[i];
                if(flag==0)
                {
                    //Move North
                    for(int i=0;i<dist;i++)                        
                    {
                        long long key = ((long long)x << 32) | ((y+1) & 0xffffffff);
                        if(st.find(key)!=st.end())
                        {
                            break;
                        }
                        else
                        {       
                            y++;
                        }
                    }
                }
                else if(flag==1)
                {
                    //Move East
                    for(int i=0;i<dist;i++)                        
                    {
                        long long key = ((long long)(x+1) << 32) | (y & 0xffffffff);
                        if(st.find(key)!=st.end())
                        {
                            break;
                        }
                        else
                        {       
                            x++;
                        }
                    }
                }
                else if(flag==2)
                {
                    //Move South
                    for(int i=0;i<dist;i++)                        
                    {
                         long long key = ((long long)x << 32) | ((y-1) & 0xffffffff);
                        if(st.find(key)!=st.end())
                        {
                            break;
                        }
                        else
                        {       
                            y--;
                        }
                    }
                }
                else
                {
                    //Move West
                    for(int i=0;i<dist;i++)                        
                    {
                        long long key = ((long long)(x-1) << 32) | (y & 0xffffffff);
                        if(st.find(key)!=st.end())
                        {
                            break;
                        }
                        else
                        {       
                            x--;
                        }
                    }
                }
                maxi=max(maxi,x*x+y*y);
            }
        }
        return maxi;
    }
};