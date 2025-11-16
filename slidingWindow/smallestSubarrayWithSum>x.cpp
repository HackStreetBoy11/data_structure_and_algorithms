class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
         int sum=0;
        int mini = INT_MAX;
        int l=0,r=0;
        while(r<arr.size())
        {
            sum+=arr[r];
            while(sum>x)
            {
                mini = min(mini,r-l+1);
                sum-=arr[l];
                l++;
            }
            r++;
        }
        return mini ==INT_MAX?0:mini;
    }
};
