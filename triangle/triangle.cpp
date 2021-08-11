class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& dp) {
        
        for(int i=dp.size()-2; i>=0; i--)
        {
            for(int j=0; j<dp[i].size(); j++)
                dp[i][j]+=min(dp[i+1][j],dp[i+1][j+1]);
        }
        return dp[0][0];
    }
};