class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       vector<int> top_frequent;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            minh.push({it.second,it.first});
            if(minh.size()>k)
                minh.pop();
        }
        while(minh.size()>0)
        {
            top_frequent.push_back(minh.top().second);
            minh.pop();
        }
        return top_frequent;
    }
};