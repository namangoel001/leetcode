class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++)
        {
            int x=intervals[i][0];
            int y=intervals[i][1];
            while(i!=intervals.size()-1 && y>=intervals[i+1][0])
            {
                 x=min(x,intervals[i+1][0]);
                 y=max(y,intervals[i+1][1]);
                i++;
            }
           v.push_back({x,y});
        }
        return v;
    }
};