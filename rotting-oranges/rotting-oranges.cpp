class Solution {
public:
     int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>que;
        int min_time=0;
        
        int row= grid.size();
        int col= grid[0].size();
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]==2)
                    que.push({i,j});
            }
        }
        
        vector<vector<int>>arr={ {1,0}, {-1,0}, {0,1}, {0,-1} };
        
        while(!que.empty())
        {
            int l=que.size();
            min_time++;
            for(int i=1; i<=l; i++)
            {
                auto[o,j]= que.front();
                que.pop();
                
                for(int k=0; k<4; k++)
                {
                    int x= o+arr[k][0];
                    int y= j+arr[k][1];
                    
                    if(x>=0 && x<row && y>=0 && y<col && grid[x][y]==1)
                    {   
                        grid[x][y]=2;
                        que.push({x,y});
                    }
                }
            }
        }
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return min_time==0?min_time:min_time-1;
    }
};