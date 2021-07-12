class Solution {
public:
     void combination(vector<vector<int>> &vec,vector<int> &v,int k,int n,int start,int sum)
    {
        if(v.size()==k && sum==n)
        {
            vec.push_back(v);
            return;  
        }
        if(sum>n || start>9 || v.size()>k)
            return;
        v.push_back(start);
        combination(vec,v,k,n,start+1,sum+start);
        v.pop_back();
        combination(vec,v,k,n,start+1,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<int> v;
         vector<vector<int>> vec;
        combination(vec,v,k,n,1,0);
        return vec;
    }
};