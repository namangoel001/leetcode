class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        int index=0;
        int max1=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>max1)
            {
                max1=arr[i];
                index=i;
            }
        }
        int j=1;
        int sum=0;
        while(j<index)
        {
            if(arr[j-1]>arr[j])
            {
                sum+=arr[j-1]-arr[j];
            }
            arr[j]=max(arr[j],arr[j-1]);
            j++;
        }
        int k=n-2;
        while(k>index)
        {
            if(arr[k+1]>arr[k])
            {
                sum+=arr[k+1]-arr[k];
            }
            arr[k]=max(arr[k],arr[k+1]);
            k--;
        }
        return sum;
    }
};