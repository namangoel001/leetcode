class Solution {
public:
    int maxSubArray(vector<int>& a) 
    {
    int sum=0;
    int max1=INT_MIN;
    for(int j=0;j<a.size();j++)
    {
        sum+=a[j];
        max1=max(max1,sum);
        if(sum<0)
          sum=0;
    }
        return max1;
    }
};