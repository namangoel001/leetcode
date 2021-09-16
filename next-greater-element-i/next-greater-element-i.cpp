class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         vector<int> vec;
        unordered_map<int,int> mp;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(s.size()==0)
                mp[nums2[i]]=-1;
            else if(nums2[i]<s.top())
                mp[nums2[i]]=s.top();
            else if(nums2[i]>=s.top())
            {
                while(s.size()>0 && nums2[i]>=s.top())
                    s.pop();
                if(s.size()==0)
                    mp[nums2[i]]=-1;
                else
                    mp[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();++i)
        {
            // if(mp.find(nums1[i])!=mp.end())
                vec.push_back(mp[nums1[i]]);
        }
        return vec;
    }
};