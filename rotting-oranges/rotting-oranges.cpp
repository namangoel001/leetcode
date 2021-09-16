class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int min_time=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        vector<vector<int>> arr={{1,0},{-1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            int len=q.size();
            min_time++;
            for(int i=0;i<len;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int x=p.first+arr[k][0];
                    int y=p.second+arr[k][1];
                    if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==1)
                    {
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return min_time==0?min_time :min_time-1;
    }
};