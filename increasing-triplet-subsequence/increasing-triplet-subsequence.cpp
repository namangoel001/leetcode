class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int suffix[n];
        int prefix[n];
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
        suffix[i]=max(suffix[i+1],nums[i]);
        }
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]=min(prefix[i-1],nums[i]);
        }
        for(auto it:suffix)
            cout<<it<<" ";
        cout<<"\n";
        for(auto it:prefix)
            cout<<it<<" ";
        for(int i=1;i<n-1;i++)
        {
            if(prefix[i-1]<nums[i] && nums[i]<suffix[i+1])
                return 1;
        }
        return 0;
    }
};