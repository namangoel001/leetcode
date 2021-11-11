class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        queue<char> q;
        int longest=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            q.push(s[i]);
            while(q.size()>0 && mp[s[i]]>1)
            {
                mp[q.front()]--;
                q.pop();
            }
            int x=q.size();
            longest=max(longest,x);
        }
        return longest;
    }
};