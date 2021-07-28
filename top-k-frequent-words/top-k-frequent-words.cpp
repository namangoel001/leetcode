class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> mp_cnt;
        
        int n=words.size();
        
        for(int i=0;i<n;++i){
            mp_cnt[words[i]]++;
        }
        
        unordered_map<int,vector<string>> mp_vector;
        
        for(auto me:mp_cnt){
            mp_vector[me.second].push_back(me.first);
        }
        
        set<int> s;
        
        for(auto& me:mp_vector){
            sort(me.second.begin(),me.second.end());
            s.insert(me.first);
        }
        
        vector<string> ans;
        
        while(k){
            vector<string> list=mp_vector[*(--s.end())];
            for(int i=0;i<list.size() and k;++i,--k){
                ans.push_back(list[i]);
            }
            s.erase(--s.end());
        }
        
        return ans;
    }
};