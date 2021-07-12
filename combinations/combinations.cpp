class Solution {
public:
    void combination(vector<vector<int>> &vec,vector<int> &v,int k,int start,int end)
    {
        if(v.size()==k)
        {
            vec.push_back(v);
            return;
        }
        while(start<=end)
        {
        v.push_back(start);
        combination(vec,v,k,start+1,end);
        v.pop_back();
        start++;
        }
    }
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>> vec;
        vector<int> v;
        combination(vec,v,k,1,n);
            return vec;
    }
};