class Solution {
public:
    void permute(vector<int> &vec,vector<int> &v,int k,int &count,vector<bool> &vis,int start)
    {
        if(v.size()==k)
        {
            for(auto it:v)
                cout<<it;
            cout<<" ";
            count++;
            return;
        }
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]%(start+1)==0 || (start+1)%vec[i]==0)
            {
            if(vis[i]==0)
            {
                vis[i]=1;
                v.push_back(vec[i]);
                permute(vec,v,k,count,vis,start+1);
                v.pop_back();
                vis[i]=0;
            }
            }
        }
    }
    int countArrangement(int n) {
        vector<int> vec;
        vector<int> v;
        int count=0;
        for(int i=1;i<=n;i++)
            vec.push_back(i);
        vector<bool> vis(vec.size(),0);
        permute(vec,v,n,count,vis,0);
        return count;
    }
};