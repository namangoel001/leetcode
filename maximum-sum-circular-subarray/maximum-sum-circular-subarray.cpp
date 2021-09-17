class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        int max_sum=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
         sum+=nums[i];
        max_sum=max(max_sum,nums[i]);
    }
        int sum1=0;
        int sum2=0;
        int max1=INT_MIN;
        int min1=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            sum1+=nums[i];
            sum2+=nums[i];
            max1=max(max1,sum1);
            min1=min(min1,sum2);
            if(sum1<0)
                sum1=0;
            if(sum2>0)
                sum2=0;
        }
        if(max1<0)
            return max_sum;
        return max1>sum-min1 ?max1 :sum-min1;
    }
};