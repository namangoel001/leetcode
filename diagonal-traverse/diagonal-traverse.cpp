class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.size()==0)
            return {};
        vector<int> res;
        int N=mat.size();
        int M=mat[0].size();
        for(int i=0;i<=N+M-2;i++)
        {
            for(int j=0;j<=i;j++)
            {
                int n=j;
                int m=i-n;
                if(i%2==0)
                    swap(n,m);
                if(n>=N || m>=M)
                    continue;
                res.push_back(mat[n][m]);
            }
        }
        return res;
    }
};