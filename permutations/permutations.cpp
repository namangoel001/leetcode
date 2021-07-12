class Solution {
public:
    void permutation(vector<int> &v,vector<vector<int>> &vec,vector<int> &nums,vector<bool> vis)
    {
        if(v.size()==nums.size())
        {
            vec.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i]==0)
            {
            vis[i]=1;
            v.push_back(nums[i]);
            permutation(v,vec,nums,vis);
            v.pop_back();
            vis[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> vec;
        vector<int> v;
        vector<bool> vis(nums.size(),0);
        permutation(v,vec,nums,vis);
        return vec;
    }
};