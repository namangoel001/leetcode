class Solution {
public:
    void combination(vector<vector<int>> &vec,vector<int> &v,vector<int>& candidates,int sum,int start,int target)
    {
        if(sum==target)
        {
            vec.push_back(v);
            return;  
        }
        if(start==candidates.size())
            return;
        if(sum>target)return;
        v.push_back(candidates[start]);
        combination(vec,v,candidates,sum+candidates[start],start+1,target);
        v.pop_back();
        int j=start;
        while(j<candidates.size()-1 && candidates[j]==candidates[j+1])
            j++;
        combination(vec,v,candidates,sum,j+1,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     vector<vector<int>> vec;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        combination(vec,v,candidates,0,0,target);
        return vec;
    }
};