class Solution {
public:
    bool check_col(vector<string>& mat,int col)
    {
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            if(mat[i][col]=='Q') return false;
        }
        return true;
    }
    bool check_diagonal(vector<string> &mat,int row,int col)
    {
        int n=mat.size();
        int i=row;
        int j=col;
        while(i>=0 && j>=0)
        {
            if(mat[i][j]=='Q') return false;
            else
            {
                i--,j--;
            }
        }
        i=row;
        j=col;
        while(i>=0 && j<n)
        {
            if(mat[i][j]=='Q') return false;
            else
            {
                i--;
                j++;
            }
        }
        return true;
    }
    void fun(vector<vector<string>> &res,vector<string> &mat,int n)
    {
        if(n==0)
        {
            res.push_back(mat);
            return;
        }
        for(int i=0;i<mat.size();i++)
        {
            if(check_col(mat,i) && check_diagonal(mat,mat.size()-n,i))
            {
                mat[mat.size()-n][i]='Q';
                fun(res,mat,n-1);
                mat[mat.size()-n][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> mat(n,string(n,'.'));
        fun(res,mat,n);
        return res;
    }
};