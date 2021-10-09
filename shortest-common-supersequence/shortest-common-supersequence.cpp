class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(str1[i-1]==str2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<(n+m-dp[n][m]);
        string str;
        while(n>0 && m>0)
        {
            if(str1[n-1]==str2[m-1])
            {
                str.push_back(str1[n-1]);
                n--;
                m--;
            }
            else
            {
                
                if(dp[n-1][m]>dp[n][m-1])
                {
                     str.push_back(str1[n-1]);
                     n--;
                }
                else 
                {   
                    str.push_back(str2[m-1]);
                    m--;
                }
            }
        }
        while(n>0)
        {
            str.push_back(str1[n-1]);
            n--;
        }
        while(m>0)
        {
            str.push_back(str2[m-1]);
            m--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};