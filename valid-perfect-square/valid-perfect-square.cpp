class Solution {
public:
    bool isPerfectSquare(int num) {
      long long lo=1,hi=num;
        while(lo<=hi)
        {
            long long mid=(lo+hi)/2;
            if(mid*mid==num)
                return mid;
            else if(mid*mid<num)
                lo=mid+1;
            else 
                hi=mid-1;
        }
        return 0;
    }
};