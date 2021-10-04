class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum1=0;
        int sum=0;
        int max_sum=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            sum1+=nums[i];
            max_sum=max(max_sum,sum1);
            if(sum1<0)
                sum1=0;
        }
        int min_sum=INT_MAX;
        sum1=0;
        for(int i=0;i<nums.size();i++)
        {
            sum1+=nums[i];
            min_sum=min(min_sum,sum1);
            if(sum1>0)
                sum1=0;
        }
        if(max_sum<0)
            return max_sum;
        return max_sum>sum-min_sum? max_sum :sum-min_sum;
    }
};