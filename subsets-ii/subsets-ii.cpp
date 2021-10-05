class Solution {
public:
    void make_sub(set<vector<int>> &vec,vector<int> v,vector<int> &nums,int start)
    {
        if(start==nums.size())
        {
            vec.insert(v);
            return;
        }
       make_sub(vec,v,nums,start+1);
       v.push_back(nums[start]);
       make_sub(vec,v,nums,start+1);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> vec;
        vector<vector<int>> res;
        vector<int> v;
        sort(nums.begin(),nums.end());
        make_sub(vec,v,nums,0);
        for(auto it:vec)
            res.push_back(it);
        return res;
    }
};