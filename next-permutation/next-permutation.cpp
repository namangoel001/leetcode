class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1)
            return;
        int n=nums.size()-1;
        while(n>0)
        {
            if(nums[n]>nums[n-1])
            {
                break;
            }
            n--;
        }
        if(n==0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        else
        {
            for(int i=nums.size()-1;i>=n;i--)
            {
                if(nums[n-1]<nums[i])
                {
                    swap(nums[n-1],nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin()+n,nums.end());
    }
};