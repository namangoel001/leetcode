class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i=1;
        long long sum=1;
        while(sum<num)
        {
            i=i+2;
            sum+=i;
        }
        if(sum==num)
            return 1;
        return 0;
    }
};