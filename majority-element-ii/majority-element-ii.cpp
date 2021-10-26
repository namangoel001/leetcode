class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> vec;
        int count1=0;
        int count2=0;
        int maj1=-1;
        int maj2=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maj1)
            {
                count1++;
            }
            else if(nums[i]==maj2)
            {
                count2++;
            }
            else if(count1==0)
            {
                maj1=nums[i];
                count1++;
            }
            else if(count2==0)
            {
                maj2=nums[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maj1)
                count1++;
            else if(nums[i]==maj2)
                count2++;
        }
        if(count1>nums.size()/3)
            vec.push_back(maj1);
        if(count2>nums.size()/3)
            vec.push_back(maj2);
        return vec;
    }
};