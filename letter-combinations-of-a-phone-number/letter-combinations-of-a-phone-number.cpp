class Solution {
public:
    void comb(string str,vector<string> &ans,int index,string digits,vector<string> &vec)
    {
        if(index==digits.size())
        {
            vec.push_back(str);
            return;
        }
        int idx=digits[index]-'0';
        for(int i=0;i<ans[idx].size();i++)
        {
            str.push_back(ans[idx][i]);
            comb(str,ans,index+1,digits,vec);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> vec;
        if(digits.size()==0)
            return vec;
        vector<string> ans{"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string str;
        comb(str,ans,0,digits,vec);
        return vec;
    }
};