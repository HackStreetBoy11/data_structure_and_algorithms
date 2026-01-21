class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto lambda = [&](auto& a,auto&b)
        {
            if(a[0]==b[0])
            {
                return a[1]<b[1];
            }
            return a[0]<b[0];
        };
        sort(pairs.begin(),pairs.end(),lambda);
        int maxlen=1;
        vector<int>dp(pairs.size(),1);
        for(int i =1;i<pairs.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if( pairs[j][1]<pairs[i][0])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxlen = max(maxlen,dp[i]);
        }
        return maxlen;
    }
};
