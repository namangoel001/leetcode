class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> vec;
        int r=matrix.size();
        int c=matrix[0].size();
        int m=0;
        int n=0;
        while(m<r && n<c)
        {
            for(int i=m;i<c;i++)
                vec.push_back(matrix[m][i]);
            m++;
            for(int i=m;i<r;i++)
                vec.push_back(matrix[i][c-1]);
            c--;
            if(m<r)
            {
                for(int i=c-1;i>=n;i--)
                    vec.push_back(matrix[r-1][i]);
                r--;
            }
            if(n<c)
            {
                for(int i=r-1;i>=m;i--)
                    vec.push_back(matrix[i][n]);
                n++;
            }
        }
        return vec;
    }
};