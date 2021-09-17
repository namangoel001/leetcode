class Solution {
public:
  
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> vec=nums;
     for(int i=0;i<nums.size();i++)
         vec.push_back(nums[i]);
        stack<int> s;
        vector<int> res;
        for(int i=vec.size()-1;i>=0;i--)
        {
            if(s.size()==0)
                res.push_back(-1);
            else if(s.top()>vec[i])
                res.push_back(s.top());
            else if(s.top()<=vec[i])
            {
                while(s.size()>0 && s.top()<=vec[i])
                    s.pop();
                if(s.size()==0)
                    res.push_back(-1);
                else
                    res.push_back(s.top());
            }
            s.push(vec[i]);
        }
        reverse(res.begin(),res.end());
        res.erase(res.begin()+nums.size(),res.end());
        return res;
    }
};