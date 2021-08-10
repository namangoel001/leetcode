class Solution {
public:
    // bool partition(vector<int>& nums,int sum,int i,vector<vector<int>>&t)
    // {
    //     //base case
    //     if(sum==0)return true;
    //     if(i>=nums.size())return false;
    //     if(t[i][sum]!=-1)
    //         return t[i][sum];
    //     //rec step
    //     if(nums[i]<=sum)
    //         return t[i][sum]=partition(nums,sum-nums[i],i+1,t)||partition(nums,sum,i+1,t);
    //     else 
    //         return t[i][sum]=partition(nums,sum,i+1,t);
    // }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2)
            return false;
        sum/=2;
        bool dp[nums.size()+1][sum+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=nums.size();i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=nums.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                 if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else  
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[nums.size()][sum];
    }
};