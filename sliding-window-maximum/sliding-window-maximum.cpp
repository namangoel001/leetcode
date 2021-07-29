class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
     priority_queue<pair<int,int>> maxh;
        int i;
        for(i=0;i<k;i++)
        {
            maxh.push({nums[i],i});
        }
        vec.push_back(maxh.top().first);
        for(int j=i;j<nums.size();j++)
        {
            while(maxh.size()>0 && maxh.top().second<=(j-k))
                maxh.pop();
            maxh.push({nums[j],j});
            vec.push_back(maxh.top().first);
        }
        return vec;
    }
};