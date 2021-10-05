class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       unordered_set<int> s;
        for(int it:nums)
            s.insert(it);
        int max1=*max_element(nums.begin(),nums.end());
        for(int i=1;i<max1;i++)
        {
            if(s.find(i)==s.end())
                return i;
        }
        return max(max1+1,1);
    }
};