class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxN=0;
        for(int i=0;i<nums.size();i++)
        {
            if(maxN>=i)
                maxN=max(maxN,i+nums[i]);
        }
        if(maxN>=nums.size()-1)
            return true;
        return false;
    }
};