class Solution {
public:
    int dp[1000][1000];
    int find_path(int m,int n)
    {
        if(m==1 && n==1)
            return 1;
        if(m<1 || n<1)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        return dp[m][n]=find_path(m-1,n) + find_path(m,n-1);
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
     memset(dp,-1,sizeof(dp));
        return find_path(m,n);
    }
};