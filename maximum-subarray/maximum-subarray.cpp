class Solution {
public:
    int maxSubArray(vector<int>& a) 
    {
    int i=0;
    int sum=0;
    int max1=INT_MIN;
	while(i<a.size() && a[i]<0)
    {
     max1=max(max1,a[i]);
         i++;
    }
    if(i==a.size())
        return max1;
    for(int j=i;j<a.size();j++)
    {
        if(sum<0)
            sum=0;
        sum+=a[j];
        max1=max(max1,sum);
    }
        return max1;
    }
};