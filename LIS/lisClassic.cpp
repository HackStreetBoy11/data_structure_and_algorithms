class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        vector<int> dp(arr.size(),1);
        int maxlen=1;
        for(int curr=1;curr<arr.size();curr++)
        {
            for(int prev = 0;prev<curr;prev++)
            {
                if(arr[curr]>arr[prev])
                {
                    dp[curr]=max(dp[curr],dp[prev]+1);
                }
            }
            maxlen = max(maxlen,dp[curr]);
        }
        return maxlen;
    }
};
