class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int res;
        vector<int> a;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            res=target-nums[i];
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j && res==nums[j])
                {
                a.push_back(i);
                a.push_back(j);
                    cnt++;
                }
            }
            if(cnt==1)
              break;
            }
    return a;
    }
};