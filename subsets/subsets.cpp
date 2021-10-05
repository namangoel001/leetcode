class Solution {
public:
    void make_sub(vector<vector<int>> &ans,vector<int> v,vector<int> &nums,int start)
    {
     if(start==nums.size())
     {
         ans.push_back(v);
         return;
     }
        make_sub(ans,v,nums,start+1);
        v.push_back(nums[start]);
        make_sub(ans,v,nums,start+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        make_sub(ans,v,nums,0);
        return ans;
    }
};