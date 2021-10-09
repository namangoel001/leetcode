class Solution {
public:
    
    long long int count_jump(vector<int>& nums,int curr,int dest, vector<int>&dp){
        if(curr>=dest)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        long long int tmp=INT_MAX;
        for(int i=1;i<=nums[curr];i++)
        {
            tmp=min(tmp,1+count_jump(nums,curr+i,dest,dp));
        }
        return dp[curr]=tmp;
    }
    int jump(vector<int>& nums){
        vector<int>dp(nums.size(),-1);
       return count_jump(nums,0,nums.size()-1,dp);
    }
};